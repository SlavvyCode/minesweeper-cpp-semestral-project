//
// Created by Adam on 09/12/2023.
//

#include "GameManager.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <regex>
using namespace std;

std::unique_ptr<Board> GameManager::preGame() {


    cout << "Type 'help' for commands at any time!" << endl << endl << endl;


    int boardSizeX;
    int boardSizeY;
    int numberOfMines;

    // Display help commands


std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");

// Board size from the user for both x and y input
    while (true) {
        cout << "Please enter the size of the board - first x then y - between 3 and 40: " << endl  << endl;

        string storedInput;
        getline(input, storedInput);

        if (storedInput == "help") {
            // Show commands
            cout << "Enter two numbers larger than 2 to dictate the size of the board." << endl ;
            cout << "Commands:" << endl;
            cout << "   help - show commands" << endl  << endl;
        } else {
            // Use a regular expression match to validate the storedInput
            std::smatch match;
            if (std::regex_match(storedInput, match, input_regex)) {
                // Use std::stringstream to convert the storedInput to integers
                std::stringstream ss(storedInput);
                ss >> boardSizeX >> boardSizeY;

                // Check if the storedInput is within the specified range
                if (boardSizeX < 3 || boardSizeY < 3 || boardSizeX > 40 || boardSizeY > 40) {
                    cout << "Invalid board size. Please enter numbers between 3 and 40." << endl  << endl;
                } else {
                    // Valid storedInput, break out of the loop
                    break;
                }
            } else {
                cout << "Invalid input. Please enter two numbers separated by a space." << endl;
            }
        }
    }



    std::regex input_regex2("^\\s*(\\d+)\\s*$");

// The number of mines has to be less than the number of cells
    while (true) {
        cout << "Please enter a number of mines between 1 and " << boardSizeX*boardSizeY-1 << "." << endl  << endl;

        string storedInput;
        getline(input, storedInput);

        if (storedInput == "help") {
            // Show commands
            cout << "pick a number from the range above." << endl;
            cout << "Commands:" << endl;
            cout << "   help - show commands" << endl  << endl;
        } else {
            // Use a regular expression match to validate the storedInput
            std::smatch match;
            if (std::regex_match(storedInput, match, input_regex2)) {
                // Use std::stringstream to convert the storedInput to an integer
                std::stringstream ss(storedInput);
                ss >> numberOfMines;

                // Check if the storedInput is within the valid range
                if (numberOfMines < 1 || numberOfMines >= boardSizeX * boardSizeY) {
                    cout << "Invalid number of mines. Please enter a number between 1 and " << boardSizeX*boardSizeY-1 << "." << endl  << endl;
                } else {
                    // Valid storedInput, break out of the loop
                    break;
                }
            } else {
                cout << "Invalid input. Please enter a valid number." << endl  << endl;
            }
        }
    }

    // Create a new board with the specified parameters
    std::unique_ptr<Board> board = std::make_unique<Board>(boardSizeX, boardSizeY, numberOfMines);
    currentBoard = std::move(board);

    return board;
}



void GameManager::quitGame() {
    cout << "Quitting game..." << endl  << endl;
    exit(0);
}




void GameManager::gameOver() {
    cout << "Game over" << endl;

    while (true) {
        cout << "Would you like to play again? (y/n)" << endl  << endl;
        string storedInput;

        getline(input, storedInput);

        if (storedInput == "y") {
            // Restart the game
            startGame();
            return;
        } else if (storedInput == "n" || storedInput == "q") {
            // Quit the game
            quitGame();
        } else if (storedInput == "help") {
            // Show commands
            cout << "Commands:" << endl;
            cout << "   y - play again" << endl;
            cout << "   n or q - quit game" << endl;
            cout << "   help - show commands" << endl  << endl;
        } else {
            // Invalid input, prompt user to try again
            cout << "Invalid input, please try again" << endl  << endl;
        }
    }


}

void GameManager::startGame() {

    preGame();
    gameLoop(nullopt);
    gameOver();



}



