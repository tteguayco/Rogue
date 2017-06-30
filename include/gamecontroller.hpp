#include "dungeon.hpp"

#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <string>

const char MOVE_UP_KEY = 'i';
const char MOVE_DOWN_KEY = 'k';
const char MOVE_LEFT_KEY = 'j';
const char MOVE_RIGHT_KEY = 'l';

const std::string GAME_TITLE = "ROGUELIKE";
const std::string VICTORY_MESSAGE = "Well done! You have won.";
const std::string EATEN_BY_MONSTER_MESSAGE
    = "You have been eaten by a monster! Try again...";
const std::string AMULET_GOTTEN_MESSAGE
    = "You got the amulet! Return to the access point (X)";

class GameController {
private:
    Dungeon* dungeon_;

public:
    GameController(Dungeon* aDungeon);
    ~GameController();
    void runGame(void);

private:
    bool moveHeroUp(void);
    bool moveHeroDown(void);
    bool moveHeroToLeft(void);
    bool moveHeroToRight(void);
};
