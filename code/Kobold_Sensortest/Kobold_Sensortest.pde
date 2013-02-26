#include <Kobold.h>

void setup()
{
  pinMode(IR, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  
  Serial.begin(115200);

//odo
  digitalWrite(15, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);
}

void loop()
{
  digitalWrite(IR, HIGH);
  Serial.print("Sensor on: ");
  Serial.print(analogRead(2));
  Serial.print(", ");
  Serial.print(analogRead(7));
  Serial.print(", ");
  Serial.print(analogRead(0));
  Serial.print(", ");
  Serial.println(analogRead(3));
  delay(200);
  digitalWrite(IR, LOW);
  Serial.print("Sensor off: ");
  Serial.print(analogRead(2));
  Serial.print(", ");
  Serial.print(analogRead(7));
  Serial.print(", ");
  Serial.print(analogRead(0));
  Serial.print(", ");
  Serial.println(analogRead(3));
  delay(200);

  Serial.print("Battery: ");
  Serial.println(analogRead(6)/8*23);
  
  Serial.print("Odometry: ");
  Serial.print(digitalRead(15));
  Serial.print(", ");
  Serial.print(digitalRead(11));
  Serial.print(", ");
  Serial.print(digitalRead(13));
}

void ISR_rec(int a,int b,int c){}
void ISR_50Hz(){}  
