  
//To be uploaded to ESP8266 that acts as the access point

#include <ESP8266WiFi.h>

WiFiServer server(80);
IPAddress IP(192,168,5,15); //setting IP address
IPAddress mask = (255,255,255,0); //subnet mask

byte ledPin = 2;

void setup() {
  Serial.begin(9600); //begin serial at 9600 bits/s
  WiFi.mode(WIFI_AP); //set mode as access point
  WiFi.softAP("Wemos_AP", "Wemos_comm");
  WiFi.softAPConfig(IP, IP, mask); //configure network interface (local IP, gateway, subnet)
  server.begin();
  pinMode(ledPin, OUTPUT); //setting pin 2 as output
  Serial.println(); //blank line
  Serial.println("accesspoint_bare_01.info");
  Serial.println("Server started");
  Serial.print("IP: "); Serial.println(WiFi.softAPIP()); //prints IP address of AP
  Serial.print("MAC: "); Serial.println(WiFi.softAPmacAddress()); //prints MAC address of AP
}

void loop() {
  WiFiClient client = server.available(); //connecting to a client
  if (!client) {return;} //if no client found, exit
  digitalWrite(ledPin, LOW); //output pin set to low
  String request = client.readStringUntil('\r'); //server read's the client's request
  Serial.println("********************************");
  Serial.println("From the station: " + request); //prints the client's request
  client.flush(); //discard any unread bytes
  Serial.print("Byte sent to the station: ");
  Serial.println("client.println(request + "ca" + "\r"));
  digitalWrite(ledPin, HIGH); //output pin is high
}
