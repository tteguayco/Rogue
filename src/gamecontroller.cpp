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

bool GameController::moveHeroUp()
{
    return dungeon_->moveHeroToCell(dungeon_->getHero()->getRow() - 1,
        dungeon_->getHero()->getCol());
}

bool GameController::moveHeroDown()
{
    return dungeon_->moveHeroToCell(dungeon_->getHero()->getRow() + 1,
        dungeon_->getHero()->getCol());
}

bool GameController::moveHeroToLeft()
{
    return dungeon_->moveHeroToCell(dungeon_->getHero()->getRow(),
        dungeon_->getHero()->getCol() - 1);
}

bool GameController::moveHeroToRight()
{
    return dungeon_->moveHeroToCell(dungeon_->getHero()->getRow(),
        dungeon_->getHero()->getCol() + 1);
}

void GameController::runGame()
{
    char keyPressed;
    bool heroMoves;

    dungeon_->generateMapRandomly();
    while (true) {
        std::system("clear");
        std::cout << GAME_TITLE << std::endl << std::endl;
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
            case MOVE_UP_KEY:     heroMoves = moveHeroUp();       break;
            case MOVE_LEFT_KEY:   heroMoves = moveHeroToLeft();   break;
            case MOVE_DOWN_KEY:   heroMoves = moveHeroDown();     break;
            case MOVE_RIGHT_KEY:  heroMoves = moveHeroToRight();  break;
            default:              heroMoves = false;
        }

        if (heroMoves) {
            dungeon_->moveMonstersToRandomPosition();
        }
    }
}
