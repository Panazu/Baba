#include "GameScene.h"

GameScene::GameScene(QWidget *parent) : QWidget(parent) {

    centralwidget = new QWidget(this);

    centralwidget->setObjectName("centralwidget");
    centralwidget->setMinimumSize(QSize(600, 600));
    centralwidget->setMouseTracking(true);
    centralwidget->setToolTipDuration(1);
    centralwidget->setStyleSheet(QString::fromUtf8(""));

    gridLayout = new QGridLayout(centralwidget);


    centralwidget->setStyleSheet(R"(
    QWidget#centralwidget {
        background-image: url(:/images/resources/background.png);
        background-repeat: repeat;
    }
    )"
                                 );

    setLayout(gridLayout);



}


void GameScene::displayBaba(const std::vector<std::vector<std::vector<Element>>>& gameBoard,
                               const std::vector<std::vector<std::vector<Element>>>& oldBoard){
    auto board = gameBoard;

    int width = board.size();
    int height = board.at(0).size();

    // Iterate through rows of the board
    for (int row = 0; row < height; row++) {

        // Iterate through columns of the board
        for (int col = 0; col < width; col++) {
            if (!board[col][row].empty()) {
                if(isDifferentCase(board,oldBoard,col,row)){//If true, we change the display of the position
                    clearCase(row,col);//clear the case if he have to change.
                    for(int layer = 0 ; layer < board[col][row].size() ; layer++){//update the content of the case with the new elements.
                        Element& element = board[col][row][layer];
                        QLabel* label = new QLabel(this);
                        label->setFixedSize(50,50);
                        label->setPixmap(babaAssets[element.getType()]);
                        gridLayout->addWidget(label, row, col);

                    }
                }
            }else{
                clearCase(row,col);
                QLabel* label = new QLabel(this);
                label->setFixedSize(50,50);
                gridLayout->addWidget(label, row, col);
            }
        }
    }
}

void GameScene::keyPressEvent(QKeyEvent *event){
    emit keyPressed(event);
}
GameScene::~GameScene() {
    delete gridLayout;
}
//this method clear the case that is asked.
void GameScene::clearCase(int row, int col){
    QLayoutItem* item = gridLayout->itemAtPosition(row, col);
    while (item != nullptr) {
        QWidget* widget = item->widget();
        gridLayout->removeWidget(widget);
        delete widget;
        item = gridLayout->itemAtPosition(row, col);
    }
}
//this method clear the board.
void GameScene::clearBoard(){
    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        item->widget()->deleteLater();
        delete item;
    }
}
//oldBoard is the state of the board before the last movement, we compare the two boards at the given position
//if the board did change or the given position during the move, it return true
bool GameScene::isDifferentCase(const std::vector<std::vector<std::vector<Element>>>& board,
                                   const std::vector<std::vector<std::vector<Element>>>& oldBoard,int col, int row){
    if (board.size() != oldBoard.size()) {
        return true; // The arrays have different length
    }

    if (board.at(col).size() != oldBoard.at(col).size()) {
        return true; // The arrays have different height
    }

    if (board.at(col).at(row).size() != oldBoard.at(col).at(row).size()) {
        return true; // The arrays have a different number of layers on the specified case
    }

    for (int layer = 0; layer < board.at(col).at(row).size(); layer++) {
        auto boardObject = board.at(col).at(row).at(layer);
        auto oldBoardObject = oldBoard.at(col).at(row).at(layer);
        if (boardObject.getType() != oldBoardObject.getType()) {
            return true; // The elements in the specified case are different in the new board (after movement) and old board (before movement)
        }
    }

    return false; // The elements in the specified case are the same in the new board and old board
}

