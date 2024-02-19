#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int getsw(void)
{

    volatile int* switches = (volatile int*) 0xbf8860d0;

    return (*switches >> 8) & 0xf;

}

int getbtns(void)
{

   return ((PORTD>>5) & 0x0007);

}