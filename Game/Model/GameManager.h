//
// Created by Adam on 09/12/2023.
//

#ifndef MINESWEEPER_GAMEMANAGER_H
#define MINESWEEPER_GAMEMANAGER_H


#include "Board.h"
#include <iostream>
#include <regex>
using namespace std;

/**
 *
 * @brief Class representing the game manager.
 * Contains the main game loop and the game over method.
 * Owns the current board.
 */
class GameManager {

public:

/**
     * Enum representing the state of the game
     * PRE_GAME - the game has not started yet
     * GAME_RUNNING - the game is running
     * GAME_OVER - the game is over
     */
    enum GameState {
        PRE_GAME,
        GAME_RUNNING,
        GAME_OVER,
    };

private:
    /**
     * The current board the user is playing on
     */
    std::unique_ptr<Board> currentBoard;

    /**
     * The input stream from which the user input is read
     */
    std::istream& input;


    /**
     * The current state of the game
     */
    GameState gameState = PRE_GAME;


public:

    /**
     * @brief Constructor for the GameManager class, creates a new GameManager instance.
     *
     * @param input - input stream
     */
    GameManager(std::istream& input) : input(input) {
    }


    /**
    * @brief Starts the Minesweeper game.
    *
    * Displays a helpful message for the player, sets up the game, enters the
    * game loop where the main gameplay takes place, and handles the conclusion
    * of the game (win, lose, or quit).
    *
    * @note Type 'help' for commands at any time.
    */
    void startGame();

    /**
     * Quits the game.
     */
    void quitGame();



    /**
     * @brief Prompts the user for the board size and number of mines.
     *
     * @return a smart unique pointer to the board which the user has specified with their input
     */
    std::unique_ptr<Board> preGame();

    /**
     * @brief The main game loop and mine distribution.
     *
     * @param seedSeq - optional seed for the random engine, otherwise uses rd() to generate a random seed
     *
     * Before anything else happens, there is a mine distribution to make sure the first cell clicked is not a mine.
     *
     * The rest of the method consists of the main game loop.
     * The loop consists of:
     * 1. letting the user flag or unflag as many cells and times as they would like
     * 2. letting the user reveal a cell (and revealing it)
     * 3. checking if the game is won or lost and acting accordingly
     *
     * it also prints the board along the way to show the user the current state of the board
     */
    void gameLoop(std::optional<size_t> seedSeq);



    /**
     * shows the game over message and lets the user start a new game or quit
     */
    void gameOver();

    /**
     * @brief Reveals the cell at the given coordinates.
     *
     * @param x == x coordinate of the cell
     * @param y == y coordinate of the cell
     */
    void revealInputDialog(int &x, int &y) const;

    /**
     * @brief Flags or unflags the cell at the given coordinates.
     *
     * @param x == x coordinate of the cell
     * @param y == y coordinate of the cell
     */
    void placeFlagDialog(int &x, int &y);


    /**
     * @return  the current state of the game
     */
    GameState getGameState() const;

    /**
     * @return the current board
     */
    Board* getCurrentBoard() const;


    /**
     * @brief Sets the current board to the given board.
     *
     * @param uniquePtr - unique pointer to the board
     */
    void setCurrentBoard(unique_ptr<Board> &&uniquePtr);
};


#endif //MINESWEEPER_GAMEMANAGER_H
