#include "dungeon.hpp"

#include <iostream>

int main(void)
{
  srand(time(NULL));
  Dungeon dungeon(20, 30);
  dungeon.generateMapRandomly();
  dungeon.print();

  return 0;
}
