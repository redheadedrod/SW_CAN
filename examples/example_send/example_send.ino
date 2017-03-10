#include <sw_can.h>
#include <SPI.h>

const int SPI_CS_PIN = 78; // PB23

SWcan SW_CAN(SPI_CS_PIN);   // Set CS pin

void setup()
{
  Serial.begin(115200);
  SW_CAN.setupSW(0x00);
  delay(100);
  SW_CAN.mode(3); // Go to normal mode. 0 - Sleep, 1 - High Speed, 2 - High Voltage Wake-Up, 3 - Normal
  delay(1000);
}

unsigned char stmp[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void loop()
{
  // Extended frame needs to be used
  // send data:  id = 0x00, extended frame, data len = 8, stmp: data buf
  SW_CAN.sendMsgBuf(0x00, 1, 8, stmp);
  delay(100);                       // send data per 100ms
}
