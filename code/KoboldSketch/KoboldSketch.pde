#include <Kobold.h>

word vasak = 1000;
word parem = 1700;

long v_arv = 0;
long p_arv = 0;

long v_eel = 0;
long p_eel = 0;


boolean v_eelmine = 0;
boolean p_eelmine = 0;

void setup()
{
  KoboldInit();
  //700, 2000 on otse edasi
  //1170, 1500 on paigal
  
  Serial.begin(9600);
  pinMode(12, INPUT);
  pinMode(15, INPUT);
  digitalWrite(12, HIGH);
  digitalWrite(15, HIGH);
  v_eelmine = digitalRead(12);
  p_eelmine = digitalRead(15);
  Serial.println(getBrightness(REAR));
}


void loop()
{
  
//  delay(10000);
//  KServo(1050, 2000);
//  delay(10000);
  

  delay(200);
  
  parem += (p_eel-p_arv)-(v_eel-v_arv);
  vasak += (p_eel-p_arv)-(v_eel-v_arv);
  
  p_eel = p_arv;
  v_eel = v_arv;
//analog 6 == pinge mõõtmine
}

void ISR_50Hz()
{
  KServo(vasak, parem);

  if (v_eelmine != digitalRead(15))
  {
    v_eelmine = digitalRead(15);
    v_arv ++;
  }

  if (p_eelmine != digitalRead(12))
  {
    v_eelmine = digitalRead(12);
    p_arv ++;
  }
  
  digitalWrite(RED_LED, !digitalRead(RED_LED));
}
