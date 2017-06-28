#include "dungeon.hpp"

int getRandomBetween(int leftLimit, int rightLimit) {
    srand(time(NULL));
    return rand() % (rightLimit - leftLimit + 1) + leftLimit;
}

void Dungeon::initializeRooms()
{
    const int roomOneTopLimit = 0;
    const int roomOneBottomLimit = numberOfRows_ / 2 - ROOM_CELL_MARGIN;
    const int roomOneLeftLimit = 0;
    const int roomOneRightLimit = numberOfCols_ / 2;

    Room roomOne(roomOneTopLimit, roomOneBottomLimit,
      roomOneLeftLimit, roomOneRightLimit);
    Room roomTwo(roomOneTopLimit, roomOneBottomLimit,
      roomOneRightLimit + ROOM_CELL_MARGIN, numberOfCols_ - 1);
    Room roomThree(roomOneBottomLimit + ROOM_CELL_MARGIN, numberOfRows_ - 1,
      roomOneTopLimit, roomOneRightLimit);

    // Store objects Room
    rooms_.push_back(roomOne);
    rooms_.push_back(roomTwo);
    rooms_.push_back(roomThree);
}

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
    initializeRooms();
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
    // Build all of the rooms
    for (std::vector<Room>::iterator roomIterator = rooms_.begin();
      roomIterator != rooms_.end();
      ++roomIterator) {
        buildRoom(*roomIterator);
    }

    SetDoorsAndCorridors();
}

void Dungeon::SetDoorsAndCorridors() {
    const int roomOneBottomDoorColumn = getRandomBetween(
      rooms_[0].getLeftLimit() + 1, rooms_[0].getRightLimit() - 1);

    const int roomOneRightDoorRow = getRandomBetween(
      rooms_[0].getTopLimit() + 1, rooms_[0].getBottomLimit() - 1);

    // Rooms 1-3
    int firstCorridorTopIndex = rooms_[0].getBottomLimit();
    int firstCorridorBottomIndex = rooms_[2].getTopLimit();
    mapElements_[firstCorridorTopIndex][roomOneBottomDoorColumn] = Door;
    mapElements_[firstCorridorBottomIndex][roomOneBottomDoorColumn] = Door;
    for (int i = firstCorridorTopIndex + 1; i < firstCorridorBottomIndex; i++) {
        mapElements_[i][roomOneBottomDoorColumn] = Corridor;
    }

    // Rooms 1-2
    int secondCorridorLeftIndex = rooms_[0].getRightLimit();
    int secondCorridorRightIndex = rooms_[1].getLeftLimit();
    mapElements_[roomOneRightDoorRow][secondCorridorLeftIndex] = Door;
    mapElements_[roomOneRightDoorRow][secondCorridorRightIndex] = Door;
    for (int i = secondCorridorLeftIndex + 1; i < secondCorridorRightIndex; i++) {
        mapElements_[roomOneRightDoorRow][i] = Corridor;
    }

    // Rooms 2-3
    
}

void Dungeon::buildRoom(Room room)
{
  for (unsigned i = room.getTopLimit(); i <= room.getBottomLimit(); i++) {
      for (unsigned j = room.getLeftLimit(); j <= room.getRightLimit(); j++) {
          // Top wall
          if (i == room.getTopLimit()) {
              mapElements_[i][j] = Wall;
          }

          // Left wall
          else if (j == room.getLeftLimit()) {
              mapElements_[i][j] = Wall;
          }

          // Bottom wall
          else if (i == room.getBottomLimit()) {
              mapElements_[i][j] = Wall;
          }

          // Right wall
          else if (j == room.getRightLimit()) {
              mapElements_[i][j] = Wall;
          }

          else {
              mapElements_[i][j] = Enabled;
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
                case Enabled:     std::cout << DISABLED_CHAR;       break;
            }
        }
        std::cout << std::endl;
    }
}
