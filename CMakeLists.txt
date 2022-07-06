cmake_minimum_required(VERSION 3.20)
project(pacman)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lncurses")
add_executable(pacman main.cpp Entity.cpp Entity.h main.h Pacman.cpp Pacman.h Game.cpp Game.h Ghost.cpp Ghost.h Food.cpp Food.h)
