#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int followAI = 0;
int diffcultyAI = 2;
int AISpeed = 1;

void AiMove(btns) //responsible for the movement of the Ai
{
    //semi-random calculations
    if (btns & 0x4 || btns & 0x8) 
    {
        followAI++;
    }
    if (xBallPos < stickWidth*2)
    {
        followAI += ((yBallPos+1) - (yPosStick1+(stickHeight/2)));
    }

    //speedup at impossible difficulty
    if (diffcultyAI > 5) 
        AISpeed = 2;
    else
        AISpeed = 1;


    if (!(followAI % diffcultyAI == 0) && xBallPos > 128/2 && xBallSpeed > 0) //movement of ai depends on difficulty and player input
    {
        if (yPosStick2+stickHeight/2 < yBallPos-2)
            yPosStick2 += AISpeed;
        else if ((yPosStick2+stickHeight/2 > yBallPos+4))
            yPosStick2 -= AISpeed;
    }
}