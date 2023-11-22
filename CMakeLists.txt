cmake_minimum_required(VERSION 3.26)
project(pcc_semestralka)

set(CMAKE_CXX_STANDARD 23)





add_executable(pcc_semestralka main.cpp
        Game/Threads/outputThread.h
        Game/Threads/outputThread.cpp
        Game/Threads/computeThread.h
        Game/Threads/computeThread.cpp
        Game/Threads/inputThread.cpp
    Game/Threads/inputThread.h
)




