#include "Element.h"

Element::Element(int x, int y, materials material): pos(x, y) {
    type = material;
}

Element::Element(int x, int y, materials material, direction direction): pos(x, y) {
    type = material;
    dir = direction;
}

// Setters
void Element::setPos(Position position) {
    pos = position;
}

// Getters
Position Element::getPos() {
    return pos;
}

materials Element::getType() {
    return type;
}


