#include "ProtoKit.h"

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "token_or_secret"
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"

// Initialize ProtoKit IoT Node
ProtoKit P(IoT_Node);

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
   
  pinMode(P.Led_1, OUTPUT); // To configure LED as output pin
  pinMode(P.Led_2, OUTPUT); // To configure LED as output pin
  pinMode(P.Led_3, OUTPUT); // To configure LED as output pin
}
int Led1 = 0; // Initialize Led1 state to 0
int Led2 = 0; // Initialize Led2 state to 0
int Led3 = 0; // Initialize Led3 state to 0

void loop() {
  
  Led1 = Firebase.getInt("Led_1"); // Read present Led_1 state from Firebase Cloud
  Led2 = Firebase.getInt("Led_2"); // Read present Led_2 state from Firebase Cloud
  Led3 = Firebase.getInt("Led_3"); // Read present Led_3 state from Firebase Cloud

  if (Led1 == 1) // Check if present Led state is 1
  {
   digitalWrite(P.Led_1, HIGH); // Make Led HIGH
  } 
  else            //else Check if present Led state is 0
  {
    digitalWrite(P.Led_1, LOW); // Make Led LOW
  }
  
  if (Led2 == 1) // Check if present Led state is 1
  {
   digitalWrite(P.Led_2, HIGH); // Make Led HIGH
  } 
  else            //else Check if present Led state is 0
  {
    digitalWrite(P.Led_2, LOW); // Make Led LOW
  }
 
  if (Led3 == 1) // Check if present Led state is 1
  {
   digitalWrite(P.Led_3, HIGH); // Make Led HIGH
  } 
  else            //else Check if present Led state is 0
  {
    digitalWrite(P.Led_3, LOW); // Make Led LOW
  }
  delay(100); // Read after every 100 milliSeconds

}

