#include "SSD1306.h"

SSD1306::LCD::LCD(I2C *i2c, int width, int height) {
  this->i2c = i2c;
  this->width = width;
  this->height = height;
  // Divided with bits per byte
  this->bufferSize = width * height / 8;
  this->buffer = new unsigned char[bufferSize];
}

SSD1306::LCD::~LCD() {
  clearScreen();
  delete[] buffer;
  buffer = nullptr;
  delete i2c;
}

bool SSD1306::LCD::sendCommand(const unsigned char cmd) {
  unsigned char msg[] = {SSD1306_COMMAND, cmd};
  if (i2c->send(msg, sizeof(msg))) {
    return true;
  }

  return false;
}

bool SSD1306::LCD::sendData(const unsigned char *data, int size) {
  for (int i = 0; i < size; ++i) {
    unsigned char msg[] = {SSD1306_DATA, data[i]};
    if (!i2c->send(msg, sizeof(msg))) {
      return false;
    }
  }

  return true;
}

bool SSD1306::LCD::init() {
  if (i2c->init()) {
    bool success = false;
    // Initialization sequence
    success = sendCommand(SSD1306_DISPLAYOFF);
    success = sendCommand(SSD1306_SETDISPLAYCLOCKDIV);
    success = sendCommand(0x80);
    success = sendCommand(SSD1306_SETMULTIPLEX);
    success = sendCommand(height - 1);
    success = sendCommand(SSD1306_SETDISPLAYOFFSET);
    success = sendCommand(0x00);
    success = sendCommand(SSD1306_SETSTARTLINE | 0x00);
    success = sendCommand(SSD1306_CHARGEPUMP);
    success = sendCommand(0x14);
    success = sendCommand(SSD1306_MEMORYMODE);
    success = sendCommand(0x01);
    success = sendCommand(SSD1306_SEGREMAP | 0x1);
    success = sendCommand(SSD1306_COMSCANDEC);
    success = sendCommand(SSD1306_SETCOMPINS);
    success = sendCommand(0x12);
    success = sendCommand(SSD1306_SETCONTRAST);
    success = sendCommand(0xCF);
    success = sendCommand(SSD1306_SETPRECHARGE);
    success = sendCommand(0xF1);
    success = sendCommand(SSD1306_SETVCOMDETECT);
    success = sendCommand(0x40);
    success = sendCommand(SSD1306_DISPLAYALLON_RESUME);
    success = sendCommand(SSD1306_NORMALDISPLAY);
    success = sendCommand(SSD1306_DEACTIVATE_SCROLL);
    success = sendCommand(SSD1306_DISPLAYON);
    success = sendCommand(SSD1306_COLUMNADDR);
    success = sendCommand(0x00);
    success = sendCommand(width - 1);
    success = sendCommand(SSD1306_PAGEADDR);
    success = sendCommand(0x00);
    success = sendCommand(0xFF);
    success = clearScreen();

    return success;
  } else {
    return false;
  }
}

bool SSD1306::LCD::drawXbitmap(const unsigned char *bitmap, int x, int y,
                               int width, int height) {
  bool success = false;
  // Align writing area
  success = setWritingArea(x, y, width, height);
  // Draw image
  success = sendData(bitmap, width * height / 8);

  return success;
}

bool SSD1306::LCD::drawXbitmap(Graphic *graphic) {
  return drawXbitmap(graphic->getData(), 0, 0, graphic->getWidth(),
                     graphic->getHeight());
}

bool SSD1306::LCD::drawXbitmap(Graphic graphic) {
  return drawXbitmap(graphic.getData(), 0, 0, graphic.getWidth(),
                     graphic.getHeight());
}

// Writing area for text needs to be set up as textboxes with matching height of
// the font
bool SSD1306::LCD::writeText(const char *text) {
  for (; *text != '\0'; ++text) {
    int index = *text - 32;
    unsigned char *iterator = SANS_SERIF_16PX_POINTERS[index];
    for (; iterator != SANS_SERIF_16PX_POINTERS[index + 1]; ++iterator) {
      unsigned char msg[] = {SSD1306_DATA, *iterator};
      if (!i2c->send(msg, sizeof(msg))) {
        return false;
      }
    }
  }

  return true;
}

bool SSD1306::LCD::setWritingArea(int x, int y, int width, int height) {
  bool success = false;
  success = sendCommand(SSD1306_COLUMNADDR);
  success = sendCommand(x);
  success = sendCommand(x + (width - 1));
  success = sendCommand(SSD1306_PAGEADDR);
  int pageStart = (unsigned char)y / 8;
  success = sendCommand(pageStart);
  success = sendCommand(pageStart + (height / 8) - 1);

  return success;
}

bool SSD1306::LCD::clearScreen() {
  memset(buffer, 0x00, bufferSize);
  return sendData(buffer, bufferSize);
}

int SSD1306::LCD::lcdWidth() { return width; }

int SSD1306::LCD::lcdHeight() { return height; }