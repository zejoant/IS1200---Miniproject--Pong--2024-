#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentMenu = 1;
char line1[] = ">  SinglePlayer";
char line2[] = "   Multiplayer";
char line3[] = "   Highscore";
char line4[] = "   Easter Egg";

void menu(int btns)
{
    if(getbtns() & 1)
        currentMenu++;

    if (currentMenu == 1)
    {
        strcpy(line1, ">  SinglePlayer");
        strcpy(line2, "   Multiplayer");
        strcpy(line4, "   Easter Egg");
    }
    if (currentMenu == 2)
    {
        strcpy(line1, "   SinglePlayer");
        strcpy(line2, ">  Multiplayer");
        strcpy(line3, "   Highscore");
     
    }
    if (currentMenu == 3)
    {
        strcpy(line2, "   Multiplayer");
        strcpy(line3, ">  Highscore");
        strcpy(line4, "   Easter Egg");
    
    }
    if (currentMenu == 4)
    {
        strcpy(line1, "   SinglePlayer");
        strcpy(line3, "   Highscore");
        strcpy(line4, ">  Easter Egg");
    }
    


    switchMenu();
}

int switchMenu()
{
display_string(0, line1);
display_string(1, line2);
display_string(2, line3);
display_string(3, line4);
display_update();
}