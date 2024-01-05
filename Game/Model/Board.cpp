//
// Created by Adam on 22/11/2023.
//

#include <iostream>
#include "Board.h"
#include <memory>
#include <stack>
#include <iomanip>
#include <random>
#include <optional>


using namespace std;

void Board::printBoard() {
    // Print the top row of numbers with correct alignment
    std::cout << "   "; // Start with spaces to align with the left edge of the board
    for (int col = 0; col < width; ++col) {
        std::cout << " " << std::setw(1) << col;
    }
    std::cout << "\n";

    // Print the wider horizontal separator
    std::cout << "  +";
    for (int col = 0; col < width; ++col) {
        std::cout << "--";
//        std::cout << ANSI_BOLD "--";
//        std::cout << ANSI_GREEN "--" ANSI_RESET;
    }
    std::cout << "+\n";

    for (int row = 0; row < height; ++row) {
        // Print the row number with correct alignment
        std::cout << std::setw(2) << row << " |"; // Use setw(2) for proper alignment

        for (int col = 0; col < width; ++col) {
            string symbol = " ";
            const Cell& cell = mapArray[col][row];

            switch (cell.state) {
                case HIDDEN:
//                    ■▣
                    symbol = "?";
                    break;
                case FLAGGED:
                    symbol = "F";
                    break;
                case REVEALED:
                    if(cell.type == MINE){
                        symbol = "X";
//                        Ô
                        //●
//                        symbol = ANSI_RED "X" ANSI_RESET;
                    }
                    else if(cell.type == EMPTY){
                        symbol = ' ';
                    }
                    else {
                        symbol = std::to_string(cell.value)[0];
                    }
                    break;
            }
            std::cout << symbol << '|';
        }
        std::cout << "\n";
    }

    // Print the bottom separation line
    std::cout << "  +";
    for (int col = 0; col < width; ++col) {
        std::cout << "--";
    }
    std::cout << "+\n";
}


bool Board::isBoardCleared() {
    if(remainingNonMines == 0 && mineNumber == flaggedMines){
        return true;
    }
    return false;
}

bool Board::distributeMines(int x, int y, const std::optional<const size_t> seedSeq) {
    // x and y are the coordinates of the first cell clicked
    // make sure that the first cell clicked is not a mine

    std::mt19937 eng;

    if (seedSeq.has_value()) {
        // If a seed sequence is provided, use it to initialize the random engine
        eng.seed(seedSeq.value());
    } else {
        // Otherwise, use a random seed
        std::random_device rd; // Obtain a random number from hardware
        eng.seed(rd());
    }


    std::uniform_int_distribution<> distrX(0, width - 1); // Define the range for x
    std::uniform_int_distribution<> distrY(0, height - 1); // Define the range for y


    size_t minesDistributed = 0;
    while (minesDistributed != mineNumber) {
        size_t randomX = distrX(eng); // Generate a random x coordinate
        size_t randomY = distrY(eng); // Generate a random y coordinate

        // Check if the random cell is the first clicked cell or already has a mine
        if (randomX == x && randomY == y || (mapArray[randomX][randomY].type == MINE)) {
            continue;
        }

        mapArray[randomX][randomY].type = MINE; // Place a mine

        // Update the surrounding cells to have the correct values
        updateMineCountForSurroundingCells(randomX, randomY);

        minesDistributed++;
    }


    updateCellsToBeNumberType(); // Distribute numbers on the board

    // Reveal the first cell clicked
    revealCell(x, y);

    return true;
}


