#include <OTA.h>
#include <SoftwareSerial.h>
SoftwareSerial Serial1(0, 1); // RX, TX

#include "live.h";
#include "qrcode.h"

#define OTA_PORT 5000
#define RECOVER_PIN 18

#define QRCODE_VERSION 7
#define QRCODE_ERROR_CORRECT 1

void setup() {
  Serial.begin(9600);
  Wire.begin(); //sda scl

  // Start time
  uint32_t dt = millis();

  // Create the QR code
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(QRCODE_VERSION)];
  qrcode_initText(&qrcode, qrcodeData, QRCODE_VERSION, QRCODE_ERROR_CORRECT, "https://thetangle.org/transaction/BPJIF9OHYZLBOT9PXDMYOWVKSZMLLEJUOQSCM9VHSHHJMYQZVGESCCWSSCIJSECQUUSZNNRXUOGZA9999");

  // Delta time
  dt = millis() - dt;
  Serial.print("QR Code size:");
  Serial.print(qrcode.size);
  Serial.print("\n");
  Serial.print("QR Code Generation Time: ");
  Serial.print(dt);
  Serial.print("\n");

  for (uint8_t y = 0; y < qrcode.size && y < 64; y++) {
    int dotWord = 0;
    for (uint8_t x = 0; x < qrcode.size && x < 16 * 8; x++) {
      dotMatrix[(y + 16) * 16 + (x / 8)] += (qrcode_getModule(&qrcode, x, y) ? 1 : 0) << (7 - x % 8);
    }
  }
  
  initLCD();
}

void loop() {
  delay(1000);
}
