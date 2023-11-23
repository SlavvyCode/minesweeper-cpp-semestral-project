//
// Created by Adam on 22/11/2023.
//

#include <iostream>
#include "board.h"
#include <memory>


void board::printBoard() {

    //unique cell ptr
    std::unique_ptr<Cell> foundCell;

    std::cout << "+";
    for (int col = 0; col < width; ++col) {
        std::cout << "--";
    }
    std::cout << "+\n";

    for (int row = 0; row < height; ++row) {
        std::cout << row + 1 << '|';

        for (int col = 0; col < width; ++col) {
            char symbol = ' ';


            *foundCell = mapArray[col][row];
            
            
            switch (foundCell->state) {
                case HIDDEN:
                    symbol = '?';
                    break;

                case FLAGGED:
                    symbol = '!';
                    break;

                case REVEALED:

                    if(foundCell->type == MINE){
                        symbol = 'X';
                    }
                    else if(foundCell->type == EMPTY){
                        symbol = ' ';
                    }
                    else {
                        symbol = foundCell->value;
                    }
                    break;

            }
            std::cout << symbol << '|';
        }
        std::cout << "\n";
    }

    std::cout << "+";
    for (int col = 0; col < width; ++col) {
        std::cout << "--";
    }
    std::cout << "+\n";

}

board::board(int width, int height, int mineNumber) {

    //in the input make sure values are first legal

}

board::~board() {

}

bool board::distributeMines(int x, int y) {
    //make sure that the first cell clicked is not a mine

    //    distribute mineNumber mines across the cells

    //do random coordinates and check if there is a mine there or if it is the first cell clicked

    //todo try to make the distribution so that the user never has to guess

    size_t minesDistributed =0;
    while (minesDistributed != mineNumber) {

        size_t randomX = rand() % width;
        size_t randomY = rand() % height;

        if(randomX == x && randomY == y ||
          (mapArray[randomX][randomY].type == MINE))
        {
            continue;
        }

        mapArray[randomX][randomY].type = MINE;

        //update the surrounding cells to have the correct values
        updateMineCountForSurroundingCells(randomX, randomY);


        minesDistributed++;
    }



    return true;



    //distribute mines semi randomly


}

void board::updateMineCountForSurroundingCells(size_t randomX, size_t randomY) {
    //top left
    if(randomX > 0 && randomY > 0){
        mapArray[randomX - 1][randomY - 1].value++;
    }
    //top
    if(randomY > 0){
        mapArray[randomX][randomY - 1].value++;
    }
    //top right
    if(randomX < width - 1 && randomY > 0){
        mapArray[randomX + 1][randomY - 1].value++;
    }
    //left
    if(randomX > 0){
        mapArray[randomX - 1][randomY].value++;
    }
    //right
    if(randomX < width - 1){
        mapArray[randomX + 1][randomY].value++;
    }
    //bottom left
    if(randomX > 0 && randomY < height - 1){
        mapArray[randomX - 1][randomY + 1].value++;
    }
    //bottom
    if(randomY < height - 1){
        mapArray[randomX][randomY + 1].value++;
    }
    //bottom right
    if(randomX < width - 1 && randomY < height - 1){
        mapArray[randomX + 1][randomY + 1].value++;
    }
}
