
//To be uploaded to ESP8266 that will be used as station point

#include <ESP8266WiFi.h>

byte ledPin = 2;
char ssid[] = "Wemos_AP"; //SSID of the AP
char pass[] = "Wemos_comm"; //password of AP

IPAddress server(192,168,4,15); //IP address of AP
WiFiClient client; //creates a client class that can access services by servers

void setup() {
  Serial.begin(9600);   //start serial with 9600 bits per second
  WiFi.mode(WIFI_STA);  //set mode as station point
  WiFi.begin(ssid, pass); //Connects to the WiFi AP
  Serial.println();       //blank line
  Serial.println(Connection to the AP");
  while (WiFi.status() != WL_CONNECTED) { //Waiting to be connected before going to next line
    Serial.print(".");
    delay(500);
  }
  // Printing connection Status
  Serial.println();
  Serial.println("Connected");
  Serial.println("station_bare_01.ino");
  Serial.print("LocalIP: "); Serial.println(WiFi.localIP()); //ESP station's local IP address
  Serial.println("MAC: " + WiFi.macAddress()); //MAC address of ESP station's interface
  Serial.print("Gateway: "); Serial.println(WiFi.gatewayIP()); //IP address of gateway(router) to access external networks
  Serial.print("AP MAC: "); Serial.println(WiFi.BSSIDstr()); //MAC address of Access Point
  pinMode(ledPin, OUTPUT); //sets digital pin 2 as output
}
//printing data from the server
void loop() {
  client.connect(server, 80);  //connecting to server, 80 is the standard port number
  digitalWrite(ledPin, LOW); //output pin off
  Serial.println("**********************************");
  Serial.print("Byte sent to the AP: ");
  Serial.println(client.print("Anyo\r");
  String answer = client.readStringUntil("\r"); //read string until carriage return
  Serial.println("From the AP: " + answer);
  clent.flush(); //discarding any unread bytes written to the client
  digitalWrite(ledPin, HIGH);
  client.stop();
  delay(2000); //2 second delay
}
