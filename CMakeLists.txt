cmake_minimum_required(VERSION 3.14)
project(Pacman)

set(CMAKE_CXX_STANDARD 14)

SET(LINK_FLAGS    "-lncurses")
#add linker flags
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${LINK_FLAGS}")

add_executable(Pacman main.cpp Pacman.cpp Pacman.hpp Food.cpp Food.hpp Ghost.cpp Ghost.hpp Object.cpp Object.hpp)