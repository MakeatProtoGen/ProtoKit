#include "ProtoKit.h"

ProtoKit P(IoT_Node);  

int buttonstate=0; // Initialize buttonstate to 0

void setup() 
{
  pinMode(P.SW_1,INPUT);//To configure pushbutton as INPUT pin
  pinMode(P.Relay_1,OUTPUT); // To configure RELAY as output pin
}

void loop() 
{
 buttonstate=digitalRead(P.SW_1); // Read present buttonstate
 if (buttonstate == HIGH) // Check if present buttonstate is high
 {
   digitalWrite(P.Relay_1, HIGH); // Make RELAY HIGH
  } 
  else            //else Check if present buttonstate is low
  {
    digitalWrite(P.Relay_1, LOW); // Make RELAY LOW
  }
 delay(10); // Read after every 10 milliSeconds
}
