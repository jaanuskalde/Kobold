#include <Kobold.h>

void setup()
{
  KoboldInit(100);
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
int data[4];

void loop()
{
  digitalWrite(IR, HIGH);
  Serial.print("Sensor on: ");
  getBrightness(data);
  Serial.print(data[0]);
  Serial.print(", ");
  Serial.print(data[1]);
  Serial.print(", ");
  Serial.print(data[2]);
  Serial.print(", ");
  Serial.println(data[3]);
  delay(200);
  digitalWrite(IR, LOW);
  Serial.print("Sensor off: ");
  getBrightness(data);
  Serial.print(data[0]);
  Serial.print(", ");
  Serial.print(data[1]);
  Serial.print(", ");
  Serial.print(data[2]);
  Serial.print(", ");
  Serial.println(data[3]);
  delay(200);

  Serial.print("Battery: ");
  Serial.println(getVolt());
  
  Serial.print("Odometry: ");
  Serial.print(digitalRead(15));
  Serial.print(", ");
  Serial.print(digitalRead(11));
  Serial.print(", ");
  Serial.print(digitalRead(13));
}

void ISR_rec(int a,int b,int c){}
void ISR_50Hz(){}  
