#include "ProtoKit.h"

ProtoKit P(IoT_Node);
  
int buttonstate=0; // Initialize buttonstate to 0

void setup() 
{
  Serial.begin(9600); // Baud rate for serial communication
  pinMode(P.SW_1,INPUT);//To configure pushbutton as INPUT pin
  pinMode(P.Led_1,OUTPUT);//To configure pushbutton as INPUT pin
  pinMode(P.Led_2,OUTPUT);//To configure pushbutton as INPUT pin
  pinMode(P.Led_3,OUTPUT); // To configure LED pin as OUTPUT pin
}

void loop() 
{
 buttonstate=digitalRead(P.SW_1); // Read present buttonstate
 Serial.println(buttonstate);/*Print buttonstate in serial 
                               monitor*/
 if (buttonstate == HIGH)// Check if present buttonstate is high 
 {
   digitalWrite(P.Led_1, HIGH);// Make LED HIGH
   digitalWrite(P.Led_2, HIGH);// Make LED HIGH
   digitalWrite(P.Led_3, HIGH);// Make LED HIGH
  } 
  else                //else Check if present buttonstate is low
  {
    digitalWrite(P.Led_1, LOW); // Make LED LOW
    digitalWrite(P.Led_2, LOW); // Make LED LOW
    digitalWrite(P.Led_3, LOW); // Make LED LOW
  }
 delay(10); // Read after every 10 milliSeconds
}
