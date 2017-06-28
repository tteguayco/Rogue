#include "dungeon.hpp"

#include <iostream>

int main(void)
{
  Dungeon dungeon(20, 30);
  dungeon.generateMapRandomly();
  dungeon.print();

  return 0;
}
