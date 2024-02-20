#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int width = 2;
const int height = 2;

int xBall = 0;
int yBall = 0;
const int ballSize = 2;

float xSpeed = 1;
float ySpeed = 1;

void BallMove()
{
    xBall += xSpeed; 
    yBall += ySpeed;

    WallCheck();
}

void WallCheck()
{
    if(yBall > 32-2 || yBall < 0) //horizontal screen edge checks
    {
        ySpeed *= -1;
        
    }
    
    if(xBall > 128-2 || xBall < 0) //vertical screen edge checks
    {
        xSpeed *= -1;
    }

    else if (yBall <= yPosStick1+stickHeight && yBall+ballSize >= yPosStick1 && xBall <= xPosStick1+stickWidth) //vertical stick1 planes check
    {
        xSpeed *= -1;
    }
    else if (yBall <= yPosStick2+stickHeight && yBall+ballSize >= yPosStick2 && xBall+ballSize >= xPosStick2) //vertical stick2 planes check
    {
        xSpeed *= -1;
    }
}
