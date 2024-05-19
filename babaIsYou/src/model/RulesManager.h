#ifndef RULESMANAGER_H
#define RULESMANAGER_H
#include <bitset>
#include <unordered_map>
#include "Element.h"
#include "MaterialHelper.h"

enum class Properties {
    PUSH,
    STOP,
    YOU,
    WIN,
    KILL,
    SINK,
    COUNT


};
class RulesManager {
    std::unordered_map<materials, std::bitset<(size_t) Properties::COUNT>> materialProperties;
public:
    RulesManager();
    Properties getMaterialProperties(materials material);
    void resetMaterialProperties();
    void applyRules(materials textMaterial, materials propertyAsMaterial);
    bool hasProperty(materials material, Properties property) const;
    bool isMaterialEffect(Element element) const;
    bool isTextMaterial(Element element) const;
};


#endif // RULESMANAGER_H
