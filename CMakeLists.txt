cmake_minimum_required(VERSION 3.26)
project(minesweeper)

set(CMAKE_CXX_STANDARD 23)

# Add the submodule directory to the project
add_subdirectory(cpp-terminal)

set(core-files
        Game/Model/Board.cpp
        Game/Model/GameManager.cpp
        Game/Model/GameManager.h
        Game/Model/GameManager.h
        Game/Model/GameManager.h
)

add_executable(minesweeper main.cpp
        ${core-files}
)


target_include_directories(minesweeper PRIVATE cpp-terminal/cpp-terminal/)

# Include the library's headers
include_directories(cpp-terminal/)


# Link against the library
target_link_libraries(minesweeper PRIVATE cpp-terminal)

#add_executable(cppterminaltest cppterminaltest.cpp)
#target_link_libraries(cppterminaltest PRIVATE cpp-terminal)


add_executable(minesweeperTests tests/tests-main.cpp
        tests/test1.cpp
        ${core-files}

)
