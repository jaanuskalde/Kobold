/*
  Kobold library.
    
  Designed for Swarmbot Kobold.
  Programmed by Jaanus Kalde 2011
  http://jaanus.tech-thing.org
  License: http://creativecommons.org/licenses/by-nc-sa/3.0/
*/

#include "WProgram.h"
#include "Kobold.h"

void KoboldInit(byte address)
{
   noInterrupts();

   servoInit();
   ADCinit();
   initCommunication(address);

   pinMode(GREEN_LED, OUTPUT);
   pinMode(RED_LED, OUTPUT);

   interrupts();
}
