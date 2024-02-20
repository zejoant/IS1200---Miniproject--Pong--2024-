#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stickWidth = 2;
int stickHeight = 32/3;

int posStick1 = 32/2 - (32/3)/2;
int posStick2 = 32/2 - (32/3)/2;

const int stickSpeed = 1;

void MoveStick1(btns)
{
    if ((posStick1 > 0))
    {
        if(getbtns() & 0x1)
        {
            posStick1 -= stickSpeed; 
        }
    }
    if (posStick1 < (32-stickHeight-1))
    {
        if(getbtns() & 0x2)
        {
        posStick1 += stickSpeed; 
        }
    }

}

void MoveStick2(btns)
{
    if ((posStick2 > 0))
    {
        if(getbtns() & 0x4)
        {
            posStick2 -= stickSpeed; 
        }
    }
    if (posStick2 < (32-stickHeight-1))
    {
        if(getbtns() & 0x8)
        {
        posStick2 += stickSpeed; 
        }
    }

}