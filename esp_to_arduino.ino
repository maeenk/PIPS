//This is the program running on Arduino for receiving the
//data from ESP8266

#include <SoftwareSerial.h>
SoftwareSerial fromESP(7,8); //Tx and Rx pins on Arduino

void setup() {
  Serial.begin(115200);
  fromESP.begin(9600);

}

void loop() {
  if (fromESP.available()) //if any data available from ESP8266
  {
    char inChar = fromESP.read(); //read data in char
    Serial.print(inChar); //prints data
  }

}
