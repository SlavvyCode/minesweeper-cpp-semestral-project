//
// Created by Adam on 22/11/2023.
//

#ifndef PCC_SEMESTRALKA_BOARD_H
#define PCC_SEMESTRALKA_BOARD_H

#include <vector>
#include <memory>

using std::vector;
using std::pair;


class Board {


private:
    ~Board();

    int width = 5;
    int height = 5;
    int mineNumber=5;

public:


    //constructor
    Board(int width, int height, int mineNumber)
            : width(width), height(height), mineNumber(mineNumber) {
        mapArray.resize(width, vector<Cell>(height, Cell(EMPTY, HIDDEN)));

    }

    //2d array of enums

    enum cellType{
        EMPTY,
        MINE,
        NUMBER
    };

    enum cellState{
        HIDDEN,
        REVEALED,
        FLAGGED
    };



    void printBoard();


    bool revealCell(int x, int y);


    //use some randomness or pseudorandomness to distribute the mines






    struct Cell {
        cellType type;
        cellState state;
        int value = 0;
        // Add more properties if needed

        // Constructor
        Cell(cellType type, cellState state) {
            this->type = type;
            this->state = state;
        }
    };


    bool distributeMines(int x, int y);

    vector<vector<Cell>> mapArray;

    void updateMineCountForSurroundingCells(size_t randomX, size_t randomY);

    void cascadeRevealBlankCells(int x, int y);
};


#endif //PCC_SEMESTRALKA_BOARD_H
