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
            std::cout << "Where do you want to place the " << ships[i]->getName() << "  (input: row col): " << std::endl;
            std::cin >> newRow >> newCol;
            std::cout << "Place horizontal? (answer y/n): " << std::endl;
            std::cin >> tmpAns;
            horizontal = tmpAns == 'y' ? true : false;
            grid.placeShip(newRow, newCol, shipSize, horizontal, 'S');
        } while (grid.canPlace(newRow, newCol, shipSize, horizontal));
    }
}

Grid Player::getGrid()
{
    return grid;
}

void HumanPlayer::makeMove(Player *opponent) // TODO : verify good input
{
    int row, col;
    std::cout << "Choose row and col to attack (input: row col): " << std::endl;
    std::cin >> row >> col;
    char posSign = opponent->getGrid().getCell(row, col);
    if (posSign == 'S')
    {
        opponent->getGrid().markHit(row, col);
        std::cout << "You hit a ship!" << std::endl;
    }
    else if (posSign == '~')
    {
        opponent->getGrid().markMiss(row, col);
        std::cout << "You missed!" << std::endl;
    }
}

int AiPlayer::getRandomCoordinate()
{
    return std::rand() % 10;
}

void AiPlayer::placeAllShips()
{
    for (int i = 0; i < 5; i++)
    {
        int row, col;
        bool horizontal = false;
        int shipSize = ships[i]->getSize();
        do
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            horizontal = !horizontal;
            grid.placeShip(row, col, shipSize, horizontal, 'S');
        } while (grid.canPlace(row, col, shipSize, horizontal));
    }
}

void AiPlayer::makeMove(Player *opponent)
{
    int row, col;
    row = getRandomCoordinate();
    col = getRandomCoordinate();
    char posSign = opponent->getGrid().getCell(row, col);
    if (posSign == 'S')
    {
        opponent->getGrid().markHit(row, col);
        std::cout << "Your ship got hit!" << std::endl;
    }
    else if (posSign == '~')
    {
        opponent->getGrid().markMiss(row, col);
        std::cout << "Opp missed You!" << std::endl;
    }
}