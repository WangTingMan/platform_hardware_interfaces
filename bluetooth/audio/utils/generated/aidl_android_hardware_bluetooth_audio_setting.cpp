#define LOG_TAG "aidl.android.hardware.bluetooth.audio.setting"
#include "aidl_android_hardware_bluetooth_audio_setting.h"

#include <assert.h>
#ifndef __BIONIC__
#define __assert2(f,n,fun,e) do { fprintf(stderr, "%s:%d: %s: Assertion `%s' failed", (f), (n), (fun), (e)); abort(); } while (false)
#endif
#define _xsdc_assert(e) do if (!(e)) __assert2(__FILE__, __LINE__, __FUNCTION__, #e); while (false)

namespace aidl {
    namespace android {
        namespace hardware {
            namespace bluetooth {
                namespace audio {
                    namespace setting {
                        template <class T>
                        constexpr void (*xmlDeleter)(T* t);
                        template <>
                        constexpr auto xmlDeleter<xmlDoc> = xmlFreeDoc;
                        template <>
                        auto xmlDeleter<xmlChar> = [](xmlChar *s) { xmlFree(s); };

                        template <class T>
                        constexpr auto make_xmlUnique(T *t) {
                            auto deleter = [](T *t) { xmlDeleter<T>(t); };
                            return std::unique_ptr<T, decltype(deleter)>{t, deleter};
                        }

                        static std::string getXmlAttribute(const xmlNode *cur, const char *attribute) {
                            auto xmlValue = make_xmlUnique(xmlGetProp(cur, reinterpret_cast<const xmlChar*>(attribute)));
                            if (xmlValue == nullptr) {
                                return "";
                            }
                            std::string value(reinterpret_cast<const char*>(xmlValue.get()));
                            return value;
                        }

                        std::optional<LeAudioOffloadSetting> readLeAudioOffloadSetting(const char* configFile) {
                            auto doc = make_xmlUnique(xmlParseFile(configFile));
                            if (doc == nullptr) {
                                return std::nullopt;
                            }
                            xmlNodePtr _child = xmlDocGetRootElement(doc.get());
                            if (_child == nullptr) {
                                return std::nullopt;
                            }
                            if (xmlXIncludeProcess(doc.get()) < 0) {
                                return std::nullopt;
                            }

                            if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("leAudioOffloadSetting"))) {
                                LeAudioOffloadSetting _value = LeAudioOffloadSetting::read(_child);
                                return _value;
                            }
                            return std::nullopt;
                        }

                        std::optional<LeAudioOffloadSetting> parseLeAudioOffloadSetting(const char* xml) {
                            auto doc = make_xmlUnique(xmlParseDoc(reinterpret_cast<const xmlChar*>(xml)));
                            if (doc == nullptr) {
                                return std::nullopt;
                            }
                            xmlNodePtr _child = xmlDocGetRootElement(doc.get());
                            if (_child == nullptr) {
                                return std::nullopt;
                            }
                            if (xmlXIncludeProcess(doc.get()) < 0) {
                                return std::nullopt;
                            }

                            if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("leAudioOffloadSetting"))) {
                                LeAudioOffloadSetting _value = LeAudioOffloadSetting::read(_child);
                                return _value;
                            }
                            return std::nullopt;
                        }


                        LeAudioOffloadSetting::LeAudioOffloadSetting(std::vector<ScenarioList> scenarioList, std::vector<ConfigurationList> configurationList, std::vector<CodecConfigurationList> codecConfigurationList, std::vector<StrategyConfigurationList> strategyConfigurationList) : scenarioList_(std::move(scenarioList)), configurationList_(std::move(configurationList)), codecConfigurationList_(std::move(codecConfigurationList)), strategyConfigurationList_(std::move(strategyConfigurationList)) {
                        }

                        const std::vector<ScenarioList>& LeAudioOffloadSetting::getScenarioList() const {
                            return scenarioList_;
                        }

                        bool LeAudioOffloadSetting::hasScenarioList() const {
                            return !(scenarioList_.empty());
                        }

                        const ScenarioList* LeAudioOffloadSetting::getFirstScenarioList() const {
                            if (scenarioList_.empty()) {
                                return nullptr;
                            }
                            return &scenarioList_[0];
                        }

                        const std::vector<ConfigurationList>& LeAudioOffloadSetting::getConfigurationList() const {
                            return configurationList_;
                        }

