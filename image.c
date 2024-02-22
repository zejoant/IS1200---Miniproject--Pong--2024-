#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StringReset()
{
    display_string(0, "");
    display_string(1, "");
    display_string(2, "");
    display_string(3, "");
    display_update();
}

void ConvertToPixels(int x, int y, int width, int height)
{
    int screenHeight;
    int screenWidth;
    
    for (screenHeight = 0; screenHeight < 32; screenHeight++)
    {
        for (screenWidth = 0; screenWidth < 128; screenWidth++)
        {
            if ((screenHeight >= y && screenHeight <= y+height) && (screenWidth >= x && screenWidth <= x+width))
            {
                displayCoords[screenHeight][screenWidth] = 0x1; 
            }
        }
    }
}


void ImageReset()
{
    int screenHeight;
    int screenWidth;
    int i;

    for (screenHeight = 0; screenHeight < 32; screenHeight++)
    {
        for (screenWidth = 0; screenWidth < 128; screenWidth++)
        {
            displayCoords[screenHeight][screenWidth] = 0x0; 
        }
    }

    for (i = 0; i < 512; i++)
    {
        displayFormat[i] = 0x0; 
    }
}

void ConvertToImage() {
  int page;
  int column;
  int row;
  
  uint8_t bitPos = 1;
  uint8_t formattedNum = 0;

  for(page = 0; page < 4; page++) {
    for(column = 0; column < 128; column++) {
      bitPos = 1;
      formattedNum = 0;

      for(row = 0; row < 8; row++) {
        if(displayCoords[8 * page + row][column]) {
          formattedNum |= bitPos;
        }
        bitPos <<= 1;
      }
      displayFormat[column + page * 128] = formattedNum;
    }
  }
}
