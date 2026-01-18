// name: liron avramov
// ID: 322875287

#include "Game.h"

Game::Game(Player *player1, Player *player2) : player1(player1), player2(player2) {}

void Game::setup()
{
    player1->placeAllShips();
    player2->placeAllShips();
}

Game::~Game() {}

void Game::start()
{
    int turn = 1;
    while (!isGameOver())
    {
        std::cout << "\n--- Turn " << turn++ << " ---" << std::endl;

        // תור שחקן 1
        std::cout << "\n"
                  << player1->getName() << "'s Board:" << std::endl;
        player1->displayGrid();

        std::cout << "Opponent's Board (Hidden):" << std::endl;
        player2->getGrid().printAiGrid();

        player1->makeMove(player2);
        if (player2->allShipsSunk())
            break;

        // תור שחקן 2
        std::cout << "\n--- " << player2->getName() << "'s Move ---" << std::endl;
        player2->makeMove(player1);
        if (player1->allShipsSunk())
            break;
    }

    // הכרזת מנצח
    std::string winnerName = player1->allShipsSunk() ? player2->getName() : player1->getName();
    std::cout << "\n*** GAME OVER - " << winnerName << " WINS! ***" << std::endl;
}

bool Game::isGameOver() const
{
    return player1->allShipsSunk() || player2->allShipsSunk();
}