                        bool LeAudioOffloadSetting::hasConfigurationList() const {
                            return !(configurationList_.empty());
                        }

                        const ConfigurationList* LeAudioOffloadSetting::getFirstConfigurationList() const {
                            if (configurationList_.empty()) {
                                return nullptr;
                            }
                            return &configurationList_[0];
                        }

                        const std::vector<CodecConfigurationList>& LeAudioOffloadSetting::getCodecConfigurationList() const {
                            return codecConfigurationList_;
                        }

                        bool LeAudioOffloadSetting::hasCodecConfigurationList() const {
                            return !(codecConfigurationList_.empty());
                        }

                        const CodecConfigurationList* LeAudioOffloadSetting::getFirstCodecConfigurationList() const {
                            if (codecConfigurationList_.empty()) {
                                return nullptr;
                            }
                            return &codecConfigurationList_[0];
                        }

                        const std::vector<StrategyConfigurationList>& LeAudioOffloadSetting::getStrategyConfigurationList() const {
                            return strategyConfigurationList_;
                        }

                        bool LeAudioOffloadSetting::hasStrategyConfigurationList() const {
                            return !(strategyConfigurationList_.empty());
                        }

                        const StrategyConfigurationList* LeAudioOffloadSetting::getFirstStrategyConfigurationList() const {
                            if (strategyConfigurationList_.empty()) {
                                return nullptr;
                            }
                            return &strategyConfigurationList_[0];
                        }

