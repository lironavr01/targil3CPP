#include "Player.h"

Player::Player(const std::string &name)
{
    playerName = name;
    ships[0] = new Carrier();
    ships[1] = new BattleShip();
    ships[2] = new Cruiser();
    ships[3] = new Submarine();
    ships[4] = new Destroyer();
}

Player::~Player()
{
    delete[] ships;
}

void Player::placeAllShips() {}

void Player::makeMove(Player *opponent) {}

bool Player::allShipsSunk() const
{
    for (int i = 0; i < 5; i++)
    {
        if (!ships[i]->isSunk())
            return false;
    }
    return true;
}

void Player::displayGrid()
{
    grid.printGrid();
}

HumanPlayer::HumanPlayer(const std::string &name) : Player(name) {}
HumanPlayer::~HumanPlayer() {}

void HumanPlayer::placeAllShips()
{
    for (int i = 0; i < 5; i++)
    {
        int newRow, newCol;
        bool horizontal;
        char tmpAns;
        int shipSize = ships[i]->getSize();
        do
        {
            std::cout << "Where do you want to place the " << ships[i]->getName() << "  (input row col)" << std::endl;
            std::cin >> newRow >> newCol;
            std::cout << "Place horizontal? (answer y/n)" << std::endl;
            std::cin >> tmpAns;
            horizontal = tmpAns == 'y' ? true : false;
            grid.placeShip(newRow, newCol, shipSize, horizontal, 'S');
        } while (grid.canPlace(newRow, newCol, shipSize, horizontal));
    }
}

void HumanPlayer::makeMove(Player *opponent) // TODO
{
}