/**
 * @class MaterialHelper
 * @brief A utility class that provides helper methods for handling materials.
 *
 * This class provides static methods for converting between material names
 * (strings) and their corresponding enumeration values, as well as accessing
 * a map of material names and their enumeration values.
 */
#include "MaterialHelper.h"

/**
  * @brief Retrieves a constant map of material names (strings) and their corresponding enumeration values.
  *
  * @return A constant reference to a map of material names and their corresponding enumeration values.
  */
const std::map<std::string, materials>& MaterialHelper::getMaterialMap() {
    static const std::map<std::string, materials> materialMap = {
        {"ROCK", materials::ROCK},
        {"WALL", materials::WALL},
        {"FLAG", materials::FLAG},
        {"METAL", materials::METAL},
        {"BABA", materials::BABA},
        {"GRASS", materials::GRASS},
        {"WATER", materials::WATER},
        {"LAVA", materials::LAVA},
        {"SKULL", materials::SKULL},
        {"STOP", materials::STOP},
        {"PUSH", materials::PUSH},
        {"YOU", materials::YOU},
        {"WIN", materials::WIN},
        {"SINK", materials::SINK},
        {"KILL", materials::KILL},
        {"IS", materials::IS},
        {"TEXT_BEST", materials::TEXT_BEST},
        {"TEXT_WALL", materials::TEXT_WALL},
        {"TEXT_ROCK", materials::TEXT_ROCK},
        {"TEXT_FLAG", materials::TEXT_FLAG},
        {"TEXT_METAL", materials::TEXT_METAL},
        {"TEXT_BABA", materials::TEXT_BABA},
        {"TEXT_GRASS", materials::TEXT_GRASS},
        {"TEXT_WATER", materials::TEXT_WATER},
        {"TEXT_LAVA", materials::TEXT_LAVA},
    };
    return materialMap;
}


/**
 * @brief Converts a material name (string) to its corresponding enumeration value.
 *
 * This method takes a material name as input and returns the corresponding
 * enumeration value. The input string is case-insensitive.
 *
 * @param materialName A string representing the name of a material.
 * @return The corresponding enumeration value for the given material name.
 * @throws std::invalid_argument if the input material name is not valid.
 */

materials MaterialHelper::getMaterialName(const std::string& materialName) {
    std::string upperMaterialName = materialName;
    std::transform(upperMaterialName.begin(), upperMaterialName.end(), upperMaterialName.begin(), ::toupper);

    const auto& materialMap = getMaterialMap();
    auto it = materialMap.find(upperMaterialName);
    if (it != materialMap.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Invalid material name");
    }
}


/**
 * @brief Converts a material enumeration value to its corresponding name (string).
 *
 * This method takes a material enumeration value as input and returns the
 * corresponding material name (string).
 *
 * @param material A materials enumeration value.
 * @return A string representing the name of the given material.
 * @throws std::invalid_argument if the input material enumeration value is not valid.
 */
std::string MaterialHelper::getMaterialString (materials material) {
    const auto& materialMap = getMaterialMap();
    auto it = std::find_if(materialMap.begin(), materialMap.end(),
                           [&](const std::pair<std::string, materials>& pair) {
        return pair.second == material;
    });

    if (it != materialMap.end()) {
        return it->first;
    } else {
        throw std::invalid_argument("Invalid material");
    }
}
