#include <DW1000Ng.hpp>

// connection pins
#if defined(ESP8266)
const uint8_t PIN_RST = 5; // reset pin
const uint8_t PIN_IRQ = 4; // irq pin
const uint8_t PIN_SS = 15; // spi select pin
#else
const uint8_t PIN_RST = 9; // reset pin
const uint8_t PIN_IRQ = 2; // irq pin
const uint8_t PIN_SS = SS; // spi select pin
#endif


void setup() {
  // DEBUG monitoring
  Serial.begin(9600);
  // initialize the driver
  DW1000Ng::initialize(PIN_SS, PIN_IRQ, PIN_RST);
  Serial.println(F("DW1000Ng initialized ..."));
  // general configuration
  DW1000Ng::setDeviceAddress(5);
  DW1000Ng::setNetworkId(10);
  Serial.println(F("Committed configuration ..."));
  // wait a bit
  delay(1000);
}

void loop() {
  // DEBUG chip info and registers pretty printed
  char msg[128];
  DW1000Ng::getPrintableDeviceIdentifier(msg);
  Serial.print("Device ID: "); Serial.println(msg);
  DW1000Ng::getPrintableExtendedUniqueIdentifier(msg);
  Serial.print("Unique ID: "); Serial.println(msg);
  DW1000Ng::getPrintableNetworkIdAndShortAddress(msg);
  Serial.print("Network ID & Device Address: "); Serial.println(msg);
  DW1000Ng::getPrintableDeviceMode(msg);
  Serial.print("Device mode: "); Serial.println(msg);
  // wait a bit
  delay(10000);
}
