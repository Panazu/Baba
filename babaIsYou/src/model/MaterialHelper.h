
#ifndef DEV4CODE_MATERIALHELPER_H
#define DEV4CODE_MATERIALHELPER_H

#include <map>
#include <algorithm>
#include <stdexcept>
#include "Materials.h"

class MaterialHelper {
public:
    static materials getMaterialName(const std::string& materialName);
    static std::string getMaterialString(materials material);

private:
    static const std::map<std::string, materials>& getMaterialMap();
};

#endif //DEV4CODE_MATERIALHELPER_H
