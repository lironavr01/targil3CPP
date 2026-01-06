#include <iostream>
class Ship
{
private:
    std::string name;
    int size;
    int hitTaken;

public:
    Ship(const std::string shipName, int shipSize);
    virtual ~Ship();
    virtual void takeHit();
    bool isSunk() const;
};