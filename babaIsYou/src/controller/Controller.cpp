#include "Controller.h"
Controller::Controller():game(Game()),view(ConsoleView()){

}
void Controller::start()
{
    game.addObserver(static_cast<Observer*>(this));
    int level = view.askLevel();
    view.displayLegend();
    while(level<5 && !view.getSaveGame()){

        try{
            if (level == -1){
                game.start(level,true);
            }else{
                game.start(level,false);
            }
        }catch(std::string message){
            view.displayMessage(message);
        }

        level = game.getLevelNumber();

        while(!game.isWon() && !game.isDead() && !view.getRestarted() && !view.getSaveGame()){
            direction dir = view.askMovement();
            if(!view.getSaveGame()){
                game.move(dir);
            }

        }
        if(game.isWon()){
            view.displayWin();
            level++;
        }else if(game.isDead()){
            view.displayLose();
        }else if(view.getRestarted()){
            view.initRestarted();
        }else if(view.getSaveGame()){
            try{
                game.saveLevel();
                view.displayMessage("Niveau sauvegarde !");
            }catch(std::string message) {
                view.displayMessage(message);
            }

        }
    }
}
void Controller::update(const std::vector<std::vector<std::vector<Element>>>& board, const std::vector<std::vector<std::vector<Element>>>& oldBoard){
    view.displayBoard(board);
}
