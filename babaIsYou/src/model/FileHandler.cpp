#include "FileHandler.h"

/**
 * @class FileHandler
 * @brief A class that handles file operations for loading and saving levels.
 *
 * This class provides methods to load and save level data to and from files.
 */


Level FileHandler::loadLevel(int levelNumber, bool restart){
    Level lvl = Level();
    std::vector<std::string> levelElements;
    std::string line;
    std::string levelfile;
    if (restart){
        if(checkFiles()){
            levelfile = "../../babaIsYou/src/resources/level/savedLevel.txt";
        }else{
            levelfile = "../../babaIsYou/src/resources/level/level_";
            levelfile += std::to_string(0)+= ".txt";
            levelElements.push_back(std::to_string(levelNumber));
        }
    }else{
        levelfile = "../../babaIsYou/src/resources/level/level_";
        levelfile += std::to_string(levelNumber)+= ".txt";
        levelElements.push_back(std::to_string(levelNumber));
    }

    std::ifstream myfile (levelfile);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            levelElements.push_back(line);
        }
        myfile.close();
    }
    else {

        throw("files not found") ;
    }

    lvl.loadLevel(levelElements);
    return lvl;
}
/**
     * @brief Loads a level from a file and returns a Level object.
     *
     * This method takes a level number and a boolean flag (restart) as input
     * parameters. If restart is true, it attempts to load a saved level;
     * otherwise, it loads a level based on the given level number.
     *
     * @param levelNumber The level number to be loaded.
     * @param restart A flag indicating whether to load a saved level (true) or not (false).
     * @return A Level object containing the loaded level data.
     */

void FileHandler::saveLevel(std::vector<std::string> boardToSave) {
    std::string path =  "../../babaIsYou/src/resources/level/savedLevel.txt";
    std::ofstream outputFile(path);

    if (outputFile.is_open()) {
        for (const auto &line : boardToSave) {
            outputFile << line << std::endl;
        }
        outputFile.close();
    } else {
        throw("Unable to open file for writing: " + path);
    }
}

/**
     * @brief Saves the current level to a file.
     *
     * This method takes a vector of strings representing the level data and
     * saves it to a file named "savedLevel.txt" in the resources/level directory.
     *
     * @param boardToSave A vector of strings containing the level data to be saved.
     */
bool FileHandler::checkFiles(){
    std::string directoryPath =  "../../babaIsYou/src/resources/level/";
    std::regex targetPattern("^savedLevel\\.txt$");
    bool fileFound = false;

    try {
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            std::string fileName = entry.path().filename().string();
            std::smatch matches;
            if (entry.is_regular_file() && std::regex_search(fileName, matches, targetPattern)) {
                fileFound = true;
                break;
            }
        }
    } catch (const std::filesystem::filesystem_error& e) {
        throw("files not found") ;

    }

    return fileFound;

}
