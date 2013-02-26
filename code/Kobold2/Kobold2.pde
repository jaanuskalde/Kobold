#include <Kobold.h>

void setup()
{
  KoboldInit(73);

  pinMode(MOD_A, OUTPUT);

  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);


  Serial.begin(115200);
  
//  KServo(4000,1000);//edasi
  KServo(2950,2350);//paigal?

  
/*
  KServo0(2000);
  KServo1(2000);
  delay(90000);
  digitalWrite(RED_LED, LOW);
*/
}

int i[4];

void loop()
{
  KServo(4000,1000);//edasi
  delay(3000);
  KServo(2950,1000);//paigal?
  delay(1000);
/*  Serial.println(getBrightness(LEFT));
  Serial.println(getBrightness(FRONT));
  Serial.println(getBrightness(RIGHT));
  Serial.println(getBrightness(REAR));
  Serial.println(getVolt());*/

  /*
  Serial.println();
   getBrightness(i);
   Serial.print(i[0]);
   Serial.print(" ");
   Serial.print(i[0]);
   Serial.print(" ");
   Serial.print(i[0]);
   Serial.print(" ");
   Serial.println(i[0]);
   delay(10);*/

}

void ISR_50Hz()
{
  int a[4];
  distance(a);
  if (a[1]>300)
  {
    KServo(2950,1000);//paigal?
    delay(1000);
  }

}
void ISR_rec(int who, int what, int str){}
