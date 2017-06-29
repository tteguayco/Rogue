#include "dungeon.hpp"

#include <cstdio>
#include <termios.h>
#include <unistd.h>

class GameController {
private:
    Dungeon* dungeon_;

public:
    GameController(Dungeon* aDungeon);
    ~GameController();
    void runGame(void);

private:
    void moveHeroUp(void);
    void moveHeroDown(void);
    void moveHeroToLeft(void);
    void moveHeroToRight(void);
};
