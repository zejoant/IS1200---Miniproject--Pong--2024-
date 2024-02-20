#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Singleplayer(btns)
{


    //Rita
    ImageReset();
    ConvertToPixels((xBall), (yBall), 2, 2);
    ConvertToPixels((2), (posStick1), stickWidth, stickHeight);
    ConvertToPixels((124), (posStick2), stickWidth, stickHeight);
    ConvertToImage();
    display_image(0, displayFormat);

     //Boll
    ballMove();

    //Pinnar
    MoveStick1(btns);
    MoveStick2(btns);

}

void Multiplayer(btns)
{
return;
}

void Highscore(btns)
{
return;
}

void EasterEgg()
{
return;
}

