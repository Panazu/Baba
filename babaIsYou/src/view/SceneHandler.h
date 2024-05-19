#ifndef SCENEHANDLER_H
#define SCENEHANDLER_H


#include <QMainWindow>
#include <QGraphicsView>
#include <QStackedWidget>
#include "GameScene.h"
#include <QGraphicsScene>


class StarterPage;
class InstructScene;
class GraphicController;


class SceneHandler:public QWidget,public Observer {
    Q_OBJECT

public:
    explicit SceneHandler(QWidget *parent = nullptr);
    ~SceneHandler();
    void setupBoard(const std::vector<std::vector<std::vector<Element>>>& board,const std::vector<std::vector<std::vector<Element>>>& oldBoard);
    void update(const std::vector<std::vector<std::vector<Element>>>& board,const std::vector<std::vector<std::vector<Element>>>& oldBoard) override;


public slots:
    void switchToInstructPage();
    void switchToGamePage(int lvlNumber);
    void switchToSavedGamePage();
    void handleKey(QKeyEvent *event);
signals:
   void keyEvent(QKeyEvent *event);

private:
   GraphicController *controller;
    QStackedWidget *stackedWidget;
    StarterPage  *starterPageScene;
   InstructScene *instructPageScene;
   GameScene *gamePage;


    int currentScene;
};

#endif // SCENEHANDLER_H
