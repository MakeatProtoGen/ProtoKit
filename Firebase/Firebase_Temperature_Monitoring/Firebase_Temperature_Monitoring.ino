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
}

float val = 0.0; // Initialize val to 0.0
float temp = 0.0; // Initialize temperature to 0.0

void loop() {
  
  val = analogRead(A0); //Read the analog value from A0 will be from 0 - 1023
  temp = val*0.2932; //Convert analog value to Celsius (3/1023)*100

  Firebase.setFloat("Temperature",temp); // Update TEMPERATURE value in Firebase Cloud
  
  delay(100); // Update after every 100 milliSeconds

}

