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
  // First we genereate a random integer to set as antenna delay
  uint16_t randNumber = random(65535);
  DW1000Ng::setAndSaveAntennaDelay(randNumber);
  // Now the antenna delay is set to this number, and it is saved in the EEPROM
  Serial.println("Now in EEPROM: " + String(DW1000Ng::getSavedAntennaDelay()));
  Serial.println("TX delay: " + String(DW1000Ng::getTxAntennaDelay()));
  Serial.println("RX delay: " + String(DW1000Ng::getRxAntennaDelay()));
  // We simulate a reboot by resetting the antenna delay
  DW1000Ng::setAntennaDelay(0);
  Serial.println("TX delay: " + String(DW1000Ng::getTxAntennaDelay()));
  Serial.println("RX delay: " + String(DW1000Ng::getRxAntennaDelay()));
  // We can now restore it from EEPROM
  DW1000Ng::setAntennaDelayFromEEPROM();
  Serial.println("Restored from EEPROM");
  Serial.println("TX delay: " + String(DW1000Ng::getTxAntennaDelay()));
  Serial.println("RX delay: " + String(DW1000Ng::getRxAntennaDelay()));

  // You can also of course retrieve the value saved in EEPROM like this
  uint16_t delaySavedInEEPROM = DW1000Ng::getSavedAntennaDelay();
}

void loop() {
  
}
