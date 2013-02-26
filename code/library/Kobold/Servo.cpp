#include "WProgram.h"
#include "Servo.h"


void servoInit()
{
// Servo part uses timer1
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  //start the timer1
  TCCR1A = 0b00000010;
  TCCR1B = 0b00011010;
  TIMSK1 = 0b00100110;

  ICR1 = 40000;
  OCR1A = 4400;
  OCR1B = 4400;
}

void KServo0(word servo)
{
  OCR1A = servo;
}

void KServo1(word servo)
{
  OCR1B = servo;
}

void KServo(word servo0, word servo1)
{
  OCR1A = servo0;
  OCR1B = servo1;
}

///Timer1 interrupts

void ISR_50Hz( void);

ISR(TIMER1_CAPT_vect)
{
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  ISR_50Hz();
}

ISR(TIMER1_COMPA_vect)
{
  digitalWrite(6, LOW);
}

ISR(TIMER1_COMPB_vect)
{
  digitalWrite(7, LOW);
}

