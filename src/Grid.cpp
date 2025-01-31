#include "Grid.h"
#include <vector>

bool Grid::isValidPosition(int x, int y) const {
    return (x >= 0 && x < m_gridWidth && y >= 0 && y < m_gridHeight);
}

bool Grid::isCellAlive(int x, int y) const {
    return grid[y][x];
}

unsigned int Grid::countLivingNeighbors(int x, int y) const {
    unsigned int livingNeighbors = 0;

    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;

            if (isValidPosition(x + i, y + j) && grid[y + j][x + i]) {
                ++livingNeighbors;
            }
        }
    }

    return livingNeighbors;
}

void Grid::switchCellState(int x, int y) {
    if (isValidPosition(x, y)) {
        grid[y][x] = !grid[y][x];
    }
}

void Grid::setCellAlive(int x, int y) {
    if (isValidPosition(x, y)) {
        grid[y][x] = true;
    }
}


void Grid::updateGrid() {
    std::vector<std::vector<bool>> tempGrid = grid;

    for (int y = 0; y < m_gridHeight; ++y) {
        for (int x = 0; x < m_gridWidth; ++x) {
            unsigned int livingNeighbors = countLivingNeighbors(x, y);

            if (grid[y][x]) {
                tempGrid[y][x] = (livingNeighbors == 2 || livingNeighbors == 3);
            } else {
                tempGrid[y][x] = (livingNeighbors == 3);
            }
        }
    }

    grid = tempGrid;
}
