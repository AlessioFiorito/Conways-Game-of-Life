cmake_minimum_required(VERSION 3.29)
project(Conway_s_Game_of_Life)

set(CMAKE_CXX_STANDARD 20)

add_executable(Conway_s_Game_of_Life src/main.cpp
        src/Grid.cpp
        include/Grid.h
        src/Cell.cpp
        include/Cell.h
        src/Game.cpp
        include/Game.h
        src/Renderer.cpp
        include/Renderer.h)
