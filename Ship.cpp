// name: liron avramov
// ID: 322875287
#include "Ship.h"
#include "string"
Ship::Ship(const std::string &shipName, int shipSize) : name(shipName), size(shipSize), hitTaken(0) {}
Ship::~Ship() {}

std::string Ship::getName() { return name; }

int Ship::getSize() { return size; }

void Ship::takeHit()
{
    hitTaken++;
    std::cout << name << " got hit!" << std::endl;
    if (isSunk())
        std::cout << name << " has sunk!" << std::endl;
}
bool Ship::isSunk() const
{
    return hitTaken >= size;
}

void Ship::setPos(int row, int col, bool horizontal)
{
    startRow = row;
    startCol = col;
    isHorizontal = horizontal;
}

bool Ship::isOnCoordinate(int r, int c)
{
    if (isHorizontal)
        return (r == startRow && c >= startCol && c < startCol + size);
    else
        return (c == startCol && r >= startRow && r < startRow + size);
}

Carrier::Carrier() : Ship("Carrier", 5) {}

BattleShip::BattleShip() : Ship("BattleShip", 4) {}

Cruiser::Cruiser() : Ship("Cruiser", 3) {}

Submarine::Submarine() : Ship("Submarine", 3) {}

Destroyer::Destroyer() : Ship("Destoryer", 2) {}

Carrier::~Carrier() {}
BattleShip::~BattleShip() {}
Cruiser::~Cruiser() {}
Submarine::~Submarine() {}
Destroyer::~Destroyer() {}