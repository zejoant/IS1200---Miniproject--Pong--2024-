#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentMenu = 1;
int continueSelect = 1;
int diffSelect = 1;

void Menu(int btns)
{
    delay(200);
    if((btns & 0x1))
    {
        currentMenu++;
    }
    else if((btns & 0x2))
    {
        currentMenu--;
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
        display_string(3, "  Difficulty");
    }
    else if (currentMenu == 2)
    {
        display_string(0, "  SinglePlayer");
        display_string(1, ">  Multiplayer");
        display_string(2, "  Highscore");
    }
    else if (currentMenu == 3)
    {
        display_string(0, "  SinglePlayer");
        display_string(1, "  Multiplayer");
        display_string(2, ">  Highscore");
        display_string(3, "  Difficulty");
    
    }
    else if (currentMenu == 4)
    {
        display_string(0, "  SinglePlayer");
        display_string(1, "  Multiplayer");
        display_string(2, "  Highscore");
        display_string(3, ">  Difficulty");
    }
    
    if(getbtns() & 0x4) //confirm button
    {
        StringReset();
        delay(200);
        window = currentMenu; 
    }

    if (!(getsw() && 0x1))
        display_update();
}

void ContinueWindow(btns)
{

    if((getbtns() & 0x1))
    {
        continueSelect = 2;
    }
    else if((getbtns() & 0x2))
    {
        continueSelect = 1;
    }

    if (continueSelect == 1)
    {
        display_string(1, ">  Continue");
        display_string(2, "  Quit");
    }
    else if (continueSelect == 2)
    {
        display_string(1, "  Continue");
        display_string(2, ">  Quit");
    }

    if(getbtns() & 0x4) //confirm button
    {
        StringReset();
        delay(1000);
        if (continueSelect == 1)
            window = 1; 
        else
            window = 7;
    }

    display_update();
}

void Difficulty()
{
    delay(200);
    if((getbtns() & 0x1))
    {
        diffSelect++;
    }
    else if((getbtns() & 0x2))
    {
        diffSelect--;
    }
    if(diffSelect > 4)
    {
        diffSelect = 1;
    }
    if(diffSelect < 1)
    {
        diffSelect = 4;
    }
    if (diffSelect == 1)
    {
        display_string(0, ">  Easy");
        display_string(1, "  Medium");
        display_string(2, "  Hard");
        display_string(3, "  Impossible");
        diffcultyAI = 2;
        PORTE = 1;
    }
    else if (diffSelect == 2)
    {
        display_string(0, "  Easy");
        display_string(1, ">  Medium");
        display_string(2, "  Hard");
        display_string(3, "  Impossible");
        diffcultyAI = 3;
        PORTE = 3;
    }
    else if (diffSelect == 3)
    {
        display_string(0, "  Easy");
        display_string(1, "  Medium");
        display_string(2, ">  Hard");
        display_string(3, "  Impossible");
        diffcultyAI = 4;
        PORTE = 7;
    }
    else if (diffSelect == 4)
    {
        display_string(0, "  Easy");
        display_string(1, "  Medium");
        display_string(2, "  Hard");
        display_string(3, ">  Impossible");
        diffcultyAI = 10;
        PORTE = 15;
    }
    
    if(getbtns() & 0x4) //confirm button
    {
        StringReset();
        delay(200);
        window = 0; 
    }

    display_update();
}