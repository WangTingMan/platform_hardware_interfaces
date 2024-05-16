/*
 * Copyright (C) 2022 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "BTAudioProviderA2dpSW"

#include "A2dpSoftwareAudioProvider.h"

#include <BluetoothAudioCodecs.h>
#include <BluetoothAudioSessionReport.h>
#include <android-base/logging.h>

#ifdef _MSC_VER
#include <base/rand_util.h>
#include <aidl\android\hardware\common\fmq\MQDescriptor.h>
#include <binder\Parcel.h>
#include <android\binder_auto_utils.h>
#include <ndk\parcel_internal.h>
#include "ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS.h"
#endif

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {

// Here the buffer size is based on SBC
static constexpr uint32_t kPcmFrameSize = 4;  // 16 bits per sample / stereo
// SBC is 128, and here we choose the LCM of 16, 24, and 32
static constexpr uint32_t kPcmFrameCount = 96;
static constexpr uint32_t kRtpFrameSize = kPcmFrameSize * kPcmFrameCount;
// The max counts by 1 tick (20ms) for SBC is about 7. Since using 96 for the
// PCM counts, here we just choose a greater number
static constexpr uint32_t kRtpFrameCount = 10;
static constexpr uint32_t kBufferSize = kRtpFrameSize * kRtpFrameCount;
static constexpr uint32_t kBufferCount = 2;  // double buffer
static constexpr uint32_t kDataMqSize = kBufferSize * kBufferCount;

A2dpSoftwareEncodingAudioProvider::A2dpSoftwareEncodingAudioProvider()
    : A2dpSoftwareAudioProvider() {
  session_type_ = SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH;
}

A2dpSoftwareDecodingAudioProvider::A2dpSoftwareDecodingAudioProvider()
    : A2dpSoftwareAudioProvider() {
  session_type_ = SessionType::A2DP_SOFTWARE_DECODING_DATAPATH;
}

A2dpSoftwareAudioProvider::A2dpSoftwareAudioProvider()
    : BluetoothAudioProvider(), data_mq_(nullptr) {
  LOG(INFO) << __func__ << " - size of audio buffer " << kDataMqSize
            << " byte(s)";
#ifdef _MSC_VER
  std::string shared_memory_name{ "aidl::android::hardware::bluetooth::audio::A2dpSoftwareAudioProvider{" };
  shared_memory_name.append( std::to_string( __LINE__ ) ).append( "}" );
  shared_memory_name.append( std::to_string( ::base::RandInt( 0, 1000 ) ) );
  std::unique_ptr<DataMQ> data_mq(
      new DataMQ(kDataMqSize, shared_memory_name,/* EventFlag */ true));
#else
  std::unique_ptr<DataMQ> data_mq(
      new DataMQ( kDataMqSize, /* EventFlag */ true ) );
#endif
  if (data_mq && data_mq->isValid()) {
    data_mq_ = std::move(data_mq);
  } else {
    ALOGE_IF(!data_mq, "failed to allocate data MQ");
    ALOGE_IF(data_mq && !data_mq->isValid(), "data MQ is invalid");
  }

}

bool A2dpSoftwareAudioProvider::isValid(const SessionType& sessionType) {
  return (sessionType == session_type_ && data_mq_ && data_mq_->isValid());
}

#ifdef _MSC_VER
ndk::ScopedAStatus A2dpSoftwareAudioProvider::startSession(
    const std::shared_ptr<IBluetoothAudioPort>& host_if,
    const AudioConfiguration& audio_config,
    const std::vector<LatencyMode>& latency_modes, DataMQDesc* _aidl_return) {
    return startSession_impl( host_if, audio_config, latency_modes, _aidl_return );
}

    ndk::ScopedAStatus A2dpSoftwareAudioProvider::startSession_impl(
        const std::shared_ptr<IBluetoothAudioPort>&host_if,
        const AudioConfiguration & audio_config,
        const std::vector<LatencyMode>&latency_modes, DataMQDesc * _aidl_return )
{
#else
ndk::ScopedAStatus A2dpSoftwareAudioProvider::startSession(
    const std::shared_ptr<IBluetoothAudioPort>& host_if,
    const AudioConfiguration& audio_config,
    const std::vector<LatencyMode>& latency_modes, DataMQDesc* _aidl_return) {
#endif
  if (audio_config.getTag() != AudioConfiguration::pcmConfig) {
    LOG(WARNING) << __func__ << " - Invalid Audio Configuration="
                 << audio_config.toString();
    *_aidl_return = DataMQDesc();
    return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
  }
  const PcmConfiguration& pcm_config =
      audio_config.get<AudioConfiguration::pcmConfig>();
  if (!BluetoothAudioCodecs::IsSoftwarePcmConfigurationValid(pcm_config)) {
    LOG(WARNING) << __func__ << " - Unsupported PCM Configuration="
                 << pcm_config.toString();
    *_aidl_return = DataMQDesc();
    return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
  }

  return BluetoothAudioProvider::startSession(
      host_if, audio_config, latency_modes, _aidl_return);
}

#ifdef _MSC_VER
ndk::ScopedAStatus A2dpSoftwareAudioProvider::onSessionReadyDebug()
{
    auto provider = ::ndk::SharedRefBase::make<A2dpSoftwareEncodingAudioProvider>();
    DataMQDesc decs;
    auto ret = provider->onSessionReady( &decs );
    return ret;
}
#endif

ndk::ScopedAStatus A2dpSoftwareAudioProvider::onSessionReady(
    DataMQDesc* _aidl_return) {
  if (data_mq_ == nullptr || !data_mq_->isValid()) {
    *_aidl_return = DataMQDesc();
    return ndk::ScopedAStatus::fromExceptionCode(EX_ILLEGAL_ARGUMENT);
  }
  *_aidl_return = data_mq_->dupeDesc();
  auto desc = data_mq_->dupeDesc();
  BluetoothAudioSessionReport::OnSessionStarted(
      session_type_, stack_iface_, &desc, *audio_config_, latency_modes_);
  return ndk::ScopedAStatus::ok();
}

}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl

#ifdef _MSC_VER

void test()
{
    std::string shared_memory_name{ "A2dpSoftwareAudioProvider{" };
    shared_memory_name.append( std::to_string( __LINE__ ) ).append( "}" );
    shared_memory_name.append( std::to_string( ::base::RandInt( 0, 1000 ) ) );
    std::unique_ptr<DataMQ> data_mq(
        new DataMQ( 7680, shared_memory_name,/* EventFlag */ true ) );

    auto desc = data_mq->dupeDesc();

    std::unique_ptr<DataMQ> data_mq2;
    data_mq2.reset( new DataMQ( desc ) );

    int x = 90;
    x++;
}

ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API void ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_TEST_NOT_USE_DIRECTLY()
{
    test();
    LOG( ERROR ) << "Should not use this.";
    aidl::android::hardware::bluetooth::audio::A2dpSoftwareAudioProvider::onSessionReadyDebug();
}
#endif
