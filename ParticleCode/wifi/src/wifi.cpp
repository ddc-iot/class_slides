/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/IoTPa/Documents/Particle/wifi/src/wifi.ino"
/*
 * Project WiFi
 * Description: Determine which WiFi connections the Argon has stored and which are visible
 * Author: Brian Rashap
 * Date: 16-SEP-2020
 */

void setup();
void loop();
#line 8 "c:/Users/IoTPa/Documents/Particle/wifi/src/wifi.ino"
WiFiAccessPoint ap[10];
WiFiAccessPoint aps[20];

int sectype;
int cytype;
int found;
int i;
byte mac[6];

String security[6] = {"WLAN_SEC_UNSEC", "WLAN_SEC_WEP", "WLAN_SEC_WPA", "WLAN_SEC_WPA2", "WLAN_SEC_WPA_ENTERPRISE", "WLAN_SEC_WPA2_ENTERPRISE"};
String cypher[4] = {"N/A","WLAN_CIPHER_AES", "WLAN_CIPHER_TKIP", "WLAN_CIPHER_AES_TKIP"};

void setup() {
  Serial.begin(9600);
  delay(100);

  Serial.printf("Scan Argon for Saved Credentials \n");
  Serial.printf("ip address: %s \n", WiFi.localIP().toString().c_str());
  WiFi.macAddress(mac);
  Serial.printf("mac: %02X:%02X:%02X:%02X:%02X:%02X \n", mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
  found = WiFi.getCredentials(ap, 5);
  Serial.printf("Credentials for %d Access Points Found \n",found);
  for (i = 0; i < found; i++) {
    sectype = (int) ap[i].security;
    cytype = (int) ap[i].cipher;
    for(int j=0;j<6;j++){
      mac[j] = ap[i].bssid[j];
    }
    
    Serial.printf("AP%d - ssid: %s \n", i,ap[i].ssid);
    Serial.printf("AP%d - mac: %02X:%02X:%02X:%02X:%02X:%02X \n", i,mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
    Serial.printf("AP%d - security: %d (security %s) \n", i,sectype,security[sectype].c_str());
    Serial.printf("AP%d - cipher:   %d (cipher %s) \n\n", i,cytype, cypher[cytype].c_str());
  }


  Serial.printf("\n \nWifi Scan of available networks \n");
  found = WiFi.scan(aps, 20); 
  for (i=0; i<found; i++) {
    Serial.printf("ssid=%s security=%d cipher=%d, channel=%d rssi=%d \n", aps[i].ssid, (int)aps[i].security, (int)aps[i].cipher, aps[i].channel, aps[i].rssi);
  }
}

void loop() {

}