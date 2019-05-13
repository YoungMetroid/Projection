#include "Geometary_Functions.h"

float Geo_Func::cx = 0;
float Geo_Func::cy = 0;
float Geo_Func::cz =  1000;
float Geo_Func::thetaX = 0;
float Geo_Func::thetaY =    0;
float Geo_Func::thetaZ = 00;
float Geo_Func::ex = 0;
float Geo_Func::ey = 0;
float Geo_Func::ez = 500;
int Geo_Func::rx = 1;
int Geo_Func::tracker = 0;
int Geo_Func::counter = 0;
int Geo_Func::middleX = 0;
int Geo_Func::middleY = 0;
int Geo_Func::middleZ = 0;
int Geo_Func::start = 516;
int Geo_Func::end = 1548;
float Geo_Func::fuerza = 1.3;

bool Geo_Func::dirX = true;
bool Geo_Func::dirY = false;
std::vector<Points> Geo_Func::points;
std::vector<Points> Geo_Func::tempP;
std::vector<Points> Geo_Func::camaraPoints;
Geo_Func::Geo_Func()
{

}
void Geo_Func::addPoint(int &x, int &y,int &z)
{
    points.push_back(Points(x-250,(y-250)*-1,z));
    std::cout << "X: " << x << "\n";
    std::cout << "Y: " << y << "\n";
    std::cout << "Z: " << z << "\n";
}

std::vector<Points> Geo_Func::getPoints()
{
    return points;
}
std::vector<Points>Geo_Func::getCamaraPoints()
{
    return camaraPoints;
}
void Geo_Func::resetP()
{
    points = tempP;
}
void Geo_Func::projection()
{
    std::vector<Points> temp;
    for(Points value:points)
    {
        double x = value.getX() - cx;
        double y = value.getY() - cy;
        start++;
        double z = value.getZ() - cz;
        double tx = degToRad(thetaX);
        double ty = degToRad(thetaY);
        double tz = degToRad(thetaZ);

       double dx = cos( ty ) * ( sin( tz ) * y
                 + cos( tz ) * x )
                 - sin( ty ) * z;

       double dy = sin( tx ) * ( cos( ty ) * z
                 + sin( ty ) * ( sin( tz ) * y
                 + cos( tz ) * x))
                 + cos( tx ) * ( cos( tz ) * y
                 - sin( tz ) * x);

       double dz = cos( tx ) * ( cos( ty ) * z
                 + sin( ty ) * ( sin( tz ) * y
                 + cos( tz ) * x))
                 + sin( tx ) * ( cos( tz ) * y
                 - sin( tz ) * x);

         int bx = (ez/dz*dx + ex);
         int by = (ez/dz*dy + ey);
        temp.push_back(Points(bx,by,0));

        std::cout << "X: " << value.getX() << std::endl;
        std::cout << "Y: " << value.getY() << std::endl;
        std::cout << "X': " << bx << std::endl;
        std::cout << "Y': " << by << std::endl;

        if(tracker == camaraPoints.size()-1)
        {
            tracker = 0;
        }
        cx = camaraPoints[tracker].getX();
       cz = camaraPoints[tracker].getY()+2000;
        //std::cout << cx << std::endl;
        if(counter == 3)
        {
            tracker++;

        }
        if(counter == 3)
        {
            counter = 0;
        }
        counter++;
    }
    Geo_Func::points.clear();
    Geo_Func::points = temp;


   //Camara Rotation

}
void Geo_Func::rotateX()
{
    std::vector<Points> temp;
    double gx = (degToRad(rx));
    for(Points value:points)
    {
        temp.push_back(Points(
                           value.getX(),
                           round(value.getY()*cos(gx) - value.getZ()*sin(gx)),
                           round(value.getY() * sin(gx) + value.getZ()*cos(gx))));
    }

    points = temp;
    tempP = points;

}
void Geo_Func::rotateY()
{
    std::vector<Points> temp;
    double gx = (degToRad(rx));
    for(Points value:points)
    {
        temp.push_back(Points(
                           round(value.getX()*cos(gx) + value.getZ() * sin(gx)),
                           value.getY(),
                           round(-value.getX() * sin(gx) + value.getZ() * cos(gx))
                              ));
    }
    points = temp;
    //tempP = points;
}

