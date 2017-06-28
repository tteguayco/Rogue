#include "room.hpp"

Room::Room(unsigned topLimit, unsigned bottomLimit, unsigned leftLimit,
  unsigned rightLimit):
    topLimit_(topLimit),
    bottomLimit_(bottomLimit),
    leftLimit_(leftLimit),
    rightLimit_(rightLimit)
{}

Room::~Room()
{
    topLimit_ = 0;
    bottomLimit_ = 0;
    leftLimit_ = 0;
    rightLimit_ = 0;
}

unsigned Room::getTopLimit()
{
    return topLimit_;
}

unsigned Room::getBottomLimit()
{
    return bottomLimit_;
}

unsigned Room::getLeftLimit()
{
    return leftLimit_;
}

unsigned Room::getRightLimit()
{
    return rightLimit_;
}
