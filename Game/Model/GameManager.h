//
// Created by Adam on 09/12/2023.
//

#ifndef MINESWEEPER_GAMEMANAGER_H
#define MINESWEEPER_GAMEMANAGER_H


#include "Board.h"
#include "Menu.h"

class GameManager {
private:
    Board* currentBoard;
    Menu* currentMenu;

    enum gameState {
        NOT_STARTED,
        GAME_RUNNING,
        GAME_OVER
    };

public:
    GameManager();
    void startGame();
    void quitGame();
    void navigateToMainMenu();

    //todo consider
//    void saveGame();


    Board* preGame();

    //game loop
    void gameLoop();
};


#endif //MINESWEEPER_GAMEMANAGER_H
