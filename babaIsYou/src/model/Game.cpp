#include "Game.h"

Game::Game() :fileHandler(FileHandler()),board(level.getBoard()){
}

void Game::start(int startingLevel, bool restart) {

    // Load the level depending on whether it's a restart or not
    if (restart) {
        level = fileHandler.loadLevel(startingLevel, true);
    } else {
        level = fileHandler.loadLevel(startingLevel, false);
    }

    // Initialize game state variables
    levelNumber = level.getNbLevel();
    won = false;
    dead = false;

    // Initialize the RulesManager
    rules = RulesManager();

    // Set the game board
    board = level.getBoard();

    // Notify observers of changes
    notifyObserver(board,oldBoard);
}




bool Game::isWon(){
    return won;
}
bool Game::isDead(){
    return dead;
}

int Game::getLevelNumber() {
    return levelNumber;
}
void Game::incrementLevel(){
    levelNumber++;
}

bool Game::isValidMove(Element el, direction dir) {
    int deltaX = 0;
    int deltaY = 0;
    setDelta(deltaX, deltaY, dir); // Sets the change in X and Y based on the direction

    int newPosX = el.getPos().getX() + deltaX; // Calculate the new X position
    int newPosY = el.getPos().getY() + deltaY; // Calculate the new Y position
    auto elementsAtNewPos = getBoardCopy().at(newPosX).at(newPosY); // Get the elements at the new position

    // Check if the new position is within the bounds of the game elements matrix
    if (!(newPosY < getBoardCopy().size() && newPosX < getBoardCopy().at(0).size())) {
        return false;
    }

    // Check if the new position contains an element in the list of stopping properties
    if (isInsideVec(Properties::STOP, elementsAtNewPos)) {
        return false;
    }

    // If the code reaches this point, the move is considered valid
    return true;
}

std::vector<std::vector<std::vector<Element>>> Game::getBoardCopy(){
    return level.getBoard();
}


// This method saves the current game level to a file, including level number, board dimensions, and element details
void Game::saveLevel() {
    std::vector<std::string> savedBoard;

    // Save the level number
    savedBoard.push_back(std::to_string(levelNumber));

    // Save the board dimensions
    int width = board.size();
    int height = board.at(0).size();
    savedBoard.push_back(std::to_string(width) + " " + std::to_string(height));

    // Iterate through the rows of the board
    for (int row = 0; row < board.size(); row++) {

        // Iterate through the columns of the board
        for (int col = 0; col < board.at(row).size(); col++) {
            std::vector<Element> actColElems = board.at(row).at(col);
            // Iterate through the elements in each cell
            for (int elemIndex = 0; elemIndex < actColElems.size(); ++elemIndex) {
                Element *currentElement = &actColElems.at(elemIndex);
                std::string elementData;

                // Check if the current element is not nullptr
                if (currentElement != nullptr) {
                    std::string elementType = MaterialHelper::getMaterialString(currentElement->getType());
                    elementData += elementType + " ";
                    elementData += currentElement->getPos().to_string();
                    savedBoard.push_back(elementData);
                }

                // Add the element data to the saved board

            }
        }
    }
    // Save the level data to a file using the fileHandler
    fileHandler.saveLevel(savedBoard);
}


void Game::checkRules() {
    rules.resetMaterialProperties();

    // Iterate through the rows of the board
    for (int row = 0; row < board.size(); row++) {

        // Iterate through the columns of the board
        for (int col = 0; col < board.at(row).size(); col++) {
            std::vector<Element> actColElems = board.at(row).at(col);
            // Iterate through the elements in each cell
            for (int elemIndex = 0; elemIndex < actColElems.size(); ++elemIndex) {
                Element currentElement = actColElems.at(elemIndex);

                // Check horizontal and vertical rules if the current element is of type "IS"
                if (currentElement.getType() == materials::IS) {
                    checkHorizontalRules(row, col);
                    checkVerticalRules(row, col);
                }
            }
        }
    }
}

