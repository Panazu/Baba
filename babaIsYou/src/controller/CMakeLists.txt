set(CONTROLLER_SOURCES
    Controller.cpp
    Controller.h
    GraphicController.cpp
    GraphicController.h
)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
add_library(controller OBJECT ${CONTROLLER_SOURCES})
target_link_libraries(controller Qt6::Widgets)

