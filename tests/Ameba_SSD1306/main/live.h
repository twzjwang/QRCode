#ifndef LIVE_HACK4U
#define LIVE_HACK4U

#include <SPI.h>
#include <Wire.h>
#include "wiring_watchdog.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_SSD1306 display(99); //Never used if you use 4pin OLED_LCD

unsigned char  dotMatrix [16 * 64] = {0};

void initLCD(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialize OLED LCD
  display.clearDisplay();
  display.drawBitmap(0, 0,  dotMatrix, 128, 64, 1);
  display.display();
}

#endif
