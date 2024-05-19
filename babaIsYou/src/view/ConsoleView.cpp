#include "ConsoleView.h"

void ConsoleView::displayBoard(std::vector<std::vector<std::vector<Element>>> board) {
    int width = board.size();
    int height = board.at(0).size();

    // Iterate through rows of the board
    for (int row = 0; row < height; row++) {

        // Iterate through columns of the board
        for (int col = 0; col < width; col++) {

            // If the current cell is not empty, print the top element's type
            if (!board[col][row].empty()) {
                std::cout << materialsToString(board[col][row].back().getType()) << " ";
            } else {
                // If the current cell is empty, print a placeholder character
                std::cout << ". ";
            }
        }
        // Add a newline character to separate rows
        std::cout << std::endl;
    }
}


char ConsoleView::materialsToString(materials material)
{
    switch (material)
    {
    case materials::BABA: return 'b';break;
    case materials::YOU: return 'Y';break;
    case materials::ROCK: return 'r';break;
    case materials::WALL: return '#';break;
    case materials::FLAG: return 'f';break;
    case materials::GRASS: return 'g';break;
    case materials::IS: return 'i';break;
    case materials::METAL: return '*';break;
    case materials::STOP: return 'S';break;
    case materials::SINK: return '5';break;
    case materials::PUSH: return 'P';break;
    case materials::WATER: return '~';break;
    case materials::LAVA: return '0';break;
    case materials::SKULL:return '@';break;
    case materials::WIN:return 'W';break;
    case materials::KILL:return 'K';break;
    case materials::TEXT_WALL: return 'M';break;
    case materials::TEXT_ROCK: return 'R';break;
    case materials::TEXT_FLAG: return 'F';break;
    case materials::TEXT_BABA: return 'B';break;
    case materials::TEXT_GRASS: return 'G';break;
    case materials::TEXT_WATER: return 'W';break;
    case materials::TEXT_METAL: return 'm';break;
    case materials::TEXT_LAVA:  return 'L';break;
    };
    return '1';
}
direction ConsoleView::askMovement(){
    std::string move;
    std::cout<<"Quel Mouvement souhaitez vous faire ? (z,q,s,d) ou 1 pour sauvegarder la partie, ou 0 pour recommencer "<<std::endl;
    std::cin >> move;
    if(move == "z"){
        return direction::TOP;
    }else if(move == "q"){
        return direction::LEFT;
    }else if(move == "s"){
        return direction::BOTTOM;
    }else if(move == "d") {
        return direction::RIGHT;
    }else if(move=="1"){
        this->save = true;
        return direction::RIGHT;
    }else if(move=="0"){
        this->restarted = true;
        return direction::RIGHT;
    }else{
        std::cout<<"entree invalide !"<<std::endl;
        return askMovement();
    }
}
void ConsoleView::displayWin(){
    std::cout<<"Vous avez Gagne !"<<std::endl;
}
void ConsoleView::displayLose(){
    std::cout<<"Vous avez perdu !"<<std::endl;
}
int ConsoleView::askLevel(){
    std::cout<<"Quel niveau voulez vous lancer ? (0,1,2,3,4,s) (s = partie sauvegardee)"<<std::endl;
    std::string answ;
    std::cin>>answ;
    if(answ=="0"){
        return 0;
    }else if(answ=="1"){
        return 1;
    }else if(answ=="2"){
        return 2;
    }else if(answ=="3"){
        return 3;
    }else if(answ=="4"){
        return 4;
    }else if(answ=="s"){
        return -1;
    }else{
        std::cout<<"entrée erronee , refaites !"<<std::endl;
        return askLevel();
    }
}
bool ConsoleView::getSaveGame() {
    return save;
}
bool ConsoleView::getRestarted(){
    return restarted;
}
void ConsoleView::initRestarted(){
    restarted = false;
}


void ConsoleView::displayMessage(std::string message) {
    std::cout << message << std::endl;
}

void ConsoleView::displayLegend(){
    std::cout << "===========Legende=============="<<std::endl;
    std::cout << "BABA = 'b' " << std::endl;
    std::cout << "YOU = 'Y' " << std::endl;
    std::cout << "ROCK = 'r' " << std::endl;
    std::cout << "WALL = '#' " << std::endl;
    std::cout << "FLAG = 'f' " << std::endl;
    std::cout << "GRASS = 'g' " << std::endl;
    std::cout << "IS = 'i' " << std::endl;
    std::cout << "METAL = '*' " << std::endl;
    std::cout << "STOP = 'S' " << std::endl;
    std::cout << "SINK = '5' " << std::endl;
    std::cout << "PUSH = 'P' " << std::endl;
    std::cout << "WATER = '~' " << std::endl;
    std::cout << "LAVA = '0' " << std::endl;
    std::cout << "SKULL = '@' " << std::endl;
    std::cout << "WIN = 'W' " << std::endl;
    std::cout << "KILL = 'K' " << std::endl;
    std::cout << "TEXT_WALL = 'M' " << std::endl;
    std::cout << "TEXT_ROCK = 'R' " << std::endl;
    std::cout << "TEXT_FLAG = 'F' " << std::endl;
    std::cout << "TEXT_BABA = 'B' " << std::endl;
    std::cout << "TEXT_GRASS = 'G' " << std::endl;
    std::cout << "TEXT_WATER = 'W' " << std::endl;
    std::cout << "TEXT_METAL = 'm' " << std::endl;
    std::cout << "TEXT_LAVA = 'L' " << std::endl;
    std::cout << "===========Legende=============="<<std::endl;

}

