/*
 * Copyright (C) 2025 The Android Open Source Project
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

#ifdef _MSC_VER

namespace aidl::android::hardware::bluetooth::audio::swoff {

    enum CodecType {
        LC3,
        OPUS,
    };

    class LeAudioCallbacks {
    public:
        virtual ~LeAudioCallbacks() = default;
        virtual void start( void ) = 0;
        virtual void stop( void ) = 0;
    };

    struct IsoStream {
        uint16_t handle;
        uint32_t channel_allocation;
    };

    struct Lc3Config {
        bool hr_mode;
        int block_bytes;
    };

    struct OpusConfig {
        int frame_bytes;
        bool vbr;
        int complexity;
    };

    struct AudioConfig {
        int bitdepth;
        int sample_rate;
        int frame_duration_us;

        CodecType codec_type;
        union {
            Lc3Config lc3;
            OpusConfig opus;
        } codec_config;
    };

    class LeAudioStream {
    public:
        LeAudioStream( const std::vector<IsoStream> iso_streams, const AudioConfig& audio_config,
            std::shared_ptr<LeAudioCallbacks> callbacks, unsigned anchor_delay_us = 30000 ) {
        }

        ~LeAudioStream() {
            handle_ = nullptr;
        }

        size_t write( const void* data, size_t len ) { return len; }

    private:
        void* handle_;
    };
}

#else
#include <swoff/swoff_lea.h>
#endif

namespace aidl::android::hardware::bluetooth::audio {

class LeAudioSwOffloadCallbacks : public swoff::LeAudioCallbacks {
 public:
  LeAudioSwOffloadCallbacks();
  void start() override;
  void stop() override;
};

class LeAudioSwOffloadInstance {
 public:
  static std::shared_ptr<LeAudioSwOffloadCallbacks> sw_offload_cbacks_;
  static std::shared_ptr<swoff::LeAudioStream> sw_offload_streams_;
  static std::atomic<bool> is_using_swoffload_;
  static std::atomic<bool> is_swoff_stream_running_;
  static void releaseSwOffload();
};

}  // namespace aidl::android::hardware::bluetooth::audio
