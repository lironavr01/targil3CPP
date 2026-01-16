#include <iostream>
#include "Player.h"

class Game
{
private:
    Player *player1;
    Player *player2;

public:
    Game(Player *player1, Player *player2);
    ~Game();
    void setup();
    void start();
    bool isGameOver() const;
};