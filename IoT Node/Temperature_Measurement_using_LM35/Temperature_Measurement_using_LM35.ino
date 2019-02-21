#include "ProtoKit.h"

ProtoKit P(IoT_Node);

int val;

void setup()
{
  Serial.begin(9600);
  pinMode(P.Led_1,OUTPUT);
}

void loop()
{
  val = analogRead(P.TEMPERATURE);
  float mv = val*2.932; 
  float cel = mv/10;
  float farh = (cel*9)/5 + 32;

  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);

/*
  if(cel<30)
  {
    digitalWrite(P.Led_1,HIGH);
  }
  else
  {
    digitalWrite(P.Led_1,LOW);
  }
*/

}

