#include <QApplication>
#include "view/SceneHandler.h"


int main(int argc, char *argv[])
{   
    QApplication a(argc, argv);
    SceneHandler scene;
    scene.show();   
    return a.exec();
}
