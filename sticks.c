#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int stickWidth = 2;
int stickHeight = 32/3;

int yPosStick1 = 32/2 - (32/3)/2;
const int xPosStick1 = 2;
int yPosStick2 = 32/2 - (32/3)/2;
const int xPosStick2 = 124;

const int stickSpeed = 1;

void MoveStick1(btns)
{
    if ((yPosStick1 > 0))
    {
        if(getbtns() & 0x1)
        {
            yPosStick1 -= stickSpeed; 
        }
    }
    if (yPosStick1 < (32-stickHeight-1))
    {
        if(getbtns() & 0x2)
        {
        yPosStick1 += stickSpeed; 
        }
    }

}

void MoveStick2(btns)
{
    if ((yPosStick2 > 0))
    {
        if(getbtns() & 0x4)
        {
            yPosStick2 -= stickSpeed; 
        }
    }
    if (yPosStick2 < (32-stickHeight-1))
    {
        if(getbtns() & 0x8)
        {
        yPosStick2 += stickSpeed; 
        }
    }

}