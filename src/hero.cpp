#include "hero.hpp"

Hero::Hero():
    currentRow_(0),
    currentCol_(0),
    numOfLives_(DEFAULT_NUMBER_OF_LIVES),
    hasAmulet_(false)
{}

Hero::~Hero()
{
  currentRow_ = 0;
  currentCol_ = 0;
  numOfLives_ = 0;
  hasAmulet_ = false;
}
