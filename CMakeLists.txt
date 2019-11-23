cmake_minimum_required(VERSION 3.15)
project(Mines)

set(CMAKE_CXX_STANDARD 14)

add_executable(Mines main.cpp src/Field.cpp src/Field.h src/Box.cpp src/Box.h src/Coordinates.cpp src/Coordinates.h src/GUI/GraphicUserInterface.cpp src/GUI/GraphicUserInterface.h)