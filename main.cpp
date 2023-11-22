//
// Created by Adam on 22/11/2023.
//

#include "Game/Threads/inputThread.h"

int main() {
    // Create an instance of InputThread
    inputThread inputThread;

    // Start the input thread
    inputThread.start();

    // Main application logic goes here
    std::cout << "Press 'Q' to quit." << std::endl;

    // Wait for the input thread to finish (pressing 'Q' will stop it)
    inputThread.stop();

    // Other cleanup or post-processing logic

    return 0;
}
