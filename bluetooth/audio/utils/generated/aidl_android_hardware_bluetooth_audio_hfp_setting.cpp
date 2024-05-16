#define LOG_TAG "aidl.android.hardware.bluetooth.audio.hfp.setting"
#include "aidl_android_hardware_bluetooth_audio_hfp_setting.h"

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
                    namespace hfp {
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

                            std::optional<HfpOffloadSetting> readHfpOffloadSetting(const char* configFile) {
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

                                if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("hfpOffloadSetting"))) {
                                    HfpOffloadSetting _value = HfpOffloadSetting::read(_child);
                                    return _value;
                                }
                                return std::nullopt;
                            }

                            std::optional<HfpOffloadSetting> parseHfpOffloadSetting(const char* xml) {
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

                                if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("hfpOffloadSetting"))) {
                                    HfpOffloadSetting _value = HfpOffloadSetting::read(_child);
                                    return _value;
                                }
                                return std::nullopt;
                            }


                            HfpOffloadSetting::HfpOffloadSetting(std::vector<PathConfiguration> pathConfiguration, std::vector<TransportConfiguration> transportConfiguration, std::vector<Configuration> configuration) : pathConfiguration_(std::move(pathConfiguration)), transportConfiguration_(std::move(transportConfiguration)), configuration_(std::move(configuration)) {
                            }

                            const std::vector<PathConfiguration>& HfpOffloadSetting::getPathConfiguration() const {
                                return pathConfiguration_;
                            }

                            bool HfpOffloadSetting::hasPathConfiguration() const {
                                return !(pathConfiguration_.empty());
                            }

                            const PathConfiguration* HfpOffloadSetting::getFirstPathConfiguration() const {
                                if (pathConfiguration_.empty()) {
                                    return nullptr;
                                }
                                return &pathConfiguration_[0];
                            }

                            const std::vector<TransportConfiguration>& HfpOffloadSetting::getTransportConfiguration() const {
                                return transportConfiguration_;
                            }

                            bool HfpOffloadSetting::hasTransportConfiguration() const {
                                return !(transportConfiguration_.empty());
                            }

                            const TransportConfiguration* HfpOffloadSetting::getFirstTransportConfiguration() const {
                                if (transportConfiguration_.empty()) {
                                    return nullptr;
                                }
                                return &transportConfiguration_[0];
                            }

                            const std::vector<Configuration>& HfpOffloadSetting::getConfiguration() const {
                                return configuration_;
                            }

                            bool HfpOffloadSetting::hasConfiguration() const {
                                return !(configuration_.empty());
                            }

                            const Configuration* HfpOffloadSetting::getFirstConfiguration() const {
                                if (configuration_.empty()) {
                                    return nullptr;
                                }
                                return &configuration_[0];
                            }

                            HfpOffloadSetting HfpOffloadSetting::read(xmlNode *root) {
                                std::string _raw;
                                std::vector<PathConfiguration> pathConfiguration;
                                std::vector<TransportConfiguration> transportConfiguration;
                                std::vector<Configuration> configuration;
                                for (auto *_child = root->xmlChildrenNode; _child != nullptr; _child = _child->next) {
                                    if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("pathConfiguration"))) {
                                        PathConfiguration _value = PathConfiguration::read(_child);
                                        pathConfiguration.push_back(std::move(_value));
                                    } else if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("transportConfiguration"))) {
                                        TransportConfiguration _value = TransportConfiguration::read(_child);
                                        transportConfiguration.push_back(std::move(_value));
                                    } else if (!xmlStrcmp(_child->name, reinterpret_cast<const xmlChar*>("configuration"))) {
                                        Configuration _value = Configuration::read(_child);
                                        configuration.push_back(std::move(_value));
                                    }
                                }
                                HfpOffloadSetting instance(pathConfiguration, transportConfiguration, configuration);
                                return instance;
                            }

                            PathConfiguration::PathConfiguration(std::optional<std::string> name, std::optional<unsigned int> bandwidth, std::optional<CodecType> codec, std::optional<unsigned short> codedDataSize, std::optional<unsigned char> pcmDataFormat, std::optional<unsigned char> pcmPayloadMsbPosition, std::optional<unsigned char> dataPath, std::optional<unsigned char> transportUnitSize) : name_(std::move(name)), bandwidth_(bandwidth), codec_(codec), codedDataSize_(codedDataSize), pcmDataFormat_(pcmDataFormat), pcmPayloadMsbPosition_(pcmPayloadMsbPosition), dataPath_(dataPath), transportUnitSize_(transportUnitSize) {
                            }

                            const std::string& PathConfiguration::getName() const {
                                _xsdc_assert(hasName());
                                return name_.value();
                            }

                            bool PathConfiguration::hasName() const {
                                return name_.has_value();
                            }

                            const unsigned int& PathConfiguration::getBandwidth() const {
                                _xsdc_assert(hasBandwidth());
                                return bandwidth_.value();
                            }

                            bool PathConfiguration::hasBandwidth() const {
                                return bandwidth_.has_value();
                            }

                            const CodecType& PathConfiguration::getCodec() const {
                                _xsdc_assert(hasCodec());
                                return codec_.value();
                            }

                            bool PathConfiguration::hasCodec() const {
                                return codec_.has_value();
                            }

                            const unsigned short& PathConfiguration::getCodedDataSize() const {
                                _xsdc_assert(hasCodedDataSize());
                                return codedDataSize_.value();
                            }

                            bool PathConfiguration::hasCodedDataSize() const {
                                return codedDataSize_.has_value();
                            }

                            const unsigned char& PathConfiguration::getPcmDataFormat() const {
                                _xsdc_assert(hasPcmDataFormat());
                                return pcmDataFormat_.value();
                            }

                            bool PathConfiguration::hasPcmDataFormat() const {
                                return pcmDataFormat_.has_value();
                            }

                            const unsigned char& PathConfiguration::getPcmPayloadMsbPosition() const {
                                _xsdc_assert(hasPcmPayloadMsbPosition());
                                return pcmPayloadMsbPosition_.value();
                            }

                            bool PathConfiguration::hasPcmPayloadMsbPosition() const {
                                return pcmPayloadMsbPosition_.has_value();
                            }

                            const unsigned char& PathConfiguration::getDataPath() const {
                                _xsdc_assert(hasDataPath());
                                return dataPath_.value();
                            }

                            bool PathConfiguration::hasDataPath() const {
                                return dataPath_.has_value();
                            }

                            const unsigned char& PathConfiguration::getTransportUnitSize() const {
                                _xsdc_assert(hasTransportUnitSize());
                                return transportUnitSize_.value();
                            }

                            bool PathConfiguration::hasTransportUnitSize() const {
                                return transportUnitSize_.has_value();
                            }

                            PathConfiguration PathConfiguration::read(xmlNode *root) {
                                std::string _raw;
                                _raw = getXmlAttribute(root, "name");
                                std::optional<std::string> name = std::nullopt;
                                if (_raw != "") {
                                    std::string &_value = _raw;
                                    name = _value;
                                }
                                _raw = getXmlAttribute(root, "bandwidth");
                                std::optional<unsigned int> bandwidth = std::nullopt;
                                if (_raw != "") {
                                    unsigned int _value = static_cast<unsigned int>(stoul(_raw));
                                    bandwidth = _value;
                                }
                                _raw = getXmlAttribute(root, "codec");
                                std::optional<CodecType> codec = std::nullopt;
                                if (_raw != "") {
                                    CodecType _value = stringToCodecType(_raw);
                                    codec = _value;
                                }
                                _raw = getXmlAttribute(root, "codedDataSize");
                                std::optional<unsigned short> codedDataSize = std::nullopt;
                                if (_raw != "") {
                                    unsigned short _value = static_cast<unsigned short>(std::stoi(_raw));
                                    codedDataSize = _value;
                                }
                                _raw = getXmlAttribute(root, "pcmDataFormat");
                                std::optional<unsigned char> pcmDataFormat = std::nullopt;
                                if (_raw != "") {
                                    unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                    pcmDataFormat = _value;
                                }
                                _raw = getXmlAttribute(root, "pcmPayloadMsbPosition");
                                std::optional<unsigned char> pcmPayloadMsbPosition = std::nullopt;
                                if (_raw != "") {
                                    unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                    pcmPayloadMsbPosition = _value;
                                }
                                _raw = getXmlAttribute(root, "dataPath");
                                std::optional<unsigned char> dataPath = std::nullopt;
                                if (_raw != "") {
                                    unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                    dataPath = _value;
                                }
                                _raw = getXmlAttribute(root, "transportUnitSize");
                                std::optional<unsigned char> transportUnitSize = std::nullopt;
                                if (_raw != "") {
                                    unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                    transportUnitSize = _value;
                                }
                                PathConfiguration instance(name, bandwidth, codec, codedDataSize, pcmDataFormat, pcmPayloadMsbPosition, dataPath, transportUnitSize);
                                return instance;
                            }

                            TransportConfiguration::TransportConfiguration(std::optional<std::string> name, std::optional<unsigned int> bandwidth, std::optional<CodecType> codec, std::optional<unsigned short> codedFrameSize) : name_(std::move(name)), bandwidth_(bandwidth), codec_(codec), codedFrameSize_(codedFrameSize) {
                            }

                            const std::string& TransportConfiguration::getName() const {
                                _xsdc_assert(hasName());
                                return name_.value();
                            }

                            bool TransportConfiguration::hasName() const {
                                return name_.has_value();
                            }

                            const unsigned int& TransportConfiguration::getBandwidth() const {
                                _xsdc_assert(hasBandwidth());
                                return bandwidth_.value();
                            }

                            bool TransportConfiguration::hasBandwidth() const {
                                return bandwidth_.has_value();
                            }

                            const CodecType& TransportConfiguration::getCodec() const {
                                _xsdc_assert(hasCodec());
                                return codec_.value();
                            }

                            bool TransportConfiguration::hasCodec() const {
                                return codec_.has_value();
                            }

                            const unsigned short& TransportConfiguration::getCodedFrameSize() const {
                                _xsdc_assert(hasCodedFrameSize());
                                return codedFrameSize_.value();
                            }

                            bool TransportConfiguration::hasCodedFrameSize() const {
                                return codedFrameSize_.has_value();
                            }

                            TransportConfiguration TransportConfiguration::read(xmlNode *root) {
                                std::string _raw;
                                _raw = getXmlAttribute(root, "name");
                                std::optional<std::string> name = std::nullopt;
                                if (_raw != "") {
                                    std::string &_value = _raw;
                                    name = _value;
                                }
                                _raw = getXmlAttribute(root, "bandwidth");
                                std::optional<unsigned int> bandwidth = std::nullopt;
                                if (_raw != "") {
                                    unsigned int _value = static_cast<unsigned int>(stoul(_raw));
                                    bandwidth = _value;
                                }
                                _raw = getXmlAttribute(root, "codec");
                                std::optional<CodecType> codec = std::nullopt;
                                if (_raw != "") {
                                    CodecType _value = stringToCodecType(_raw);
                                    codec = _value;
                                }
                                _raw = getXmlAttribute(root, "codedFrameSize");
                                std::optional<unsigned short> codedFrameSize = std::nullopt;
                                if (_raw != "") {
                                    unsigned short _value = static_cast<unsigned short>(std::stoi(_raw));
                                    codedFrameSize = _value;
                                }
                                TransportConfiguration instance(name, bandwidth, codec, codedFrameSize);
                                return instance;
                            }

                            Configuration::Configuration(std::optional<std::string> name, std::optional<CodecType> codec, std::optional<unsigned short> maxLatencyMs, std::optional<unsigned short> packetTypes, std::optional<unsigned char> retransmissionEffort, std::optional<bool> useControllerCodec, std::optional<std::string> inputPathConfiguration, std::optional<std::string> outputPathConfiguration, std::optional<std::string> inputTransportConfiguration, std::optional<std::string> outputTransportConfiguration) : name_(std::move(name)), codec_(codec), maxLatencyMs_(maxLatencyMs), packetTypes_(packetTypes), retransmissionEffort_(retransmissionEffort), useControllerCodec_(useControllerCodec), inputPathConfiguration_(std::move(inputPathConfiguration)), outputPathConfiguration_(std::move(outputPathConfiguration)), inputTransportConfiguration_(std::move(inputTransportConfiguration)), outputTransportConfiguration_(std::move(outputTransportConfiguration)) {
                            }

                            const std::string& Configuration::getName() const {
                                _xsdc_assert(hasName());
                                return name_.value();
                            }

                            bool Configuration::hasName() const {
                                return name_.has_value();
                            }

                            const CodecType& Configuration::getCodec() const {
                                _xsdc_assert(hasCodec());
                                return codec_.value();
                            }

                            bool Configuration::hasCodec() const {
                                return codec_.has_value();
                            }

                            const unsigned short& Configuration::getMaxLatencyMs() const {
                                _xsdc_assert(hasMaxLatencyMs());
                                return maxLatencyMs_.value();
                            }

                            bool Configuration::hasMaxLatencyMs() const {
                                return maxLatencyMs_.has_value();
                            }

                            const unsigned short& Configuration::getPacketTypes() const {
                                _xsdc_assert(hasPacketTypes());
                                return packetTypes_.value();
                            }

                            bool Configuration::hasPacketTypes() const {
                                return packetTypes_.has_value();
                            }

                            const unsigned char& Configuration::getRetransmissionEffort() const {
                                _xsdc_assert(hasRetransmissionEffort());
                                return retransmissionEffort_.value();
                            }

                            bool Configuration::hasRetransmissionEffort() const {
                                return retransmissionEffort_.has_value();
                            }

                            const bool& Configuration::getUseControllerCodec() const {
                                _xsdc_assert(hasUseControllerCodec());
                                return useControllerCodec_.value();
                            }

                            bool Configuration::hasUseControllerCodec() const {
                                return useControllerCodec_.has_value();
                            }

                            const std::string& Configuration::getInputPathConfiguration() const {
                                _xsdc_assert(hasInputPathConfiguration());
                                return inputPathConfiguration_.value();
                            }

                            bool Configuration::hasInputPathConfiguration() const {
                                return inputPathConfiguration_.has_value();
                            }

                            const std::string& Configuration::getOutputPathConfiguration() const {
                                _xsdc_assert(hasOutputPathConfiguration());
                                return outputPathConfiguration_.value();
                            }

                            bool Configuration::hasOutputPathConfiguration() const {
                                return outputPathConfiguration_.has_value();
                            }

                            const std::string& Configuration::getInputTransportConfiguration() const {
                                _xsdc_assert(hasInputTransportConfiguration());
                                return inputTransportConfiguration_.value();
                            }

                            bool Configuration::hasInputTransportConfiguration() const {
                                return inputTransportConfiguration_.has_value();
                            }

                            const std::string& Configuration::getOutputTransportConfiguration() const {
                                _xsdc_assert(hasOutputTransportConfiguration());
                                return outputTransportConfiguration_.value();
                            }

                            bool Configuration::hasOutputTransportConfiguration() const {
                                return outputTransportConfiguration_.has_value();
                            }

                            Configuration Configuration::read(xmlNode *root) {
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
                                _raw = getXmlAttribute(root, "maxLatencyMs");
                                std::optional<unsigned short> maxLatencyMs = std::nullopt;
                                if (_raw != "") {
                                    unsigned short _value = static_cast<unsigned short>(std::stoi(_raw));
                                    maxLatencyMs = _value;
                                }
                                _raw = getXmlAttribute(root, "packetTypes");
                                std::optional<unsigned short> packetTypes = std::nullopt;
                                if (_raw != "") {
                                    unsigned short _value = static_cast<unsigned short>(std::stoi(_raw));
                                    packetTypes = _value;
                                }
                                _raw = getXmlAttribute(root, "retransmissionEffort");
                                std::optional<unsigned char> retransmissionEffort = std::nullopt;
                                if (_raw != "") {
                                    unsigned char _value = static_cast<unsigned char>(std::stoi(_raw));
                                    retransmissionEffort = _value;
                                }
                                _raw = getXmlAttribute(root, "useControllerCodec");
                                std::optional<bool> useControllerCodec = std::nullopt;
                                if (_raw != "") {
                                    bool _value = _raw == "true";
                                    useControllerCodec = _value;
                                }
                                _raw = getXmlAttribute(root, "inputPathConfiguration");
                                std::optional<std::string> inputPathConfiguration = std::nullopt;
                                if (_raw != "") {
                                    std::string &_value = _raw;
                                    inputPathConfiguration = _value;
                                }
                                _raw = getXmlAttribute(root, "outputPathConfiguration");
                                std::optional<std::string> outputPathConfiguration = std::nullopt;
                                if (_raw != "") {
                                    std::string &_value = _raw;
                                    outputPathConfiguration = _value;
                                }
                                _raw = getXmlAttribute(root, "inputTransportConfiguration");
                                std::optional<std::string> inputTransportConfiguration = std::nullopt;
                                if (_raw != "") {
                                    std::string &_value = _raw;
                                    inputTransportConfiguration = _value;
                                }
                                _raw = getXmlAttribute(root, "outputTransportConfiguration");
                                std::optional<std::string> outputTransportConfiguration = std::nullopt;
                                if (_raw != "") {
                                    std::string &_value = _raw;
                                    outputTransportConfiguration = _value;
                                }
                                Configuration instance(name, codec, maxLatencyMs, packetTypes, retransmissionEffort, useControllerCodec, inputPathConfiguration, outputPathConfiguration, inputTransportConfiguration, outputTransportConfiguration);
                                return instance;
                            }
                        } // setting
                    } // hfp
                } // audio
            } // bluetooth
        } // hardware
    } // android
} // aidl
