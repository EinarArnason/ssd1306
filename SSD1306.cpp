#include "SSD1306.h"

SSD1306::LCD::LCD(I2C* i2c, int width, int height) {
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

void SSD1306::LCD::sendCommand(const unsigned char cmd) {
    unsigned char msg[] = {SSD1306_COMMAND, cmd};
    if (!i2c->send(msg)) {
        std::cout << "Failed to write to i2c" << std::endl;
    }
}

void SSD1306::LCD::sendData(const unsigned char* data, int size) {
    for (int i = 0; i < size; ++i) {
        unsigned char msg[] = {SSD1306_DATA, data[i]};
        if (!i2c->send(msg)) {
            std::cout << "Failed to write to i2c" << std::endl;
        }
    }
}

void SSD1306::LCD::init() {
    if (i2c->init()) {
        // Initialization sequence
        sendCommand(SSD1306_DISPLAYOFF);
        sendCommand(SSD1306_SETDISPLAYCLOCKDIV);
        sendCommand(0x80);
        sendCommand(SSD1306_SETMULTIPLEX);
        sendCommand(height - 1);
        sendCommand(SSD1306_SETDISPLAYOFFSET);
        sendCommand(0x00);
        sendCommand(SSD1306_SETSTARTLINE | 0x00);
        sendCommand(SSD1306_CHARGEPUMP);
        sendCommand(0x14);
        sendCommand(SSD1306_MEMORYMODE);
        sendCommand(0x01);
        sendCommand(SSD1306_SEGREMAP | 0x1);
        sendCommand(SSD1306_COMSCANDEC);
        sendCommand(SSD1306_SETCOMPINS);
        sendCommand(0x12);
        sendCommand(SSD1306_SETCONTRAST);
        sendCommand(0xCF);
        sendCommand(SSD1306_SETPRECHARGE);
        sendCommand(0xF1);
        sendCommand(SSD1306_SETVCOMDETECT);
        sendCommand(0x40);
        sendCommand(SSD1306_DISPLAYALLON_RESUME);
        sendCommand(SSD1306_NORMALDISPLAY);
        sendCommand(SSD1306_DEACTIVATE_SCROLL);
        sendCommand(SSD1306_DISPLAYON);
        sendCommand(SSD1306_COLUMNADDR);
        sendCommand(0x00);
        sendCommand(width - 1);
        sendCommand(SSD1306_PAGEADDR);
        sendCommand(0x00);
        sendCommand(0xFF);
        clearScreen();
    } else {
        std::cout << "Failed to initialize I2C device" << std::endl;
    }
}

void SSD1306::LCD::drawXbitmap(const unsigned char* bitmap, int x, int y,
                               int width, int height) {
    // Align writing area
    setWritingArea(x, y, width, height);
    // Draw image
    sendData(bitmap, width * height / 8);
}

// Writing area for text needs to be set up as textboxes with matching height of
// the font
void SSD1306::LCD::writeText(const char* text) {
    for (; *text != '\0'; ++text) {
        int index = *text - 32;
        unsigned char* iterator = SANS_SERIF_16PX_POINTERS[index];
        for (; iterator != SANS_SERIF_16PX_POINTERS[index + 1]; ++iterator) {
            unsigned char msg[] = {SSD1306_DATA, *iterator};
            if (!i2c->send(msg)) {
                std::cout << "Failed to write to i2c" << std::endl;
            }
        }
    }
}

void SSD1306::LCD::setWritingArea(int x, int y, int width, int height) {
    sendCommand(SSD1306_COLUMNADDR);
    sendCommand(x);
    sendCommand(x + (width - 1));
    sendCommand(SSD1306_PAGEADDR);
    int pageStart = (unsigned char)y / 8;
    sendCommand(pageStart);
    sendCommand(pageStart + (height / 8) - 1);
}

void SSD1306::LCD::clearScreen() {
    memset(buffer, 0x00, bufferSize);
    sendData(buffer, bufferSize);
}

int SSD1306::LCD::lcdWidth() { return width; }

int SSD1306::LCD::lcdHeight() { return height; }