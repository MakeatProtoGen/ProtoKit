#include <SoftwareSerial.h> // To define software Serial
#include "ProtoKit.h"

ProtoKit P(WSN_Node);

char incoming=0; //Initialize incoming data to 0

SoftwareSerial WSN(8, 9);//Set software serial(RX,TX) pins

void setup() 
{
  pinMode(P.Led_3,OUTPUT); //To configure LED a output pin
  pinMode(P.Relay_1,OUTPUT); // To configure RELAY as output pin
  Serial.begin(9600); // Baud rate for serial communication
  WSN.begin(9600); /*Baud rate for software serial 
                          communication*/ 
}
void loop() 
{ 
  if(WSN.available()>0) /*check if any incoming data 
                                     from software serial pins */
  {
    incoming = WSN.read();/*read incoming data
                                     from software serial pins */
    WSN.println(incoming);/*print incoming data in serial
                                  monitor*/
    if(incoming=='1') // check if incoming number is digit 1
    {
      digitalWrite(P.Led_3,HIGH); // set LED as high
    }
    if(incoming=='2') // check if incoming number is digit 2
    {
      digitalWrite(P.Led_3,LOW); // set LED as low
    }
    if(incoming=='3') // check if incoming number is digit 3
    {
      digitalWrite(P.Relay_1,HIGH); //Set RELAY as HIGH
    }
    if(incoming=='4') //check if incoming number is digit 4
    {
      digitalWrite(P.Relay_1,LOW);// set RELAY as low
    }
  
  }
}
