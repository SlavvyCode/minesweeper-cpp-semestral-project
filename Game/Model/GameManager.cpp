//
// Created by Adam on 09/12/2023.
//

#include "GameManager.h"
#include <iostream>
#include <sstream>
#include <regex>
using namespace std;

std::unique_ptr<Board> GameManager::preGame() {
    cout << "Type 'help' for commands at any time!" << endl << endl << endl;

    //declare variables for the board size and number of mines

    // the board sizes in each direction
    int boardSizeX;
    int boardSizeY;

    // the number of mines on the board
    int numberOfMines;

    // make a regex which will filter user input
    std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");


// Board size from the user for both x and y input
    while (true) {
        cout << "Please enter the size of the board - first x then y - between 3 and 25: " << endl  << endl;

        // Get the user input
        string storedInput;
        getline(input, storedInput);

        if (storedInput == "help") {
            // Show commands
            cout << "Enter two numbers larger than 2 to dictate the size of the board." << endl ;
            cout << "Commands:" << endl;
            cout << "   help - show commands"  << endl;
            cout << "   exit - quit game" << endl  << endl;
        }
        else if(storedInput == "exit")
        {
            // swap the regexes to free up memory
            std::regex().swap(input_regex);
            quitGame();
        }
        else {
            // Use a regular expression match to validate the storedInput
            std::smatch match;
            if (std::regex_match(storedInput, match, input_regex)) {
                // Use std::stringstream to convert the storedInput to integers
                std::stringstream ss(storedInput);
                // Read the two numbers from the stringstream
                ss >> boardSizeX >> boardSizeY;

                // Check if the storedInput is within the specified range
                if (boardSizeX < 3 || boardSizeY < 3 || boardSizeX > 25 || boardSizeY > 25) {
                    cout << "Invalid board size. Please enter numbers between 3 and 25." << endl  << endl;
                } else {
                    // Valid storedInput, break out of the loop
                    break;
                }
            } else {
                cout << "Invalid input. Please enter two numbers separated by a space." << endl;
            }
        }
    }


    // make a regex which will filter user input
    std::regex input_regex2("^\\s*(\\d+)\\s*$");

// The number of mines has to be less than the number of cells
    while (true) {
        cout << "Please enter a number of mines between 1 and " << boardSizeX * boardSizeY - 1 << "." << endl  << endl;

        // Get the user input
        string storedInput;
        getline(input, storedInput);

        if (storedInput == "help") {
            // Show commands
            cout << "pick a number from the range above." << endl;
            cout << "Commands:" << endl;
            cout << "   exit - quit the game";
            cout << "   help - show commands" << endl  << endl;
        } else if(storedInput== "exit"){
            // swap the regexes to free up memory
            std::regex().swap(input_regex);
            std::regex().swap(input_regex2);

            quitGame();
        }
        else
        {
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
    // Set the current board to the newly created board
    currentBoard = std::move(board);

    // swap the regexes to free up memory
    std::regex().swap(input_regex);
    std::regex().swap(input_regex2);

    return board;
}



void GameManager::quitGame() {
    cout << "Quitting game..." << endl  << endl;
    // Reset the board pointer since despite being a unique pointer, it was causing still reachable memory leaks in valgrind.
    currentBoard.reset();
    std::exit(0);
}




void GameManager::gameOver() {
    cout << "Game over" << endl;

    while (true) {
        cout << "Would you like to play again? (y/n)" << endl  << endl;

        // Get the user input
        string storedInput;
        getline(input, storedInput);

        if (storedInput == "y") {
            // start the game anew
            startGame();
            return;
        } else if (storedInput == "n" || storedInput == "q" || storedInput == "exit") {
            // Quit the game
            quitGame();
        } else if (storedInput == "help") {
            // Show commands
            cout << "Commands:" << endl;
            cout << "   y - play again" << endl;
            cout << "   n or q or exit - quit game" << endl;
            cout << "   help - show commands" << endl  << endl;
        } else {
            // Invalid input, prompt user to try again
            cout << "Invalid input, please try again" << endl  << endl;
        }
    }


}

void GameManager::startGame() {
    // Set the game state to pre-game where the board is configured
    preGame();
    // Start the game loop
    gameLoop(nullopt);
    // game over dialogue
    gameOver();
}



void GameManager::gameLoop(std::optional<size_t> seedSeq) {
    bool gameWon = false;

    //initial state of the game to make sure the first cell clicked is not a mine and to show the player the board
    gameState = GameState::GAME_RUNNING;
    // print the board
    currentBoard->printBoard();

    //declare variables for the coordinates of the cell to reveal
    int x, y;

    //get the coordinates of the cell to reveal
    revealInputDialog(x, y);

    //distribute the mines on the board using mt19937 so that the first cell clicked is not a mine
    currentBoard->distributeMines(x,y,seedSeq);

    //game loop
    while (gameState != GameState::GAME_OVER) {
        //while the player decides they want to place a flag, let them place as many flags as they want
        // until they say they don't want to place a flag anymore

        while (true) {
            currentBoard->printBoard();

            cout << "Would you like to place a flag? (y/n)" << endl;
            // Get the user input
            string storedInput;
            getline(input, storedInput);

            if (storedInput == "y") {

                // print the board
                currentBoard->printBoard();

                // x and y are the coordinates on the board
                int x, y;
                // get the coordinates of the cell to place the flag
                placeFlagDialog(x, y);

                // place or remove the flag
                currentBoard->placeOrRemoveFlag(x, y);

                // check if the board is cleared
                if(currentBoard->isBoardCleared()){
                    // if it is, the game is over and the player has won
                    gameState = GameState::GAME_OVER;
                    cout << "You win!" << endl  << endl;
                    // set gameWon to true so that the game over message doesn't show twice
                    gameWon = true;
                    break;
                }
                else if(gameWon){
                    break;
                }



            } else if (storedInput == "n") {
                {
                    // print the board
                    currentBoard->printBoard();
                    break;
                }
            }
            else if(storedInput=="exit"){
                // quit the game
                quitGame();
            }
            else if (storedInput == "help") {
                // Show commands
                cout << "Commands:" << endl;
                cout << "   y - place a flag" << endl;
                cout << "   n - don't place a flag" << endl;
                cout << "   help - show commands" << endl ;
                cout << "   exit - quit game" << endl  << endl;
            } else {
                cout << "Invalid input, please try again" << endl  << endl;
            }
        }



        if(currentBoard->isBoardCleared() && !gameWon){
            gameState = GameState::GAME_OVER;
            cout << "You win!" << endl  << endl;
            break;
        }
        else if (gameWon){
            break;
        }


        //get the coordinates of the cell to reveal
        revealInputDialog(x, y);

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


        //check if the board is cleared for the last time
        if(currentBoard->isBoardCleared()){
            gameState = GameState::GAME_OVER;
            cout << "You win!" << endl  << endl;
            break;
        }
}

    //if game is over is checked outside of this method

    return;

}



void GameManager::revealInputDialog(int &x, int &y) const {
    // make a regex which will filter user input
    std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");

    while (true) {
        cout << "Please enter the coordinates of the cell you want to reveal: " << endl << endl;

        // Get the user input
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

    // swap the regexes to free up memory
    std::regex().swap(input_regex);

}
void GameManager::placeFlagDialog(int &x, int &y) {
    // make a regex which will filter user input
    std::regex input_regex("^\\s*(\\d+)\\s+(\\d+)\\s*$");

    while (true)
    {
        cout << "Please enter the coordinates of the cell you want to flag: " << endl  << endl;

        // Get the user input
        string storedInput;
        getline(input, storedInput);

        if(storedInput == "help"){
        cout << "   enter two coordinates that place you within the confines of the board to place the flag." << endl  << endl;
            cout << "Commands:" << endl;
            cout << "   exit - exit the game" << endl;
            cout << "   help - show commands" << endl  << endl;

        }
        else if(storedInput == "exit"){
            // swap the regexes to free up memory
            std::regex().swap(input_regex);
            quitGame();
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

    // swap the regexes to free up memory
    std::regex().swap(input_regex);

}

GameManager::GameState GameManager::getGameState() const {
    return gameState;
}


Board* GameManager::getCurrentBoard() const {
    if(currentBoard == nullptr){
        return nullptr;
    }
    return currentBoard.get();
}


void GameManager::setCurrentBoard(unique_ptr<Board> &&uniquePtr) {
    currentBoard = std::move(uniquePtr);
}




















