#include "Game.h"
#include "raylib.h"

Game::Game(unsigned int width, unsigned int height, float cellSize)
    : grid(width, height, cellSize), renderer(width * cellSize, height * cellSize, cellSize), currentState(GameState::PAUSED) {
}

void Game::run() {
    while (!WindowShouldClose()) {
        handleInput();
        update();
        renderer.render(grid);
    }
}

void Game::handleInput() {
    if (IsKeyPressed(KEY_SPACE)) {
        currentState = (currentState == GameState::PAUSED) ? GameState::SIMULATING : GameState::PAUSED;
    }

    if (currentState == GameState::PAUSED && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        Vector2 mousePosition = GetMousePosition();
        float cellX = mousePosition.x / grid.getCellSize();
        float cellY = mousePosition.y / grid.getCellSize();
        grid.setCellAlive(cellX, cellY);
    }
}

void Game::update() {
    if (currentState == GameState::SIMULATING) {
        grid.updateGrid();
    }
}
