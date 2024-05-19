#include "Observable.h"

void Observable::notifyObserver(const std::vector<std::vector<std::vector<Element>>>& board, const std::vector<std::vector<std::vector<Element>>>& oldBoard){
    for (auto obs : observers)
    {
        obs->update(board,oldBoard);
    }
}
void Observable::addObserver(Observer* obs){
    observers.push_back(obs);
}
void Observable::removeObserver(Observer* obs){
    auto it = std::find(observers.begin(), observers.end(), obs);
    if (it != observers.end()) {
        observers.erase(it);
    }
}
