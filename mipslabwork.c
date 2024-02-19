/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

uint8_t display[32][128];
uint8_t oled_display[512];
int initial_active = 0;
int window = 0;


char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void ) 
{
  return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
  PORTE = 0x0;      // LED:s
  TRISECLR = 0xff;  // Set as output (LED:S)
  TRISDSET = 0xfe0; // Set as input (BTN 2-4, SW 1-4)
  TRISFSET = 0x2;   // Set as input (BTN 1)
  volatile int *trise = (volatile int *)0xbf886100;
}

/* This function is called repetitively from the main program */

void labwork( void ) 
{
  int btns = getbtns();
  int sw = getsw();

  if(sw & 1)
  {
    //quit();
    return;
  }

  if (window == 0)
  {
    menu(btns);
  }
  else if (window == 1)
  {
    return;
  }
  else
  {
    return;
  }

}
