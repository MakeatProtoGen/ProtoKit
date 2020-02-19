#include "ProtoKit.h"

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "example.firebaseio.com"
#define FIREBASE_AUTH "token_or_secret"
#define FIREBASE_HOST "esptest-68005.firebaseio.com"
#define FIREBASE_AUTH "FstwMokSUscz1l29AaMh7wHhqRPHmjCDRhcV3LGv"
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
}

float val = 0.0; // Initialize val to 0.0
float light = 0.0; // Initialize temperature to 0.0

void loop() {
  
  val = analogRead(A0); //Read the analog value from A0 will be from 0 - 1023
  light = val*.09775; //Convert analog value to Percentage of Light Intensity (3/1023)*(100/3)  
  Firebase.setFloat("Light_Intensity",light);// Update LIGHT INTENSITY percentage in Firebase Cloud
  
  delay(100); // Update after every 100 milliSeconds

}

