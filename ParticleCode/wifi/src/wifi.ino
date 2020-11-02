/*
 * Project wifi
 * Description:
 * Author:
 * Date:
 */

WiFiAccessPoint ap[10];
WiFiAccessPoint aps[20];

void setup() {
  Serial.begin(9600);

  Serial.printf("ip address: %s \n", WiFi.localIP().toString().c_str());
  int found = WiFi.getCredentials(ap, 5);
  for (int i = 0; i < found; i++) {
    Serial.printf("ssid: %s \n", ap[i].ssid);
    // security is one of WLAN_SEC_UNSEC, WLAN_SEC_WEP, WLAN_SEC_WPA, WLAN_SEC_WPA2, WLAN_SEC_WPA_ENTERPRISE, WLAN_SEC_WPA2_ENTERPRISE
    Serial.printf("security: %d \n", (int) ap[i].security);
    // cipher is one of WLAN_CIPHER_AES, WLAN_CIPHER_TKIP or WLAN_CIPHER_AES_TKIP
    Serial.printf("cipher: %d \n", (int) ap[i].cipher);
  }

  found = WiFi.scan(aps, 20);
  for (int i=0; i<found; i++) {
    WiFiAccessPoint& ap1 = aps[i];
    Serial.printf("ssid=%s security=%d channel=%d rssi=%d \n", ap1.ssid, (int)ap1.security, (int)ap1.channel, ap1.rssi);
  }
}

void loop() {

}