#include <map>

#include "aidl_android_hardware_bluetooth_audio_hfp_setting_enums.h"

namespace aidl {
    namespace android {
        namespace hardware {
            namespace bluetooth {
                namespace audio {
                    namespace hfp {
                        namespace setting {
                            const std::map<std::string, CodecType> CodecTypeString {
                                { "LC3", CodecType::LC3 },
                                { "CVSD", CodecType::CVSD },
                                { "MSBC", CodecType::MSBC },
                            };

                            CodecType stringToCodecType(const std::string& value) {
                                auto enumValue = CodecTypeString.find(value);
                                return enumValue != CodecTypeString.end() ? enumValue->second : CodecType::UNKNOWN;
                            }

                            std::string toString(CodecType o) {
                                switch (o) {
                                    case CodecType::LC3: return "LC3";
                                    case CodecType::CVSD: return "CVSD";
                                    case CodecType::MSBC: return "MSBC";
                                    default: return std::to_string(static_cast<int>(o));
                                }
                            }

                        } // setting
                    } // hfp
                } // audio
            } // bluetooth
        } // hardware
    } // android
} // aidl
