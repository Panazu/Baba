#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H
#include "../model/Game.h"

class ConsoleView{
    char materialsToString(materials m);
    bool save;
    bool restarted;
public:
    void displayBoard(std::vector<std::vector<std::vector<Element>>> board);
    direction askMovement();
    void displayWin();
    void displayLose();
    bool getSaveGame();
    bool getRestarted();
    void initRestarted();
    void displayLegend();
    int askLevel();
    void displayMessage(std::string message);
};
#endif // CONSOLEVIEW_H
