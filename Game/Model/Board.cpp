//
// Created by Adam on 22/11/2023.
//

#include <iostream>
#include "Board.h"
#include <memory>

using namespace std;

void Board::printBoard() {

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


Board::~Board() {
}

bool Board::distributeMines(int x, int y) {

    //x and y are the coordinates of the first cell clicked

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

void Board::updateMineCountForSurroundingCells(size_t randomX, size_t randomY) {
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

bool Board::revealCell(int x, int y) {

    if(x<0 || x>width || y<0 || y>height){
        cout << "Invalid coordinates, please try again" << endl;
        return false;
    }

    //if the cell is already revealed, do nothing
    if(mapArray[x][y].state == REVEALED){
        return false;
    }

    //if the cell is flagged, do nothing
    if(mapArray[x][y].state == FLAGGED){
        return false;
    }

    //if the cell is a mine, return true, leave logic for game ending to other method
    if(mapArray[x][y].type == MINE || mapArray[x][y].type == NUMBER ){
        mapArray[x][y].state = REVEALED;
        return true;
    }

    //if the cell is empty, reveal it and reveal all surrounding cells

    if(mapArray[x][y].type == EMPTY){
        mapArray[x][y].state = REVEALED;
        cascadeRevealBlankCells(x,y);
        return true;
    }


    throw "Error: unexpected behaviour in Board::revealCell()";

    return false;



}

void Board::cascadeRevealBlankCells(int x, int y) {

        //if the cell is empty, reveal it and reveal all surrounding cells



        int iteratingX = x;
        int iteratingY = y;

        for (iteratingX; iteratingX < x+1; ++iteratingX) {

            for (iteratingY; iteratingY; ++iteratingY) {

                if(iteratingX == x && iteratingY == y){
                    continue;
                }
                if(iteratingX < 0 || iteratingX > width || iteratingY < 0 || iteratingY > height){
                    continue;
                }

                Cell cellToReveal = mapArray[iteratingX][iteratingY];

                if(cellToReveal.type == EMPTY && cellToReveal.state == HIDDEN){
                    cellToReveal.state = REVEALED;
                    cascadeRevealBlankCells(x + 1, y + 1);
                }
                else if(cellToReveal.type == NUMBER && cellToReveal.state == HIDDEN){
                    cellToReveal.state = REVEALED;
                }


            }

        }

}




