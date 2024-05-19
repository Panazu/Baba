#include "Position.h"

#include <string>

Position::Position(int x, int y){
    posX = x;
    posY = y;
}
int Position::getX(){
    return this->posX;
}
int Position::getY(){
    return this->posY;
}
std::string Position::to_string() {
    return std::string( std::to_string(posX) + " " + std::to_string(posY));
}
