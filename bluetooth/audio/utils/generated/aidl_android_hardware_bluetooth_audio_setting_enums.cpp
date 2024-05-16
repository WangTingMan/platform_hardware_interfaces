#include <map>

#include "aidl_android_hardware_bluetooth_audio_setting_enums.h"

namespace aidl {
    namespace android {
        namespace hardware {
            namespace bluetooth {
                namespace audio {
                    namespace setting {
                        const std::map<std::string, AudioLocation> AudioLocationString {
                            { "MONO", AudioLocation::MONO },
                            { "STEREO", AudioLocation::STEREO },
                        };

                        AudioLocation stringToAudioLocation(const std::string& value) {
                            auto enumValue = AudioLocationString.find(value);
                            return enumValue != AudioLocationString.end() ? enumValue->second : AudioLocation::UNKNOWN;
                        }

                        std::string toString(AudioLocation o) {
                            switch (o) {
                                case AudioLocation::MONO: return "MONO";
                                case AudioLocation::STEREO: return "STEREO";
                                default: return std::to_string(static_cast<int>(o));
                            }
                        }

                        const std::map<std::string, CodecType> CodecTypeString {
                            { "LC3", CodecType::LC3 },
                            { "APTX_ADAPTIVE_LE", CodecType::APTX_ADAPTIVE_LE },
                            { "APTX_ADAPTIVE_LEX", CodecType::APTX_ADAPTIVE_LEX },
                        };

                        CodecType stringToCodecType(const std::string& value) {
                            auto enumValue = CodecTypeString.find(value);
                            return enumValue != CodecTypeString.end() ? enumValue->second : CodecType::UNKNOWN;
                        }

                        std::string toString(CodecType o) {
                            switch (o) {
                                case CodecType::LC3: return "LC3";
                                case CodecType::APTX_ADAPTIVE_LE: return "APTX_ADAPTIVE_LE";
                                case CodecType::APTX_ADAPTIVE_LEX: return "APTX_ADAPTIVE_LEX";
                                default: return std::to_string(static_cast<int>(o));
                            }
                        }

                    } // setting
                } // audio
            } // bluetooth
        } // hardware
    } // android
} // aidl
