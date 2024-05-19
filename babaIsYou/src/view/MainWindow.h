#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QPushButton>
#include "SceneHandler.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow; }
QT_END_NAMESPACE

//class SceneHandler;

class InstructScene : public QMainWindow
{
    Q_OBJECT

public:
    InstructScene(QWidget *parent = nullptr);
    ~InstructScene();

    void onMyPlayButtonClicked();
    void onMyLevel1ButtonClicked();
    void onMyLevel2ButtonClicked();
    void onMyLevel3ButtonClicked();
    void onMyLevel4ButtonClicked();
    void onMySavedLevelButtonClicked();
    QPushButton *SavedButton() const;
    SceneHandler *sceneHandler;

private:
    void stopFocus();
    Ui::MainWindow *Ui;


};
#endif // MAINWINDOW_H
