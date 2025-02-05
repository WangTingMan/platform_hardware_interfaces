#ifndef AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_SETTING_H
#define AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_SETTING_H

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

#include "aidl_android_hardware_bluetooth_audio_setting_enums.h"

#include <aidl_session/LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS_.h>

#define AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS LIBBLUETOOTHAUDIOSESSIONAIDL_EXPORTS

namespace aidl {
    namespace android {
        namespace hardware {
            namespace bluetooth {
                namespace audio {
                    namespace setting {
                        class LeAudioOffloadSetting;
                        class ScenarioList;
                        class ConfigurationList;
                        class CodecConfigurationList;
                        class StrategyConfigurationList;
                        class Scenario;
                        class Configuration;
                        class CodecConfiguration;
                        class StrategyConfiguration;
                        AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS std::optional<LeAudioOffloadSetting> readLeAudioOffloadSetting(const char* configFile);

                        AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS std::optional<LeAudioOffloadSetting> parseLeAudioOffloadSetting(const char* xml);

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS LeAudioOffloadSetting {
                            private:
                            const std::vector<ScenarioList> scenarioList_;
                            const std::vector<ConfigurationList> configurationList_;
                            const std::vector<CodecConfigurationList> codecConfigurationList_;
                            const std::vector<StrategyConfigurationList> strategyConfigurationList_;
                            public:
                            LeAudioOffloadSetting(std::vector<ScenarioList> scenarioList, std::vector<ConfigurationList> configurationList, std::vector<CodecConfigurationList> codecConfigurationList, std::vector<StrategyConfigurationList> strategyConfigurationList);
                            const std::vector<ScenarioList>& getScenarioList() const;
                            bool hasScenarioList() const;
                            const ScenarioList* getFirstScenarioList() const;
                            const std::vector<ConfigurationList>& getConfigurationList() const;
                            bool hasConfigurationList() const;
                            const ConfigurationList* getFirstConfigurationList() const;
                            const std::vector<CodecConfigurationList>& getCodecConfigurationList() const;
                            bool hasCodecConfigurationList() const;
                            const CodecConfigurationList* getFirstCodecConfigurationList() const;
                            const std::vector<StrategyConfigurationList>& getStrategyConfigurationList() const;
                            bool hasStrategyConfigurationList() const;
                            const StrategyConfigurationList* getFirstStrategyConfigurationList() const;
                            static LeAudioOffloadSetting read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS ScenarioList {
                            private:
                            const std::vector<Scenario> scenario_;
                            public:
                            explicit ScenarioList(std::vector<Scenario> scenario);
                            const std::vector<Scenario>& getScenario() const;
                            bool hasScenario() const;
                            const Scenario* getFirstScenario() const;
                            static ScenarioList read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS ConfigurationList {
                            private:
                            const std::vector<Configuration> configuration_;
                            public:
                            explicit ConfigurationList(std::vector<Configuration> configuration);
                            const std::vector<Configuration>& getConfiguration() const;
                            bool hasConfiguration() const;
                            const Configuration* getFirstConfiguration() const;
                            static ConfigurationList read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS CodecConfigurationList {
                            private:
                            const std::vector<CodecConfiguration> codecConfiguration_;
                            public:
                            explicit CodecConfigurationList(std::vector<CodecConfiguration> codecConfiguration);
                            const std::vector<CodecConfiguration>& getCodecConfiguration() const;
                            bool hasCodecConfiguration() const;
                            const CodecConfiguration* getFirstCodecConfiguration() const;
                            static CodecConfigurationList read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS StrategyConfigurationList {
                            private:
                            const std::vector<StrategyConfiguration> strategyConfiguration_;
                            public:
                            explicit StrategyConfigurationList(std::vector<StrategyConfiguration> strategyConfiguration);
                            const std::vector<StrategyConfiguration>& getStrategyConfiguration() const;
                            bool hasStrategyConfiguration() const;
                            const StrategyConfiguration* getFirstStrategyConfiguration() const;
                            static StrategyConfigurationList read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS Scenario {
                            private:
                            const std::optional<std::string> encode_;
                            const std::optional<std::string> decode_;
                            const std::optional<std::string> broadcast_;
                            public:
                            Scenario(std::optional<std::string> encode, std::optional<std::string> decode, std::optional<std::string> broadcast);
                            const std::string& getEncode() const;
                            bool hasEncode() const;
                            const std::string& getDecode() const;
                            bool hasDecode() const;
                            const std::string& getBroadcast() const;
                            bool hasBroadcast() const;
                            static Scenario read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS Configuration {
                            private:
                            const std::optional<std::string> name_;
                            const std::optional<std::string> codecConfiguration_;
                            const std::optional<std::string> strategyConfiguration_;
                            public:
                            Configuration(std::optional<std::string> name, std::optional<std::string> codecConfiguration, std::optional<std::string> strategyConfiguration);
                            const std::string& getName() const;
                            bool hasName() const;
                            const std::string& getCodecConfiguration() const;
                            bool hasCodecConfiguration() const;
                            const std::string& getStrategyConfiguration() const;
                            bool hasStrategyConfiguration() const;
                            static Configuration read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS CodecConfiguration {
                            private:
                            const std::optional<std::string> name_;
                            const std::optional<CodecType> codec_;
                            const std::optional<unsigned char> pcmBitDepth_;
                            const std::optional<int> samplingFrequency_;
                            const std::optional<int> frameDurationUs_;
                            const std::optional<int> octetsPerCodecFrame_;
                            const std::optional<unsigned char> codecFrameBlocksPerSdu_;
                            public:
                            CodecConfiguration(std::optional<std::string> name, std::optional<CodecType> codec, std::optional<unsigned char> pcmBitDepth, std::optional<int> samplingFrequency, std::optional<int> frameDurationUs, std::optional<int> octetsPerCodecFrame, std::optional<unsigned char> codecFrameBlocksPerSdu);
                            const std::string& getName() const;
                            bool hasName() const;
                            const CodecType& getCodec() const;
                            bool hasCodec() const;
                            const unsigned char& getPcmBitDepth() const;
                            bool hasPcmBitDepth() const;
                            const int& getSamplingFrequency() const;
                            bool hasSamplingFrequency() const;
                            const int& getFrameDurationUs() const;
                            bool hasFrameDurationUs() const;
                            const int& getOctetsPerCodecFrame() const;
                            bool hasOctetsPerCodecFrame() const;
                            const unsigned char& getCodecFrameBlocksPerSdu() const;
                            bool hasCodecFrameBlocksPerSdu() const;
                            static CodecConfiguration read(xmlNode *root);
                        };

                        class AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_API_EXPORTS StrategyConfiguration {
                            private:
                            const std::optional<std::string> name_;
                            const std::optional<AudioLocation> audioLocation_;
                            const std::optional<unsigned char> connectedDevice_;
                            const std::optional<unsigned char> channelCount_;
                            public:
                            StrategyConfiguration(std::optional<std::string> name, std::optional<AudioLocation> audioLocation, std::optional<unsigned char> connectedDevice, std::optional<unsigned char> channelCount);
                            const std::string& getName() const;
                            bool hasName() const;
                            const AudioLocation& getAudioLocation() const;
                            bool hasAudioLocation() const;
                            const unsigned char& getConnectedDevice() const;
                            bool hasConnectedDevice() const;
                            const unsigned char& getChannelCount() const;
                            bool hasChannelCount() const;
                            static StrategyConfiguration read(xmlNode *root);
                        };

                    } // setting
                } // audio
            } // bluetooth
        } // hardware
    } // android
} // aidl
#endif // AIDL_ANDROID_HARDWARE_BLUETOOTH_AUDIO_SETTING_H
