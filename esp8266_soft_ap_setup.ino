
//Setting up soft-AP with ESP8266

#include <ESP8266WiFi,h>

void setup() {
  Serial.begin(115200);
  Serial.printLn();

  Serial.print("Setting soft-AP...");
  boolean result = WiFi.softAP("ESPsoftAP_01", "password-to-soft-AP"); //setting up access point ESPsoftAP_01
  if (result == true)
  {
    Serial.println("Ready"); //device connected
  }
  else
  {
    Serial.println("Failed"); //Not connected
  }
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum()); //display 1 if connected, 0 if not
  delay(3000);
}
