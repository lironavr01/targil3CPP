#include "Game.h"

int main()
{
    std::srand(std::time(nullptr));
    std::string name;
    std::cout << "Enter your name: " << std::endl;
    std::getline(std::cin, name);
    HumanPlayer p1(name);
    AiPlayer Ai("PC");
    Game game(&p1, &Ai);
    game.setup();
    game.start();
}