#ifndef AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_HFP_SETTING_ENUMS_H
#define AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_HFP_SETTING_ENUMS_H

#include <array>
#include <string>

#include <xsdc/XsdcSupport.h>

namespace aidl {
    namespace android {
        namespace hardware {
            namespace bluetooth {
                namespace audio {
                    namespace hfp {
                        namespace setting {
                            enum class CodecType {
                                UNKNOWN = -1,
                                LC3,
                                CVSD,
                                MSBC,
                            };
                            CodecType stringToCodecType(const std::string& value);
                            std::string toString(CodecType o);

                        } // setting
                    } // hfp
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
        template<> inline constexpr std::array<::aidl::android::hardware::bluetooth::audio::hfp::setting::CodecType, 3> xsdc_enum_values<::aidl::android::hardware::bluetooth::audio::hfp::setting::CodecType> = {
            ::aidl::android::hardware::bluetooth::audio::hfp::setting::CodecType::LC3,
            ::aidl::android::hardware::bluetooth::audio::hfp::setting::CodecType::CVSD,
            ::aidl::android::hardware::bluetooth::audio::hfp::setting::CodecType::MSBC,
        };
    }  // namespace details
}  // namespace android

#endif // AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_HFP_SETTING_ENUMS_H
