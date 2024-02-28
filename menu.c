#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int currentMenu = 1;
int continueSelect = 1;
int diffSelect = 1;
char menuItems[4][16] = {">  SinglePlayer", "  Multiplayer", "  Highscore", "  Difficulty"};

void Menu(int btns) //displaying on the menu
{
    int i;

    if(BtnCheck(btns, 0x1)) //move up in menu
    {
        currentMenu++;
    }
    else if(BtnCheck(btns, 0x2)) //move down in menu
    {
        currentMenu--;
    }

    if(currentMenu > 4) //wrap-around
    {
        currentMenu = 1;
    }
    if(currentMenu < 1) //wrap-around
    {
        currentMenu = 4;
    }

    /*for (i = 0; i < 4; i++)
    {
        display_string(i, menuItems[i]);
        menuItems[i][0] = 0x7f;
    }

    menuItems[currentMenu-1][0] = 0x3e;
    display_string(currentMenu-1, menuItems[currentMenu-1]);*/

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
    
    if(BtnCheck(btns, 0x4)) //confirm button
    {
        StringReset();
        delay(100);
        window = currentMenu; 
    }

    if (!(getsw() && 0x1))
        display_update();
}

void ContinueWindow(btns) //window that pops up after winning/losing asking you to continue or quit.
{

    if(BtnCheck(btns, 0x1))
    {
        if (continueSelect == 2)
            continueSelect = 1;
        else
            continueSelect = 2;
    }
    else if(BtnCheck(btns, 0x2))
    {
        if (continueSelect == 1)
            continueSelect = 2;
        else
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

    if(BtnCheck(btns, 0x4)) //confirm button
    {
        StringReset();
        delay(100);
        if (continueSelect == 1)
            window = 1; 
        else
            window = 7;
    }

    display_update();
}

void Difficulty(btns) //difficulty settings menu
{
    if(BtnCheck(btns, 0x1))
    {
        diffSelect++;
    }
    else if(BtnCheck(btns, 0x2))
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
    
    if(BtnCheck(btns, 0x4)) //confirm button
    {
        StringReset();
        delay(100);
        window = 0; 
    }

    display_update();
}