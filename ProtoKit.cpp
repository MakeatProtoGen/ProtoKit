/*==============================
    *ProtoKit.cpp
================================*/

#include "Arduino.h"
#include "ProtoKit.h"

#define WSN_Node 1
#define IoT_Node_V1_0 2
#define IoT_Node_V0_9 3
#define IoT_Node_V1_1 4

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

        //case for IoT NodeV V1.0
        case 2: Buzzer = 0;      //BUZZER
                Led_1 = 12;      //LED 1 
                Led_2 = 13;      //LED 2
                Led_3 = 15;      //LED 3
                SW_1 = 16;       //PUSHBUTTON 1
                SW_2 = 2;       //PUSHBUTTON 2
                SW_3 = 14;      //PUSHBUTTON 3
                LDR = A0;       //LDR
                TEMPERATURE = A0;   //LM35
                pinMode(Buzzer, OUTPUT);
		        digitalWrite(Buzzer, HIGH);	
                pinMode(Led_1, OUTPUT);
		        digitalWrite(Led_1,LOW);
                pinMode(Led_2, OUTPUT);
		        digitalWrite(Led_2,LOW);
                pinMode(Led_3, OUTPUT);
		        digitalWrite(Led_3,LOW);
                break; 

        //case for IoT Node V0.9
        case 3: Buzzer = 0;      //BUZZER
                Led_1 = 10;      //LED 1 
                Led_2 = 13;      //LED 2
                Led_3 = 15;      //LED 3
                SW_1 = 16;       //PUSHBUTTON 1
                SW_2 = 12;       //PUSHBUTTON 2
                SW_3 = 14;      //PUSHBUTTON 3
                LDR = A0;       //LDR
                TEMPERATURE = A0;   //LM35	
                pinMode(Buzzer, OUTPUT);
		        digitalWrite(Buzzer,HIGH);
                pinMode(Led_1, OUTPUT);
		        digitalWrite(Led_1,LOW);
                pinMode(Led_2, OUTPUT);
		        digitalWrite(Led_2,LOW);
                pinMode(Led_3, OUTPUT);
		        digitalWrite(Led_3,LOW);
                break;       

        //case for IoT Node V1.1
        case 4: Buzzer = 0;      //BUZZER
                Led_1 = 10;      //LED 1
                Led_2 = 13;      //LED 2
                Led_3 = 15;      //LED 3
                SW_1 = 16;       //PUSHBUTTON 1
                SW_2 = 12;       //PUSHBUTTON 2
                SW_3 = 14;      //PUSHBUTTON 3
                LDR = A0;       //LDR
                TEMPERATURE = A0;   //LM35	
                pinMode(Buzzer, OUTPUT);
		        digitalWrite(Buzzer,LOW);
                pinMode(Led_1, OUTPUT);
		        digitalWrite(Led_1,LOW);
                pinMode(Led_2, OUTPUT);
		        digitalWrite(Led_2,LOW);
                pinMode(Led_3, OUTPUT);
		        digitalWrite(Led_3,LOW);
                break;              
    } 
}
