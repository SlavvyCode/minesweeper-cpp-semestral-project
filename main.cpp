//
// Created by Adam on 22/11/2023.
//

#include "Game/Model/GameManager.h"

#include <unistd.h>
#include <iostream>
#include <thread>
#include <mutex>

int main() {

    //FUCK THREADS LET ME JUST GET IT DONE


    GameManager gameManager = GameManager();
    gameManager.startGame();


    return 0;
}


