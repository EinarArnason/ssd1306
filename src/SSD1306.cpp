#include "SSD1306.h"

SSD1306::LCD::LCD(I2C* i2c, int width, int height, unsigned long frequency,
                  unsigned char address) {
  this->i2c = i2c;
  this->width = width;
  this->height = height;
  // Divided with bits per byte
  this->size = width * height / 8;
  this->inverted = false;
  this->i2cConfig.address = address;
  this->i2cConfig.frequency = frequency;
}

SSD1306::LCD::~LCD() { turnOff(); }

bool SSD1306::LCD::sendCommand(const unsigned char cmd) {
  unsigned char msg[] = {COMMAND, cmd};
  if (i2c->send(i2cConfig, (char*)msg, sizeof(msg))) {
    return true;
  }

  return false;
}

bool SSD1306::LCD::sendData(const unsigned char* data, int size) {
  for (int i = 0; i < size; ++i) {
    unsigned char msg[] = {DATA, data[i]};
    if (!i2c->send(i2cConfig, (char*)msg, sizeof(msg))) {
      return false;
    }
  }

  return true;
}

bool SSD1306::LCD::init() {
  if (i2c->init()) {
    int success = 0;
    int count = 0;
    isOn = true;
    contrast = 0;
    // Initialization sequence
    success += turnOff();
    count++;
    success += setMultiplexRatio(height - 1);
    count++;
    success += sendCommand(SET_DISPLAY_OFFSET);
    count++;
    success += sendCommand(0x00);
    count++;
    success += sendCommand(SET_START_LINE);
    count++;
    success += sendCommand(SET_SEGMENT_REMAP_OFF);
    count++;
    success += sendCommand(SET_COM_OUTPUT_SCAN_NORMAL);
    count++;
    success += sendCommand(SET_COM_PINS_HW_CONFIG);
    count++;
    success += sendCommand(COM_PINS_SEQUENTIAL);
    count++;
    success += setContrast(DEFAULT_CONTRAST);
    count++;
    success += sendCommand(ENTIRE_DISPLAY_ON_RESUME_RAM);
    count++;
    success += sendCommand(NORMAL_DISPLAY);
    count++;
    success += sendCommand(SET_DISPLAY_CLOCK_DIVIDER);
    count++;
    success += sendCommand(DEFAULT_DISPLAY_CLOCK_DIVIDER);
    count++;
    success += sendCommand(CHARGE_PUMP_SETTING);
    count++;
    success += sendCommand(CHARGE_PUMP_ENABLE);
    count++;
    success += setMemoryAddressingMode(MEMORY_ADDRESSING_VERTICAL);
    count++;
    success += sendCommand(DEACTIVATE_SCROLL);
    count++;
    success += clearScreen();
    count++;
    success += turnOn();
    count++;

    return success == count;
  } else {
    return false;
  }
}

// Align writing area and draw x bitmap image
bool SSD1306::LCD::drawXbitmap(const unsigned char* bitmap, int x, int y,
                               int width, int height) {
  return setWritingArea(x, y, width, height) &&
         sendData(bitmap, width * height / 8);
}

bool SSD1306::LCD::drawXbitmap(Graphic* graphic) {
  return drawXbitmap(graphic->getData(), 0, 0, graphic->getWidth(),
                     graphic->getHeight());
}

bool SSD1306::LCD::drawXbitmap(Graphic graphic) {
  return drawXbitmap(graphic.getData(), 0, 0, graphic.getWidth(),
                     graphic.getHeight());
}

// Writing area for text needs to be set up as textboxes with matching height of
// the font
bool SSD1306::LCD::writeText(const char* text, int length) {
  int dataWritten = 0;
  for (; *text != '\0'; ++text) {
    int index = *text - ASCII_OFFSET;

    if (index >= SANS_SERIF_16PX_POINTERS_LENGTH) {
      continue;
    }

    unsigned char* iterator = SANS_SERIF_16PX_POINTERS[index];
    for (; iterator != SANS_SERIF_16PX_POINTERS[index + 1]; ++iterator) {
      unsigned char msg[] = {DATA, *iterator};
      if (!i2c->send(i2cConfig, (char*)msg, sizeof(msg))) {
        return false;
      }

      dataWritten++;
    }
  }

  unsigned char pad[length - dataWritten];
  memset(pad, 0, sizeof(pad));
  sendData(pad, sizeof(pad));

  return true;
}

