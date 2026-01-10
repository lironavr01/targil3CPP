#include <iostream>
class Ship
{
protected:
    std::string name;
    int size;
    int hitTaken;

public:
    Ship(const std::string shipName, int shipSize);
    virtual ~Ship();
    virtual void takeHit();
    bool isSunk() const;
};

class Carrier : Ship
{
public:
    Carrier();
    ~Carrier();
};

class BattleShip : Ship
{
public:
    BattleShip();
    ~BattleShip();
};

class Cruiser : Ship
{
public:
    Cruiser();
    ~Cruiser();
};

class Submarine : Ship
{
public:
    Submarine();
    ~Submarine();
};

class Destroyer : Ship
{
public:
    Destroyer();
    ~Destroyer();
};