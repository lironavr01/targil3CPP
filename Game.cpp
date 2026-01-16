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
    int moveCounter = 1;
    while (isGameOver())
    {
        std::cout << "Turn number " << moveCounter++ << std::endl;
        player1->displayGrid();
        player2->displayGrid();
        player1->makeMove(player2);
        player2->makeMove(player1);
    }
}

bool Game::isGameOver() const
{
    return player1->allShipsSunk() || player2->allShipsSunk();
}