#include "Level.h"

Level::Level(){
}
std::vector<std::vector<std::vector<Element>>>&  Level::getBoard(){
    return elems;
}
int Level::getHeight(){
    return height;
}
int Level::getLength(){
    return length;
}
int Level::getNbLevel(){
    return nbLevel;
}

/**
   * @brief Loads a level from a vector of strings.
   *
   * This method takes a vector of strings as input and processes it to load
   * the level data into the Level object. The input vector should contain
   * level information in the following format: type, x, y, direction.
   * Each element is separated by a space.
   *
   * @param tab A vector of strings containing the level data.
   */

void Level::loadLevel(std::vector<std::string> levelData) {
    nbLevel = std::stoi(levelData.at(0));
    levelData.erase(levelData.begin());

    // Iterate through each element string in levelData
    for (int i = 0; i < levelData.size(); ++i) {
        std::string elementString = levelData.at(i); // Store the element string in an intermediate container
        std::vector<std::string> elementAttributes;
        size_t pos = 0;
        std::string attribute;

        // Parse each character in the element string
        while (pos < elementString.size()) {
            if (elementString.at(pos) == ' ') { // If a space is encountered, add the attribute to the vector and clear the attribute string
                elementAttributes.push_back(attribute);
                attribute = "";
            } else { // Otherwise, append the current character to the attribute string
                attribute += elementString.at(pos);
            }
            ++pos; // Move to the next character
        }
        elementAttributes.push_back(attribute);

        if (elementAttributes.size() == 2) {
            height = std::stoi(elementAttributes.at(0));
            length = std::stoi(elementAttributes.at(1));
            elems.resize(std::stoi(elementAttributes.at(0)));

            for (auto &row : elems) {
                row.resize(std::stoi(elementAttributes.at(1)), std::vector<Element>());
            }
        } else if (elementAttributes.size() > 2 && elementAttributes.size() < 5) {
            int x = std::stoi(elementAttributes.at(1));
            int y = std::stoi(elementAttributes.at(2));

            if (elementAttributes.size() == 4) {
                elems.at(x).at(y).push_back(Element(x, y, MaterialHelper::getMaterialName(elementAttributes.at(0)), direction(std::stoi(elementAttributes.at(3)))));
            } else if (elementAttributes.size() == 3) {
                elems.at(x).at(y).push_back(Element(x, y, MaterialHelper::getMaterialName(elementAttributes.at(0))));
            }
        }
    }
}






