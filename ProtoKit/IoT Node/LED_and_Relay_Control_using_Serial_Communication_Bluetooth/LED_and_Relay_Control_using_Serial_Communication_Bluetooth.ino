#include "ProtoKit.h"

ProtoKit P(IoT_Node);

char incoming=0;  //Initialize inccomingdata to 0                  

void setup()
{
  Serial.begin(9600); //Baud rate for serial communication
  pinMode(P.Led_3,OUTPUT); // To configure LED  pin as OUTPUT pin
  pinMode(P.Relay_1,OUTPUT); // To configure RELAY pin as OUTPUT pin
}
void loop()
{
  if(Serial.available()>0)/*check if any incoming data 
                                     from  serial monitor */
  {
    incoming=Serial.read(); /*read if any incoming data
                                     from  serial monitor */
    if(incoming=='1') // check if incoming number is digit 1
    {
      Serial.println(1);
      digitalWrite(P.Led_3,HIGH); // Set LED 1 as high
    }
    if(incoming=='2') // check if incoming number is digit 2
    {
       digitalWrite(P.Led_3,LOW); // Set LED 1 as LOW
    }
    if(incoming=='3') // check if incoming number is digit 3
    {
      digitalWrite(P.Relay_1,HIGH); // Set RELAY 1 as HIGH
    }
    if(incoming=='4') //check if incoming number is digit 4
    {
       digitalWrite(P.Relay_1,LOW); // set RELAY 1 as low
    }
  } 
}

