#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentMenu = 1;

void menu(int btns)
{
    if(getbtns() & 1)
    {
        currentMenu++;
    }
    if(getbtns() & 2)
    {
        currentMenu--;
    }
    if(getbtns() & 3) //confirm button
    {
        return; //placeholder
    }
    if(currentMenu > 4)
    {
        currentMenu = 0;
    }
    if(currentMenu < 1)
    {
        currentMenu = 4;
    }

    if (currentMenu == 1)
    {
        display_string(0, ">  SinglePlayer");
        display_string(1, "   Multiplayer");
        display_string(3, "   Easter Egg");
    }
    if (currentMenu == 2)
    {
        display_string(0, "   SinglePlayer");
        display_string(1, ">  Multiplayer");
        display_string(2, "   Highscore");
     
    }
    if (currentMenu == 3)
    {
        display_string(1, "   Multiplayer");
        display_string(2, ">  Highscore");
        display_string(3, "   Easter Egg");
    
    }
    if (currentMenu == 4)
    {
        display_string(0, "   SinglePlayer");
        display_string(2, "   Highscore");
        display_string(3, ">  Easter Egg");
    }
    


    display_update();
}

