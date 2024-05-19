cmake_minimum_required(VERSION 3.5)

add_executable(BabaIsYouTests

    testMyClass.cpp
    ../src/controller/Controller.cpp
    ../src/view/consoleView.cpp
    ../src/model/Element.cpp
    ../src/model/FileHandler.cpp
    ../src/model/Game.cpp
    ../src/model/Level.cpp
    ../src/model/MaterialHelper.cpp
    ../src/model/Observable.cpp
    ../src/model/Observer.cpp
    ../src/model/Position.cpp
    ../src/model/RulesManager.cpp

)
target_include_directories(BabaIsYouTests PRIVATE
    ../src/model
    ../src/controller
)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)
#list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

target_link_libraries(BabaIsYouTests Catch2::Catch2WithMain)
