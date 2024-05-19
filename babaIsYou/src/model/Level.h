#ifndef LEVEL_H
#define LEVEL_H
#include <vector>
#include "Element.h"
#include <string>
#include <cstring>
#include <map>
#include "MaterialHelper.h"

class Level{
    std::vector<std::vector<std::vector<Element>>> elems;
    int height;
    int length;
    int nbLevel;
    
public:
    void loadLevel(std::vector<std::string>);
    std::vector<std::vector<std::vector<Element>>>& getBoard();
    Level();
    int getLength();
    int getHeight();
    int getNbLevel();
};

#endif // LEVEL_H
