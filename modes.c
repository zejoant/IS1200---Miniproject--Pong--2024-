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
    ConvertToPixels((xBallPos), (yBallPos), 2, 2);
    ConvertToPixels((2), (yPosStick1), stickWidth, stickHeight);
    ConvertToPixels((124), (yPosStick2), stickWidth, stickHeight);
    ConvertToImage();
    display_image(0, displayFormat);

     //Boll
    BallMove();

    //Pinnar
    MoveStick1(btns);
    AiMove();
}

void Multiplayer(btns)
{
    //Rita
    ImageReset();
    ConvertToPixels((xBallPos), (yBallPos), 2, 2);
    ConvertToPixels((2), (yPosStick1), stickWidth, stickHeight);
    ConvertToPixels((124), (yPosStick2), stickWidth, stickHeight);
    ConvertToImage();
    display_image(0, displayFormat);

     //Boll
    BallMove();

    //Pinnar
    MoveStick1(btns);
    MoveStick2(btns);
}

void Highscore(btns)
{
return;
}

void EasterEgg()
{
return;
}

void ShowScore()
{
    ImageReset();

    display_string(0, "      SCORE");
    display_string(1, "-----------------");
    display_string(3, "-----------------");

    
    if(scoreP1 == 1 && scoreP2 == 0)
        display_string(2, " P1: 1    P2: 0");
    if(scoreP1 == 2 && scoreP2 == 0)
        display_string(2, " P1: 2    P2: 0");
    if(scoreP1 == 3 && scoreP2 == 0)
        display_string(2, " P1: 3    P2: 0");

    if(scoreP1 == 0 && scoreP2 == 1)
        display_string(2, " P1: 0    P2: 1");
    if(scoreP1 == 1 && scoreP2 == 1)
        display_string(2, " P1: 1    P2: 1");
    if(scoreP1 == 2 && scoreP2 == 1)
        display_string(2, " P1: 2    P2: 1");
    if(scoreP1 == 3 && scoreP2 == 1)
        display_string(2, " P1: 3    P2: 1");

    if(scoreP1 == 0 && scoreP2 == 2)
        display_string(2, " P1: 0    P2: 2");
    if(scoreP1 == 1 && scoreP2 == 2)
        display_string(2, " P1: 1    P2: 2");
    if(scoreP1 == 2 && scoreP2 == 2)
        display_string(2, " P1: 2    P2: 2");
    if(scoreP1 == 3 && scoreP2 == 2)
        display_string(2, " P1: 3    P2: 2");

    if(scoreP1 == 0 && scoreP2 == 3)
        display_string(2, " P1: 0    P2: 3");
    if(scoreP1 == 1 && scoreP2 == 3)
        display_string(2, " P1: 1    P2: 3");
    if(scoreP1 == 2 && scoreP2 == 3)
        display_string(2, " P1: 2    P2: 3");
    if(scoreP1 == 3 && scoreP2 == 3)
        display_string(2, " P1: 3    P2: 3");
    
    if(scoreP1 == 4)
        display_string(2, "Player 1 wins!");
    if(scoreP2 == 4)
        display_string(2, "Player 2 wins!");
    
    display_update();
    delay(2500);
    MatchReset();

    if(scoreP1 == 4 || scoreP2 == 4)
    {
        scoreP1 = 0;
        scoreP2 = 0;
        StringReset();
        Quit();
    }
    else
        window = windowMem;
    
}

