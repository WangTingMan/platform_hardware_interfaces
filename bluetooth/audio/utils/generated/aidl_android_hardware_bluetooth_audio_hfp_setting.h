#ifndef AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_HFP_SETTING_H
#define AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_HFP_SETTING_H

#include <array>
#include <map>
#include <optional>
#include <string>
#include <vector>
#include <sstream>

#if __has_include(<libxml/parser.h>)
#include <libxml/parser.h>
#include <libxml/xinclude.h>
#else
#error Require libxml2 library. Please add libxml2 to shared_libs or static_libs
#endif

#include "aidl_android_hardware_bluetooth_audio_hfp_setting_enums.h"

namespace aidl {
    namespace android {
        namespace hardware {
            namespace bluetooth {
                namespace audio {
                    namespace hfp {
                        namespace setting {
                            class HfpOffloadSetting;
                            class PathConfiguration;
                            class TransportConfiguration;
                            class Configuration;
                            std::optional<HfpOffloadSetting> readHfpOffloadSetting(const char* configFile);

                            std::optional<HfpOffloadSetting> parseHfpOffloadSetting(const char* xml);

                            class HfpOffloadSetting {
                                private:
                                const std::vector<PathConfiguration> pathConfiguration_;
                                const std::vector<TransportConfiguration> transportConfiguration_;
                                const std::vector<Configuration> configuration_;
                                public:
                                HfpOffloadSetting(std::vector<PathConfiguration> pathConfiguration, std::vector<TransportConfiguration> transportConfiguration, std::vector<Configuration> configuration);
                                const std::vector<PathConfiguration>& getPathConfiguration() const;
                                bool hasPathConfiguration() const;
                                const PathConfiguration* getFirstPathConfiguration() const;
                                const std::vector<TransportConfiguration>& getTransportConfiguration() const;
                                bool hasTransportConfiguration() const;
                                const TransportConfiguration* getFirstTransportConfiguration() const;
                                const std::vector<Configuration>& getConfiguration() const;
                                bool hasConfiguration() const;
                                const Configuration* getFirstConfiguration() const;
                                static HfpOffloadSetting read(xmlNode *root);
                            };

                            class PathConfiguration {
                                private:
                                const std::optional<std::string> name_;
                                const std::optional<unsigned int> bandwidth_;
                                const std::optional<CodecType> codec_;
                                const std::optional<unsigned short> codedDataSize_;
                                const std::optional<unsigned char> pcmDataFormat_;
                                const std::optional<unsigned char> pcmPayloadMsbPosition_;
                                const std::optional<unsigned char> dataPath_;
                                const std::optional<unsigned char> transportUnitSize_;
                                public:
                                PathConfiguration(std::optional<std::string> name, std::optional<unsigned int> bandwidth, std::optional<CodecType> codec, std::optional<unsigned short> codedDataSize, std::optional<unsigned char> pcmDataFormat, std::optional<unsigned char> pcmPayloadMsbPosition, std::optional<unsigned char> dataPath, std::optional<unsigned char> transportUnitSize);
                                const std::string& getName() const;
                                bool hasName() const;
                                const unsigned int& getBandwidth() const;
                                bool hasBandwidth() const;
                                const CodecType& getCodec() const;
                                bool hasCodec() const;
                                const unsigned short& getCodedDataSize() const;
                                bool hasCodedDataSize() const;
                                const unsigned char& getPcmDataFormat() const;
                                bool hasPcmDataFormat() const;
                                const unsigned char& getPcmPayloadMsbPosition() const;
                                bool hasPcmPayloadMsbPosition() const;
                                const unsigned char& getDataPath() const;
                                bool hasDataPath() const;
                                const unsigned char& getTransportUnitSize() const;
                                bool hasTransportUnitSize() const;
                                static PathConfiguration read(xmlNode *root);
                            };

                            class TransportConfiguration {
                                private:
                                const std::optional<std::string> name_;
                                const std::optional<unsigned int> bandwidth_;
                                const std::optional<CodecType> codec_;
                                const std::optional<unsigned short> codedFrameSize_;
                                public:
                                TransportConfiguration(std::optional<std::string> name, std::optional<unsigned int> bandwidth, std::optional<CodecType> codec, std::optional<unsigned short> codedFrameSize);
                                const std::string& getName() const;
                                bool hasName() const;
                                const unsigned int& getBandwidth() const;
                                bool hasBandwidth() const;
                                const CodecType& getCodec() const;
                                bool hasCodec() const;
                                const unsigned short& getCodedFrameSize() const;
                                bool hasCodedFrameSize() const;
                                static TransportConfiguration read(xmlNode *root);
                            };

                            class Configuration {
                                private:
                                const std::optional<std::string> name_;
                                const std::optional<CodecType> codec_;
                                const std::optional<unsigned short> maxLatencyMs_;
                                const std::optional<unsigned short> packetTypes_;
                                const std::optional<unsigned char> retransmissionEffort_;
                                const std::optional<bool> useControllerCodec_;
                                const std::optional<std::string> inputPathConfiguration_;
                                const std::optional<std::string> outputPathConfiguration_;
                                const std::optional<std::string> inputTransportConfiguration_;
                                const std::optional<std::string> outputTransportConfiguration_;
                                public:
                                Configuration(std::optional<std::string> name, std::optional<CodecType> codec, std::optional<unsigned short> maxLatencyMs, std::optional<unsigned short> packetTypes, std::optional<unsigned char> retransmissionEffort, std::optional<bool> useControllerCodec, std::optional<std::string> inputPathConfiguration, std::optional<std::string> outputPathConfiguration, std::optional<std::string> inputTransportConfiguration, std::optional<std::string> outputTransportConfiguration);
                                const std::string& getName() const;
                                bool hasName() const;
                                const CodecType& getCodec() const;
                                bool hasCodec() const;
                                const unsigned short& getMaxLatencyMs() const;
                                bool hasMaxLatencyMs() const;
                                const unsigned short& getPacketTypes() const;
                                bool hasPacketTypes() const;
                                const unsigned char& getRetransmissionEffort() const;
                                bool hasRetransmissionEffort() const;
                                const bool& getUseControllerCodec() const;
                                bool hasUseControllerCodec() const;
                                const std::string& getInputPathConfiguration() const;
                                bool hasInputPathConfiguration() const;
                                const std::string& getOutputPathConfiguration() const;
                                bool hasOutputPathConfiguration() const;
                                const std::string& getInputTransportConfiguration() const;
                                bool hasInputTransportConfiguration() const;
                                const std::string& getOutputTransportConfiguration() const;
                                bool hasOutputTransportConfiguration() const;
                                static Configuration read(xmlNode *root);
                            };

                        } // setting
                    } // hfp
                } // audio
            } // bluetooth
        } // hardware
    } // android
} // aidl
#endif // AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_HFP_SETTING_H
