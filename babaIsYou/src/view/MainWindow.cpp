#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QToolButton>
#include <QDebug>
#include <QtWidgets/QWidget>
#include <QtGui/QKeyEvent>


InstructScene::InstructScene(QWidget *parent)
    : QMainWindow(parent)
    , Ui(new Ui::MainWindow)
{
    sceneHandler = static_cast<SceneHandler*>(parent);
    Ui->setupUi(this);
    connect(Ui->PlayButton, &QPushButton::clicked, this, &InstructScene::onMyPlayButtonClicked);
    connect(Ui->Level1Button, &QPushButton::clicked, this, &InstructScene::onMyLevel1ButtonClicked);
    connect(Ui->Level2Button, &QPushButton::clicked, this, &InstructScene::onMyLevel2ButtonClicked);
    connect(Ui->Level3Button, &QPushButton::clicked, this, &InstructScene::onMyLevel3ButtonClicked);
    connect(Ui->Level4Button, &QPushButton::clicked, this, &InstructScene::onMyLevel4ButtonClicked);
    connect(Ui->SavedButton, &QPushButton::clicked, this, &InstructScene::onMySavedLevelButtonClicked);
    stopFocus();
}

void InstructScene::stopFocus(){
    Ui->PlayButton->setFocusPolicy(Qt::NoFocus);
    Ui->Level1Button->setFocusPolicy(Qt::NoFocus);
    Ui->Level2Button->setFocusPolicy(Qt::NoFocus);
    Ui->Level3Button->setFocusPolicy(Qt::NoFocus);
    Ui->Level4Button->setFocusPolicy(Qt::NoFocus);
    Ui->SavedButton->setFocusPolicy(Qt::NoFocus);
}
QPushButton *InstructScene::SavedButton() const{
    return Ui->SavedButton;
}


InstructScene::~InstructScene()
{
    delete Ui;
}

void InstructScene::onMyPlayButtonClicked() {
    sceneHandler->switchToGamePage(0);
}

void InstructScene::onMyLevel1ButtonClicked()
{
    sceneHandler->switchToGamePage(1);
}

void InstructScene::onMyLevel2ButtonClicked()
{
    sceneHandler->switchToGamePage(2);
}

void InstructScene::onMyLevel3ButtonClicked()
{
    sceneHandler->switchToGamePage(3);
}

void InstructScene::onMyLevel4ButtonClicked()
{
    sceneHandler->switchToGamePage(4);
}

void InstructScene::onMySavedLevelButtonClicked()
{
    sceneHandler->switchToGamePage(-1);
}
