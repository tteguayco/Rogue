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
    dungeon_->generateMapRandomly();
    //dungeon_->print();

    char keyPressed;
    while (true) {

        system("cls");
        dungeon_->print();

        if (dungeon_->getHero()->hasWon()) {
            std::cout << "\nWell done! You have won." << std::endl;
            break;
        }
        else if (dungeon_->getHero()->hasAmulet()) {
            std::cout << "\nYou got the amulet! Return to the access point (X)"
                << std::endl;
        }

        std::cout << "Lives: " << dungeon_->getHero()->getNumberOfLives()
            << std::endl;

        keyPressed = getch();
        switch (keyPressed) {
            case 'i': moveHeroUp();       break;
            case 'j': moveHeroToLeft();   break;
            case 'k': moveHeroDown();     break;
            case 'l': moveHeroToRight();  break;
        }
    }
}
