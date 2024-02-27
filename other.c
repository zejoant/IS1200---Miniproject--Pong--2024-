#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prevInput = 0000;

void Quit() //resets certain values
{
    window = 0;
    currentMenu = 1;
    scoreValue = 0;
    diffcultyAI = 2;
    diffSelect = 1;
    PORTE = 1;
}   

void MatchReset() //resets positions of match components
{

    xBallPos = 128/2 -1;
    yBallPos = 32/2 -1;

    yBallSpeed = 0;
    if (scoreP1 <= scoreP2)
        xBallSpeed = 1;
    else
        xBallSpeed = -1;

    yPosStick1 = 32/2 - stickHeight/2;
    yPosStick2 = 32/2 - stickHeight/2;
}

void Restart() //resets whole game and returns to menu
{
        MatchReset();
        ImageReset();
        StringReset();
        scoreP1 = 0;
        scoreP2 = 0;
        Quit();
        display_update();
}

int BtnCheck(btns, mask) //returns true if button was pressed that frame
{
    if ((btns & mask) && !(prevInput & mask))
    {
        prevInput |= mask;
        return 1;
    }
    else if (!(btns & mask) && (prevInput & mask))
    {
        prevInput &= !mask;
    }
    return 0;
}



