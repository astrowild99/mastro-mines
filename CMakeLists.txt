cmake_minimum_required(VERSION 3.15)
project(Mines)

set(CMAKE_CXX_STANDARD 14)

# Set the minimum version of cmake required to build this project
cmake_minimum_required(VERSION 2.6)
# Use the package PkgConfig to detect GTK+ headers/library files
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
# Add other flags to the compiler
add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(Mines main.cpp src/Field.cpp src/Field.h src/Box.cpp src/Box.h src/Coordinates.cpp src/Coordinates.h src/GUI/GraphicUserInterface.cpp src/GUI/GraphicUserInterface.h src/Player.cpp src/Player.h src/CLI/CommandLineInterface.cpp src/CLI/CommandLineInterface.h src/GameInterface.cpp src/GameInterface.h)

# Link the target to the GTK+ libraries
target_link_libraries(Mines ${GTK3_LIBRARIES})