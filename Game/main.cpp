//
// Created by Adam on 22/11/2023.
//

#include "Model/GameManager.h"
#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>

int main(int argc, char* argv[]) {

    /// provide help if requested by the user
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--help") {
            // Print program usage information
            std::cout << "Minesweeper - Semestral project - made by Adam Štrobl: " << std::endl;
            std::cout << "   Minesweeper is a single-player game, the objective of which is to flag all mines on a rectangular board containing hidden \"mines\" without revealing them" << endl;
            std::cout << "   You gain information about the location of neighbouring mines from every revealed cell with mines adjacent." << std::endl;
            std::cout << "How to play: " << std::endl;
            std::cout << "      Follow the instructions given to you by the program and have fun!" << std::endl;
            std::cout << "      If you ever get stuck, type \"help\" while playing the game at any timew for a further elaboration of what to do." << std::endl;
            return 0;
        }
    }


    std::istream& userInput = std::cin; // User input stream

    // Start the game and make a new instance of GameManager which will handle the game
    GameManager gameManager = GameManager(userInput);
    gameManager.startGame();



    return 0;
}