void Game::checkHorizontalRules(int posX, int posY) {
    const int colLeft = posX - 1;
    const int colRight = posX + 1;

    // Check if the column to the left is out of bounds or empty
    if (colLeft < 0 || board.at(colLeft).at(posY).empty()) {
        return;
    }

    // Check if the element in the column to the left is text material
    if (!rules.isTextMaterial(board.at(colLeft).at(posY).back())) {
        return;
    }

    // Check if the column to the right is out of bounds or empty
    if (colRight >= board[posX].size() || board.at(colRight).at(posY).empty()) {
        return;
    }

    // Check if the element in the column to the right has a material effect
    if (!rules.isMaterialEffect(board.at(colRight).at(posY).back())) {
        return;
    }

    // Apply the rules using the element types in the columns to the left and right
    rules.applyRules(board.at(colLeft).at(posY).back().getType(), board.at(colRight).at(posY).back().getType());
}


void Game::checkVerticalRules(int posX, int posY) {
    const int rowAbove = posY - 1;
    const int rowBelow = posY + 1;

    // Check if the row above is out of bounds or empty
    if (rowAbove < 0 || board.at(posX).at(rowAbove).empty()) {
        return;
    }

    // Check if the element in the row above is text material
    if (!rules.isTextMaterial(board.at(posX).at(rowAbove).back())) {
        return;
    }

    // Check if the row below is out of bounds or empty
    if (rowBelow >= board[posY].size() || board.at(posX).at(rowBelow).empty()) {
        return;
    }

    // Check if the element in the row below has a material effect
    if (!rules.isMaterialEffect(board.at(posX).at(rowBelow).back())) {
        return;
    }

    // Apply the rules using the element types in the row above and below
    rules.applyRules(board.at(posX).at(rowAbove).back().getType(), board.at(posX).at(rowBelow).back().getType());
}


void Game::setDelta(int & deltaX, int & deltaY, direction dir) {
    // Adjust the change in X and Y (deltaX and deltaY) based on the given direction
    switch (dir) {
    case TOP:
        deltaY--; // Move one position up
        break;
    case BOTTOM:
        deltaY++; // Move one position down
        break;
    case RIGHT:
        deltaX++; // Move one position to the right
        break;
    case LEFT:
        deltaX--; // Move one position to the left
        break;
    }
}



bool Game::isInside(Properties property , materials mat){
    return rules.hasProperty(mat,property);
}
bool Game::isInsideVec(Properties property , std::vector<Element> mat){
    for(auto el : mat){
        if(isInside(property,el.getType())){
            return true;
        }
    }
    return false;
}

// We work with a copy of the board instead of a reference when we make a move.
//This prevents our move methods to move again the same element more than needed.
void Game::move(direction dir) {
    setOldBoard();
    checkRules();
    int deltaX = 0;
    int deltaY = 0;
    std::vector<std::vector<std::vector<Element>>> boardCopy = getBoardCopy();
    setDelta(deltaX, deltaY, dir);

    // Iterate through the board
    int nbRow = boardCopy.size();
    for (int row = 0; row < nbRow; row++) {
        int nbCol = boardCopy.at(row).size();
        for (int col = 0; col < nbCol; col++) {
            int nbLayers = boardCopy.at(row).at(col).size();
            int countKilledElement = 0;
            for (int layer = 0; layer < nbLayers; ++layer) {
                Element activeElem = boardCopy.at(row).at(col).at(layer);
                if (isInside(Properties::YOU, activeElem.getType())) {
                    prepareMove(activeElem, deltaX, deltaY, boardCopy, row, col, layer, dir,countKilledElement);
                }
            }
        }
    }
    if(isWon()){
        if(levelNumber < 4){
            start(levelNumber+1,false);
        }else{
            start(0,false);
        }
    }else if(isDead()){
        start(levelNumber,false);
        setOldBoard();
    }
    notifyObserver(board,oldBoard);
}

