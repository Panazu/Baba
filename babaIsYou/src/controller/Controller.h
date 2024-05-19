#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../model/Observer.h"
#include "../model/Game.h"
#include "../view/ConsoleView.h"

class Controller : public Observer{
public:
    Controller();
    void start();
    void update(const std::vector<std::vector<std::vector<Element>>>& board, const std::vector<std::vector<std::vector<Element>>>& oldBoard) override;
private:
    Game game;
    ConsoleView view;
};
#endif // CONTROLLER_H
