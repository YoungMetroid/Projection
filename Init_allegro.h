#ifndef INIT_ALLEGRO_H
#define INIT_ALLEGRO_H

#include <allegro5/allegro.h>

#include <iostream>

class Init_Allegro
{
private:
    static bool execute;
public:
    Init_Allegro(void);

    ALLEGRO_DISPLAY * display;
    ALLEGRO_COLOR blue = al_map_rgb(78,60,220);
    ALLEGRO_COLOR red = al_map_rgb(200,50,70);
    ALLEGRO_EVENT_QUEUE *eventqueue = NULL;
    ALLEGRO_TIMER *timer = NULL;
    void inicialize(void);
    int init_display(void);

};

#endif // INIT_ALLEGRO_H
