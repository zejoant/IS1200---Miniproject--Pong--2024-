#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int AIFollow = 0;
int diffculty = 3;

void AiMove()
{
    if (getbtns() & 0x4 || getbtns() & 0x8)
    {
        AIFollow++;
    }
    if (xBallPos < stickWidth*2)
    {
        AIFollow += ((yBallPos+1) - (yPosStick1+(stickHeight/2)));
    }

    if (!(AIFollow % diffculty == 0) && xBallPos > 128/2 && xBallSpeed > 0)
    {
        if (yPosStick2+stickHeight/2 < yBallPos+1)
            yPosStick2 += 1;
        else
            yPosStick2 -= 1;
    }
}