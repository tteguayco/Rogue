#include "gamecontroller.hpp"

#include <iostream>

int main(void)
{
    srand(time(NULL));
    Dungeon dungeon(20, 30);
    GameController gameController(&dungeon);

    // Let's start!
    gameController.runGame();

    return 0;
}
