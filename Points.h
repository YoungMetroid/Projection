#ifndef POINTS_H
#define POINTS_H


class Points
{
private:
    int x;
    int y;
    int z;
public:
    Points(int,int,int);
    int getX();
    int getY();
    int getZ();
    void setX(int);
    void setY(int);
    void setZ(int);
};

#endif // POINTS_H