void GameManager::gameLoop(std::optional<size_t> seedSeq) {

    //initial state of the game to make sure the first cell clicked is not a mine and to show the player the board
    gameState = GameState::GAME_RUNNING;
    currentBoard->printBoard();
    int x, y;
    revealInputDialogNotRaw(x, y);
    currentBoard->distributeMines(x,y,seedSeq);


    //game loop
    while (gameState != GameState::GAME_OVER) {
        //while the player decides they want to place a flag, let them place as many flags as they want
        // until they say they don't want to place a flag anymore

        while (true) {
            currentBoard->printBoard();

            cout << "Would you like to place a flag? (y/n)" << endl;
            string storedInput;
            getline(input, storedInput);

            if (storedInput == "y") {

                currentBoard->printBoard();

                int x, y;
                placeFlagDialogNotRaw(x, y);

                currentBoard->placeOrRemoveFlag(x, y);

                if(currentBoard->isBoardCleared()){
                    gameState = GameState::GAME_OVER;
                    cout << "You win!" << endl  << endl;
                    break;
                }
            } else if (storedInput == "n") {
                {
                    currentBoard->printBoard();
                    break;
                }
            } else if (storedInput == "help") {
                // Show commands
                cout << "Commands:" << endl;
                cout << "   y - place a flag" << endl;
                cout << "   n - don't place a flag" << endl;
                cout << "   help - show commands" << endl  << endl ;
            } else {
                cout << "Invalid input, please try again" << endl  << endl;
            }
        }



        if(currentBoard->isBoardCleared()){
            gameState = GameState::GAME_OVER;
            cout << "You win!" << endl  << endl;
            break;
        }



        revealInputDialogNotRaw(x, y);

        //if the player sucessfully reveals a cell,
        if(currentBoard->revealCell(x,y)){
            //check if it was a mine they revealed
            if(currentBoard->isCellMine(x,y)){
                //reveal the mine and end the game
                currentBoard->mapArray[x][y].state = Board::REVEALED;
                gameState = GameState::GAME_OVER;
                currentBoard->printBoard();
            }

        }
        //if xy is a mine, game over




    }

    //if game is over is checked outside of this method

    return;

}



void GameManager::revealInputDialogNotRaw(int &x, int &y) const {

    std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");

    while (true) {
        cout << "Please enter the coordinates of the cell you want to reveal: " << endl << endl;
        string storedInput;
        getline(input, storedInput);

        // Use a regular expression match to validate the storedInput
        std::smatch match;
        if (std::regex_match(storedInput, match, input_regex)) {
            // Use std::stringstream to convert the storedInput to integers
            std::stringstream ss(storedInput);
            ss >> x >> y;

            // Check if the storedInput is within the valid range
            if (x < 0 || x >= currentBoard->width || y < 0 || y >= currentBoard->height) {
                cout << "Invalid coordinates, please try again" << endl  << endl;
            } else {
                // Valid storedInput, break out of the loop
                break;
            }
        } else {
            cout << "Invalid input. Please enter two numbers separated by a space." << endl  << endl;
        }
    }

}
void GameManager::placeFlagDialogNotRaw(int &x, int &y) const {
    std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");

    while (true)
    {
        cout << "Please enter the coordinates of the cell you want to flag: " << endl  << endl;
        string storedInput;
        getline(input, storedInput);

        if(storedInput == "help"){
        cout << "   enter two coordinates that place you within the confines of the board to place the flag." << endl  << endl;
            cout << "Commands:" << endl;
            cout << "   help - show commands" << endl  << endl;
        }
        else {
            // Use a regular expression match to validate the storedInput
            std::smatch match;
            if (std::regex_match(storedInput, match, input_regex)) {
                // Use std::stringstream to convert the storedInput to integers
                std::stringstream ss(storedInput);
                ss >> x >> y;

                // Check if the storedInput is within the valid range
                if (x < 0 || x >= currentBoard->width || y < 0 || y >= currentBoard->height) {
                    cout << "Invalid coordinates, please try again" << endl << endl;
                } else {
                    // Valid storedInput, break out of the loop
                    break;
                }
            } else {
                cout << "Invalid input. Please enter two numbers separated by a space." << endl << endl;
            }
        }
    }

}

GameManager::GameState GameManager::getGameState() const {
    return gameState;
}


//get board readonly
Board* GameManager::getCurrentBoard() const {
    if(currentBoard == nullptr){
        return nullptr;
    }
    return currentBoard.get();
}

void GameManager::setCurrentBoard(unique_ptr<Board> &&uniquePtr) {
    currentBoard = std::move(uniquePtr);

}




