void Geo_Func::rotateZ()
{
    std::vector<Points> temp;
    double gx = (degToRad(rx));
    for(Points value:points)
    {
        temp.push_back(Points(
                           round(value.getX() * cos(gx) - value.getY() * sin(gx)),
                           round(value.getX() * sin(gx) + value.getY() * cos(gx)),
                           value.getZ()
                              ));
    }
    points = temp;
    tempP = points;
}
//Elipse
void Geo_Func::createFigure()
{
    //Front vertices
    points.push_back(Points(-50,50,-50));
    points.push_back(Points(50,50,-50));

    points.push_back(Points(50,50,-50));
    points.push_back(Points(50,-50,-50));

    points.push_back(Points(50,-50,-50));
    points.push_back(Points(-50,-50,-50));

    points.push_back(Points(-50,-50,-50));
    points.push_back(Points(-50,50,-50));


    //Back Vertices

    points.push_back(Points(-50,50,50));
    points.push_back(Points(50,50,50));

    points.push_back(Points(50,50,50));
    points.push_back(Points(50,-50,50));

    points.push_back(Points(50,-50,50));
    points.push_back(Points(-50,-50,50));

    points.push_back(Points(-50,-50,50));
    points.push_back(Points(-50,50,50));


   // Conecting Back and front vertices

    points.push_back(Points(-50,50,-50));
    points.push_back(Points(-50,50,50));

    points.push_back(Points(50,50,-50));
    points.push_back(Points(50,50,50));

    points.push_back(Points(50,-50,-50));
    points.push_back(Points(50,-50,50));

    points.push_back(Points(-50,-50,-50));
    points.push_back(Points(-50,-50,50));

//Pyramid
    points.push_back(Points(50,50,-50));
    points.push_back(Points(200,0,0));

    points.push_back(Points(50,-50,-50));
    points.push_back(Points(200,0,0));

    points.push_back(Points(50,50,50));
    points.push_back(Points(200,0,0));

    points.push_back(Points(50,-50,50));
    points.push_back(Points(200,0,0));


//Pyramid
    points.push_back(Points(-50,50,-50));
    points.push_back(Points(-200,0,0));

    points.push_back(Points(-50,-50,-50));
    points.push_back(Points(-200,0,0));

    points.push_back(Points(-50,50,50));
    points.push_back(Points(-200,0,0));

    points.push_back(Points(-50,-50,50));
    points.push_back(Points(-200,0,0));








    tempP = points;
}

double Geo_Func::degToRad(double deg)
{
    //std::cout << M_PI * deg / 180.0 << "\n";
    return M_PI * deg / 180.0;
}
void Geo_Func::loadCamaraPoints()
{
    std::ifstream camaraFile;
    camaraFile.open("Elipse Points.txt");
    std::string strTemp = "";
    std::string temp = "";
    std::vector<std::string>str;
    while(camaraFile >> strTemp)
    {
        str.push_back(strTemp);
    }
    std::cout << str[0] << std::endl;
    for(int i = 0; i < str.size();i++)
    {
        int x;
        int y;
        for(int j = 0; j < str[i].size();j++)
        {
            std::string s = str[i].substr(j,1);
            if(s.compare(",") == 0)
            {
                x = std::stoi(temp);
                std::cout << "X: " << x << std::endl;
               // x -=250;
                 temp = "";
            }
            else
                temp +=str[i][j];
        }
        y = std::stoi(temp);
        std::cout << "Y: " << y << std::endl;
       // y = (y -250)+-1;

        camaraPoints.push_back(Points(x,y,0));
         temp = "";
    }
}

void Geo_Func::move_to_origin()
{
    if(!points.empty())
    {
        std::cout << "TO Origin" << std::endl;
        int maxX = points[0].getX();
        int minX = points[0].getX();
        int maxY = points[0].getY();
        int minY = points[0].getY();
        int maxZ = points[0].getZ();
        int minZ = points[0].getZ();
        for(Points values: points)
        {
            if(maxX < values.getX())
                maxX = values.getX();
            if(maxY < values.getY())
                maxY  = values.getY();
            if(maxZ < values.getZ())
                maxZ = values.getZ();
            if(minX > values.getX())
                minX = values.getX();
            if(minY > values.getY())
                minY = values.getY();
            if(minZ > values.getZ())
                minZ = values.getZ();
        }
        int middleX = round((maxX +  minX) / 2);
        int middleY = round((maxY +  minY) / 2);
        int middleZ = round((maxZ +  minZ) / 2);
        std::vector<Points> temp;
        std::cout << "Mx: " << middleX << std::endl;
        std::cout << "My: " << middleY << std::endl;
        std::cout << "Mz: " << middleZ << std::endl;
        for(Points value:points)
        {
            temp.push_back(Points(value.getX()-middleX,
                                  value.getY()-middleY,
                                  value.getZ() - middleZ));
        }
        points = temp;
    }
}
void Geo_Func::moveBack()
{
     if(!points.empty())
    {
         std::vector<Points> temp;
    for(Points value:points)
    {
        temp.push_back(Points(
                           value.getX()+middleX,
                           value.getY()+middleY,
                           value.getZ()+middleZ));
    }
    points = temp;
     }
     middleX = 0;
     middleY = 0;
     middleZ = 0;
     tempP = points;
}
