#include "ProtoKit.h"

// ProtoKit P(IoT_Node_V1_0);
ProtoKit P(IoT_Node_V1_1);
// ProtoKit P(IoT_Node_V0_9);

int val;

void setup()
{
  Serial.begin(9600); // Baud rate for serial communication
  pinMode(P.Led_1,OUTPUT); // To configure LED pin as OUTPUT pin
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


  // if(cel<30)
  // {
  //   digitalWrite(P.Led_1,HIGH);
  // }
  // else
  // {
  //   digitalWrite(P.Led_1,LOW);
  // }


}

