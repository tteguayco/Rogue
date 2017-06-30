#include "gamecontroller.hpp"

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

GameController::GameController(Dungeon* aDungeon)
{
    dungeon_ = aDungeon;
}

GameController::~GameController()
{
    dungeon_ = NULL;
}

void GameController::moveHeroUp()
{
    dungeon_->moveHeroToCell(dungeon_->getHero()->getRow() - 1,
        dungeon_->getHero()->getCol());
}

void GameController::moveHeroDown()
{
    dungeon_->moveHeroToCell(dungeon_->getHero()->getRow() + 1,
        dungeon_->getHero()->getCol());
}

void GameController::moveHeroToLeft()
{
    dungeon_->moveHeroToCell(dungeon_->getHero()->getRow(),
        dungeon_->getHero()->getCol() - 1);
}

void GameController::moveHeroToRight()
{
    dungeon_->moveHeroToCell(dungeon_->getHero()->getRow(),
        dungeon_->getHero()->getCol() + 1);
}

void GameController::runGame()
{
    char keyPressed;

    dungeon_->generateMapRandomly();
    while (true) {
        std::system("clear");
        dungeon_->print();

        std::cout << "Lives: " << dungeon_->getHero()->getNumberOfLives()
            << std::endl;

        if (dungeon_->getHero()->isDead()) {
            std::cout << EATEN_BY_MONSTER_MESSAGE << std::endl;
            break;
        }
        else if (dungeon_->getHero()->hasWon()) {
            std::cout << VICTORY_MESSAGE << std::endl;
            break;
        }
        else if (dungeon_->getHero()->hasAmulet()) {
            std::cout << AMULET_GOTTEN_MESSAGE << std::endl;
        }

        keyPressed = getch();
        switch (keyPressed) {
            case MOVE_UP_KEY:     moveHeroUp();       break;
            case MOVE_LEFT_KEY:   moveHeroToLeft();   break;
            case MOVE_DOWN_KEY:   moveHeroDown();     break;
            case MOVE_RIGHT_KEY:  moveHeroToRight();  break;
        }

        //dungeon_->moveMonstersToRandomPosition();
    }
}
