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

// Setup a feed called 'Temperature' for publishing.
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
Adafruit_MQTT_Publish SW_1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/SW_1");
Adafruit_MQTT_Publish SW_2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/SW_2");
Adafruit_MQTT_Publish SW_3 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/SW_3");

/*************************** Sketch Code ************************************/

// Bug workaround for Arduino 1.6.6, it seems to need a function declaration
// for some reason (only affects ESP8266, likely an arduino-builder bug).
void MQTT_connect();

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println(F("ProtoKit Push Button Interface"));

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
  
  pinMode(P.SW_1, INPUT); // To configure SW as input pin
  pinMode(P.SW_2, INPUT); // To configure SW as input pin
  pinMode(P.SW_3, INPUT); // To configure SW as input pin
  
}

int SW1 = 0; // Initialize SW1 state to 0
int SW2 = 0; // Initialize SW2 state to 0
int SW3 = 0; // Initialize SW3 state to 0

void loop() {
  
  
  // Ensure the connection to the MQTT server is alive (this will make the first
  // connection and automatically reconnect when disconnected).  See the MQTT_connect
  // function definition further below.
  MQTT_connect();

  SW1 = digitalRead(P.SW_1); // Read present SW_1 state
  SW2 = digitalRead(P.SW_2); // Read present SW_2 state
  SW3 = digitalRead(P.SW_3); // Read present Led_3 state
  
  // Now we can publish stuff!
  Serial.print(F("\nSending SW1 state "));
  Serial.print(SW1);
  Serial.print("...");
  if (! SW_1.publish(SW1)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  
  Serial.print(F("\nSending SW2 state "));
  Serial.print(SW2);
  Serial.print("...");
  if (! SW_2.publish(SW2)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
  }
  
  Serial.print(F("\nSending SW3 state "));
  Serial.print(SW3);
  Serial.print("...");
  if (! SW_3.publish(SW3)) {
    Serial.println(F("Failed"));
  } else {
    Serial.println(F("OK!"));
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
