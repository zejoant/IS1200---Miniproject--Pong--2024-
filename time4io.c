#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int getsw(void) //gets the bits for all 4 switches
{

    volatile int* switches = (volatile int*) 0xbf8860d0;

    return (*switches >> 8) & 0xf;

}

int getbtns(void) //gets the bits for all 4 buttons
{

   return ((((PORTD>>5) & 0x0007) <<1) | ((PORTF>>1) & 0x1));


}