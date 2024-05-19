#include "RulesManager.h"

/**
 * @class RulesManager
 * @brief A class responsible for managing the game rules and properties of materials.
 * It create for each a bitset of size 6 properties, that represent all 6 different rules applicable
 * If the rules is active, properties in the bitset is 1 and otherwise 0
 * This class manages the game rules, handles the properties of materials, and provides
 * methods for applying rules, resetting properties
 *
 */

RulesManager::RulesManager() {
    for (size_t i = 0; i < static_cast<size_t>(materials::TEXT_LAVA) + 1; ++i) {
        materials material = static_cast<materials>(i);
        materialProperties[material] = std::bitset<(size_t) Properties::COUNT>();

        std::string materialName = MaterialHelper::getMaterialString(material);

        if (materialName.find("BABA") == 0) {
            materialProperties[material][static_cast<size_t>(Properties::YOU)] = true;
        }

        if (materialName.find("TEXT_") == 0 ||
                materialName.find("YOU") == 0 ||
                materialName.find("PUSH") == 0 ||
                materialName.find("SINK") == 0 ||
                materialName.find("KILL") == 0 ||
                materialName.find("STOP") == 0 ||
                materialName.find("WIN") == 0 ||
                materialName.find("IS") == 0) {
            materialProperties[material][static_cast<size_t>(Properties::PUSH)] = true;
        }


    }
}


Properties RulesManager::getMaterialProperties(materials material) {
    switch (material) {
    case materials::PUSH:
        return Properties::PUSH;
    case materials::STOP:
        return Properties::STOP;
    case materials::YOU:
        return Properties::YOU;
    case materials::WIN:
        return Properties::WIN;
    case materials::KILL:
        return Properties::KILL;
    case materials::SINK:
        return Properties::SINK;
    default:
        return Properties::COUNT;
    }
}



/**
 * @brief Resets material properties to their default values
 * (meaning all textRules and effect materials are movable)
 */
void RulesManager::resetMaterialProperties() {
    for (auto &entry: materialProperties) {
        materials material = entry.first;
        entry.second.reset();

        std::string materialName = MaterialHelper::getMaterialString(material);

        if (materialName.find("TEXT_") == 0 ||
                materialName.find("YOU") == 0 ||
                materialName.find("PUSH") == 0 ||
                materialName.find("SINK") == 0 ||
                materialName.find("KILL") == 0 ||
                materialName.find("STOP") == 0 ||
                materialName.find("WIN") == 0 ||
                materialName.find("IS") == 0) {
            materialProperties[material][static_cast<size_t>(Properties::PUSH)] = true;
        }
    }
}

/**
  * @brief Applies a rule by associating a property with a material.
  * @param textMaterial The materials enumeration value of the text material.
  * @param propertyAsMaterial The materials enumeration value of the property.
  */

void RulesManager::applyRules(materials textMaterial, materials propertyAsMaterial) {
    Properties property = getMaterialProperties(propertyAsMaterial);
    std::string textMaterialName = MaterialHelper::getMaterialString(textMaterial);
    std::string materialName = textMaterialName.substr(5);
    materials material = MaterialHelper::getMaterialName(materialName);
    materialProperties[material][static_cast<size_t>(property)] = true;
}


/**
 * @brief Checks if a material has a specific property.
 * This way, we know if a rules is enabled
 * @param material The materials enumeration value.
 * @param property The Properties enumeration value.
 * @return True if the material has the given property, false otherwise.
 */
bool RulesManager::hasProperty(materials material, Properties property) const {
    return materialProperties.at(material).test((size_t) property);
}



bool RulesManager::isMaterialEffect(Element element) const {
    auto material = element.getType();
    switch (material) {
    case materials::STOP:
    case materials::PUSH:
    case materials::YOU:
    case materials::WIN:
    case materials::SINK:
    case materials::KILL:
        return true;
    default:
        return false;
    }
}

bool RulesManager::isTextMaterial(Element element) const {
    auto material = element.getType();
    switch (material) {
    case materials::TEXT_WALL:
    case materials::TEXT_BABA:
    case materials::TEXT_FLAG:
    case materials::TEXT_ROCK:
    case materials::TEXT_WATER:
    case materials::TEXT_LAVA:
    case materials::TEXT_GRASS:
    case materials::TEXT_METAL:
        return true;
    default:
        return false;
    }

}

