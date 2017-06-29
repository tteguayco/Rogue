#include "room.hpp"
#include "monster.hpp"
#include "hero.hpp"

#include <iostream>
#include <cstdlib>
#include <vector>

const unsigned NUMBER_OF_MONSTERS_BY_ROOM = 3;

/*
 * Representation of the map's elements.
 */
const char WALL_CHAR = '*';
const char DOOR_CHAR = '+';
const char CORRIDOR_CHAR = '#';
const char ACCESS_POINT_CHAR = 'X';
const char HERO_CHAR = '@';
const char AMULET_CHAR = '&';
const char MONSTER_CHAR = 'O';
const char DISABLED_CHAR = ' ';

/*
 * Between a pair of rooms, there will be ROOM_CELL_MARGIN
 * cells of separation.
 */
const unsigned ROOM_CELL_MARGIN = 4;

enum Cell {
    Disabled, Enabled, Wall, Door, Corridor, AccessPoint, Amulet
};

class Dungeon {
private:
    unsigned numberOfRows_;         // Number of rows of the map
    unsigned numberOfCols_;         // Number of columns of the map

    Hero* hero_;
    std::vector<Room> rooms_;
    std::vector<Monster> monsters_;

    /*
     * Access point: it is the start/end point in the Dungeon.
     * By default, it will be set in the room number 1.
     */
    unsigned accessPointRow_;
    unsigned accessPointCol_;

    /*
     * Amulet point: it is the point where the amulet is placed in.
     * By default, it will be set in the room number 3.
     */
     unsigned amuletRow_;
     unsigned amuletCol_;

    /*
     * The map is represented as a matrix of characters.

     * There will be a method which will print all of these
     * characters in the screen in order to visualize the map.
     */
    Cell** mapElements_;

public:
    Dungeon(int nrows, int ncols);
    ~Dungeon();
    void generateMapRandomly(void);
    void print(void);
    void readFromFile(char* fileName);

private:
    void initializeRooms();
    void initializeMap(void);
    void setDoorsAndCorridors(void);
    void setAccessPoint(void);
    void setAmulet(void);
    void setMonsters(void);
    void moveMonstersToRandomPosition(void);
    void buildRoom(Room room);
};
