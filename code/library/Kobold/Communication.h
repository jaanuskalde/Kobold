/*
  Kobold library.
    
  Designed for Swarmbot Kobold.
  Programmed by Jaanus Kalde 2011
  http://jaanus.tech-thing.org
  License: http://creativecommons.org/licenses/by-nc-sa/3.0/
*/

#ifndef Communication_h
#define Communication_h

#include "WProgram.h"
#include "Adc.h"

//ir out pin
#define IR 19

#define IR_ON digitalWrite(IR, LOW)
#define IR_OFF digitalWrite(IR, HIGH)
#define IR_TOGGLE digitalWrite(IR, !digitalRead(IR))

//magic constants for ir
//they are non dependat of each other

//this one is the minimum absolute differenve between low and high
#define ir_min_diff 6

//this one is the divider for minimum relative difference between low and high
#define ir_min_perc 8


//constants
extern volatile byte address;

//communication
void initCommunication(byte address);
void send(byte);

//distance measurement
void distance(int data[4]);

#endif