bool SSD1306::LCD::setWritingArea(int x, int y, int width, int height) {
  int success = 0;
  int count = 0;
  success += setColumnRange(x, x + (width - 1));
  count++;
  int pageStart = (unsigned char)y / 8;
  success += setPageRange(pageStart, pageStart + (height / 8) - 1);
  count++;

  return success == count;
}

bool SSD1306::LCD::setWritingArea(SSD1306::TextBox textBox) {
  return setWritingArea(textBox.x(), textBox.y(), textBox.width(),
                        textBox.height());
}

bool SSD1306::LCD::fillRectangle(int x, int y, int width, int height,
                                 bool color) {
  int size = width * height / 8;
  unsigned char data;

  if (color) {
    data = 0xff;
  } else {
    data = 0x00;
  }

  if (!setWritingArea(x, y, width, height)) {
    return false;
  }

  for (int i = 0; i < size; ++i) {
    unsigned char msg[] = {DATA, data};
    if (!i2c->send(i2cConfig, (char*)msg, sizeof(msg))) {
      return false;
    }
  }

  return true;
}

bool SSD1306::LCD::print(TextBox textBox, const char* text) {
  return setWritingArea(textBox) && writeText(text, textBox.size());
}

bool SSD1306::LCD::clearScreen() {
  unsigned char buffer[size];
  memset(buffer, 0x00, size);
  int success = 0;
  int count = 0;
  success += setColumnRange(0x00, 0xFF);
  count++;
  success += setPageRange(0x00, 0xFF);
  count++;
  success += sendData(buffer, size);
  count++;

  return success == count;
}

bool SSD1306::LCD::turnOff() {
  if (isOn && sendCommand(SSD1306::DISPLAY_OFF)) {
    isOn = false;
    return true;
  }

  return false;
}

bool SSD1306::LCD::turnOn() {
  if (!isOn && sendCommand(SSD1306::DISPLAY_ON)) {
    isOn = true;
    return true;
  };

  return false;
}

bool SSD1306::LCD::lcdIsOn() { return isOn; }

bool SSD1306::LCD::setContrast(unsigned char value) {
  if (contrast == value) {
    return false;
  }

  int success = 0;
  int count = 0;
  success += sendCommand(SSD1306::SET_CONTRAST);
  count++;
  success += sendCommand(value);
  count++;

  if (success == count) {
    contrast = value;
    return true;
  }

  return false;
}

bool SSD1306::LCD::entireDisplayOn(bool resumeRam) {
  if (resumeRam) {
    return sendCommand(ENTIRE_DISPLAY_ON_RESUME_RAM);
  }
  return sendCommand(ENTIRE_DISPLAY_ON_IGNORE_RAM);
}

bool SSD1306::LCD::setMultiplexRatio(unsigned char ratio) {
  int success = 0;
  int count = 0;
  success += sendCommand(SET_MUX_RATIO);
  count++;
  success += sendCommand(ratio);
  count++;

  return success == count;
}

bool SSD1306::LCD::setMemoryAddressingMode(unsigned char mode) {
  int success = 0;
  int count = 0;
  success += sendCommand(SET_MEMORY_ADDRESSING_MODE);
  count++;
  success += sendCommand(mode);
  count++;

  return success == count;
}

bool SSD1306::LCD::invert() {
  if (inverted) {
    if (sendCommand(NORMAL_DISPLAY)) {
      inverted = false;
      return true;
    } else {
      return false;
    }
  }

  if (sendCommand(INVERT_DISPLAY)) {
    inverted = true;
    return true;
  }

  return false;
}

bool SSD1306::LCD::setColumnRange(unsigned char start, unsigned char end) {
  int success = 0;
  int count = 0;
  success += sendCommand(SET_COLUMN_ADDRESS);
  count++;
  success += sendCommand(start);
  count++;
  success += sendCommand(end);
  count++;

  return success == count;
}

bool SSD1306::LCD::setPageRange(unsigned char start, unsigned char end) {
  int success = 0;
  int count = 0;
  success += sendCommand(SET_PAGE_ADDRESS);
  count++;
  success += sendCommand(start);
  count++;
  success += sendCommand(end);
  count++;

  return success == count;
}

bool SSD1306::LCD::setChargePumpSetting(unsigned char setting) {
  int success = 0;
  int count = 0;
  success += sendCommand(CHARGE_PUMP_SETTING);
  count++;
  success += sendCommand(setting);
  count++;

  return success == count;
}

int SSD1306::LCD::lcdWidth() { return width; }

int SSD1306::LCD::lcdHeight() { return height; }