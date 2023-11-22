//
// Created by Adam on 21/11/2023.
//

#include "inputThread.h"


//vlákno inputThread slouží k načítání vstupů z klávesnice. Zde je očekáváno zmáčknutí klávesy Q pro ukončení programu

inputThread::inputThread() : isRunning(false) {
    // Initialize other members if needed
}

inputThread::~inputThread() {
    stop(); // Ensure the thread is stopped when the object is destroyed
}

void inputThread::start() {
    isRunning.store(true);
    thread = std::thread(&inputThread::handleInputs, this);
}

void inputThread::stop() {
    isRunning.store(false);
    if (thread.joinable()) {
        thread.join();
    }
}

void inputThread::handleInputs() {
    while (isRunning.load()) {
        // Get keypress
        char key = _getwch(); // Use _getch() for simplicity (Windows-specific)

        // Handle the keypress
        switch (key) {
            case 'q':
            case 'Q':
                stop(); // Stop the thread if 'Q' is pressed
                break;

                // Add other key handling logic here

            default:
                // Handle unknown key or ignore
                break;
        }
    }
}
