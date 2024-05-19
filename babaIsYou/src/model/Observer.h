#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include "Element.h"

class Observer {
public:
    Observer();
    virtual void update(const std::vector<std::vector<std::vector<Element>>>& board, const std::vector<std::vector<std::vector<Element>>>& oldBoard) = 0;
};

#endif // OBSERVER_H
