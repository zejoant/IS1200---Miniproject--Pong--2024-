#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Quit()
{
    window = 0;
    currentMenu = 1;
}   

void MatchReset()
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

void Restart()
{
        MatchReset();
        ImageReset();
        display_update();
        StringReset();
        scoreP1 = 0;
        scoreP2 = 0;
        Quit();
}



