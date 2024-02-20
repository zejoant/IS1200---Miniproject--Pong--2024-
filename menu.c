#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentMenu = 1;

void menu(int btns)
{
    delay(200);
    if((getbtns() & 0x1))
    {
        currentMenu++;
    }
    else if((getbtns() & 0x2))
    {
        currentMenu--;
    }
    else if(getbtns() & 0x4) //confirm button
    {
        window = 1; 
    }

    if(currentMenu > 4)
    {
        currentMenu = 1;
    }
    if(currentMenu < 1)
    {
        currentMenu = 4;
    }

    if (currentMenu == 1)
    {
        display_string(0, ">  SinglePlayer");
        display_string(1, "  Multiplayer");
        display_string(2, "  Highscore");
        display_string(3, "  Easter Egg");
    }
    else if (currentMenu == 2)
    {
        display_string(0, "  SinglePlayer");
        display_string(1, ">  Multiplayer");
        display_string(2, "  Highscore");
        
     
    }
    else if (currentMenu == 3)
    {
        display_string(1, "  Multiplayer");
        display_string(2, ">  Highscore");
        display_string(3, "  Easter Egg");
    
    }
    else if (currentMenu == 4)
    {
        display_string(0, "  SinglePlayer");
        display_string(2, "  Highscore");
        display_string(3, ">  Easter Egg");
    }
    


    display_update();
}

