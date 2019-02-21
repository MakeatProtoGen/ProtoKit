/*==============================
    *ProtoKit.cpp
================================*/

#include "Arduino.h"
#include "ProtoKit.h"

#define WSN_Node 1
#define IoT_Node 2

//CONSTRUCTOR TO CHOOSE BOARD
ProtoKit::ProtoKit(uint8_t boardName){
    _boardName = boardName;
    pins();
}

void ProtoKit::pins(){
    switch(_boardName){
        //case for WSN Node
        case 1: Buzzer = 16;      //BUZZER
                Led_1 = 8;       //LED 1
                Led_2 = 9;       //LED 2
                Led_3 = 10;      //LED 3
                Relay_1 = 5;       //RELAY 1
                Relay_2 = 6;       //RELAY 2
                SW_1 = 2;       //PUSHBUTTON 1
                SW_2 = 3;       //PUSHBUTTON 2
                SW_3 = 7;       //PUSHBUTTON 3
                LDR = 15;       //LDR
                POT = 17;       //POTENTIOMETER
                TEMPERATURE = 14;   //LM35
                break;

        //case for IoT Node
        case 2: Buzzer = 0;      //BUZZER
                Led_1 = 10;      //LED 1
                Led_2 = 13;      //LED 2
                Led_3 = 15;      //LED 3
                Relay_1 = 10;      //RELAY 1
                Relay_2 = 13;      //RELAY 2
                SW_1 = 16;       //PUSHBUTTON 1
                SW_2 = 12;       //PUSHBUTTON 2
                SW_3 = 14;      //PUSHBUTTON 3
                LDR = A0;       //LDR
                TEMPERATURE = A0;   //LM35
		pinMode(10, OUTPUT);
		digitalWrite(10,LOW);
		digitalWrite(0,HIGH);	
                break;                         
    } 
}
