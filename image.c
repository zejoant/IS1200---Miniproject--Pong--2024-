#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
                display[screenHeight][screenWidth] = 0x1; 
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
            display[screenHeight][screenWidth] = 0x0; 
        }
    }

    for (i = 0; i < 512; i++)
    {
        oledDisplay[i] = 0x0; 
    }
}

void ConvertToImage() {
  int page, column, row, c, k;
  uint8_t powerOfTwo = 1;
  uint8_t oledNumber = 0;

  for(page = 0; page < 4; page++) {
    for(column = 0; column < 128; column++) {
      powerOfTwo = 1;
      oledNumber = 0;

      for(row = 0; row < 8; row++) {
        if(display[8 * page + row][column]) {
          oledNumber |= powerOfTwo;
        }
        powerOfTwo <<= 1;
      }
      oledDisplay[column + page * 128] = oledNumber;
    }
  }
}
