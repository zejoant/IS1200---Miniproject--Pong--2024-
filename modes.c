#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Singleplayer(btns)
{
    //Draw
    ImageReset();
    ConvertToPixels((xBallPos), (yBallPos), 2, 2);
    ConvertToPixels((2), (yPosStick1), stickWidth, stickHeight);
    ConvertToPixels((124), (yPosStick2), stickWidth, stickHeight);
    ConvertToImage();
    display_image(0, displayFormat);

    //Ball
    BallMove();

    //Sticks
    MoveStick1(btns);
    AiMove();
}

void Multiplayer(btns)
{
    //Draw
    ImageReset();
    ConvertToPixels((xBallPos), (yBallPos), 2, 2);
    ConvertToPixels((2), (yPosStick1), stickWidth, stickHeight);
    ConvertToPixels((124), (yPosStick2), stickWidth, stickHeight);
    ConvertToImage();
    display_image(0, displayFormat);

     //Ball
    BallMove();

    //Sticks
    MoveStick1(btns);
    MoveStick2(btns);
}

void ShowScore()
{
    ImageReset();

    display_string(0, "      SCORE");
    display_string(1, "-----------------");
    display_string(3, "-----------------");

    
    if(scoreP1 == 1 && scoreP2 == 0)
        display_string(2, " P1: 1    P2: 0");
    else if(scoreP1 == 2 && scoreP2 == 0)
        display_string(2, " P1: 2    P2: 0");
    else if(scoreP1 == 3 && scoreP2 == 0)
        display_string(2, " P1: 3    P2: 0");

    else if(scoreP1 == 0 && scoreP2 == 1)
        display_string(2, " P1: 0    P2: 1");
    else if(scoreP1 == 1 && scoreP2 == 1)
        display_string(2, " P1: 1    P2: 1");
    else if(scoreP1 == 2 && scoreP2 == 1)
        display_string(2, " P1: 2    P2: 1");
    else if(scoreP1 == 3 && scoreP2 == 1)
        display_string(2, " P1: 3    P2: 1");

    else if(scoreP1 == 0 && scoreP2 == 2)
        display_string(2, " P1: 0    P2: 2");
    else if(scoreP1 == 1 && scoreP2 == 2)
        display_string(2, " P1: 1    P2: 2");
    else if(scoreP1 == 2 && scoreP2 == 2)
        display_string(2, " P1: 2    P2: 2");
    else if(scoreP1 == 3 && scoreP2 == 2)
        display_string(2, " P1: 3    P2: 2");

    else if(scoreP1 == 0 && scoreP2 == 3)
        display_string(2, " P1: 0    P2: 3");
    else if(scoreP1 == 1 && scoreP2 == 3)
        display_string(2, " P1: 1    P2: 3");
    else if(scoreP1 == 2 && scoreP2 == 3)
        display_string(2, " P1: 2    P2: 3");
    else if(scoreP1 == 3 && scoreP2 == 3)
        display_string(2, " P1: 3    P2: 3");
    
    else if(scoreP1 == 4)
        display_string(2, "Player 1 wins!");
    else if(scoreP2 == 4 && windowMem != 1)
        display_string(2, "Player 2 wins!");
    else if (scoreP2 == 4 && windowMem == 1)
        display_string(2, "AI wins!");
    
    display_update();
    delay(2500);
    MatchReset();

    if (scoreP1 == 4)
    {
        scoreValue++;
    }
    if(scoreP1 == 4 || scoreP2 == 4)
    {
        if (windowMem == 1)
        {
            StringReset();
            window = 6;
            scoreP1 = 0;
            scoreP2 = 0;
        }
        else if (windowMem == 2)
        {
            scoreP1 = 0;
            scoreP2 = 0;
            StringReset();
            Quit();
        }
    }
    else
    {
        window = windowMem;
    }
        
    
}


