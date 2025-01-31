#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Renderer.h"

enum class GameState {
    PAUSED,
    SIMULATING
};

class Game {
public:
    Game(unsigned int width, unsigned int height, float cellSize);
    void run();

private:
    Grid grid;
    Renderer renderer;
    GameState currentState;

    void handleInput();
    void update();
};

#endif // GAME_H
