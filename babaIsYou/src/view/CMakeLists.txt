find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(VIEW_SOURCES
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
    StarterPage.ui
    StarterPage.h
    StarterPage.cpp
    SceneHandler.h
    SceneHandler.cpp
    SceneHandler.ui
    GameScene.h
    GameScene.cpp
    ConsoleView.cpp
    ConsoleView.h
)


add_library(view ${VIEW_SOURCES})

target_link_libraries(view PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
