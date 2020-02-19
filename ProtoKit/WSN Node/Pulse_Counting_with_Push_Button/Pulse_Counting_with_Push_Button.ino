#include "ProtoKit.h"

ProtoKit P(WSN_Node);

int count=0;// Initialize count to 0.                    
int lastButtonState = 0;// Initialize previous buttonstate to 0
int a=0; // Initialize buttonstate to 0.

void setup()
{
  Serial.begin(9600); //Baud rate for serial communication
  pinMode(P.SW_1,INPUT);// To configure pushbutton as INPUT pin
  pinMode(P.Led_1,OUTPUT); // To configure LED pin as OUTPUT pin
}
void loop()
{
  a = digitalRead(P.SW_1); // Read present buttonstate
  if (a != lastButtonState) /* Check if buttonstate is not equal 
                                to previous button state */
  {
    if(a==HIGH)// Check if present buttonstate is high
    {     
      count++; // Count everytime buttonstate is high  
    }
  }
    
  if(count==5) // Check count reaches 5 
  {
    digitalWrite(P.Led_1,HIGH);// Make LED  HIGH
    delay(3000);           // Keep LED  HIGH for 1 second
    digitalWrite(P.Led_1,LOW); // Make LED  LOW after 1 second
    count = 0;               // Reintialize count to 0
  }
  
  Serial.println(count); // print count in serial monitor
  lastButtonState = a;    /* intialize previous button state to 
                          present button state*/
  delay(10);   // Read after every 10 milliSeconds

}
