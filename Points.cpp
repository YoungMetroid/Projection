#include "Points.h"

Points::Points(int x,int y,int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

int Points::getX()
{return x;}

int Points::getY()
{return y;}
int Points::getZ()
{return z;}

void Points::setX(int x)
{
    this->x = x;
}

void Points::setY(int y)
{
    this->y = y;
}
void Points::setZ(int z)
{
    this->z = z;
}
