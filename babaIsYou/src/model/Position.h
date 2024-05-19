#ifndef POSITION_H
#define POSITION_H
#include <string>


class Position{
    int posX;
    int posY;
public:
    Position(int x , int y);
    int getX();
    int getY();
    std::string to_string();
};

#endif // POSITION_H
