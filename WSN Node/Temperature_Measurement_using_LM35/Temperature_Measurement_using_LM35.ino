#include "ProtoKit.h"

ProtoKit P(WSN_Node);

int val = 0;// Initialize val to 0

void setup()
{
  Serial.begin(9600);
  pinMode(P.Led_1,OUTPUT);
}

void loop()
{
  val = analogRead(P.TEMPERATURE); //Read the analog value from A0 will be from 0 - 1023
  float mv = val*4.88758; //Convert analog value to mv (5/1023)*1000 
  float cel = mv/10;//Convert mv to Celsius
  
  float farh = (cel*9)/5 + 32;//Convert Celsius to Farh 

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

