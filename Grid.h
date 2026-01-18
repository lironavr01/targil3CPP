// name: liron avramov
// ID: 322875287
#include <iostream>

class Grid
{
private:
    char cells[10][10];
    // empty: '~' ship: 'S' hit: 'X' miss: 'M'

public:
    Grid();
    bool isTileOccupied(int row, int col) const;
    bool isBounds(int row, int col) const;
    bool placeShip(int row, int col, int shipSize, bool horizontal, char symbol);
    void markHit(int row, int col);  // X
    void markMiss(int row, int col); // M
    char getCell(int row, int col) const;
    bool canPlace(int row, int col, int shipSize, bool horizontal);
    void printSelfGrid();
    void printAiGrid();
};