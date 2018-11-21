#include "ProtoKit.h"

ProtoKit P(WSN_Node);  

int h=255; // initialize high value for speaker as 255
int l=0; // initialize low value for speaker as 0
int buttonstate=0; // Initialize buttonstate to 0

void setup() 
{
  pinMode(P.SW_1,INPUT);// Configure pushbutton as INPUT pin
}

void loop() 
{
 buttonstate=digitalRead(P.SW_1); // Read present buttonstate
 
 if(buttonstate==HIGH) // Check if present buttonstate is high
 {
  analogWrite(P.Buzzer,h);  // Turn on the speaker
 }
 
 if(buttonstate==LOW) // Check if present buttonstate is low
 {
  analogWrite(P.Buzzer,l); // Turn off speaker
 }
 
}
