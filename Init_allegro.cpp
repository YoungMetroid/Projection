#include "Init_allegro.h"

Init_Allegro::Init_Allegro(void)
{

}

bool Init_Allegro::execute = false;


void Init_Allegro::inicialize(void)
{
    if(!execute)
{
    std::cout << "Inicialized" << std::endl;
    al_install_keyboard();
    al_install_mouse();
    eventqueue = al_create_event_queue();
    timer = al_create_timer(1.0/30);
    al_register_event_source(eventqueue,al_get_keyboard_event_source());
    al_register_event_source(eventqueue,al_get_timer_event_source(timer));
    al_register_event_source(eventqueue,al_get_display_event_source(display));
    al_register_event_source(eventqueue,al_get_mouse_event_source());
    execute = true;
    al_start_timer(timer);
}
else
{
    std::cout << "Did no execute because allegro components should only be initialized once" << std::endl;
    std::cin.get();
}

}
int Init_Allegro::init_display()
{
    display = al_create_display(500,500);
    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }
     else return 1;
}
