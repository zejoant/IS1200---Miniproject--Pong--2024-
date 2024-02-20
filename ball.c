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

float xSpeed = 1;
float ySpeed = 1;

void ballMove()
{
    xBall += xSpeed; 
    yBall += ySpeed;
    
    if(yBall > 32-2 || yBall < 0){
        ySpeed *= -1;
    }
    if(xBall > 128-2 || xBall < 0){
        xSpeed *= -1;
    }
}
