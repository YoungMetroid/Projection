#ifndef GEO_FUNC_H
#define GEO_FUNC_H
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include "Points.h"
class Geo_Func
{
private:
    static std::vector<Points> points;
    static std::vector<Points> tempP;
    static std::vector<Points> camaraPoints;
    static float perspectiveM[][4];
    static float cx,cy,cz;
    static float thetaX,thetaY,thetaZ;
    static float ex,ey,ez;
    static int rx;
    static int tracker;
    static int counter;
    static bool dirX,dirY;
    static int middleX;
    static int middleY;
    static int middleZ;
    static int start;
    static int end;
    static float fuerza;
public:
    Geo_Func();
    static void addPoint(int&,int&,int&);
    static std::vector<Points> getPoints();
    static std::vector<Points> getCamaraPoints();
    static void projection();
    static void createFigure();
    static double degToRad(double);
    static void resetP();
    static void rotateX();
    static void rotateY();
    static void rotateZ();
    static void rotateCamaraY();
    static void loadCamaraPoints();
    static void moveObject();
    static void move_to_origin();
    static void moveBack();


};

#endif // GEO_FUNC_H
