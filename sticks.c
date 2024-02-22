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

int stickSpeed1 = 0;
int stickSpeed2 = 0;

void MoveStick1(btns)
{
    if(getbtns() & 0x8)
    {
        stickSpeed1 = -1;
        if ((yPosStick1 < 0))
        {
            stickSpeed1 = 0;
        }
    }
    if(getbtns() & 0x4)
    {
        stickSpeed1 = 1;
        if (yPosStick1+stickHeight > (32-1))
        {
            stickSpeed1 = 0;
        }
    }

    if (!(getbtns() & 0x8) && !(getbtns() & 0x4))
        stickSpeed1 = 0;

    yPosStick1 += stickSpeed1; 
}

void MoveStick2(btns)
{
    if(getbtns() & 0x2)
    {
        stickSpeed2 = -1;
        if ((yPosStick2 < 0))
        {
            stickSpeed2 = 0;
        }
    }
    if(getbtns() & 0x1)
    {
        stickSpeed2 = 1;
        if (yPosStick2+stickHeight > (32-1))
        {
            stickSpeed2 = 0;
        }
    }

    if (!(getbtns() & 0x1) && !(getbtns() & 0x2))
        stickSpeed2 = 0;

    yPosStick2 += stickSpeed2; 
}