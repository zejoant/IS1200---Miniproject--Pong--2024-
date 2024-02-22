#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int width = 2;
const int height = 2;

int xBallPos = 0;
int yBallPos = 0;
int yLastPos = 0;
const int ballSize = 2;

float xSpeed = 1;
float ySpeed = 1;

void WallCheck()
{
    if(yBallPos > 32-2 || yBallPos < 0) //horizontal screen edge checks
    {
        ySpeed *= -1;
        
    }
    
    if(xBallPos > 128-2 || xBallPos < 0) //vertical screen edge checks
    {
        xSpeed *= -1;
    }

    else if (yBallPos <= yPosStick1+stickHeight && yBallPos+ballSize >= yPosStick1 && xBallPos <= xPosStick1+stickWidth) //vertical stick1 planes check
    {
        if(yLastPos >= yPosStick1+stickHeight || yLastPos+ballSize <= yPosStick1)
        {
           // ySpeed *= -1;
            ySpeed = ySpeed * -1 + stickSpeed2;
        }
        else
            xSpeed *= -1;
    }
    else if (yBallPos <= yPosStick2+stickHeight && yBallPos+ballSize >= yPosStick2 && xBallPos+ballSize >= xPosStick2) //vertical stick2 planes check
    {
        if(yLastPos >= yPosStick2+stickHeight || yLastPos+ballSize <= yPosStick2)
        {
            //ySpeed *= -1;
            ySpeed = ySpeed * -1 + stickSpeed2;
        }
        else
            xSpeed *= -1;
    }
}

void BallMove()
{
    yLastPos = yBallPos;
    xBallPos += xSpeed; 
    yBallPos += ySpeed;

    WallCheck();
}


