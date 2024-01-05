cmake_minimum_required(VERSION 3.16)
project(minesweeper)

set(CMAKE_CXX_STANDARD 17)

set(core-files
        Game/Model/GameManager.h
        Game/Model/Board.cpp
        Game/Model/GameManager.cpp
)

add_executable(minesweeper
        Game/main.cpp
        ${core-files}
)


add_executable(minesweeperTests
        tests/tests-main.cpp
        tests/test1.cpp
        ${core-files}
)
