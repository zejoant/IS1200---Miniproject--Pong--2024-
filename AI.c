#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int followAI = 0;
int diffcultyAI = 2;

void AiMove() //responsible for the movement of the Ai
{
    if (getbtns() & 0x4 || getbtns() & 0x8)
    {
        followAI++;
    }
    if (xBallPos < stickWidth*2)
    {
        followAI += ((yBallPos+1) - (yPosStick1+(stickHeight/2)));
    }

    if (!(followAI % diffcultyAI == 0) && xBallPos > 128/2 && xBallSpeed > 0) //movement of ai depends on difficulty and player input
    {
        if (yPosStick2+stickHeight/2 < yBallPos+1)
            yPosStick2 += 1;
        else
            yPosStick2 -= 1;
    }
}