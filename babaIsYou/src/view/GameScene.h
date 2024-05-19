
#ifndef GAMESCENE_H
#define GAMESCENE_H


#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPixmap>
#include "../model/Game.h"
#include <QKeyEvent>
#include <vector>
#include <QMap>

class GameScene : public QWidget {
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);
    QWidget* centralwidget;
    void displayBaba(const std::vector<std::vector<std::vector<Element>>>& gameBoard,const std::vector<std::vector<std::vector<Element>>>& oldBoard);
    ~GameScene();
    void keyPressEvent(QKeyEvent *event) override;

    QPixmap baba;
    QPixmap rock;
    QPixmap text;
    QPixmap flag;
    QPixmap wall;
    QPixmap win;
    QPixmap metal;
    QPixmap skull;
    QPixmap stop;
    QPixmap push;
    QPixmap grass;
    QPixmap you;
    QPixmap text_water;
    QPixmap text_flag;
    QPixmap text_wall;
    QPixmap text_rock;
    QPixmap text_baba;
    QPixmap is;
    QPixmap kill;
    QPixmap surprise;
    QPixmap sink;
    QPixmap lava;
    QPixmap water;
    QPixmap text_lava;
signals:
    void keyPressed(QKeyEvent* event);



private:
    QGridLayout *gridLayout;
    void clearBoard();
    bool isDifferentCase(const std::vector<std::vector<std::vector<Element>>>& board,const std::vector<std::vector<std::vector<Element>>>& oldBoard, int col , int row);
    void clearCase(int row, int col);

    const QMap<materials,QPixmap> babaAssets {
        {materials::BABA, QPixmap(":images/resources/baba.png")},
        {materials::ROCK, QPixmap(":images/resources/rock.png")},
        {materials::FLAG, QPixmap(":images/resources/flag.png")},
        {materials::WALL, QPixmap(":images/resources/wall.png")},
        {materials::WIN, QPixmap(":images/resources/text_win.png")},
        {materials::METAL, QPixmap(":images/resources/metal.png")},
        {materials::SKULL, QPixmap(":images/resources/skull.png")},
        {materials::STOP, QPixmap(":images/resources/stop.png")},
        {materials::PUSH, QPixmap(":images/resources/push.png")},
        {materials::GRASS, QPixmap(":images/resources/grass.png")},
        {materials::YOU, QPixmap(":images/resources/you.png")},
        {materials::TEXT_WATER, QPixmap(":images/resources/text_water.png")},
        {materials::TEXT_FLAG, QPixmap(":images/resources/text_flag.png")},
        {materials::TEXT_WALL, QPixmap(":images/resources/text_wall.png")},
        {materials::TEXT_ROCK, QPixmap(":images/resources/text_rock.png")},
        {materials::TEXT_BABA, QPixmap(":images/resources/text_baba.png")},
        {materials::IS, QPixmap(":images/resources/is.png")},
        {materials::KILL, QPixmap(":images/resources/kill.png")},
        {materials::SINK, QPixmap(":images/resources/sink.png")},
        {materials::LAVA, QPixmap(":images/resources/lava.png")},
        {materials::TEXT_LAVA, QPixmap(":images/resources/text_lava.png")},
        {materials::WATER, QPixmap(":images/resources/water.png")}
    };

};






#endif // GAMESCENE_H

