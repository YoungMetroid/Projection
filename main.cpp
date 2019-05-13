#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <Init_allegro.h>
#include "Keys.h"

int main(void)
{
    if(!al_init())
    {
        return -1;
    }   

    Init_Allegro inicia;
    Geo_Func::loadCamaraPoints();
    Geo_Func::move_to_origin();
    /*for(int i = 0; i < Geo_Func::getCamaraPoints().size();i++)
    {
        std::cout << Geo_Func::getCamaraPoints()[i].getX() << std::endl;
    }
    */

    if(!inicia.init_display())
    return -1;


    bool gameLoop = false;
    bool redraw = false;

    inicia.inicialize();

   while(!gameLoop)
   {
       ALLEGRO_EVENT event;
       al_wait_for_event(inicia.eventqueue,&event);
       if(event.type == ALLEGRO_EVENT_TIMER)
       {
            redraw = true;
       }
       else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
       {
            gameLoop = true;
       }
       if(Keys::checkInputs(event))
           redraw = true;
       if(redraw == true and al_is_event_queue_empty(inicia.eventqueue))
       {

           redraw = false;
           al_clear_to_color(al_map_rgb(0,0,0));
           //al_draw_line(250,0,250,500,inicia.red,1.0);
           //al_draw_line(0,250,500,250,inicia.red,1.0);
          // Geo_Func::rotateZ();
           //Geo_Func::rotateX();
           Geo_Func::move_to_origin();
           Geo_Func::rotateY();
          // Geo_Func::rotateY();
           Geo_Func::moveBack();


           Geo_Func::projection();
           for(int i = 1; i < Geo_Func::getPoints().size();i+=2)
           {
                al_draw_line(
                            Geo_Func::getPoints()[i-1].getX()+250,
                            Geo_Func::getPoints()[i-1].getY()*-1+250,
                            Geo_Func::getPoints()[i].getX()+250,
                            Geo_Func::getPoints()[i].getY()*-1+250,
                            inicia.blue,2.0);
           }
           Geo_Func::resetP();
           al_flip_display();
       }
   }
   return 0;
}
