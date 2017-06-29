#include "hero.hpp"

Hero::Hero(unsigned initialRow, unsigned initialCol):
    currentRow_(initialRow),
    currentCol_(initialCol),
    numOfLives_(DEFAULT_NUMBER_OF_LIVES),
    hasAmulet_(false),
    hasWon_(false)
{}

Hero::~Hero()
{
    currentRow_ = 0;
    currentCol_ = 0;
    numOfLives_ = 0;
    hasAmulet_ = false;
}

unsigned Hero::getRow()
{
    return currentRow_;
}

unsigned Hero::getCol()
{
    return currentCol_;
}

bool Hero::hasAmulet()
{
    return hasAmulet_;
}

void Hero::takeAmulet()
{
    hasAmulet_ = true;
}

void Hero::setRow(unsigned newRow)
{
    currentRow_ = newRow;
}

void Hero::setCol(unsigned newCol)
{
    currentCol_ = newCol;
}

bool Hero::hasWon()
{
    return hasWon_;
}

void Hero::markAsWinner()
{
    hasWon_ = true;
}

void Hero::decreaseLife()
{
    if (!isDead()) {
        numOfLives_--;
    }
}

bool Hero::isDead(void)
{
    if (numOfLives_ <= 0) {
        return true;
    } else {
        return false;
    }
}

unsigned Hero::getNumberOfLives()
{
    return numOfLives_;
}

void Hero::moveUp()
{
    if (currentRow_ > 0) {
        currentRow_--;
    }
}

void Hero::moveDown()
{
    currentRow_++;
}

void Hero::moveToLeft()
{
    if (currentCol_ > 0) {
        currentCol_--;
    }
}

void Hero::moveToRight()
{
    currentCol_++;
}
