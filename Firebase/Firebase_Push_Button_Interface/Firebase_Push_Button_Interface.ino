#include "ProtoKit.h"

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "token_or_secret"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

// Initialize ProtoKit IoT Node
// ProtoKit P(IoT_Node_V1_0);
ProtoKit P(IoT_Node_V1_1);
// ProtoKit P(IoT_Node_V0_9);

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
   
  pinMode(P.SW_1, INPUT); // To configure SW as input pin
  pinMode(P.SW_2, INPUT); // To configure SW as input pin
  pinMode(P.SW_3, INPUT); // To configure SW as input pin
}

int SW1 = 0; // Initialize SW1 state to 0
int SW2 = 0; // Initialize SW2 state to 0
int SW3 = 0; // Initialize SW3 state to 0

void loop() {
  
  SW1 = digitalRead(P.SW_1); // Read present SW_1 state
  SW2 = digitalRead(P.SW_2); // Read present SW_2 state
  SW3 = digitalRead(P.SW_3); // Read present Led_3 state

  Firebase.setInt("SW_1", SW1); //Update the current state of the SW1 in Firebase Cloud
        // handle error
      if (Firebase.failed()) {
          Serial.print("SW_1 update failed:");
          Serial.println(Firebase.error());  
          return;
      }

  Firebase.setInt("SW_2", SW2); //Update the current state of the SW2 in Firebase Cloud
        // handle error
      if (Firebase.failed()) {
          Serial.print("SW_2 update failed:");
          Serial.println(Firebase.error());  
          return;
      }

  Firebase.setInt("SW_3", SW3); //Update the current state of the SW3 in Firebase Cloud
        // handle error
      if (Firebase.failed()) {
          Serial.print("SW_3 update failed:");
          Serial.println(Firebase.error());  
          return;
      }

  delay(100); // Update after every 100 milliSeconds

}

