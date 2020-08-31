
//Setting up station point with ESP8266

#include <ESP8266WiFi,h>

void setup() {
  Serial.begin(115200);
  Serial.printLn();

  WiFi.begin("network-name", "password-to-network"); //name of network and password to connect

  Serial.print("Connecting");
  
  while (WiFi.status() != WL_CONNECTED)              //waiting to be connected before going to next step
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());                    //Print the IP address of the network connected
}

void loop() {}
