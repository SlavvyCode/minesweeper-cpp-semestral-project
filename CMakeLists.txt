cmake_minimum_required(VERSION 3.26)
project(MinesweeperPCC)

set(CMAKE_CXX_STANDARD 23)

add_executable(MinesweeperPCC main.cpp
        Game/Threads/inputThread.cpp
)
