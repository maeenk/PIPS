//This is the transmitter program running on ESP8266
#include <SoftwareSerial.h>
SoftwareSerial toUno(D4,D5); //Rx and Tx pins

void setup() {
  toUno.begin(9600);

}

void loop() {
  toUno.println("Data to send to Arduino"); //data to be printed in Arduino
  delay(2000);

}