// We work with a copy of the board instead of a reference when we make a move.
//This prevents our move methods to move again the same element more than needed.
void Game::prepareMove(Element activeElem, int deltaX, int deltaY,const std::vector<std::vector<std::vector<Element>>>& board, int row, int col, int layer, direction dir,int& countKilledElement) {
    // Check if movement is within the board
    int newPosY = activeElem.getPos().getY() + deltaY;
    int newPosX = activeElem.getPos().getX() + deltaX;
    if (newPosY < board.size() && newPosX < board.at(row).size()) {
        // Check if the move is valid
        if (isValidMove(activeElem, dir)) {
            // Check if the target cell contains an object to be pushed
            std::vector<Element> targetCase = board.at(row + deltaX).at(col + deltaY);
            if (isInsideVec(Properties::PUSH, targetCase)) {
                // Push the object two cells away in the given direction
                Position nextToPushPos = Position(row + (deltaX * 2), col + (deltaY * 2));
                if (pushMove(targetCase, nextToPushPos, deltaX, deltaY, board, dir)) {
                    moveObj(activeElem, Position(newPosX, newPosY), layer);
                }
            } else {
                moveObj(activeElem, Position(newPosX,newPosY), layer);
            }

            // Check if the target cell contains an object that drowns or kills the player
            if (isInsideVec(Properties::SINK, targetCase) || isInsideVec(Properties::KILL, targetCase)) {
                if(countKilledElement < 1){
                    deleteObject(activeElem,Position(newPosX , newPosY));
                    countKilledElement++;
                }
            } else if (isInsideVec(Properties::WIN, targetCase)) {
                won = true;
            }
        } else {
            // Movement within the board, but invalid (e.g., blocked by a wall)
        }
    } else {
        // Movement outside the board
    }
    checkDeath();
}

// We work with a copy of the board instead of a reference when we make a move.
//This prevents our move methods to move again the same element more than needed.
bool Game::pushMove(std::vector<Element> elements, Position destination, int deltaX, int deltaY, const std::vector<std::vector<std::vector<Element>>>& board, direction dir) {
    // Check if movement is within the board
    bool isInYBound = (destination.getY() < board.size());
    bool isInXBound = (destination.getX() < board.at(0).size());
    if (isInYBound && isInXBound) {
        std::vector<Element> destElemCase = board[destination.getX()][destination.getY()];
        if (!isInsideVec(Properties::STOP, destElemCase)) {
            for (int index = 0; index < elements.size(); index++) {
                if (isInside(Properties::PUSH, elements.at(index).getType())) {
                    if (isValidMove(elements.at(index), dir)) {
                        bool isText = (rules.isTextMaterial(elements.at(index)) || rules.isMaterialEffect(elements.at(index)) || elements.at(index).getType() == materials::IS);
                        if (isInsideVec(Properties::PUSH, destElemCase)) {
                            Position nextToDestPos(destination.getX() + deltaX, destination.getY() + deltaY);
                            if (pushMove(destElemCase, nextToDestPos, deltaX, deltaY, board, dir)) {
                                moveObj(elements.at(index), destination, index);
                                return true;
                            } else {
                                return false;
                            }
                        } else if (isInsideVec(Properties::SINK, destElemCase) && !isText) {
                            moveObj(elements.at(index), destination, index);
                            level.getBoard()[destination.getX()][destination.getY()].clear(); // Remove the water
                            return true;
                        } else {
                            moveObj(elements.at(index), destination, index);
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void Game::moveObj(Element element, Position destination, int index) {
    std::vector<Element>& elementCase = level.getBoard().at(element.getPos().getX()).at(element.getPos().getY());
    // Swap the element with the last element in the vector and remove the last element
    std::swap(elementCase[index], elementCase.back());
    elementCase.pop_back();

    // Update the element's position
    element.setPos(Position(destination.getX(), destination.getY()));

    std::vector<Element>& destCase = level.getBoard().at(destination.getX()).at(destination.getY());
    // Place the element at its new position
    destCase.push_back(element);
}
void Game::checkDeath(){
    std::vector<std::vector<std::vector<Element>>>& board = level.getBoard();
    int countYouElements = 0;
    for(int i = 0 ; i < board.size() ; i++){
        for(int j = 0 ; j < board.at(i).size();j++){
            for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                if(isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                    countYouElements++;
                }
            }
        }
    }
    if(countYouElements < 1){
        dead = true;
    }
}
void Game::deleteObject(Element element,Position destination){
    level.getBoard().at(destination.getX()).at(destination.getY()).pop_back();
}
std::vector<std::vector<std::vector<Element>>>& Game::getOldBoard(){
    return oldBoard;
}
void Game::setOldBoard(){
    oldBoard = board;
}
