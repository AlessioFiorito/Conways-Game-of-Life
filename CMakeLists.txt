cmake_minimum_required(VERSION 3.29)
project(Conway_s_Game_of_Life)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(raylib REQUIRED)

add_executable(Conway_s_Game_of_Life
        src/main.cpp
        src/Grid.cpp
        src/Cell.cpp
        src/Game.cpp
        src/Renderer.cpp
)

target_link_libraries(Conway_s_Game_of_Life raylib)
