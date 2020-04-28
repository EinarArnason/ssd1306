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

bool SSD1306::LCD::sendData(const unsigned char data) {
    unsigned char msg[] = {DATA, data};
    return i2c->send(i2cConfig, (char*)msg, sizeof(msg));
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
    success += setMultiplexRatio(width - 1);
    count++;
    success += setDisplayOffset();
    count++;
    success += setDisplayStartLine();
    count++;
    success += setSegmentRemap();
    count++;
    success += setComOutputScanDirection();
    count++;
    success += setComPinsHwConfig();
    count++;
    success += setContrast();
    count++;
    success += entireDisplayOn();
    count++;
    success += invert(false);
    count++;
    success += setDisplayClock(0, 8);
    count++;
    success += setChargePumpSetting(true);
    count++;
    success += setMemoryAddressingMode(MEMORY_ADDRESSING_VERTICAL);
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

  // Padding to clear leftover pixels on screen
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

bool drawLine(unsigned char x1, unsigned char y1, unsigned char x2,
                unsigned char y2, unsigned char width) {
  
  return false;
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

bool SSD1306::LCD::setLowerColumnStartAddress(unsigned char address) {
  address = SET_LOWER_COLUMN_START_ADDRESS | (address & 0x0F);
  return sendCommand(address);
}

bool SSD1306::LCD::setHigherColumnStartAddress(unsigned char address) {
  address = SET_HIGHER_COLUMN_START_ADDRESS | (address & 0x0F);
  return sendCommand(address);
}

bool SSD1306::LCD::setMemoryAddressingMode(unsigned char mode) {
  mode = mode & 0x03;
  if (mode == 3) {
    return false;
  }

  int success = 0;
  int count = 0;
  success += sendCommand(SET_MEMORY_ADDRESSING_MODE);
  count++;
  success += sendCommand(mode);
  count++;

  return success == count;
}

bool SSD1306::LCD::setColumnRange(unsigned char start, unsigned char end) {
  start = start & 0x7F;
  end = end & 0x7F;
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
  start = start & 0x07;
  end = end & 0x07;
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

bool SSD1306::LCD::setDisplayStartLine(unsigned char start) {
  start = SET_START_LINE | (start & 0x3F);

  return sendCommand(start);
}

bool SSD1306::LCD::setContrast(unsigned char value) {
  if (contrast == value) {
    return false;
  }

  int success = 0;
  int count = 0;
  success += sendCommand(SET_CONTRAST);
  count++;
  success += sendCommand(value);
  count++;

  if (success == count) {
    contrast = value;
    return true;
  }

  return false;
}

bool SSD1306::LCD::setSegmentRemap(bool remap) {
  unsigned char mapping = SET_SEGMENT_REMAP | remap;

  return sendCommand(mapping);
}

bool SSD1306::LCD::entireDisplayOn(bool resumeRam) {
  unsigned char cmd = ENTIRE_DISPLAY_ON | resumeRam;

  return sendCommand(cmd);
}

bool SSD1306::LCD::invert(bool invert) {
  unsigned char inverse = SET_INVERSE | invert;

  if (sendCommand(inverse)) {
    inverted = invert;
    return true;
  }

  return false;
}

bool SSD1306::LCD::invert() {
  unsigned char inverse = SET_INVERSE | !inverted;

  if (sendCommand(inverse)) {
    inverted = !inverted;
    return true;
  }

  return false;
}

bool SSD1306::LCD::setMultiplexRatio(unsigned char ratio) {
  ratio = ratio & 0x3F;
  int success = 0;
  int count = 0;
  success += sendCommand(SET_MUX_RATIO);
  count++;
  success += sendCommand(ratio);
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

bool SSD1306::LCD::setPageStartAddress(unsigned char address) {
  address = SET_PAGE_START_ADDRESS | (address & 0x07);

  return sendCommand(address);
}

bool SSD1306::LCD::setComOutputScanDirection(bool remapped) {
  unsigned char direction = SET_COM_OUTPUT_SCAN | (remapped << 3);

  return sendCommand(direction);
}

bool SSD1306::LCD::setDisplayOffset(unsigned char offset) {
  offset = offset & 0x3F;
  int success = 0;
  int count = 0;
  success += sendCommand(SET_DISPLAY_OFFSET);
  count++;
  success += sendCommand(offset);
  count++;

  return success == count;
}

bool SSD1306::LCD::setDisplayClock(unsigned char ratio,
                                   unsigned char frequency) {
  unsigned char cmd = (frequency << 4) | (ratio & 0x0F);
  int success = 0;
  int count = 0;
  success += sendCommand(SET_DISPLAY_CLOCK);
  count++;
  success += sendCommand(cmd);
  count++;

  return success == count;
}

bool SSD1306::LCD::setPreChargePeriod(unsigned char phase1,
                                      unsigned char phase2) {
  unsigned char cmd = (phase2 << 4) | (phase1 & 0x0F);

  if (!cmd) {
    return false;
  }

  int success = 0;
  int count = 0;
  success += sendCommand(SET_PRECHARGE_PERIOD);
  count++;
  success += sendCommand(cmd);
  count++;

  return success == count;
}

bool SSD1306::LCD::setComPinsHwConfig(bool alternative, bool leftRightRemap) {
  unsigned char cmd = 0x02 | (alternative << 4) | (leftRightRemap << 5);
  int success = 0;
  int count = 0;
  success += sendCommand(SET_COM_PINS_HW_CONFIG);
  count++;
  success += sendCommand(cmd);
  count++;

  return success == count;
}

bool SSD1306::LCD::setVcomhDeselectLevel(unsigned char level) {
  level = level & 0x70;
  int success = 0;
  int count = 0;
  success += sendCommand(SET_VCOM_DESELECT_LEVEL);
  count++;
  success += sendCommand(level);
  count++;

  return success == count;
}

bool SSD1306::LCD::horizontalScrollSetup(unsigned char direction,
                                         unsigned char start, unsigned char end,
                                         unsigned char interval) {
  direction = direction & 0x01;
  start = start & 0x07;
  end = end & 0x07;
  interval = interval & 0x07;

  int success = 0;
  int count = 0;
  success += sendCommand(HORIZONTAL_SCROLL_SETUP | direction);
  count++;
  success += sendCommand(0x00);
  count++;
  success += sendCommand(start);
  count++;
  success += sendCommand(interval);
  count++;
  success += sendCommand(end);
  count++;
  success += sendCommand(0x00);
  count++;
  success += sendCommand(0xFF);
  count++;

  return success == count;
}

bool SSD1306::LCD::verticalAndHorizontalScrollSetup(
    unsigned char direction, unsigned char start, unsigned char end,
    unsigned char interval, unsigned char verticalOffset) {
  direction = direction & 0x03;
  start = start & 0x07;
  end = end & 0x07;
  interval = interval & 0x07;
  verticalOffset = verticalOffset & 0x3F;

  int success = 0;
  int count = 0;
  success += sendCommand(HORIZONTAL_SCROLL_SETUP | direction);
  count++;
  success += sendCommand(0x00);
  count++;
  success += sendCommand(start);
  count++;
  success += sendCommand(interval);
  count++;
  success += sendCommand(end);
  count++;
  success += sendCommand(verticalOffset);
  count++;

  return success == count;
}

bool SSD1306::LCD::deactivateScroll() { return sendCommand(DEACTIVATE_SCROLL); }

bool SSD1306::LCD::activateScroll() { return sendCommand(ACTIVATE_SCROLL); }

bool SSD1306::LCD::setVerticalScrollArea(unsigned char topRows,
                                         unsigned char scrollAreaRows) {
  topRows = topRows & 0x3F;
  scrollAreaRows = scrollAreaRows & 0x7F;

  int success = 0;
  int count = 0;
  success += sendCommand(SET_VERTICAL_SCROLL_AREA);
  count++;
  success += sendCommand(topRows);
  count++;
  success += sendCommand(scrollAreaRows);
  count++;

  return success == count;
}

bool SSD1306::LCD::setChargePumpSetting(bool enableChargePump) {
  unsigned char cmd = 0x10 | (enableChargePump << 2);
  int success = 0;
  int count = 0;
  success += sendCommand(CHARGE_PUMP_SETTING);
  count++;
  success += sendCommand(cmd);
  count++;

  return success == count;
}

int SSD1306::LCD::lcdWidth() { return width; }

int SSD1306::LCD::lcdHeight() { return height; }

int SSD1306::LCD::lcdSize() { return size; }