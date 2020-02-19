/*==============================
    *ProtoKit.h
================================*/

#ifndef PROTOKIT_H
#define PROTOKIT_H

#define WSN_Node 1
#define IoT_Node_V1_0 2
#define IoT_Node_V0_9 3
#define IoT_Node_V1_1 4

#include "Arduino.h"

class ProtoKit
{
  public:
    ProtoKit(uint8_t boardName);
    void pins();
    int Buzzer;       //BUZZER
    int Led_1;       //LED 1
    int Led_2;       //LED 2
    int Led_3;       //LED 3
    int Relay_1;       //RELAY 1
    int Relay_2;       //RELAY 2
    int SW_1;       //PUSHBUTTON 1
    int SW_2;       //PUSHBUTTON 2
    int SW_3;       //PUSHBUTTON 3
    int LDR;        //LDR
    int POT;        //POTENTIOMETER
    int TEMPERATURE;    //LM35
  private:
    uint8_t _boardName;  //BOARD VERSION
    
};

#endif
