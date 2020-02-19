#include "ProtoKit.h"

// ProtoKit P(IoT_Node_V1_0);
ProtoKit P(IoT_Node_V1_1);
// ProtoKit P(IoT_Node_V0_9);

int h=255; // initialize high value for speaker as 255
int l=0; // initialize low value for speaker as 0
int buttonstate=0; // Initialize buttonstate to 0

void setup() 
{
  pinMode(P.SW_1,INPUT);//To configure pushbutton as INPUT pin
  pinMode(P.Buzzer, OUTPUT); // To configure Buzzer pin as OUTPUT pin
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
