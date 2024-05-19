#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <string>
#include "Level.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <sstream>

class FileHandler{
    bool checkFiles();
public:
    Level loadLevel(int levelNumber,bool restart);
    void saveLevel(std::vector<std::string> boardToSave);
};

#endif // FILEREADER_H
