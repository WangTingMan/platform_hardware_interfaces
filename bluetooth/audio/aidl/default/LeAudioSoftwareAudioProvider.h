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

#pragma once

#include "BluetoothAudioProvider.h"
#include "ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS.h"

namespace aidl {
namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {

class ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API LeAudioSoftwareAudioProvider : public BluetoothAudioProvider {
 public:
  LeAudioSoftwareAudioProvider();

  bool isValid(const SessionType& sessionType) override;

  ndk::ScopedAStatus startSession(
      const std::shared_ptr<IBluetoothAudioPort>& host_if,
      const AudioConfiguration& audio_config,
      const std::vector<LatencyMode>& latency_modes,
      DataMQDesc* _aidl_return);

 private:
  // audio data queue for software encoding
  std::unique_ptr<DataMQ> data_mq_;

  ndk::ScopedAStatus onSessionReady(DataMQDesc* _aidl_return) override;
};

class ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API LeAudioSoftwareOutputAudioProvider : public LeAudioSoftwareAudioProvider {
 public:
  LeAudioSoftwareOutputAudioProvider();
};

class ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API LeAudioSoftwareInputAudioProvider : public LeAudioSoftwareAudioProvider {
 public:
  LeAudioSoftwareInputAudioProvider();
};

class ANDROIDHARDWAREBLUETOOTHAUDIOIMPL_EXPORTS_API LeAudioSoftwareBroadcastAudioProvider
    : public LeAudioSoftwareAudioProvider {
 public:
  LeAudioSoftwareBroadcastAudioProvider();
};

}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
}  // namespace aidl