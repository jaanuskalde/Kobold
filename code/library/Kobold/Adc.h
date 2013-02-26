/*
  Kobold library.
  
  -- ADC --
  Takes all analog inputs needed for the robot (four IR sensors and battery sense).
  
  Designed for Swarmbot Kobold.
  Programmed by Jaanus Kalde 2011
  http://jaanus.tech-thing.org
  License: http://creativecommons.org/licenses/by-nc-sa/3.0/
*/

#ifndef Adc_h
#define Adc_h

#include "WProgram.h"

void ADCinit();

//Module analog input
#define MOD_A 18

extern volatile int sensor[4];

// Function for lipo voltage. Number returned is in millivolts.
int getVolt();

enum SENSOR {LEFT, FRONT, RIGHT, REAR};

// Function to get brightness on particular sensor.
// Usage: int a = getBrightness(REAR);
int getBrightness(enum SENSOR which);
void getBrightness(int data[4]);

//Function to get ADC value from add on module.
int getModuleAnalog();

#endif
