#ifndef ELEMENT_H
#define ELEMENT_H
#include "Position.h"
#include "Direction.h"
#include "Materials.h"
#include <string>
class Element{
    Position pos;
    direction dir;
    materials type;
public:
    Element(int x, int y,materials mat);
    Element(int x , int y,materials mat,direction dir);
    Element();
    void setPos(Position);
    Position getPos();
    materials getType();
};

#endif // ELEMENT_H
