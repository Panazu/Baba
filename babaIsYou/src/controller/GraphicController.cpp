#include "GraphicController.h"

GraphicController::GraphicController(){
    model = new Game();
}
void GraphicController::handleKeyPress(QKeyEvent *event){
    if(event->key() == Qt::Key_R){
        model->setOldBoard();
        startGame(model->getLevelNumber());
    }else if(event->key() == Qt::Key_S){
        model->saveLevel();
    }else if(event->key() == Qt::Key_Up){
        model->move(direction::TOP);
    }else if(event->key() == Qt::Key_Down){
        model->move(direction::BOTTOM);
    }else if(event->key() == Qt::Key_Left){
        model->move(direction::LEFT);
    }else if(event->key() == Qt::Key_Right){
        model->move(direction::RIGHT);
    }
}
void GraphicController::startGame(int lvlNumber){
    if (lvlNumber == -1){
        model->start(lvlNumber,true);
    }else{
        model->start(lvlNumber,false);
    }
}
void GraphicController::addObserverToModel(Observer* observer){
    model->addObserver(observer);
}
