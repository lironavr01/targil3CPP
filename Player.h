#include <iostream>
#include "Ship.h"
#include "Grid.h"
#include "Player.h"

class Player
{
private:
    std::string *playerName;
    Ship *ships[5];
    Grid grid;

public:
    Player();
    virtual ~Player();
    virtual void placeAllShips();
    virtual void makeMove(Player *opponent);
    bool allShipsSunk() const;
    void displayGrid();
};