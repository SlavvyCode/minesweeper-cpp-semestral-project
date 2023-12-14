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
    int boardSizeX;
    int boardSizeY;
    int numberOfMines;

    // Display help commands


std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");

// Board size from the user for both x and y input
    while (true) {
        cout << "Please enter the size of the board - first x then y - between 3 and 40: " << endl  << endl;

        string input;
        getline(cin, input);

        if (input == "--help") {
            // Show commands
            cout << "Enter two numbers larger than 2 to dictate the size of the board." << endl ;
            cout << "Commands:" << endl;
            cout << "   --help - show commands" << endl  << endl;
        } else {
            // Use a regular expression match to validate the input
            std::smatch match;
            if (std::regex_match(input, match, input_regex)) {
                // Use std::stringstream to convert the input to integers
                std::stringstream ss(input);
                ss >> boardSizeX >> boardSizeY;

                // Check if the input is within the specified range
                if (boardSizeX < 2 || boardSizeY < 2 || boardSizeX > 40 || boardSizeY > 40) {
                    cout << "Invalid board size. Please enter numbers between 2 and 40." << endl  << endl;
                } else {
                    // Valid input, break out of the loop
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

        string input;
        getline(cin, input);

        if (input == "--help") {
            // Show commands
            cout << "pick a number from the range above." << endl;
            cout << "Commands:" << endl;
            cout << "   --help - show commands" << endl  << endl;
        } else {
            // Use a regular expression match to validate the input
            std::smatch match;
            if (std::regex_match(input, match, input_regex2)) {
                // Use std::stringstream to convert the input to an integer
                std::stringstream ss(input);
                ss >> numberOfMines;

                // Check if the input is within the valid range
                if (numberOfMines < 1 || numberOfMines >= boardSizeX * boardSizeY) {
                    cout << "Invalid number of mines. Please enter a number between 1 and " << boardSizeX*boardSizeY-1 << "." << endl  << endl;
                } else {
                    // Valid input, break out of the loop
                    break;
                }
            } else {
                cout << "Invalid input. Please enter a valid number." << endl  << endl;
            }
        }
    }


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
        string input;

        getline(cin, input);

        if (input == "y") {
            // Restart the game
            startGame();
        } else if (input == "n" || input == "q") {
            // Quit the game
            quitGame();
        } else if (input == "--help") {
            // Show commands
            cout << "Commands:" << endl;
            cout << "   y - play again" << endl;
            cout << "   n or q - quit game" << endl;
            cout << "   --help - show commands" << endl  << endl;
        } else {
            // Invalid input, prompt user to try again
            cout << "Invalid input, please try again" << endl  << endl;
        }
    }


}

void GameManager::startGame() {
    cout << "Type '--help' for commands at any time!" << endl << endl << endl;

    preGame();
    gameLoop();
    gameOver();



}



void GameManager::gameLoop() {

    gameState = GameState::GAME_RUNNING;
    currentBoard->printBoard();


    int x, y;
    revealInputDialogNotRaw(x, y);


    currentBoard->distributeMines(x,y);


    while (gameState != GameState::GAME_OVER) {
        //while the player decides they want to place a flag, let them place as many flags as they want
        // until they say they don't want to place a flag anymore

        while (true) {
            currentBoard->printBoard();

            cout << "Would you like to place a flag? (y/n)" << endl;
            string input;
            getline(cin, input);

            if (input == "y") {

                currentBoard->printBoard();

                int x, y;
                placeFlagDialogNotRaw(x, y);

                currentBoard->placeOrRemoveFlag(x, y);

                if(currentBoard->isBoardCleared()){
                    gameState = GameState::GAME_OVER;
                    cout << "You win!" << endl  << endl;
                    break;
                }




            } else if (input == "n") {
                break;
            } else if (input == "--help") {
                // Show commands
                cout << "Commands:" << endl;
                cout << "   y - place a flag" << endl;
                cout << "   n - don't place a flag" << endl;
                cout << "   --help - show commands" << endl  << endl ;
            } else {
                cout << "Invalid input, please try again" << endl  << endl;
            }
        }



        if(currentBoard->isBoardCleared()){
//            gameState = GameState::GAME_OVER;
//            cout << "You win!" << endl  << endl;
            break;
        }



        revealInputDialogNotRaw(x, y);

        currentBoard->revealCell(x,y);

        if(isCellMine(x,y)){
            //reveal the mine and end the game
            currentBoard->mapArray[x][y].state = Board::REVEALED;
            gameState = GameState::GAME_OVER;
        }
        //if xy is a mine, game over


        currentBoard->printBoard();


    }

    //if game is over is checked outside of this method

    return;

}



void GameManager::revealInputDialogNotRaw(int &x, int &y) const {

    std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");

    while (true) {
        cout << "Please enter the coordinates of the cell you want to reveal: " << endl << endl;
        string input;
        getline(cin, input);

        // Use a regular expression match to validate the input
        std::smatch match;
        if (std::regex_match(input, match, input_regex)) {
            // Use std::stringstream to convert the input to integers
            std::stringstream ss(input);
            ss >> x >> y;

            // Check if the input is within the valid range
            if (x < 0 || x >= currentBoard->width || y < 0 || y >= currentBoard->height) {
                cout << "Invalid coordinates, please try again" << endl  << endl;
            } else {
                // Valid input, break out of the loop
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
        string input;
        getline(cin, input);

        if(input == "--help"){
        cout << "   enter two coordinates that place you within the confines of the board to place the flag." << endl  << endl;
            cout << "Commands:" << endl;
            cout << "   --help - show commands" << endl  << endl;
        }
        else {
            // Use a regular expression match to validate the input
            std::smatch match;
            if (std::regex_match(input, match, input_regex)) {
                // Use std::stringstream to convert the input to integers
                std::stringstream ss(input);
                ss >> x >> y;

                // Check if the input is within the valid range
                if (x < 0 || x >= currentBoard->width || y < 0 || y >= currentBoard->height) {
                    cout << "Invalid coordinates, please try again" << endl << endl;
                } else {
                    // Valid input, break out of the loop
                    break;
                }
            } else {
                cout << "Invalid input. Please enter two numbers separated by a space." << endl << endl;
            }
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

