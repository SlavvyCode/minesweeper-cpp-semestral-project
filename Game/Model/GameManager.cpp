//
// Created by Adam on 09/12/2023.
//

#include "GameManager.h"
#include <iostream>
#include <limits>
using namespace std;


std::unique_ptr<Board> GameManager::preGame(){
int boardSizeX;
int boardSizeY;
int numberOfMines;

//board size from user for both x and y input


//make it so that x and y is at least 2 and so the number of mines has to be less than the number of cells

    while (true) {
        cout << "Please enter the size of the board - first x then y: " << endl;

        if (!(cin >> boardSizeX) || !(cin >> boardSizeY)) {
            // Input failed, handle the error
            cout << "Invalid input. Please enter valid integers." << endl;

            // Clear the error flag
            cin.clear();

            // Discard the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (boardSizeX < 2 || boardSizeY < 2) {
            cout << "Invalid board size, please try again" << endl;
        } else {
            // Valid input, break out of the loop
            break;
        }
    }



//the number of mines has to be less than the number of cells
while (true) {
    cout << "Please enter the number of mines: " << endl;

    // Check if the input is a valid integer
    if (!(cin >> numberOfMines)) {
        cout << "Invalid input. Please enter a valid number." << endl;
        // Clear the input buffer to handle the invalid input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else if (numberOfMines >= boardSizeX * boardSizeY) {
        cout << "Invalid number of mines. Please enter a smaller value." << endl;
    } else {
        // Valid input, break out of the loop
        break;
    }
}
std::unique_ptr<Board> board = std::make_unique<Board>(boardSizeX, boardSizeY, numberOfMines);
currentBoard = std::move(board);

return board;

}



void GameManager::quitGame() {
    cout << "Quitting game..." << endl;
    exit(0);

}
void GameManager::gameOver() {
    cout << "Game over" << endl;
    cout << "Would you like to play again? (y/n)" << endl;
    char input;
    cin >> input;

    if(input == 'y'){
        //todo doesn't this make me stuck in this function?
        startGame();
    }
    else if(input == 'n'){
        navigateToMainMenu();
    }
    else{
        cout << "Invalid input, please try again" << endl;
    }

}

void GameManager::startGame() {
    // in main menu

    preGame();
    gameLoop();
    gameOver();




}

void GameManager::navigateToMainMenu() {

    cout << "Navigating to main menu..." << endl;
    // in game
    // save game
    // quit game
    // main menu
    // load game
    // start game


}

void GameManager::gameLoop() {

    gameState = GameState::GAME_RUNNING;
    currentBoard->printBoard();

    //todo
    // ctrl + c to quit to main menu

    int x, y;
    revealInputDialogNotRaw(x, y);


    currentBoard->distributeMines(x,y);


    while (gameState != GameState::GAME_OVER) {
        //get input or wait for raw input

        currentBoard->printBoard();


        //while the player decides they want to place a flag, let them place as many flags as they want
        // until they say they don't want to place a flag anymore
        while (true) {
            cout << "Would you like to place a flag? (y/n)" << endl;
            char input;
            cin >> input;

            if (input == 'y') {
                int x, y;
                placeFlagDialogNotRaw(x, y);

                currentBoard->placeOrRemoveFlag(x, y);
            } else if (input == 'n') {
                break;
            } else {
                cout << "Invalid input, please try again" << endl;
            }
        }





        revealInputDialogNotRaw(x, y);

        currentBoard->revealCell(x,y);

        if(isCellMine(x,y)){
            gameState = GameState::GAME_OVER;
        }
        //if xy is a mine, game over


        currentBoard->printBoard();


        if(currentBoard->isBoardCleared()){
            gameState = GameState::GAME_OVER;
            cout << "You win!" << endl;
        }

    }

    //if game is over is checked outside of this method

    return;

}

void GameManager::revealInputDialogNotRaw(int &x, int &y) const {

    while (true) {
        cout << "Please enter the coordinates of the cell you want to reveal: " << endl;

        // Check if the input is a valid integer for both x and y
        if (!(cin >> x) || !(cin >> y)) {
            cout << "Invalid input. Please enter valid integer coordinates." << endl;
            // Clear the input buffer to handle the invalid input
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (x < 0 || x >= currentBoard->width || y < 0 || y >= currentBoard->height) {
            cout << "Invalid coordinates, please try again" << endl;
        } else {
            // Valid input, break out of the loop
            break;
        }
    }

}
void GameManager::placeFlagDialogNotRaw(int &x, int &y) const {

    while (true)
    {
        cout << "Please enter the coordinates of the cell you want to flag: " << endl;
        // Check if the input is a valid integer for both x and y
        if (!(cin >> x) || !(cin >> y)) {
            cout << "Invalid input. Please enter valid integer coordinates." << endl;
            // Clear the input buffer to handle the invalid input
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (x < 0 || x >= currentBoard->width || y < 0 || y >= currentBoard->height) {
            cout << "Invalid coordinates, please try again" << endl;
        } else {
            // Valid input, break out of the loop
            break;
        }
    }

}







bool GameManager::isCellMine(int x, int y) {
    if(currentBoard->mapArray[x][y].type == Board::MINE){
        return true;
    }
    else{
        return false;
    }
}

