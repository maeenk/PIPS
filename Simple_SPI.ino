#include <SPI.h>
#define XSPI_MISO 14
#define XSPI_MOSI 12
#define XSPI_SCLK 13
#define XSPI_SS 15

// Put SCK, MOSI, SS pins into output mode
// Also put SCK, MOSI into LOW state, and SS into HIGH state
// Then put SPI hardware into Master mode and turn SPI on

SPISettings settingsA(2000000,MSBFIRST,SPI_MODE0);  // 2MHz Minimum Speed Before was 20 MHz
int rx_data[11];
void setup(){
  pinMode(XSPI_SS, OUTPUT);
  digitalWrite(XSPI_SS, HIGH);
  pinMode(XSPI_MOSI, OUTPUT);
  digitalWrite(XSPI_SS, LOW);
  pinMode(XSPI_SCLK,OUTPUT);
  digitalWrite(XSPI_SCLK, LOW);
  pinMode(XSPI_MISO,INPUT);
  Serial.begin(115200);
  SPI.begin();
  SPI.transfer(0x10);
  for (int i = 0; i < 11; ++i){
    rx_data[i] = SPI.transfer(0);
  }
}

void loop(){
  int val_1, val_2;
  Serial.print("Sending command, getting back these bytes: ");
  digitalWrite(SS, LOW);
  SPI.beginTransaction(settingsA);
  val_1 = SPI.transfer(0xAA);
  val_2 = SPI.transfer(0x55);
  SPI.endTransaction();
  digitalWrite(SS,HIGH);

  Serial.print(" ");
  Serial.print(val_1, HEX);
  Serial.print(val_2, HEX);
  Serial.println("- Done -");
  Serial.println(" ");
  delay(100);
}
