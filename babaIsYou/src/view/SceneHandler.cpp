#include "SceneHandler.h"
#include "MainWindow.h"
#include "../controller/GraphicController.h"
#include "StarterPage.h"

SceneHandler::SceneHandler(QWidget *parent) :
    QWidget(parent){

    controller = new GraphicController();
    controller->addObserverToModel(this);

    starterPageScene = new StarterPage(this);
    instructPageScene = new InstructScene(this);
    gamePage = new GameScene(this);


    //We create a stackedWidget that handle the different scenes

    stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(starterPageScene);
    stackedWidget->addWidget(instructPageScene);
    stackedWidget->addWidget(gamePage);


    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    setLayout(layout);
    connect(gamePage,&GameScene::keyPressed,this,&SceneHandler::handleKey);
    connect(starterPageScene->startButton(),&QPushButton::clicked,this,&SceneHandler::switchToInstructPage);
    this->setFixedSize(622,622);

}

SceneHandler::~SceneHandler() {
    // No specific cleanup needed in this case
}


void SceneHandler::switchToInstructPage(){
    stackedWidget->setCurrentWidget(instructPageScene);
}
void SceneHandler::switchToSavedGamePage(){
       stackedWidget->setCurrentWidget(starterPageScene);
    starterPageScene->switchToSavedGamePage();
}
void SceneHandler::switchToGamePage(int lvlNumber){
    controller->startGame(lvlNumber);
    stackedWidget->setCurrentWidget(gamePage);
}
void SceneHandler::handleKey(QKeyEvent *event){
    if(event->key() == Qt::Key_S){
        switchToSavedGamePage();
    }
    controller->handleKeyPress(event);
}
void SceneHandler::setupBoard(const std::vector<std::vector<std::vector<Element>>>& board,const std::vector<std::vector<std::vector<Element>>>& oldBoard){
    gamePage->displayBaba(board,oldBoard);
}
void SceneHandler::update(const std::vector<std::vector<std::vector<Element>>> &board, const std::vector<std::vector<std::vector<Element>>> &oldBoard){
    setupBoard(board,oldBoard);
}


