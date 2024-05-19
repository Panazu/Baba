#include "StarterPage.h"
#include "ui_StarterPage.h"

StarterPage::StarterPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StarterPage)
{
    ui->setupUi(this);



}

StarterPage::~StarterPage()
{
    delete ui;

}

void StarterPage::switchToSavedGamePage()
{
    this->setStyleSheet(QString::fromUtf8("StarterPage {\n"
                                                     "    background-image: url(\":images/resources/SaveGamePage.png\");\n"
                                                     "    background-repeat: no-repeat;\n"
                                                     "    background-position: center;\n"
                                                     "}\n"
                                                     ""));

    ui->startButton->deleteLater();
}

QPushButton *StarterPage::startButton() const{
    return ui->startButton;
}
