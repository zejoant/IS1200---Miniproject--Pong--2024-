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

char list[4][8] = {"AAA: 02", "BBB: 01", "CCC: 00", "DDD: 00"};
char temp1[8] = "OOO: 00";
char temp2[8] = "TTT: 00";

void SaveScore()
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

    //PORTE = (list[0][5]-48)*10 + list[0][6]-48;
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

void InputScore(btns)
{   
    delay(200);

    if(letter1 == 91){
        letter1 = 65;
    }
    if(letter2 == 91){
        letter2 = 65;
    }
    if(letter3 == 91){
        letter3 = 65;
    }

    if(getbtns() & 0x1 && selectedLetter < 3)
       selectedLetter++; 
    else if (getbtns() & 0x2 && selectedLetter > 0)
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

    if(getbtns() & 0x4)
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
            delay(1000);
            window = 3;
        }
    }

    display_update();

}

//char firstPlace[11] = "1. AAA: 00"
//char secondPlace[11] = "2. BBB: 00"
//char thirdPlace[11] = "3. CCC: 00"
//char fourthPlace[11] = "4. DDD: 00"



void Highscore(btns)
{
    delay(500);
    display_string(0, list[0]);
    display_string(1, list[1]);
    display_string(2, list[2]);
    display_string(3, list[3]);

    if (getbtns() && 0x4)
    {
        StringReset();
        delay(500);
        currentMenu = 3;
        window = 0;
    }
    display_update();
}