#include "ProtoKit.h"

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "token_or_secret"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

// Initialize ProtoKit IoT Node
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
   
  pinMode(P.Relay_1, OUTPUT); // To configure RELAY as output pin
  pinMode(P.Relay_2, OUTPUT); // To configure RELAY as output pin
}
int Relay1 = 0; // Initialize Relay state to 0
int Relay2 = 0; // Initialize Relay state to 0

void loop() {
  
  Relay1 = Firebase.getInt("Relay_1"); // Read present Relay_1 state from Firebase Cloud
  Relay2 = Firebase.getInt("Relay_2"); // Read present Relay_2 state from Firebase Cloud

  if (Relay1 == 1) // Check if present Relay state is 1
  {
   digitalWrite(P.Relay_1, HIGH); // Make RELAY HIGH
  } 
  else            //else Check if present Relay state is 0
  {
    digitalWrite(P.Relay_1, LOW); // Make RELAY LOW
  }
  
  if (Relay2 == 1) // Check if present Relay state is 1
  {
   digitalWrite(P.Relay_2, HIGH); // Make RELAY HIGH
  } 
  else            //else Check if present Relay state is 0
  {
    digitalWrite(P.Relay_2, LOW); // Make RELAY LOW
  }
 
  delay(100); // Read after every 100 milliSeconds
}

