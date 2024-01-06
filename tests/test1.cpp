#include "../catch.hpp"
#include "../Game/Model/Board.h"
#include "../Game/Model/GameManager.h"

//#include "tests-helper.hpp"

#include <vector>
#include <random>
#include <ctime>
#include <cassert>
#include <optional>
#include <sstream>




TEST_CASE("scenario1", "[scenario1][small board]") {
    const int width = 10;
    const int height = 10;
    const int numberOfMines = 10;

    // Repeat the test multiple times to increase reliability
    for (int i = 0; i < 100; ++i) {
        Board board(width, height, numberOfMines);

        SECTION("Check if mines are distributed evenly") {
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

        SECTION("Check if the board is created correctly") {
            REQUIRE(board.width == width);
            REQUIRE(board.height == height);
            REQUIRE(board.mineNumber == numberOfMines);
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
    }

}







//check if the game is quit correctly

TEST_CASE("End game state - requirement testing") {
    SECTION("Check if the game detects win condition in a vacuum") {
        const int width = 2;
        const int height = 2;
        const int numberOfMines = 3;


        Board board(width, height, numberOfMines);

        // Choose a safe cell and reveal it
        int safeX = 0;
        int safeY = 0;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (i == safeX && j == safeY) {
                    continue;
                }
                board.mapArray[i][j].type = Board::MINE ;
            }
        }
        board.revealCell(safeX, safeY);

        for (int i = 0; i < 2; ++i) {

            for (int j = 0; j < 2; ++j) {
                if (i == safeX && j == safeY) {
                    continue;
                }
                board.updateMineCountForSurroundingCells(i,j);
            }
        }

        board.updateCellsToBeNumberType();

        REQUIRE(board.mapArray[safeX][safeY].state == Board::REVEALED);
        REQUIRE(board.mapArray[safeX][safeY].type == Board::NUMBER);


        //flag all the other cells
        board.placeOrRemoveFlag(0,1);
        board.placeOrRemoveFlag(1,0);
        board.placeOrRemoveFlag(1,1);


        REQUIRE(board.isBoardCleared());
    }


    SECTION("Check if the game detects loss condition in a vacuum") {
        const int width = 2;
        const int height = 2;
        const int numberOfMines = 3;


        Board board(width, height, numberOfMines);

        // Choose a safe cell and reveal it
        int safeX = 0;
        int safeY = 0;

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                if (i == safeX && j == safeY) {
                    continue;
                }
                board.mapArray[i][j].type = Board::MINE ;
            }
        }
        board.revealCell(safeX, safeY);

        for (int i = 0; i < 2; ++i) {

            for (int j = 0; j < 2; ++j) {
                if (i == safeX && j == safeY) {
                    continue;
                }
                board.updateMineCountForSurroundingCells(i,j);
            }
        }

        board.updateCellsToBeNumberType();

        board.revealCell(0,1);
        REQUIRE(board.isCellMine(0,1));

    }
}


TEST_CASE("Simulate player input at runtime"){
    SECTION("Check if the game detects win condition") {

        //3x3 board and set only one mine at the bottom middle

//           0 1 2
//          +------+
//        0 | | | |
//        1 |1|1|1|
//        2 |1|X|1|
//          +------+


        std::string fakeInput =
                "1 1\n"
                "n\n"
                "2 2\n"

                "y\n" // flagged the mine
                "1 2\n"

                "n\n"
                "0 0\n"
                "n\n"
                "2 1\n"
                "n\n"
                "0 1\n"
                "n\n"
                "0 2\n"
                "n\n"
                "2 1\n"
                "n\n"
                "2 2"; // revealed last cell



        std::istringstream fakeInputStringStream(fakeInput);

        GameManager gameManager = GameManager(fakeInputStringStream);

        std::unique_ptr<Board> board = std::make_unique<Board>(3, 3, 1);
        gameManager.setCurrentBoard(std::move(board));



        size_t seed = 42;
        std::optional<size_t> seedOptional(seed);

        gameManager.gameLoop(seed);

        //game is over
        assert(gameManager.getGameState() == GameManager::GAME_OVER);

        //qualifies as victory!
        assert(gameManager.getCurrentBoard()->isBoardCleared()==true);

    }

    SECTION("Check if the game detects loss") {

        //3x3 board and set only one mine at the bottom middle

//           0 1 2
//          +------+
//        0 | | | |
//        1 |1|1|1|
//        2 |1|X|1|
//          +------+


        std::string fakeInput =
                "1 1\n"
                "n\n"
                "2 2\n"

                "n\n" // flagged the mine
                "1 2";



        std::istringstream fakeInputStringStream(fakeInput);

        GameManager gameManager = GameManager(fakeInputStringStream);

        std::unique_ptr<Board> board = std::make_unique<Board>(3, 3, 1);
        gameManager.setCurrentBoard(std::move(board));



        size_t seed = 42;
        std::optional<size_t> seedOptional(seed);

        gameManager.gameLoop(seed);

        //game is over
        assert(gameManager.getGameState() == GameManager::GAME_OVER);

        //qualifies as victory!
        assert(gameManager.getCurrentBoard()->isBoardCleared()==false);

    }


    SECTION("Check if the game handles faulty input well") {

        // type this into console
        std::string fakeInput = "-3 -222\n"
                                "8888888 888888\n"
                                "3.5 3.14159265\n"
                                "3 2\n"
                                "abc\n"
                                "n\n"
                                "1 1\n"
                                "n\n"
                                "1 2\n"; // game lost here

        std::istringstream fakeInputStringStream(fakeInput);

        GameManager gameManager = GameManager(fakeInputStringStream);

        std::unique_ptr<Board> board = std::make_unique<Board>(3, 3, 1);
        gameManager.setCurrentBoard(std::move(board));




        size_t seed = 42;
        std::optional<size_t> seedOptional(seed);

        gameManager.gameLoop(seed);

//        gameManager.startGame();


        assert(gameManager.getCurrentBoard()->height == 3);
        assert(gameManager.getCurrentBoard()->width == 3);

    }
}

