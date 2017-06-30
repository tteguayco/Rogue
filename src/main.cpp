#include "gamecontroller.hpp"

#include <iostream>

const unsigned DEFAULT_NROWS = 20;
const unsigned DEFAULT_NCOLS = 30;

const unsigned MIN_NROWS = 20;
const unsigned MIN_NCOLS = 20;

int main(void)
{
    srand(time(NULL));
    Dungeon dungeon(DEFAULT_NROWS, DEFAULT_NCOLS);
    GameController gameController(&dungeon);

    // Let's start!
    gameController.runGame();

    return 0;
}
