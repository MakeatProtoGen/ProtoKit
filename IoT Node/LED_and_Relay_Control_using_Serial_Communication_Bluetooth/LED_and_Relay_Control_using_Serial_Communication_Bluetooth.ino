#include "ProtoKit.h"

ProtoKit P(IoT_Node_V1_0);
// ProtoKit P(IoT_Node_V1_1);
// ProtoKit P(IoT_Node_V0_9);


char incoming = 0;  //Initialize inccomingdata to 0                  

void setup()
{
  Serial.begin(9600); //Baud rate for serial communication
  pinMode(P.Led_3,OUTPUT); // To configure LED 3 pin as OUTPUT pin
  pinMode(P.Led_1,OUTPUT); // To configure LED 1 pin as OUTPUT pin
}
void loop()
{
  if(Serial.available() > 0)/*check if any incoming data from  serial port */
  {
    incoming=Serial.read(); /*read incoming data from  serial port */
    if(incoming=='1') // check if incoming number is digit 1
    {
      Serial.println("Turning on LED 3");
      digitalWrite(P.Led_3,HIGH); // Set LED 3 as high
    }
    if(incoming=='2') // check if incoming number is digit 2
    {
      Serial.println("Turning off LED 3");
      digitalWrite(P.Led_3,LOW); // Set LED 3 as LOW
    }
    if(incoming=='3') // check if incoming number is digit 3
    {
      Serial.println("Turning on LED 1");
      digitalWrite(P.Led_1,HIGH); // Set LED 1 as HIGH
    }
    if(incoming=='4') //check if incoming number is digit 4
    {
      Serial.println("Turning off LED 1");
       digitalWrite(P.Led_1,LOW); // set LED 1 as low
    }
  } 
}

