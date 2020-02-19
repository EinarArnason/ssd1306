#pragma once

#include "Fonts/SansSerif16px.h"
#include "Graphic.h"
#include "I2C.h"
#include <string.h>

const unsigned char SSD1306_MEMORYMODE = 0x20;
const unsigned char SSD1306_COLUMNADDR = 0x21;
const unsigned char SSD1306_PAGEADDR = 0x22;
const unsigned char SSD1306_SETCONTRAST = 0x81;
const unsigned char SSD1306_CHARGEPUMP = 0x8D;
const unsigned char SSD1306_SEGREMAP = 0xA0;
const unsigned char SSD1306_DISPLAYALLON_RESUME = 0xA4;
const unsigned char SSD1306_DISPLAYALLON = 0xA5;
const unsigned char SSD1306_NORMALDISPLAY = 0xA6;
const unsigned char SSD1306_INVERTDISPLAY = 0xA7;
const unsigned char SSD1306_SETMULTIPLEX = 0xA8;
const unsigned char SSD1306_DISPLAYOFF = 0xAE;
const unsigned char SSD1306_DISPLAYON = 0xAF;
const unsigned char SSD1306_COMSCANINC = 0xC0;
const unsigned char SSD1306_COMSCANDEC = 0xC8;
const unsigned char SSD1306_SETDISPLAYOFFSET = 0xD3;
const unsigned char SSD1306_SETDISPLAYCLOCKDIV = 0xD5;
const unsigned char SSD1306_SETPRECHARGE = 0xD9;
const unsigned char SSD1306_SETCOMPINS = 0xDA;
const unsigned char SSD1306_SETVCOMDETECT = 0xDB;

const unsigned char SSD1306_SETLOWCOLUMN = 0x00;
const unsigned char SSD1306_SETHIGHCOLUMN = 0x10;
const unsigned char SSD1306_SETSTARTLINE = 0x40;

const unsigned char SSD1306_EXTERNALVCC = 0x01;
const unsigned char SSD1306_SWITCHCAPVCC = 0x02;

const unsigned char SSD1306_RIGHT_HORIZONTAL_SCROLL = 0x26;
const unsigned char SSD1306_LEFT_HORIZONTAL_SCROLL = 0x27;
const unsigned char SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL = 0x29;
const unsigned char SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL = 0x2A;
const unsigned char SSD1306_DEACTIVATE_SCROLL = 0x2E;
const unsigned char SSD1306_ACTIVATE_SCROLL = 0x2F;
const unsigned char SSD1306_SET_VERTICAL_SCROLL_AREA = 0xA3;

const unsigned char SSD1306_COMMAND = 0x00;
const unsigned char SSD1306_DATA = 0x40;
namespace SSD1306 {
class LCD {
private:
  I2C *i2c;
  int width;
  int height;
  unsigned char *buffer;
  int bufferSize;

public:
  LCD(I2C *i2c, int width, int height);
  ~LCD();
  bool init();
  bool sendData(const unsigned char *data, int size);
  bool sendCommand(const unsigned char cmd);
  /*
      Image must be flipped and top must be oriented left because byte
     orientation in SSD1306 RAM is vertical, width exceeding LCD height is
     fine.
  */
  bool drawXbitmap(const unsigned char *bitmap, int x, int y, int width,
                   int height);
  bool drawXbitmap(Graphic *graphic);
  bool drawXbitmap(Graphic graphic);
  bool writeText(const char *text);
  bool setWritingArea(int x, int y, int width, int height);
  bool clearScreen();
  int lcdWidth();
  int lcdHeight();
};
} // namespace SSD1306