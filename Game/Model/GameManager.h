//
// Created by Adam on 09/12/2023.
//

#ifndef MINESWEEPER_GAMEMANAGER_H
#define MINESWEEPER_GAMEMANAGER_H


#include "Board.h"
#include "Menu.h"
#include <iostream>
using namespace std;

class GameManager {
private:
    std::unique_ptr<Board> currentBoard;
    Menu* currentMenu;

    enum GameState {
        NOT_STARTED,
        GAME_RUNNING,
        GAME_OVER
    };

    GameState gameState;

    static void handleCtrlC(int signum) {
        cout << "\nReceived Ctrl+C.\n";
        // Implement your custom 'back' functionality or exit the program

        navigateToMainMenu();
    }


public:
    GameManager() {
        // Set up signal handler for Ctrl+C
        signal(SIGINT, handleCtrlC);
    }

    void startGame();
    void quitGame();
    static void navigateToMainMenu();

    bool isCellMine(int x, int y);
    //todo consider
//    void saveGame();


    std::unique_ptr<Board> preGame();

    //game loop
    void gameLoop();


    void gameOver();

    void revealInputDialogNotRaw(int &x, int &y) const;
};


#endif //MINESWEEPER_GAMEMANAGER_H
