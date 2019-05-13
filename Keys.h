#ifndef KEYS_H
#define KEYS_H

#include "allegro5/allegro.h"
#include "Geometary_Functions.h"
#include <iostream>

class Keys
{
private:

public:
    Keys();
    static int x,y,z;
    static bool checkInputs(ALLEGRO_EVENT&);
};

#endif // KEYS_H
