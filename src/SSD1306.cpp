#include "SSD1306.h"

SSD1306::LCD::LCD(I2C* i2c, int width, int height, unsigned long frequency,
                  unsigned char address) {
    this->i2c = i2c;
    this->width = width;
    this->height = height;
    // Divided with bits per byte
    this->size = width * height / 8;
    this->i2cConfig.address = address;
    this->i2cConfig.frequency = frequency;
}

SSD1306::LCD::~LCD() { off(); }

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
        isOn = true;
        contrast = 0;
        // Initialization sequence
        success += off();
        success += sendCommand(SETDISPLAYCLOCKDIV);
        success += sendCommand(0x80);
        success += sendCommand(SETMULTIPLEX);
        success += sendCommand(height - 1);
        success += sendCommand(SETDISPLAYOFFSET);
        success += sendCommand(0x00);
        success += sendCommand(SETSTARTLINE | 0x00);
        success += sendCommand(CHARGEPUMP);
        success += sendCommand(0x14);
        success += sendCommand(MEMORYMODE);
        success += sendCommand(0x01);
        success += sendCommand(SEGREMAP | 0x1);
        success += sendCommand(COMSCANDEC);
        success += sendCommand(SETCOMPINS);
        success += sendCommand(0x12);
        setContrast(0xcf);
        success += sendCommand(SETPRECHARGE);
        success += sendCommand(0xF1);
        success += sendCommand(SETVCOMDETECT);
        success += sendCommand(0x40);
        success += sendCommand(DISPLAYALLON_RESUME);
        success += sendCommand(NORMALDISPLAY);
        success += sendCommand(DEACTIVATE_SCROLL);
        success += on();
        success += sendCommand(COLUMNADDR);
        success += sendCommand(0x00);
        success += sendCommand(width - 1);
        success += sendCommand(PAGEADDR);
        success += sendCommand(0x00);
        success += sendCommand(0xFF);
        success += clearScreen();

        return success == 31;
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
    success += sendCommand(COLUMNADDR);
    success += sendCommand(x);
    success += sendCommand(x + (width - 1));
    success += sendCommand(PAGEADDR);
    int pageStart = (unsigned char)y / 8;
    success += sendCommand(pageStart);
    success += sendCommand(pageStart + (height / 8) - 1);

    return success == 6;
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

    return sendData(buffer, size);
}

bool SSD1306::LCD::off() {
    if (isOn && sendCommand(SSD1306::DISPLAYOFF)) {
        isOn = false;
        return true;
    }

    return false;
}

bool SSD1306::LCD::on() {
    if (!isOn && sendCommand(SSD1306::DISPLAYON)) {
        isOn = true;
        return true;
    };

    return false;
}

bool SSD1306::LCD::lcdOn() { return isOn; }

bool SSD1306::LCD::setContrast(unsigned char value) {
    if (contrast == value) {
        return false;
    }

    int success = 0;
    success += sendCommand(SSD1306::SETCONTRAST);
    success += sendCommand(value);

    if (success == 2) {
        contrast = value;
        return true;
    }

    return false;
}

int SSD1306::LCD::lcdWidth() { return width; }

int SSD1306::LCD::lcdHeight() { return height; }