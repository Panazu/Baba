#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <vector>
#include "Observer.h"
class Observable{
    std::vector<Observer*> observers;
public:
    void notifyObserver(const std::vector<std::vector<std::vector<Element>>>& board, const std::vector<std::vector<std::vector<Element>>>& oldBoard);
    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);
};

#endif // OBSERVABLE_H
