#include "ProtoKit.h"

ProtoKit P(IoT_Node);

int ldrValue = 0;// Initialize ldrValue to 0
int ledValue = 0;// Initialize ledValue to 0

void setup() 
{
  Serial.begin(9600); //Baud rate for serial communication
}

void loop() 
{
  ldrValue = analogRead(P.LDR);// Read present analog input from sensor
  ledValue = map(ldrValue, 0, 1023, 0, 255);/*change the analog out
                                          value to control LED
                                          brightness*/
  analogWrite(P.Led_3,ledValue); // write analog value to output pin
  Serial.print("sensor = "); // print values
  Serial.print(ldrValue);
  Serial.print("\t output = ");
  Serial.println(ledValue);
  delay(10); // Read after every 10 milliSeconds
}
