#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char line[17] = {0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03}; 

void Singleplayer(btns) //calling of singleplaying functions
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
    AiMove(btns);
}

void Multiplayer(btns) //calling of multiplayer functions
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

void ShowScore() //for displaying scores between rounds, winner, resetting positions of ball etc
{
    char scoreComparison[] = " P1: 0    P2: 0";

    //inputs scores in string to be displayed
    scoreComparison[5] = scoreP1+48;
    scoreComparison[14] = scoreP2+48;

    if (windowMem == 1) //displays "AI" instead of "P2"
    {
        scoreComparison[10] = 0x41;
        scoreComparison[11] = 0x49;
    }

    ImageReset();

    display_string(0, "      SCORE");
    display_string(1, line);
    display_string(2, scoreComparison);
    display_string(3, line);
    
    //checks winning conditions
    if(scoreP1 == 4 && windowMem != 1)
    {
        display_string(0, "   Game Over");
        display_string(2, " Player 1 wins!");
    }
    else if(scoreP2 == 4 && windowMem != 1)
    {
        display_string(0, "   Game Over");
        display_string(2, " Player 2 wins!");
    }
    else if (scoreP2 == 4 && windowMem == 1)
    {
        display_string(0, "Nice try but...");
        display_string(2, "    AI wins");
    }
    else if (scoreP1 == 4 && windowMem == 1)
    {
        display_string(0, "Congratulations");
        display_string(2, "    You won!");
    }
    
    display_update();
    delay(2500);
    MatchReset();

    if (scoreP1 == 4) //adds to score value for the highscore
    {
        scoreValue++;
    }
    if(scoreP1 == 4 || scoreP2 == 4) //ends match if score of either is 4
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


