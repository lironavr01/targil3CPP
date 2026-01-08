#include "Ship.h"
#include "string"
Ship::Ship(const std::string shipName, int shipSize) : name(shipName), size(shipSize), hitTaken(0) {}
Ship::~Ship() {}
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