#include "ProtoKit.h"

ProtoKit P(WSN_Node);

int potValue = 0;  // Initialize ldrValue to 0      
int ledValue = 0; // Initialize ledValue to 0      

void setup() 
{
   Serial.begin(9600); //Baud rate for serial communication
}

void loop() 
{  
  potValue = analogRead(P.POT); // Read present analog input from POT
  ledValue = map(potValue, 0, 1023, 0, 255);/*change the analog out value from 0 - 1023 to 0 - 255
                                              to control LED brightness*/
  analogWrite(P.Led_3, ledValue);// write analog value to output pin
  Serial.print("sensor = "); // print values
  Serial.print(potValue);
  Serial.print("\t\t output = ");
  Serial.println(ledValue);
  delay(10); // Read after every 10 milliSeconds
}
