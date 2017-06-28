#include "monster.hpp"

Monster::Monster(unsigned initialRow, unsigned initialCol):
    row_(initialRow),
    col_(initialCol)
{}

Monster::~Monster()
{
    row_ = 0;
    col_ = 0;
}

unsigned Monster::getRow()
{
    return row_;
}

unsigned Monster::getCol()
{
    return col_;
}

void Monster::setRow(unsigned aRow)
{
    row_ = aRow;
}

void Monster::setCol(unsigned aCol)
{
    col_ = aCol;
}
