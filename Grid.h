#include <iostream>

class Grid
{
private:
    char cells[10][10];

public:
    Grid();
    bool isTileOccupied(int row, int col) const;
    bool isBounds(int row, int col) const;
    void placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
    void markHit(int row, int col);  // X
    void markMiss(int row, int col); // M
    char getCell(int row, int col) const;
    void printGrid();
};