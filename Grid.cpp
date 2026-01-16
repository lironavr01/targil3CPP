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
    return (row >= 0 && row < 10) && (col >= 0 && col < 10);
}

bool Grid::canPlace(int row, int col, int shipSize, bool horizontal)
{
    if (horizontal)
    {
        for (int i = col; i < col + shipSize; i++)
        {
            if (cells[row][i] != '~' || !isBounds(row, i))
                return false;
        }
        return true;
    }
    else // horizontal == false
    {
        for (int i = row; i < row + shipSize; i++)
        {
            if (cells[i][col] != '~' || !isBounds(i, col))
                return false;
        }
        return true;
    }
}

// שנה את הסוג ל-bool
bool Grid::placeShip(int row, int col, int shipSize, bool horizontal, char symbol)
{
    if (canPlace(row, col, shipSize, horizontal))
    {
        if (horizontal)
        {
            for (int i = col; i < col + shipSize; i++) // שים לב לתיקון הלולאה
            {
                cells[row][i] = symbol;
            }
        }
        else // vertical
        {
            for (int i = row; i < row + shipSize; i++) // שים לב לתיקון הלולאה
            {
                cells[i][col] = symbol;
            }
        }
        return true; // ההצבה הצליחה!
    }

    return false; // ההצבה נכשלה (ואל תדפיס כאן כלום)
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

void Grid::printSelfGrid()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < 10; j++)
        {
            std::cout << cells[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

void Grid::printAiGrid()
{
    for (int i = 0; i < 10; i++)
    {
        std::cout << "| ";
        for (int j = 0; j < 10; j++)
        {
            if (cells[i][j] == 'S') // make sure dont print the ships of opp
                std::cout << '~' << " | ";
            else
                std::cout << cells[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}