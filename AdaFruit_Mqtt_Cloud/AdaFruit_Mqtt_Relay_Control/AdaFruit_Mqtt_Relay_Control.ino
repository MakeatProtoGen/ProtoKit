#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#include "ProtoKit.h"
ProtoKit P(IoT_Node);// Initialize ProtoKit IoT Node

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "...your SSID..."
#define WLAN_PASS       "...your password..."

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // use 8883 for SSL
#define AIO_USERNAME    "...your AIO username (see https://accounts.adafruit.com)..."
#define AIO_KEY         "...your AIO key..."

/************ Global State (you don't need to change this!) ******************/

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;
// or... use WiFiFlientSecure for SSL
//WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

/****************************** Feeds ***************************************/

// Setup a feed called 'Relay' for subscribing to changes.
Adafruit_MQTT_Subscribe Relay1 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay_1");
Adafruit_MQTT_Subscribe Relay2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Relay_2");

/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println(F("ProtoKit Relay Control"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&Relay1);
  mqtt.subscribe(&Relay2);
  
  //Initialize Relay as OUTPUT
  pinMode(P.Relay_1, OUTPUT);
  pinMode(P.Relay_2, OUTPUT);
}

uint32_t x=0;

void loop() {
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();

  // this is our 'wait for incoming subscription packets' busy subloop
  // try to spend your time here

  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(5000))) {
    if (subscription == &Relay1) 
    {
      Serial.print(F("Relay_1: "));
      Serial.println((char *)Relay1.lastread);
      
      int state = atoi((char *)Relay1.lastread); //Convert ASCII to Integer and store in state
      
      if (state == 1) // Check if present buttonstate is high
      {
       digitalWrite(P.Relay_1, HIGH); // Make RELAY HIGH
      } 
      else            //else Check if present buttonstate is low
      {
        digitalWrite(P.Relay_1, LOW); // Make RELAY LOW
      }
    }
    
    if (subscription == &Relay2) 
    {
      Serial.print(F("Relay_2: "));
      Serial.println((char *)Relay2.lastread);
      
      int state = atoi((char *)Relay2.lastread); //Convert ASCII to Integer and store in state
      
      if (state == 1) // Check if present buttonstate is high
      {
       digitalWrite(P.Relay_2, HIGH); // Make RELAY HIGH
      } 
      else            //else Check if present buttonstate is low
      {
        digitalWrite(P.Relay_2, LOW); // Make RELAY LOW
      }
    }
    
  }

  // ping the server to keep the mqtt connection alive
  // NOT required if you are publishing once every KEEPALIVE seconds
  /*
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }
  */
  delay(5000);
}

// Function to connect and reconnect as necessary to the MQTT server.

// Should be called in the loop function and it will take care if connecting.

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
