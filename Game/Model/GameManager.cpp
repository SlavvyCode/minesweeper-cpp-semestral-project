//
// Created by Adam on 09/12/2023.
//

#include "GameManager.h"
#include <iostream>
using namespace std;


Board *GameManager::preGame(){
int boardSizeX;
int boardSizeY;
int numberOfMines;

//board size from user for both x and y input
cout << "Please enter the size of the board - first x then y: " << endl;

cin >> boardSizeX;
cin >> boardSizeY;



cout << "Please enter the number of mines: " << endl;
cin >> numberOfMines;

Board* board = new Board(boardSizeX,boardSizeY, numberOfMines);

return board;

}



void GameManager::quitGame() {
    cout << "Quitting game..." << endl;
    exit(0);

}

void GameManager::startGame() {
    // in main menu

    preGame();


}

void GameManager::navigateToMainMenu() {

    // in game
    // save game
    // quit game
    // main menu
    // load game
    // start game


}

void GameManager::gameLoop() {

    //todo
    //game loop
    //while game is not over
    //get input or wait for raw input

    //update board
    //print board



    //if game is over
    //{
    //print game over message
    //ask user if they want to play again
    //if yes
    //start game
    //if no
    //main menu
    //}

    //if game is not over
    //continue game loop

    currentBoard->printBoard();

    //get input

    int x, y;
    cout << "Please enter the coordinates of the cell you want to reveal: " << endl;
    cin >> x;
    cin >> y;


    currentBoard->distributeMines(x,y);


    while (gameState != gameState.GAME_OVER) {
        //get input or wait for raw input


        cout << "Please enter the coordinates of the next cell you want to reveal: " << endl;
        cin >> x;
        cin >> y;

        //

        currentBoard.revealCell(x,y);


        currentBoard->printBoard();
        currentBoard.();

        //update board
        //print board

    }

}
