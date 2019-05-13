#include "Keys.h"

int Keys::x;
int Keys::y;
int Keys::z;

Keys::Keys()
{

}

bool Keys::checkInputs(ALLEGRO_EVENT &event)
{
    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_P:
           std::cout << "projecting" << std::endl;
           Geo_Func::rotateY();
           Geo_Func::projection();
           return true;
           break;
        case ALLEGRO_KEY_C:
            Geo_Func::createFigure();
            return true;
            break;
        default:
            break;
        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        if(event.mouse.button & 1)
        {
            Keys::x = event.mouse.x;
            Keys::y = event.mouse.y;
            Keys::z = 0;
            Geo_Func::addPoint(x,y,z);
            return true;
        }
    }
    return false;
}
