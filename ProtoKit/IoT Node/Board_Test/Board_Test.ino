#include "ProtoKit.h"

// ProtoKit P(IoT_Node_V1_0);
ProtoKit P(IoT_Node_V1_1);
// ProtoKit P(IoT_Node_V0_9);

int button1state = 0; // Initialize button1state to 0
int button2state = 0; // Initialize button2state to 0
int button3state = 0; // Initialize button3state to 0



int val;

void setup()
{
  Serial.begin(9600); // Baud rate for serial communication

  pinMode(P.SW_1, INPUT); //To configure pushbutton as INPUT pin
  pinMode(P.SW_2, INPUT); //To configure pushbutton as INPUT pin
  pinMode(P.SW_3, INPUT); //To configure pushbutton as INPUT pin
  pinMode(P.Led_1, OUTPUT); // To configure LED pin as OUTPUT pin
  pinMode(P.Led_2, OUTPUT); // To configure LED pin as OUTPUT pin
  pinMode(P.Led_3, OUTPUT); // To configure LED pin as OUTPUT pin
  pinMode(P.Buzzer, OUTPUT); // To configure Buzzer pin as OUTPUT pin

  digitalWrite(P.Led_1, HIGH);
  delay(500);
  digitalWrite(P.Led_1, LOW);
  delay(500);
  digitalWrite(P.Led_2, HIGH);
  delay(500);
  digitalWrite(P.Led_2, LOW);
  delay(500);
  digitalWrite(P.Led_3, HIGH);
  delay(500);
  digitalWrite(P.Led_3, LOW);
  delay(500);
  digitalWrite(P.Buzzer, !digitalRead(P.Buzzer));
  delay(500);
  digitalWrite(P.Buzzer, !digitalRead(P.Buzzer));
}

void loop()
{
  button1state = digitalRead(P.SW_1); // Read present buttonstate
  Serial.print(button1state);/*Print buttonstate in serial monitor*/
  button2state = digitalRead(P.SW_2);
  Serial.print(button2state);
  button3state = digitalRead(P.SW_3);
  Serial.print(button3state);

  if (button1state == HIGH | button2state == HIGH | button3state == HIGH) // Check if present buttonstate is high
  {
    digitalWrite(P.Led_1, HIGH);// Make LED HIGH
    digitalWrite(P.Led_2, HIGH);// Make LED HIGH
    digitalWrite(P.Led_3, HIGH);// Make LED HIGH
    delay(10);
  }
  else                //else Check if present buttonstate is low
  {
    digitalWrite(P.Led_1, LOW); // Make LED LOW
    digitalWrite(P.Led_2, LOW); // Make LED LOW
    digitalWrite(P.Led_3, LOW); // Make LED LOW
  }



  val = analogRead(P.TEMPERATURE);
  float mv = val * 2.932;
  float cel = mv / 10;
  float farh = (cel * 9) / 5 + 32;

  Serial.print("  TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(10); // Read after every 10 milliSeconds
}
