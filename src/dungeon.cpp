#include "dungeon.hpp"

void Dungeon::initializeMap()
{
    mapElements_ = new Cell*[numberOfRows_];
    for (unsigned i = 0; i < numberOfRows_; i++) {
      mapElements_[i] = new Cell[numberOfCols_];

      for (unsigned j = 0; j < numberOfCols_; j++) {
        mapElements_[i][j] = Disabled;
      }
    }
}

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

Dungeon::~Dungeon()
{
    for (unsigned i = 0; i < numberOfRows_; i++) {
        delete [] mapElements_[i];
    }
    delete [] mapElements_;
}

void Dungeon::generateMapRandomly()
{
    const int roomOneWidth = numberOfCols_ / 2;
    const int roomTwoWidth = numberOfCols_ - roomOneWidth + ROOM_CELL_MARGIN;

    const int roomOneAndTwoHeight = numberOfRows_ / 2 - ROOM_CELL_MARGIN;

    // Room 1
    buildRoom(0, roomOneAndTwoHeight, 0, roomOneWidth);

    // Room 2
    buildRoom(0, roomOneAndTwoHeight,
      roomOneWidth + ROOM_CELL_MARGIN,
      numberOfCols_);

    // Room 3
    buildRoom(roomOneAndTwoHeight + ROOM_CELL_MARGIN,
      numberOfRows_, 0, roomOneWidth);
}

void Dungeon::buildRoom(int topLimit, int bottomLimit, int leftLimit, int rightLimit)
{
  for (int i = topLimit; i < bottomLimit; i++) {
      for (int j = leftLimit; j < rightLimit; j++) {
          // Top wall
          if (i == topLimit) {
              mapElements_[i][j] = Wall;
          }

          // Left wall
          else if (j == leftLimit) {
              mapElements_[i][j] = Wall;
          }

          // Bottom wall
          else if (i == bottomLimit - 1) {
              mapElements_[i][j] = Wall;
          }

          // Right wall
          else if (j == rightLimit - 1) {
              mapElements_[i][j] = Wall;
          }
      }
  }
}

void Dungeon::print()
{
    for (unsigned i = 0; i < numberOfRows_; i++) {
        for (unsigned j = 0; j < numberOfCols_; j++) {
            switch (mapElements_[i][j]) {
                case Disabled:    std::cout << DISABLED_CHAR;       break;
                case Wall:        std::cout << WALL_CHAR;           break;
                case Door:        std::cout << DOOR_CHAR;           break;
                case Corridor:    std::cout << CORRIDOR_CHAR;       break;
                case AccessPoint: std::cout << ACCESS_POINT_CHAR;   break;
                case Hero:        std::cout << HERO_CHAR;           break;
                case Amulet:      std::cout << AMULET_CHAR;         break;
                case Monster:     std::cout << MONSTER_CHAR;        break;
            }
        }
        std::cout << std::endl;
    }
}
