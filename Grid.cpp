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
void Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    if (horizontal)
    {
        int i = col;
        for (; i < shipSize; i++)
        {
            if (cells[row][i] != '~' || !isBounds(row, i))
            {
                std::cout << "cant place ship there!" << std::endl;
                break;
            }
            cells[row][i] = symbol;
        }
        if (col - i - 1 != shipSize)
        {
            for (int j = i; i != col; i--)
            {
                cells[row][j] = '~';
            }
            return;
        }
    }
    else // horizontal == false
    {
        int i = row;
        for (; i < shipSize; i++)
        {
            if (cells[i][col] != '~' || !isBounds(i, col))
            {
                std::cout << "cant place ship there!" << std::endl;
                break;
            }
            cells[i][col] = symbol;
        }
        if (row - i - 1 != shipSize)
        {
            for (int j = i; i != row; j--)
            {
                cells[j][col] = '~';
            }
            return;
        }
    }
}

void Grid::markHit(int row, int col)
{
    if (getCell(row, col) == 'S')
        cells[row][col] = 'X';
}

void Grid::markMiss(int row, int col)
{
    if (getCell(row, col) != 'S')
        cells[row][col] = 'M';
}

char Grid::getCell(int row, int col) const
{
    return cells[row][col];
}

void printGrid() // TODO
{
}