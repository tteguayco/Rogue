#include "dungeon.hpp"

#include <iostream>

int main(void)
{
  Dungeon dungeon(20, 30);
  dungeon.print();

  std::cout << "Ok. Program running..." << std::endl;
  return 0;
}
