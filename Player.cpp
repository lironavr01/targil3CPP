// name: liron avramov
// ID: 322875287
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
    for (int i = 0; i < 5; i++)
    {
        delete ships[i];
    }
}

void Player::placeAllShips() {}
void Player::makeMove(Player *opponent) {}

std::string Player::getName()
{
    return playerName;
}

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
    grid.printSelfGrid();
}

Grid &Player::getGrid()
{
    return grid;
}

void Player::checkShipHit(int row, int col)
{
    for (int i = 0; i < 5; i++)
    {
        if (ships[i]->isOnCoordinate(row, col))
        {
            ships[i]->takeHit();
            return;
        }
    }
}

// ---------------- HumanPlayer ----------------

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

        bool placed = false;

        while (!placed)
        {
            std::cout << "Where do you want to place the " << ships[i]->getName()
                      << " (size " << shipSize << ")? (input: row col): " << std::endl;

            if (!(std::cin >> newRow >> newCol))
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Invalid input. Please enter numbers." << std::endl;
                continue;
            }

            std::cout << "Place horizontal? (y/n): " << std::endl;
            std::cin >> tmpAns;
            horizontal = (tmpAns == 'y' || tmpAns == 'Y');

            if (grid.placeShip(newRow, newCol, shipSize, horizontal, 'S'))
            {
                placed = true;
                ships[i]->setPos(newRow, newCol, horizontal);
                std::cout << "Placed successfully!" << std::endl;
                grid.printSelfGrid();
            }
            else
            {
                std::cout << "Invalid placement! Out of bounds or overlapping. Try again." << std::endl;
            }
        }
    }
}

void HumanPlayer::makeMove(Player *opponent)
{
    int row, col;
    bool validMove = false;

    while (!validMove)
    {
        std::cout << "Choose row and col to attack (input: row col): " << std::endl;
        if (!(std::cin >> row >> col))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input. Try again." << std::endl;
            continue;
        }

        if (row < 0 || row >= 10 || col < 0 || col >= 10)
        {
            std::cout << "Out of bounds! Try again." << std::endl;
            continue;
        }

        char currentCell = opponent->getGrid().getCell(row, col);

        if (currentCell == 'X' || currentCell == 'M')
        {
            std::cout << "You already attacked this spot! Choose another." << std::endl;
        }
        else
        {
            validMove = true;
        }
    }

    char posSign = opponent->getGrid().getCell(row, col);
    if (posSign == 'S')
    {
        opponent->getGrid().markHit(row, col);
        opponent->checkShipHit(row, col);
        std::cout << "You hit a ship!" << std::endl;
    }
    else if (posSign == '~')
    {
        opponent->getGrid().markMiss(row, col);
        std::cout << "You missed!" << std::endl;
    }
}

// ---------------- AiPlayer ----------------

AiPlayer::AiPlayer(const std::string &name) : Player(name) {}
AiPlayer::~AiPlayer() {}

int AiPlayer::getRandomCoordinate()
{
    return std::rand() % 10;
}

void AiPlayer::placeAllShips()
{
    for (int i = 0; i < 5; i++)
    {
        int row, col;
        bool horizontal;
        int shipSize = ships[i]->getSize();

        bool placed = false;

        while (!placed)
        {
            row = getRandomCoordinate();
            col = getRandomCoordinate();
            horizontal = std::rand() % 2;

            if (grid.placeShip(row, col, shipSize, horizontal, 'S'))
            {
                placed = true;
                ships[i]->setPos(row, col, horizontal);
            }
        }
    }
    std::cout << "AI has placed all ships." << std::endl;
}

void AiPlayer::makeMove(Player *opponent)
{
    int row, col;
    bool validMove = false;

    while (!validMove)
    {
        row = getRandomCoordinate();
        col = getRandomCoordinate();

        char cell = opponent->getGrid().getCell(row, col);
        if (cell != 'X' && cell != 'M')
        {
            validMove = true;
            opponent->checkShipHit(row, col);
        }
    }

    std::cout << "AI attacks " << row << " " << col << std::endl;

    char posSign = opponent->getGrid().getCell(row, col);
    if (posSign == 'S')
    {
        opponent->getGrid().markHit(row, col);
        std::cout << "Your ship got hit!" << std::endl;
    }
    else if (posSign == '~')
    {
        opponent->getGrid().markMiss(row, col);
        std::cout << "AI missed!" << std::endl;
    }
}