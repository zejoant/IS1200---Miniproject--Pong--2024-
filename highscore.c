#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char hej[4] = "hej";
//display_string(0, hej);

int scoreValue = 0;
int letter1 = 65;
int letter2 = 65;
int letter3 = 65;
char initials[16] = "Name: AAA  Done";
int selectedLetter = 0;

char list[4][8] = {"ACE: 02", "BOB: 01", "NON: 00", "NON: 00"};
char temp1[8] = "OOO: 00";
char temp2[8] = "TTT: 00";

void SaveScore() //converts score and initials to fit the highscore list
{
    int i;
    int j;
    int k;

    //initialize your score into temp1
    temp1[0] = initials[6];
    temp1[1] = initials[7];
    temp1[2] = initials[8];
    temp1[5] = (scoreValue / 10) + 48; //48 = 0x30
    temp1[6] = (scoreValue % 10) + 48;

    PORTE = scoreValue;

    for(i = 0; i < 4; i++)
    {
        if((list[i][5]-48)*10 + list[i][6]-48 < scoreValue) //48 = 0x30
        {
            for(j = i; j < 4; j++)
            {
                for(k = 0; k<8; k++)
                {
                    temp2[k] = list[j][k];
                    list[j][k] = temp1[k];
                    temp1[k] = temp2[k];
                }
            }
            break;
        }
    }

    scoreValue = 0;
    letter1 = 65;
    letter2 = 65;
    letter3 = 65;
    selectedLetter = 0;
    continueSelect = 1;
}

void InputScore(btns) //lets the user input their initials for the highscore list.
{   
    if(letter1 == 91)
    {
        letter1 = 65;
    }
    if(letter2 == 91)
    {
        letter2 = 65;
    }
    if(letter3 == 91)
    {
        letter3 = 65;
    }

    if(BtnCheck(btns, 0x1) && selectedLetter < 3)
       selectedLetter++; 
    else if (BtnCheck(btns, 0x2) && selectedLetter > 0)
        selectedLetter--;

    if (selectedLetter == 0)
        display_string(2, "      ^  ");
    if (selectedLetter == 1)
        display_string(2, "       ^ ");
    if (selectedLetter == 2)
        display_string(2, "        ^");
    if (selectedLetter == 3)
        display_string(2, "            ^^");

    initials[6] = letter1;
    initials[7] = letter2;
    initials[8] = letter3;

    display_string(1, initials);

    if(BtnCheck(btns, 0x4))
    {
        if (selectedLetter == 0)
            letter1++;
        if (selectedLetter == 1)
            letter2++;
        if (selectedLetter == 2)
            letter3++;
        if (selectedLetter == 3)
        {
            StringReset();
            SaveScore();
            delay(100);
            window = 3;
        }
    }

    if(BtnCheck(btns, 0x8))
    {
        if (selectedLetter == 0)
            letter1--;
        if (selectedLetter == 1)
            letter2--;
        if (selectedLetter == 2)
            letter3--;
    }

    display_update();

}

void Highscore(btns) //displaying of the highscore list
{
    display_string(0, list[0]);
    display_string(1, list[1]);
    display_string(2, list[2]);
    display_string(3, list[3]);

    if (BtnCheck(btns, 0x4))
    {
        StringReset();
        delay(100);
        currentMenu = 3;
        window = 0;
    }
    display_update();
}