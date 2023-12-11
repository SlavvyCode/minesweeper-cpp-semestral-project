#include "catch.hpp"
#include "Game/Model/Board.h"

//#include "tests-helper.hpp"

#include <vector>
#include <random>
#include <ctime>



//write test
//check if the board is created correctly
//check if the mines are distributed correctly
//check if the cells are revealed correctly
//check if the game is won correctly
//check if the game is lost correctly
//check if the game is quit correctly


TEST_CASE("scenario1", "[scenario1][small board]") {
    const int width = 10;
    const int height = 10;
    const int numberOfMines = 10;

    // Repeat the test multiple times to increase reliability
    for (int i = 0; i < 100; ++i) {
        Board board(width, height, numberOfMines);

        SECTION("Check if mines are distributed") {
            // Count the number of mines in each row and column
            std::vector<int> minesInRow(width, 0);
            std::vector<int> minesInColumn(height, 0);

            for (int col = 0; col < width; ++col) {
                for (int row = 0; row < height; ++row) {
                    if (board.mapArray[col][row].type == Board::MINE) {
                        minesInRow[col]++;
                        minesInColumn[row]++;
                    }
                }
            }

            // Calculate the average number of mines per row and column
            double averageMinesPerRow = static_cast<double>(numberOfMines) / width;
            double averageMinesPerColumn = static_cast<double>(numberOfMines) / height;

            // Check if the number of mines in each row is close to the average
            for (int col = 0; col < width; ++col) {
                REQUIRE(minesInRow[col] == Approx(averageMinesPerRow).margin(1));
            }

            // Check if the number of mines in each column is close to the average
            for (int row = 0; row < height; ++row) {
                REQUIRE(minesInColumn[row] == Approx(averageMinesPerColumn).margin(1));
            }
        }
    }
}

TEST_CASE("Board creation and basic functionality", "[Board]") {
    SECTION("Check if the board is created correctly") {
        const int width = 10;
        const int height = 10;
        const int numberOfMines = 10;

        Board board(width, height, numberOfMines);

        REQUIRE(board.width == width);
        REQUIRE(board.height == height);
        REQUIRE(board.mineNumber == numberOfMines);

        // Add more checks if needed
    }

    SECTION("Check if cells are revealed correctly") {
        const int width = 2;
        const int height = 2;
        const int numberOfMines = 3;

        Board board(width, height, numberOfMines);

        // Choose a safe cell and reveal it
        int safeX = 0;
        int safeY = 0;

        board.revealCell(safeX, safeY);

        REQUIRE(board.mapArray[safeX][safeY].state == Board::REVEALED);
        REQUIRE(board.mapArray[safeX][safeY].type == Board::EMPTY);
        REQUIRE(board.getRemainingNonMineCells() == 1);

    }

    // Add more sections for other scenarios you want to test
}