                        LeAudioOffloadSetting LeAudioOffloadSetting::read(xmlNode *root) {
                            std::string _raw;
                            std::vector<ScenarioList> scenarioList;
                            std::vector<ConfigurationList> configurationList;
                            std::vector<CodecConfigurationList> codecConfigurationList;
                            std::vector<StrategyConfigurationList> strategyConfigurationList;
                            for (auto *_child = root->xmlChildrenNode; _child != nullptr; _child = _child->next) {
                                if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("scenarioList"))) {
                                    ScenarioList _value = ScenarioList::read(_child);
                                    scenarioList.push_back(std::move(_value));
                                } else if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("configurationList"))) {
                                    ConfigurationList _value = ConfigurationList::read(_child);
                                    configurationList.push_back(std::move(_value));
                                } else if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("codecConfigurationList"))) {
                                    CodecConfigurationList _value = CodecConfigurationList::read(_child);
                                    codecConfigurationList.push_back(std::move(_value));
                                } else if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("strategyConfigurationList"))) {
                                    StrategyConfigurationList _value = StrategyConfigurationList::read(_child);
                                    strategyConfigurationList.push_back(std::move(_value));
                                }
                            }
                            LeAudioOffloadSetting instance(scenarioList, configurationList, codecConfigurationList, strategyConfigurationList);
                            return instance;
                        }

                        ScenarioList::ScenarioList(std::vector<Scenario> scenario) : scenario_(std::move(scenario)) {
                        }

                        const std::vector<Scenario>& ScenarioList::getScenario() const {
                            return scenario_;
                        }

                        bool ScenarioList::hasScenario() const {
                            return !(scenario_.empty());
                        }

                        const Scenario* ScenarioList::getFirstScenario() const {
                            if (scenario_.empty()) {
                                return nullptr;
                            }
                            return &scenario_[0];
                        }

                        ScenarioList ScenarioList::read(xmlNode *root) {
                            std::string _raw;
                            std::vector<Scenario> scenario;
                            for (auto *_child = root->xmlChildrenNode; _child != nullptr; _child = _child->next) {
                                if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("scenario"))) {
                                    Scenario _value = Scenario::read(_child);
                                    scenario.push_back(std::move(_value));
                                }
                            }
                            ScenarioList instance(scenario);
                            return instance;
                        }

                        ConfigurationList::ConfigurationList(std::vector<Configuration> configuration) : configuration_(std::move(configuration)) {
                        }

                        const std::vector<Configuration>& ConfigurationList::getConfiguration() const {
                            return configuration_;
                        }

                        bool ConfigurationList::hasConfiguration() const {
                            return !(configuration_.empty());
                        }

                        const Configuration* ConfigurationList::getFirstConfiguration() const {
                            if (configuration_.empty()) {
                                return nullptr;
                            }
                            return &configuration_[0];
                        }

                        ConfigurationList ConfigurationList::read(xmlNode *root) {
                            std::string _raw;
                            std::vector<Configuration> configuration;
                            for (auto *_child = root->xmlChildrenNode; _child != nullptr; _child = _child->next) {
                                if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("configuration"))) {
                                    Configuration _value = Configuration::read(_child);
                                    configuration.push_back(std::move(_value));
                                }
                            }
                            ConfigurationList instance(configuration);
                            return instance;
                        }

                        CodecConfigurationList::CodecConfigurationList(std::vector<CodecConfiguration> codecConfiguration) : codecConfiguration_(std::move(codecConfiguration)) {
                        }

                        const std::vector<CodecConfiguration>& CodecConfigurationList::getCodecConfiguration() const {
                            return codecConfiguration_;
                        }

                        bool CodecConfigurationList::hasCodecConfiguration() const {
                            return !(codecConfiguration_.empty());
                        }

                        const CodecConfiguration* CodecConfigurationList::getFirstCodecConfiguration() const {
                            if (codecConfiguration_.empty()) {
                                return nullptr;
                            }
                            return &codecConfiguration_[0];
                        }

                        CodecConfigurationList CodecConfigurationList::read(xmlNode *root) {
                            std::string _raw;
                            std::vector<CodecConfiguration> codecConfiguration;
                            for (auto *_child = root->xmlChildrenNode; _child != nullptr; _child = _child->next) {
                                if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("codecConfiguration"))) {
                                    CodecConfiguration _value = CodecConfiguration::read(_child);
                                    codecConfiguration.push_back(std::move(_value));
                                }
                            }
                            CodecConfigurationList instance(codecConfiguration);
                            return instance;
                        }

                        StrategyConfigurationList::StrategyConfigurationList(std::vector<StrategyConfiguration> strategyConfiguration) : strategyConfiguration_(std::move(strategyConfiguration)) {
                        }

                        const std::vector<StrategyConfiguration>& StrategyConfigurationList::getStrategyConfiguration() const {
                            return strategyConfiguration_;
                        }

                        bool StrategyConfigurationList::hasStrategyConfiguration() const {
                            return !(strategyConfiguration_.empty());
                        }

                        const StrategyConfiguration* StrategyConfigurationList::getFirstStrategyConfiguration() const {
                            if (strategyConfiguration_.empty()) {
                                return nullptr;
                            }
                            return &strategyConfiguration_[0];
                        }

                        StrategyConfigurationList StrategyConfigurationList::read(xmlNode *root) {
                            std::string _raw;
                            std::vector<StrategyConfiguration> strategyConfiguration;
                            for (auto *_child = root->xmlChildrenNode; _child != nullptr; _child = _child->next) {
                                if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("strategyConfiguration"))) {
                                    StrategyConfiguration _value = StrategyConfiguration::read(_child);
                                    strategyConfiguration.push_back(std::move(_value));
                                }
                            }
                            StrategyConfigurationList instance(strategyConfiguration);
                            return instance;
                        }

                        Scenario::Scenario(std::optional<std::string> encode, std::optional<std::string> decode, std::optional<std::string> broadcast) : encode_(std::move(encode)), decode_(std::move(decode)), broadcast_(std::move(broadcast)) {
                        }

                        const std::string& Scenario::getEncode() const {
                            _xsdc_assert(hasEncode());
                            return encode_.value();
                        }

                        bool Scenario::hasEncode() const {
                            return encode_.has_value();
                        }

                        const std::string& Scenario::getDecode() const {
                            _xsdc_assert(hasDecode());
                            return decode_.value();
                        }

                        bool Scenario::hasDecode() const {
                            return decode_.has_value();
                        }

                        const std::string& Scenario::getBroadcast() const {
                            _xsdc_assert(hasBroadcast());
                            return broadcast_.value();
                        }

                        bool Scenario::hasBroadcast() const {
                            return broadcast_.has_value();
                        }

                        Scenario Scenario::read(xmlNode *root) {
                            std::string _raw;
                            _raw = getXmlAttribute(root, "encode");
                            std::optional<std::string> encode = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                encode = _value;
                            }
                            _raw = getXmlAttribute(root, "decode");
                            std::optional<std::string> decode = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                decode = _value;
                            }
                            _raw = getXmlAttribute(root, "broadcast");
                            std::optional<std::string> broadcast = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                broadcast = _value;
                            }
                            Scenario instance(encode, decode, broadcast);
                            return instance;
                        }

                        Configuration::Configuration(std::optional<std::string> name, std::optional<std::string> codecConfiguration, std::optional<std::string> strategyConfiguration) : name_(std::move(name)), codecConfiguration_(std::move(codecConfiguration)), strategyConfiguration_(std::move(strategyConfiguration)) {
                        }

                        const std::string& Configuration::getName() const {
                            _xsdc_assert(hasName());
                            return name_.value();
                        }

                        bool Configuration::hasName() const {
                            return name_.has_value();
                        }

                        const std::string& Configuration::getCodecConfiguration() const {
                            _xsdc_assert(hasCodecConfiguration());
                            return codecConfiguration_.value();
                        }

                        bool Configuration::hasCodecConfiguration() const {
                            return codecConfiguration_.has_value();
                        }

                        const std::string& Configuration::getStrategyConfiguration() const {
                            _xsdc_assert(hasStrategyConfiguration());
                            return strategyConfiguration_.value();
                        }

                        bool Configuration::hasStrategyConfiguration() const {
                            return strategyConfiguration_.has_value();
                        }

                        Configuration Configuration::read(xmlNode *root) {
                            std::string _raw;
                            _raw = getXmlAttribute(root, "name");
                            std::optional<std::string> name = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                name = _value;
                            }
                            _raw = getXmlAttribute(root, "codecConfiguration");
                            std::optional<std::string> codecConfiguration = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                codecConfiguration = _value;
                            }
                            _raw = getXmlAttribute(root, "strategyConfiguration");
                            std::optional<std::string> strategyConfiguration = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                strategyConfiguration = _value;
                            }
                            Configuration instance(name, codecConfiguration, strategyConfiguration);
                            return instance;
                        }

                        CodecConfiguration::CodecConfiguration(std::optional<std::string> name, std::optional<CodecType> codec, std::optional<unsigned char> pcmBitDepth, std::optional<int> samplingFrequency, std::optional<int> frameDurationUs, std::optional<int> octetsPerCodecFrame, std::optional<unsigned char> codecFrameBlocksPerSdu) : name_(std::move(name)), codec_(codec), pcmBitDepth_(pcmBitDepth), samplingFrequency_(samplingFrequency), frameDurationUs_(frameDurationUs), octetsPerCodecFrame_(octetsPerCodecFrame), codecFrameBlocksPerSdu_(codecFrameBlocksPerSdu) {
                        }

                        const std::string& CodecConfiguration::getName() const {
                            _xsdc_assert(hasName());
                            return name_.value();
                        }

                        bool CodecConfiguration::hasName() const {
                            return name_.has_value();
                        }

                        const CodecType& CodecConfiguration::getCodec() const {
                            _xsdc_assert(hasCodec());
                            return codec_.value();
                        }

                        bool CodecConfiguration::hasCodec() const {
                            return codec_.has_value();
                        }

                        const unsigned char& CodecConfiguration::getPcmBitDepth() const {
                            _xsdc_assert(hasPcmBitDepth());
                            return pcmBitDepth_.value();
                        }

                        bool CodecConfiguration::hasPcmBitDepth() const {
                            return pcmBitDepth_.has_value();
                        }

                        const int& CodecConfiguration::getSamplingFrequency() const {
                            _xsdc_assert(hasSamplingFrequency());
                            return samplingFrequency_.value();
                        }

                        bool CodecConfiguration::hasSamplingFrequency() const {
                            return samplingFrequency_.has_value();
                        }

                        const int& CodecConfiguration::getFrameDurationUs() const {
                            _xsdc_assert(hasFrameDurationUs());
                            return frameDurationUs_.value();
                        }

                        bool CodecConfiguration::hasFrameDurationUs() const {
                            return frameDurationUs_.has_value();
                        }

                        const int& CodecConfiguration::getOctetsPerCodecFrame() const {
                            _xsdc_assert(hasOctetsPerCodecFrame());
                            return octetsPerCodecFrame_.value();
                        }

                        bool CodecConfiguration::hasOctetsPerCodecFrame() const {
                            return octetsPerCodecFrame_.has_value();
                        }

                        const unsigned char& CodecConfiguration::getCodecFrameBlocksPerSdu() const {
                            _xsdc_assert(hasCodecFrameBlocksPerSdu());
                            return codecFrameBlocksPerSdu_.value();
                        }

                        bool CodecConfiguration::hasCodecFrameBlocksPerSdu() const {
                            return codecFrameBlocksPerSdu_.has_value();
                        }

                        CodecConfiguration CodecConfiguration::read(xmlNode *root) {
                            std::string _raw;
                            _raw = getXmlAttribute(root, "name");
                            std::optional<std::string> name = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                name = _value;
                            }
                            _raw = getXmlAttribute(root, "codec");
                            std::optional<CodecType> codec = std::nullopt;
                            if (_raw != "") {
                                CodecType _value = stringToCodecType(_raw);
                                codec = _value;
                            }
                            _raw = getXmlAttribute(root, "pcmBitDepth");
                            std::optional<unsigned char> pcmBitDepth = std::nullopt;
                            if (_raw != "") {
                                unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                pcmBitDepth = _value;
                            }
                            _raw = getXmlAttribute(root, "samplingFrequency");
                            std::optional<int> samplingFrequency = std::nullopt;
                            if (_raw != "") {
                                int _value = std::stoi(_raw);
                                samplingFrequency = _value;
                            }
                            _raw = getXmlAttribute(root, "frameDurationUs");
                            std::optional<int> frameDurationUs = std::nullopt;
                            if (_raw != "") {
                                int _value = std::stoi(_raw);
                                frameDurationUs = _value;
                            }
                            _raw = getXmlAttribute(root, "octetsPerCodecFrame");
                            std::optional<int> octetsPerCodecFrame = std::nullopt;
                            if (_raw != "") {
                                int _value = std::stoi(_raw);
                                octetsPerCodecFrame = _value;
                            }
                            _raw = getXmlAttribute(root, "codecFrameBlocksPerSdu");
                            std::optional<unsigned char> codecFrameBlocksPerSdu = std::nullopt;
                            if (_raw != "") {
                                unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                codecFrameBlocksPerSdu = _value;
                            }
                            CodecConfiguration instance(name, codec, pcmBitDepth, samplingFrequency, frameDurationUs, octetsPerCodecFrame, codecFrameBlocksPerSdu);
                            return instance;
                        }

                        StrategyConfiguration::StrategyConfiguration(std::optional<std::string> name, std::optional<AudioLocation> audioLocation, std::optional<unsigned char> connectedDevice, std::optional<unsigned char> channelCount) : name_(std::move(name)), audioLocation_(audioLocation), connectedDevice_(connectedDevice), channelCount_(channelCount) {
                        }

                        const std::string& StrategyConfiguration::getName() const {
                            _xsdc_assert(hasName());
                            return name_.value();
                        }

                        bool StrategyConfiguration::hasName() const {
                            return name_.has_value();
                        }

                        const AudioLocation& StrategyConfiguration::getAudioLocation() const {
                            _xsdc_assert(hasAudioLocation());
                            return audioLocation_.value();
                        }

                        bool StrategyConfiguration::hasAudioLocation() const {
                            return audioLocation_.has_value();
                        }

                        const unsigned char& StrategyConfiguration::getConnectedDevice() const {
                            _xsdc_assert(hasConnectedDevice());
                            return connectedDevice_.value();
                        }

                        bool StrategyConfiguration::hasConnectedDevice() const {
                            return connectedDevice_.has_value();
                        }

                        const unsigned char& StrategyConfiguration::getChannelCount() const {
                            _xsdc_assert(hasChannelCount());
                            return channelCount_.value();
                        }

                        bool StrategyConfiguration::hasChannelCount() const {
                            return channelCount_.has_value();
                        }

                        StrategyConfiguration StrategyConfiguration::read(xmlNode *root) {
                            std::string _raw;
                            _raw = getXmlAttribute(root, "name");
                            std::optional<std::string> name = std::nullopt;
                            if (_raw != "") {
                                std::string &_value = _raw;
                                name = _value;
                            }
                            _raw = getXmlAttribute(root, "audioLocation");
                            std::optional<AudioLocation> audioLocation = std::nullopt;
                            if (_raw != "") {
                                AudioLocation _value = stringToAudioLocation(_raw);
                                audioLocation = _value;
                            }
                            _raw = getXmlAttribute(root, "connectedDevice");
                            std::optional<unsigned char> connectedDevice = std::nullopt;
                            if (_raw != "") {
                                unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                connectedDevice = _value;
                            }
                            _raw = getXmlAttribute(root, "channelCount");
                            std::optional<unsigned char> channelCount = std::nullopt;
                            if (_raw != "") {
                                unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                channelCount = _value;
                            }
                            StrategyConfiguration instance(name, audioLocation, connectedDevice, channelCount);
                            return instance;
                        }
                    } // setting
                } // audio
            } // bluetooth
        } // hardware
    } // android
} // aidl
