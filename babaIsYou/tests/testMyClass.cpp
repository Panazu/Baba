#include <catch2/catch_test_macros.hpp>
#include "Controller.h"

TEST_CASE( "Test of Game") {
    Game game;
    SECTION("move"){
        int x;
        int y;
        game.start(0,false);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::LEFT);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() != newPos.getX()) || (oldPos.getY() != newPos.getY())));
    }
    SECTION("move left"){
        int x;
        int y;
        game.start(0,false);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::LEFT);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX()-1 == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("move right"){
        int x;
        int y;
        game.start(0,false);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::RIGHT);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX()+1 == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("move top"){
        int x;
        int y;
        game.start(0,false);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::TOP);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY()-1 == newPos.getY())));
    }
    SECTION("move bottom"){
        int x;
        int y;
        game.start(0,false);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::BOTTOM);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY()+1 == newPos.getY())));
    }
    SECTION("move push"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        bool rockMoved= false;
        for(auto elem : newBoard.at(x+1).at(y)){
            if(elem.getType() == materials::ROCK){
                rockMoved = true;
            }
        }
        REQUIRE( rockMoved);
    }
    SECTION("move blocked"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::TOP);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::TOP);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("move push blocked"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::BOTTOM);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("move push on push"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::BOTTOM);
        game.move(direction::RIGHT);
        game.move(direction::BOTTOM);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        bool rock1Moved= false;
        bool rock2Moved= false;
        for(auto elem : newBoard.at(x-1).at(y)){
            if(elem.getType() == materials::ROCK){
                rock1Moved = true;
            }
        }
        for(auto elem : newBoard.at(x-2).at(y)){
            if(elem.getType() == materials::ROCK){
                rock2Moved = true;
            }
        }
        REQUIRE( (rock1Moved && rock2Moved));
    }
    SECTION("move death on sink"){
        game.start(3,false);
        int x;
        int y;
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("move death on kill"){
        game.start(4,false);
        int x;
        int y;
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("move death on kill when multiple You"){
        game.start(4,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::BOTTOM);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::BOTTOM);
        game.move(direction::LEFT);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        REQUIRE(!game.isDead());
    }
    SECTION("move win"){
        game.start(0,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        Element newLevelFlag = game.getBoardCopy().at(9).at(8).at(0);
        REQUIRE(newLevelFlag.getType() == materials::FLAG);
    }
    SECTION("destroy rule"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::TOP);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::BOTTOM);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::BOTTOM);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY()+1 == newPos.getY())));
    }
    SECTION("create rule"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::TOP);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::BOTTOM);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::BOTTOM);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::BOTTOM);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::BOTTOM);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("save and launch saved"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.saveLevel();
        game.start(-1,true);
        board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("move out of bounds blocked"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        x = board.at(i).at(j).at(k).getPos().getX();
                        y = board.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position oldPos(x,y);
        game.move(direction::LEFT);
        auto newBoard = game.getBoardCopy();
        for(int i = 0 ; i < newBoard.size() ; i++){
            for(int j = 0 ; j < newBoard.at(i).size();j++){
                for(int k = 0 ; k < newBoard.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,newBoard.at(i).at(j).at(k).getType())){
                        x = newBoard.at(i).at(j).at(k).getPos().getX();
                        y = newBoard.at(i).at(j).at(k).getPos().getY();
                    }
                }
            }
        }
        Position newPos(x,y);
        REQUIRE(((oldPos.getX() == newPos.getX()) && (oldPos.getY() == newPos.getY())));
    }
    SECTION("pos attribute and position in vector same after move"){
        bool correctPos = false;
        game.start(0,false);
        game.move(direction::LEFT);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        if(i == board.at(i).at(j).at(k).getPos().getX() && j ==  board.at(i).at(j).at(k).getPos().getY()){
                            correctPos = true;
                        }
                    }
                }
            }
        }
        REQUIRE(correctPos);
    }
    SECTION("pos attribute and position in vector same"){
        bool correctPos = false;
        game.start(0,false);
        auto board = game.getBoardCopy();
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board.at(i).size();j++){
                for(int k = 0 ; k < board.at(i).at(j).size(); ++k){
                    if(game.isInside(Properties::YOU,board.at(i).at(j).at(k).getType())){
                        if(i == board.at(i).at(j).at(k).getPos().getX() && j ==  board.at(i).at(j).at(k).getPos().getY()){
                            correctPos = true;
                        }
                    }
                }
            }
        }
        REQUIRE(correctPos);
    }
    SECTION("level 0 achieved"){
        int x;
        int y;
        game.start(0,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        Element newLevelFlag = game.getBoardCopy().at(9).at(8).at(0);
        REQUIRE(newLevelFlag.getType() == materials::FLAG);
    }
    SECTION("level 1 achieved"){
        int x;
        int y;
        game.start(1,false);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::BOTTOM);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::BOTTOM);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::BOTTOM);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        Element newLevelFlag = game.getBoardCopy().at(12).at(5).at(0);
        REQUIRE(newLevelFlag.getType() == materials::FLAG);
    }
    SECTION("level 2 achieved"){
        int x;
        int y;
        game.start(2,false);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        Element newLevelFlag = game.getBoardCopy().at(3).at(14).at(0);
        REQUIRE(newLevelFlag.getType() == materials::FLAG);
    }
    SECTION("level 3 achieved"){
        int x;
        int y;
        game.start(3,false);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::RIGHT);

        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);

        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);

        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);

        game.move(direction::RIGHT);
        game.move(direction::TOP);

        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);

        game.move(direction::BOTTOM);
        game.move(direction::LEFT);

        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);
        game.move(direction::TOP);

        game.move(direction::LEFT);
        game.move(direction::TOP);
        game.move(direction::RIGHT);

        game.move(direction::BOTTOM);
        game.move(direction::RIGHT);
        game.move(direction::TOP);
        game.move(direction::RIGHT);
        game.move(direction::BOTTOM);
        Element newLevelFlag = game.getBoardCopy().at(12).at(7).at(0);
        REQUIRE(newLevelFlag.getType() == materials::FLAG);
    }
    SECTION("level 4 achieved"){
        int x;
        int y;
        game.start(4,false);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);

        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);

        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);

        game.move(direction::BOTTOM);

        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);

        game.move(direction::BOTTOM);
        game.move(direction::LEFT);

        game.move(direction::TOP);
        game.move(direction::TOP);

        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);

        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);
        game.move(direction::BOTTOM);

        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);
        game.move(direction::LEFT);

        game.move(direction::BOTTOM);

        game.move(direction::TOP);

        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        game.move(direction::RIGHT);
        Element newLevelFlag = game.getBoardCopy().at(12).at(8).at(0);
        REQUIRE(newLevelFlag.getType() == materials::FLAG);
    }
}
