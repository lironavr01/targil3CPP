#include <iostream>
#include "Ship.h"
#include "Grid.h"

class Player
{
protected:
    std::string playerName;
    Ship *ships[5];
    Grid grid;

public:
    Player(const std::string &name);
    virtual ~Player();
    virtual void placeAllShips();
    virtual void makeMove(Player *opponent);
    virtual Grid &getGrid();
    virtual std::string getName();
    bool allShipsSunk() const;
    void displayGrid();
    void checkShipHit(int row, int col);
};

class HumanPlayer : public Player
{
public:
    HumanPlayer(const std::string &name);
    ~HumanPlayer();
    void placeAllShips() override;
    void makeMove(Player *opponent) override;
};

class AiPlayer : public Player
{
public:
    AiPlayer(const std::string &name);
    ~AiPlayer();
    void placeAllShips() override;
    void makeMove(Player *opponent) override;
    int getRandomCoordinate();
};