set(MODEL_SOURCES
    Materials.h
    Direction.h
    Position.h
    Position.cpp
    Element.h
    Element.cpp
    Observable.h
    Observer.h
    Observer.cpp
    Observable.cpp
    Level.h
    Level.cpp
    FileHandler.h
    FileHandler.cpp
    Game.h
    Game.cpp
    RulesManager.cpp
    RulesManager.h
    MaterialHelper.h
    MaterialHelper.cpp
)

add_library(model OBJECT ${MODEL_SOURCES})
