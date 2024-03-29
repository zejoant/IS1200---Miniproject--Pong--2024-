#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int width = 2;
const int height = 2;

float xBallPos = 128/2 - 1;
float yBallPos = 32/2 - 1;
int yLastPos = 0;
const int ballSize = 2;

int a = 1;
int b = -1;

float xBallSpeed = 1.0;
float yBallSpeed = 0.0;

int scoreP2 = 0;
int scoreP1 = 0;

void WallCheck() //checks for collission
{
    /*if(yBallPos > 32-2 || yBallPos < 0) //horizontal screen edge checks
    {
        yBallSpeed *= -1.0;
    }*/

    //horizontal screen edge checks
    if (yBallPos < 0) 
    {
        yBallSpeed *= -1.0;
        yBallPos = 0;
    }
    else if (yBallPos > 32-2)
    {
        yBallSpeed *= -1.0;
        yBallPos = 32-2;
    }
    
    if(xBallPos > 128) //vertical screen edge checks
    {
        scoreP1++;
        followAI += scoreP1;
        windowMem = window;
        window = 5;
    }
    if(xBallPos < -ballSize)
    {
        scoreP2++;
        windowMem = window;
        window = 5;
    }

    else if (yBallPos <= yPosStick1+stickHeight && yBallPos+ballSize >= yPosStick1 && xBallPos <= xPosStick1+stickWidth) //vertical stick1 planes check
    {
        if(yLastPos >= yPosStick1+stickHeight || yLastPos+ballSize <= yPosStick1)
        {
            yBallSpeed = yBallSpeed * -1.0 + (float)stickSpeed2;
        }
        else
        {
            if (xBallSpeed < 0)
                xBallSpeed = -xBallSpeed;
            //xBallSpeed *= -1.0;
            //xBallSpeed = abs(xBallSpeed);
            yBallSpeed += (((float)yBallPos+((float)ballSize/2.0)) - ((float)yPosStick1+((float)stickHeight/2.0)))/4.0 + stickSpeed1;

        }
    }
    else if (yBallPos <= yPosStick2+stickHeight && yBallPos+ballSize >= yPosStick2 && xBallPos+ballSize >= xPosStick2) //vertical stick2 planes check
    {
        if(yLastPos >= yPosStick2+stickHeight || yLastPos+ballSize <= yPosStick2)
        {
            yBallSpeed = yBallSpeed * -1.0 + (float)stickSpeed2;
        }
        else
        {
            if (xBallSpeed > 0)
                xBallSpeed = -xBallSpeed;
            //xBallSpeed *= -1.0;
            //xBallSpeed = -abs(xBallSpeed);
            yBallSpeed += (((float)yBallPos+((float)ballSize/2.0)) - ((float)yPosStick2+((float)stickHeight/2.0)))/4.0 + stickSpeed2;
        }
    }
}

void BallMove() //moves the ball
{
    yLastPos = yBallPos;
    xBallPos += xBallSpeed; 
    yBallPos += yBallSpeed;

    WallCheck();
}


