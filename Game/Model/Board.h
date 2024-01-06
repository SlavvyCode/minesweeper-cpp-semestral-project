//
// Created by Adam on 22/11/2023.
//

#ifndef PCC_SEMESTRALKA_BOARD_H
#define PCC_SEMESTRALKA_BOARD_H

#include <vector>
#include <memory>
#include <optional>
#include <random>

using std::vector;
using std::pair;

/**
 * @brief Class representing the board of the game.
 * Contains a 2d vector of cells, and methods for manipulating the board.
 */
class Board {


private:


    /**
     * Number of mines that are flagged
     */
    int flaggedMines = 0;
    /**
     * Number of cells that are not mines and are not revealed
     */
    int remainingNonMines;

public:

    //constants

    /**
     * Width of the board
     */
    const int width = 5;
    /**
     * Height of the board
     */
    const int height = 5;
    /**
     * Number of mines on the board
     */
    const int mineNumber = 5;


    /**
     * @brief Constructor for the Board class, creates a new board with the given dimensions and number of mines.
     *
     * @param width
     * @param height
     * @param mineNumber
     */
    Board(int width, int height, int mineNumber)
            : width(width), height(height), mineNumber(mineNumber) {
        mapArray.resize(width, vector<Cell>(height, Cell(EMPTY, HIDDEN)));
        remainingNonMines = width * height - mineNumber;

    }

    //2d array of enums

    /**
     * @brief Enum representing each type of cell
     * NUMBER
     * MINE
     * EMPTY
     */
    enum cellType{
        EMPTY,
        MINE,
        NUMBER
    };

    /**
     * @brief Enum representing the state of each cell
     * HIDDEN
     * REVEALED
     * FLAGGED
     *
     */
    enum cellState{
        HIDDEN,
        REVEALED,
        FLAGGED
    };



    /**
     * @brief Prints the board to the console.
     */
    void printBoard();


    /**
     * @brief Reveals the cell at the given coordinates.
     * @param x
     * @param y
     * @return
     */
    bool revealCell(int x, int y);

    /**
     * @brief Places or removes a flag at the given coordinates.
     * @param x
     * @param y
     * @return
     */
    bool placeOrRemoveFlag(int x, int y);
    //use some randomness or pseudorandomness to distribute the mines

    /**
     * Checks if the given cell is a mine.
     * @param x == x coordinate of the cell
     * @param y == y coordinate of the cell
     * @return true if the cell is a mine, false otherwise
     */
    bool isCellMine(int x, int y);


    /**
     * @brief Struct representing a cell on the board.
     */
    struct Cell {

        cellType type;
        cellState state;
        /**
         * @brief Value of the cell, means number of adjacent mines.
         * Only displayed in game if the cell is a number
         */
        int value = 0;


        /**
         * @brief Constructor for the Cell struct.
         * @param type
         * @param state
         */
        Cell(cellType type, cellState state) {
            this->type = type;
            this->state = state;
        }

        /**
         * @brief Default constructor for the Cell struct.
         * used only for smart pointer
         */
        Cell() {

        }
    };


    /**
     * @brief Distributes the mines on the board using mt19937.
     * x and y parameters are the first cell clicked to ensure that the first clicked cell is not a mine.
     * @param x
     * @param y
     * @param seed optional seed for the random engine, otherwise uses rd() to generate a random seed
     * @return
     */
    bool distributeMines(int x, int y, const std::optional<const size_t> seedSeq);
    /**
     * keeps track of the cells and their locations
     */
    vector<vector<Cell>> mapArray;

    /**
     * @brief Updates the value of cells around a mine.
     * @param mineX
     * @param mineY
     */
    void updateMineCountForSurroundingCells(size_t mineX, size_t mineY);


/**
 * @brief recursively reveals all cells in an area until it hits numbers.
 * @param x,y starting coordinates of the recursion cell
 */
    void cascadeRevealCells(int x, int y);


    /**
     * @brief Once the mines are distributed and values of cells are set,
     * this method sets cells to be a type number if they aren't a mine and if their value isn't 0
     */
    void updateCellsToBeNumberType();

    /**
     * @brief Checks if the board is cleared, meaning all non-mine cells are revealed.
     * @return mineNumber == flaggedMines - if true, the board is cleared and all mines are flagged
     */
    bool isBoardCleared();


    /**
     * @brief Prints the top or bottom edge of the board.
     */
    void printTopOrBottomBoardEdge() const;

    /**
     * @brief Prints the board in between its top and bottom edge
     */
    void printBoardContents();
};


#endif //PCC_SEMESTRALKA_BOARD_H
