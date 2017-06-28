#include "dungeon.hpp"

Dungeon::Dungeon():
    numberOfRows_(0),
    numberOfCols_(0),
    accessPointRow_(0),
    accessPointCol_(0),
    amuletRow_(0),
    amuletCol_(0)
{}

Dungeon::Dungeon(int nrows, int ncols):
    numberOfRows_(nrows),
    numberOfCols_(ncols),
    accessPointRow_(0),
    accessPointCol_(0),
    amuletRow_(0),
    amuletCol_(0)
{
    initializeMap();
}

void Dungeon::initializeMap()
{
    // initialize map
    mapElements_ = new char*[numberOfRows_];
    for (unsigned i = 0; i < numberOfRows_; i++) {
      mapElements_[i] = new char [numberOfCols_];
    }
}

Dungeon::~Dungeon()
{

}

void Dungeon::generateRandomly()
{
    
}
