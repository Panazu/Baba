#ifndef GRAPHICCONTROLLER_H
#define GRAPHICCONTROLLER_H
#include "../model/Game.h"
#include "../model/Observer.h"
#include "../view/SceneHandler.h"

class GraphicController:public QObject{
    Q_OBJECT
public:
    GraphicController();
    void start();
public slots:
    void handleKeyPress(QKeyEvent *event);
    void startGame(int lvlNumber);
    void addObserverToModel(Observer* observer);
private:
    Game *model;
};
#endif // GRAPHICCONTROLLER_H
