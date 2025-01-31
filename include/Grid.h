#ifndef GRID_H
#define GRID_H

#include <vector>


class Grid {
public:
    //constructor
    Grid(unsigned int width, unsigned int height, unsigned int cellSize) : m_gridWidth(width), m_gridHeight(height),
    m_cellSize(cellSize), grid(height, std::vector<bool>(width, false)) {}

    bool isValidPosition(int x, int y) const;
    bool isCellAlive(int x, int y) const;
    unsigned int countLivingNeighbors(int x, int y) const;
    void switchCellState(int x, int y);
    void updateGrid();
    void setCellAlive(int x, int y);
    unsigned int getGridWidth() const { return m_gridWidth; }
    unsigned int getGridHeight() const { return m_gridHeight; }
    unsigned int getCellSize() const { return m_cellSize; }


private:
    std::vector<std::vector<bool>> grid;
    unsigned int m_gridWidth;
    unsigned int m_gridHeight;
    unsigned int m_cellSize;
};



#endif //GRID_H
