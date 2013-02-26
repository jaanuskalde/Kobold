/*
  Kobold servo library.
  
  -- Servo --
  For controlling two servos on pins 6 and 7. Uses timer1 COMPA, COMPB and OVF interrupts.
  Designed for minimum space and maximum speed. Operates with 16Mhz clock.
  
  Designed for Swarmbot Kobold.
  Programmed by Jaanus Kalde 2011
  http://jaanus.tech-thing.org
  License: http://creativecommons.org/licenses/by-nc-sa/3.0/
*/

#ifndef Servo_h
#define Servo_h
#include "WProgram.h"

#define LEFT_WHEEL 15
#define RIGHT_WHEEL 12

// Servo part
void servoInit();
void KServo0(word);
void KServo1(word);
void KServo(word, word);

#endif
