#ifndef AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_SETTING_ENUMS_H
#define AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_SETTING_ENUMS_H

#include <array>
#include <string>

#include <xsdc/XsdcSupport.h>

namespace aidl {
    namespace android {
        namespace hardware {
            namespace bluetooth {
                namespace audio {
                    namespace setting {
                        enum class AudioLocation {
                            UNKNOWN = -1,
                            MONO,
                            STEREO,
                        };
                        AudioLocation stringToAudioLocation(const std::string& value);
                        std::string toString(AudioLocation o);

                        enum class CodecType {
                            UNKNOWN = -1,
                            LC3,
                            APTX_ADAPTIVE_LE,
                            APTX_ADAPTIVE_LEX,
                        };
                        CodecType stringToCodecType(const std::string& value);
                        std::string toString(CodecType o);

                    } // setting
                } // audio
            } // bluetooth
        } // hardware
    } // android
} // aidl

//
// global type declarations for package
//

namespace android {
    namespace details {
        template<> inline constexpr std::array<::aidl::android::hardware::bluetooth::audio::setting::AudioLocation, 2> xsdc_enum_values<::aidl::android::hardware::bluetooth::audio::setting::AudioLocation> = {
            ::aidl::android::hardware::bluetooth::audio::setting::AudioLocation::MONO,
            ::aidl::android::hardware::bluetooth::audio::setting::AudioLocation::STEREO,
        };
        template<> inline constexpr std::array<::aidl::android::hardware::bluetooth::audio::setting::CodecType, 3> xsdc_enum_values<::aidl::android::hardware::bluetooth::audio::setting::CodecType> = {
            ::aidl::android::hardware::bluetooth::audio::setting::CodecType::LC3,
            ::aidl::android::hardware::bluetooth::audio::setting::CodecType::APTX_ADAPTIVE_LE,
            ::aidl::android::hardware::bluetooth::audio::setting::CodecType::APTX_ADAPTIVE_LEX,
        };
    }  // namespace details
}  // namespace android

#endif // AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_SETTING_ENUMS_H
