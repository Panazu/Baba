cmake_minimum_required(VERSION 3.5)

project(BabaIsYouGui VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

add_subdirectory(controller)
add_subdirectory(model)
add_subdirectory(view)

add_executable(BabaIsYouGui
    main.cpp
    $<TARGET_OBJECTS:model>
    $<TARGET_OBJECTS:view>
    $<TARGET_OBJECTS:controller>
    resources.qrc
)

target_link_libraries(BabaIsYouGui PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BabaIsYouGui)
endif()

set_target_properties(BabaIsYouGui PROPERTIES
    MACOSX_BUNDLE_BUNDLE_NAME "Baba Is You"
    MACOSX_BUNDLE_GUI_IDENTIFIER "my.example.com"
    MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
