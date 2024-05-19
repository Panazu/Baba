#ifndef GAME_H
#define GAME_H
#include "Observable.h"
#include "FileHandler.h"
#include "RulesManager.h"
#include <algorithm>

class Game : public Observable{
    Level level;
    RulesManager rules;
    FileHandler fileHandler;
    int levelNumber;
    bool won;
    bool dead;
    bool isValidMove(Element el,direction dir);
    bool isInsideVec(Properties property, std::vector<Element> mat);
    void moveObj(Element,Position,int);
    void setDelta(int & dx, int & dy, direction dir);
    bool pushMove(std::vector<Element> mat,Position dest,int dx,int dy,const std::vector<std::vector<std::vector<Element>>>& board, direction dir);
    void prepareMove(Element actElem,int dx,int dy,const std::vector<std::vector<std::vector<Element>>>& board,int i , int j , int k , direction dir,int& countKilledElement);
    void checkDeath();
    void deleteObject(Element element,Position destination);
    std::vector<std::vector<std::vector<Element>>> oldBoard;
    std::vector<std::vector<std::vector<Element>>>& board;
    void checkHorizontalRules(int x, int y);
    void checkVerticalRules(int x, int y);
    std::vector<std::vector<std::vector<Element>>>& getOldBoard();
    void incrementLevel();
public:
    Game();
    bool isWon();
    void checkRules();
    bool isDead();
    void move(direction dir);
    bool isInside(Properties property , materials);
    void start(int i,bool restart);
    std::vector<std::vector<std::vector<Element>>> getBoardCopy();
    void saveLevel();
    int getLevelNumber();
    void setOldBoard();
};

#endif // GAME_H
