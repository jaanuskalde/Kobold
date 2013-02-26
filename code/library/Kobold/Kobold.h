/*
  Kobold library.
  
  Some built in constants for board (odometry pins and leds)

  -- ADC --
  Takes all analog inputs needed for the robot (four IR sensors and battery sense).
  
  Designed for Swarmbot Kobold.
  Programmed by Jaanus Kalde 2011
  http://jaanus.tech-thing.org
  License: http://creativecommons.org/licenses/by-nc-sa/3.0/
*/

#ifndef Kobold_h
#define Kobold_h

#include "WProgram.h"
#include "Servo.h"
#include "Adc.h"
#include "Communication.h"

//argument0 is current robots address. address must be odd number
void KoboldInit(byte address);

#define RED_LED 9
#define GREEN_LED 8
#define MOD_IR 3
#define MOD_PIN A4

#endif
