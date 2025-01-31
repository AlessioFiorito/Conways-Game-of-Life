#include "Renderer.h"
#include <raylib.h>

Renderer::Renderer(unsigned int width, unsigned int height, float cellSize) : m_windowWidth(width), m_windowHeight(height),
m_cellSize(cellSize) {
    InitWindow(m_windowHeight, m_windowWidth, "Game of Life");
    SetTargetFPS(10);
}

void Renderer::render(const Grid& grid) const {
    BeginDrawing();
    ClearBackground(BLACK);

    int gridWidth = grid.getGridWidth();
    int gridHeight = grid.getGridHeight();

    for (int y = 0; y < gridHeight; ++y) {
        for (int x = 0; x < gridWidth; ++x) {
            Rectangle cell = { x * m_cellSize, y * m_cellSize, m_cellSize, m_cellSize };

            if (grid.isCellAlive(x, y)) {
                DrawRectangleRec(cell, BLACK);
            } else {
                DrawRectangleRec(cell, WHITE);
                DrawRectangleLinesEx(cell, 1, GRAY);
            }
        }
    }

    EndDrawing();
}


