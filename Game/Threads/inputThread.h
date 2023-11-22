//
// Created by Adam on 21/11/2023.
//

#ifndef CMAKEPROJEKT_INPUTTHREAD_H
#define CMAKEPROJEKT_INPUTTHREAD_H


#include <iostream>
#include <thread>
#include <mutex>


class inputThread {
public:
    inputThread(); // Constructor
    ~inputThread(); // Destructor

    void start(); // Start the input thread
    void stop(); // Stop the input thread

private:
    std::thread thread; // Input thread
    std::atomic<bool> isRunning; // Atomic flag to control the thread

    // Function to handle keyboard inputs
    void handleInputs();

    // Add any other private members or functions as needed
};

#endif //CMAKEPROJEKT_INPUTTHREAD_H
