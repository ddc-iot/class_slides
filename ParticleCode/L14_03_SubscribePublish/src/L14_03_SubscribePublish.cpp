/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoTPa/Documents/IoT/cohort4/L14_Moisture/L14_03_SubscribePublish/src/L14_03_SubscribePublish.ino"
/*
 * Project L14_03_SubscribePublish
 * Description: Starter Code for Adafruit.io
 * Author: Brian Rashap
 * Date: 6-Aug-2020
 */

#include <Adafruit_MQTT.h>

#include "Adafruit_MQTT/Adafruit_MQTT.h" 
#include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h" 
#include "Adafruit_MQTT/Adafruit_MQTT.h" 

#include "credentials.h"

/************ Global State (you don't need to change this!) ***   ***************/ 
void setup();
void loop();
void MQTT_connect();
#line 17 "c:/Users/IoTPa/Documents/IoT/cohort4/L14_Moisture/L14_03_SubscribePublish/src/L14_03_SubscribePublish.ino"
TCPClient TheClient; 

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 

/****************************** Feeds ***************************************/ 
// Setup Feeds to publish or subscribe 
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname> 
Adafruit_MQTT_Publish mqttObj1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/<FeedNameA");
Adafruit_MQTT_Subscribe mqttObj2 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/FeedNameB");

/************Declare Variables*************/
unsigned long last, lastTime;
float value1, value2;

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
  waitFor(Serial.isConnected, 15000); //wait for Serial Monitor to startup

  //Connect to WiFi without going to Particle Cloud
  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf(".");
  }

  // Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&mqttObj2);
}

void loop() {
  // Validate connected to MQTT Broker
  MQTT_connect();

  // Ping MQTT Broker every 2 minutes to keep connection alive
  if ((millis()-last)>120000) {
      Serial.printf("Pinging MQTT \n");
      if(! mqtt.ping()) {
        Serial.printf("Disconnecting \n");
        mqtt.disconnect();
      }
      last = millis();
  }

  // publish to cloud every 30 seconds
  value1 = random(0,100);
  if((millis()-lastTime > 30000)) {
    if(mqtt.Update()) {
      mqttObj1.publish(value1);
      Serial.printf("Publishing %0.2f \n",value1); 
      } 
    lastTime = millis();
  }


  // this is our 'wait for incoming subscription packets' busy subloop
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(1000))) {
    if (subscription == &mqttObj2) {
      value2 = atof((char *)mqttObj2.lastread);
      Serial.printf("The value received from the Cloud is %0.2f \n",value2);
    }
  }
}

// Function to connect and reconnect as necessary to the MQTT server.
void MQTT_connect() {
  int8_t ret;
 
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
 
  Serial.print("Connecting to MQTT... ");
 
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.printf("%s\n",(char *)mqtt.connectErrorString(ret));
       Serial.printf("Retrying MQTT connection in 5 seconds..\n");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
  }
  Serial.printf("MQTT Connected!\n");
}