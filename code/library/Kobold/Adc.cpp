#include "WProgram.h"
#include "Adc.h"

volatile int volt = 0;//voltage in lipo. 546 = 3.2V, 631 = 3.7V, 712 = 4.2V
volatile int m_adc = 0;
volatile int sensor[] = {0,0,0,0};


void ADCinit()
{
   ADCSRA = 0b11001111;
   pinMode(14, INPUT);//ADC0
   pinMode(16, INPUT);//ADC2
   pinMode(17, INPUT);//ADC3
   pinMode(20, INPUT);//ADC6
   pinMode(21, INPUT);//ADC7
   
}

int getVolt()
{
   return volt*3;
}

int getBrightness(enum SENSOR num)
{
   return sensor[num];
}

void getBrightness(int data[4])
{
   data[0] = sensor[0];
   data[1] = sensor[1];
   data[2] = sensor[2];
   data[3] = sensor[3];
}

int getModuleAnalog()
{
   return m_adc;
}

//ADC interrupt

ISR(ADC_vect)
{
/*
   ADC vector, reads 6 adc values and saves them in variables.
   sensor[0] - ADC2
   sensor[1] - ADC7
   sensor[2] - ADC0
   sensor[3] - ADC3
   volt   - ADC6
*/

	if ((ADMUX & 0x0F) == 0x02)
	{
		sensor[0] = ADC;
		ADMUX = (ADMUX & 0xF0) | 0x07;
	}
	else if ((ADMUX & 0x0F) == 0x07)
	{
		sensor[1] = ADC;
		ADMUX = (ADMUX & 0xF0) | 0x00;
	}
	else if ((ADMUX & 0x0F) == 0x00)
	{
		sensor[2] = ADC;
		ADMUX = (ADMUX & 0xF0) | 0x03;
	}
	else if ((ADMUX & 0x0F) == 0x03)
	{
		sensor[3] = ADC;
		ADMUX = (ADMUX & 0xF0) | 0x06;
	}
	else if ((ADMUX & 0x0F) == 0x06)
	{
		volt = volt/4 + volt/2 + ADC/2;
		ADMUX = (ADMUX & 0xF0) | 0x04;
	}
	else if ((ADMUX & 0x0F) == 0x04)
	{
		m_adc = ADC;
		ADMUX = (ADMUX & 0xF0) | 0x02;
	}
   bitSet(ADCSRA,ADSC);
}
