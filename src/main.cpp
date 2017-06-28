#include "dungeon.hpp"

#include <iostream>

int main(void)
{
  Dungeon dungeon(40, 40);
  dungeon.generateMapRandomly();
  dungeon.print();

  return 0;
}
