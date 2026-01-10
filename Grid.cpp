#include "Grid.h"

Grid::Grid()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cells[i][j] = '~';
        }
    }
}

bool Grid::isTileOccupied(int row, int col) const
{
    return cells[row][col] == 'S';
}

bool Grid::isBounds(int row, int col) const
{
    bool isRow = (row > 0) || (row < 10);
    bool isCol = (col > 0) || (col < 10);
    return row && col;
}
void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
// TODO