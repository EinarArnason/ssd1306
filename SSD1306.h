#pragma once

#include "Fonts/SansSerif16px.h"
#include "Graphic.h"
#include "TextBox.h"
#include <I2C.h>
#include <string.h>

namespace SSD1306 {
    static const unsigned char I2C_ADDRESS = 0x3c;
    static const unsigned char MEMORYMODE = 0x20;
    static const unsigned char COLUMNADDR = 0x21;
    static const unsigned char PAGEADDR = 0x22;
    static const unsigned char SETCONTRAST = 0x81;
    static const unsigned char CHARGEPUMP = 0x8D;
    static const unsigned char SEGREMAP = 0xA0;
    static const unsigned char DISPLAYALLON_RESUME = 0xA4;
    static const unsigned char DISPLAYALLON = 0xA5;
    static const unsigned char NORMALDISPLAY = 0xA6;
    static const unsigned char INVERTDISPLAY = 0xA7;
    static const unsigned char SETMULTIPLEX = 0xA8;
    static const unsigned char DISPLAYOFF = 0xAE;
    static const unsigned char DISPLAYON = 0xAF;
    static const unsigned char COMSCANINC = 0xC0;
    static const unsigned char COMSCANDEC = 0xC8;
    static const unsigned char SETDISPLAYOFFSET = 0xD3;
    static const unsigned char SETDISPLAYCLOCKDIV = 0xD5;
    static const unsigned char SETPRECHARGE = 0xD9;
    static const unsigned char SETCOMPINS = 0xDA;
    static const unsigned char SETVCOMDETECT = 0xDB;

    static const unsigned char SETLOWCOLUMN = 0x00;
    static const unsigned char SETHIGHCOLUMN = 0x10;
    static const unsigned char SETSTARTLINE = 0x40;

    static const unsigned char EXTERNALVCC = 0x01;
    static const unsigned char SWITCHCAPVCC = 0x02;

    static const unsigned char RIGHT_HORIZONTAL_SCROLL = 0x26;
    static const unsigned char LEFT_HORIZONTAL_SCROLL = 0x27;
    static const unsigned char VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL = 0x29;
    static const unsigned char VERTICAL_AND_LEFT_HORIZONTAL_SCROLL = 0x2A;
    static const unsigned char DEACTIVATE_SCROLL = 0x2E;
    static const unsigned char ACTIVATE_SCROLL = 0x2F;
    static const unsigned char SET_VERTICAL_SCROLL_AREA = 0xA3;

    static const unsigned char COMMAND = 0x00;
    static const unsigned char DATA = 0x40;

    static const char DEGREE_SYMBOL = 127;
    static const int ASCII_OFFSET = 32;

    class LCD {
      private:
        I2C* i2c;
        int width;
        int height;
        unsigned char* buffer;
        int bufferSize;
        bool isOn;
        unsigned char contrast;
        I2C::Config i2cConfig;

      public:
        LCD(I2C* i2c = nullptr, int width = 128, int height = 64,
            unsigned long frequency = 400000U,
            unsigned char address = I2C_ADDRESS);
        ~LCD();
        bool init();
        bool sendData(const unsigned char* data, int size);
        bool sendCommand(const unsigned char cmd);
        /*
            Image must be flipped and top must be oriented left because byte
           orientation in SSD1306 RAM is vertical, width exceeding LCD height is
           fine.
        */
        bool drawXbitmap(const unsigned char* bitmap, int x, int y, int width,
                         int height);
        bool drawXbitmap(Graphic* graphic);
        bool drawXbitmap(Graphic graphic);
        bool writeText(const char* text, int length);
        bool setWritingArea(int x, int y, int width, int height);
        bool setWritingArea(TextBox textBox);
        bool fillRectangle(int x, int y, int width, int height, bool color);
        bool print(TextBox textBox, const char* text);
        bool clearScreen();
        void clearBuffer();
        bool off();
        bool on();
        bool lcdOn();
        bool setContrast(unsigned char value);
        int lcdWidth();
        int lcdHeight();
    };
} // namespace SSD1306