#include <iostream>
class Ship
{
protected:
    std::string name;
    int size;
    int hitTaken;

public:
    Ship(const std::string &shipName, int shipSize);
    virtual ~Ship();
    int getSize();
    std::string getName();
    virtual void takeHit();
    bool isSunk() const;
};

class Carrier : public Ship
{
public:
    Carrier();
    ~Carrier();
};

class BattleShip : public Ship
{
public:
    BattleShip();
    ~BattleShip();
};

class Cruiser : public Ship
{
public:
    Cruiser();
    ~Cruiser();
};

class Submarine : public Ship
{
public:
    Submarine();
    ~Submarine();
};

class Destroyer : public Ship
{
public:
    Destroyer();
    ~Destroyer();
};