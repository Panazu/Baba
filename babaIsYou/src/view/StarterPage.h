#ifndef STARTERPAGE_H
#define STARTERPAGE_H


#include <QGraphicsScene>
#include <QPushButton>
#include <QMainWindow>



namespace Ui {
class StarterPage;
}

class StarterPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit StarterPage(QWidget *parent = nullptr);
    ~StarterPage();
    void switchToSavedGamePage();

    QPushButton *startButton() const;

private:
    Ui::StarterPage *ui;


};



#endif // STARTERPAGE_H