void Board::updateMineCountForSurroundingCells(size_t mineX, size_t mineY) {
    //top left
    if(mineX > 0 && mineY > 0){
        mapArray[mineX - 1][mineY - 1].value++;
    }
    //top
    if(mineY > 0){
        mapArray[mineX][mineY - 1].value++;
    }
    //top right
    if(mineX < width - 1 && mineY > 0){
        mapArray[mineX + 1][mineY - 1].value++;
    }
    //left
    if(mineX > 0){
        mapArray[mineX - 1][mineY].value++;
    }
    //right
    if(mineX < width - 1){
        mapArray[mineX + 1][mineY].value++;
    }
    //bottom left
    if(mineX > 0 && mineY < height - 1){
        mapArray[mineX - 1][mineY + 1].value++;
    }
    //bottom
    if(mineY < height - 1){
        mapArray[mineX][mineY + 1].value++;
    }
    //bottom right
    if(mineX < width - 1 && mineY < height - 1){
        mapArray[mineX + 1][mineY + 1].value++;
    }



}

bool Board::revealCell(int x, int y) {

    if(x<0 || x>width || y<0 || y>height){
        cout << "Invalid coordinates, please try again" << endl;
        return false;
    }





    //if the cell is already revealed, do nothing
    if(mapArray[x][y].state == REVEALED){
        cout << "That cell is revealed already, please try again" << endl;
        return false;
    }

    //if the cell is flagged, do nothing
    if(mapArray[x][y].state == FLAGGED){
        cout << "That cell is flagged, please try again" << endl;
        return false;
    }

    if(mapArray[x][y].type==MINE)
        return true;


    //if the cell is empty, reveal it and reveal all surrounding cells

    if(mapArray[x][y].type == EMPTY || mapArray[x][y].type == NUMBER){
        cascadeRevealCells(x, y);
        return true;
    }

    throw "Error: unexpected behaviour in Board::revealCell()";
}

void Board::cascadeRevealCells(int x, int y) {
    // Check if the cell is within bounds
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }

    // Get the cell to reveal
    Cell& cellToReveal = mapArray[x][y];

    // If the cell is a mine or already revealed, do nothing
    if (cellToReveal.type == MINE || cellToReveal.state == REVEALED) {
        return;
    }

    // Reveal the cell and decrement the count of remaining non-mine cells
    cellToReveal.state = REVEALED;
    remainingNonMines--;



    // Only cascade reveal if the cell is blank
    if (cellToReveal.type == EMPTY ) {
        // Iterate over the 3x3 grid centered around the current cell
        for (int i = std::max(0, x - 1); i <= std::min(width - 1, x + 1); ++i) {
            for (int j = std::max(0, y - 1); j <= std::min(height - 1, y + 1); ++j) {
                // Skip the current cell (x, y)
                if (i == x && j == y) {
                    continue;
                }
                // Recursively reveal adjacent blank cells
                cascadeRevealCells(i, j);
            }
        }
    }
}


void Board::updateCellsToBeNumberType() {

    //iterate through the board and update the numbers
    for (int row = 0; row < height; ++row) {
        for (int col = 0; col < width; col++) {


            Cell& foundCell = mapArray[col][row];

            if (foundCell.type == MINE) {
                continue;
            }
            if (foundCell.value == 0) {
                continue;
            }

            // Change the type to NUMBER equal to value
            foundCell.type = NUMBER;



        }
    }

}


bool Board::placeOrRemoveFlag(int x, int y) {
    if(x<0 || x>width || y<0 || y>height){
        cout << "Invalid coordinates, please try again" << endl;
        return false;
    }

    //if the cell is already revealed, do nothing
    if(mapArray[x][y].state == REVEALED){
        cout << "That cell is revealed already, please try again" << endl;
        return false;
    }

    //if the cell is flagged, do nothing
    if(mapArray[x][y].state == FLAGGED){
        cout << "Flag removed" << endl;

        mapArray[x][y].state = HIDDEN;

        if(mapArray[x][y].type == MINE)
            flaggedMines--;

        return true;

    }


    //if the cell is a mine, return true, leave logic for game ending to other method
    if(mapArray[x][y].type == MINE  ){
        mapArray[x][y].state = FLAGGED;
        flaggedMines++;
        return true;
    }

    else throw "Error: unexpected behaviour in Board::placeOrRemoveFlag()";
}




bool Board::isCellMine(int x, int y) {
    if(mapArray[x][y].type == Board::MINE){
        return true;
    }
    else{
        return false;
    }
}


