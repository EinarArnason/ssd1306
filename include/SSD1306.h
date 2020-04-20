#pragma once

#include <Graphic.h>
#include <I2C.h>
#include <SansSerif16px.h>
#include <TextBox.h>
#include <string.h>

namespace SSD1306 {
    static const unsigned char I2C_ADDRESS = 0x3c;

    // Set the order of memory addressing
    static const unsigned char SET_MEMORY_ADDRESSING_MODE = 0x20;
    // Every column is addressed for each page
    static const unsigned char MEMORY_ADDRESSING_HORIZONTAL = 0x00;
    // Every page is addressed for each column
    static const unsigned char MEMORY_ADDRESSING_VERTICAL = 0x01;
    // Every column is addressed for a single page
    static const unsigned char MEMORY_ADDRESSING_PAGE = 0x10;

    static const unsigned char SET_CONTRAST = 0x81;
    static const unsigned char DEFAULT_CONTRAST = 0x7f;

    // Specifies column start address and end address of the display data RAM.
    static const unsigned char SET_COLUMN_ADDRESS = 0x21;
    // Specifies page start address and end address of the display data RAM
    static const unsigned char SET_PAGE_ADDRESS = 0x22;
    
    // Charge pump regulator setting
    static const unsigned char CHARGE_PUMP_SETTING = 0x8D;
    static const unsigned char CHARGE_PUMP_ENABLE = 0x14;
    static const unsigned char CHARGE_PUMP_DISABLE = 0x10;

    static const unsigned char SET_SEGMENT_REMAP_OFF = 0xA0;
    static const unsigned char SET_SEGMENT_REMAP_ON = 0xA1;

    static const unsigned char DISPLAYALLON_RESUME = 0xA4;
    static const unsigned char DISPLAYALLON = 0xA5;

    static const unsigned char NORMAL_DISPLAY = 0xA6;
    static const unsigned char INVERT_DISPLAY = 0xA7;

    static const unsigned char SET_MUX_RATIO = 0xA8;

    static const unsigned char DISPLAY_OFF = 0xAE;
    static const unsigned char DISPLAY_ON = 0xAF;

    static const unsigned char SET_COM_OUTPUT_SCAN_NORMAL = 0xC0;
    static const unsigned char SET_COM_OUTPUT_SCAN_REMAPPED = 0xC8;

    static const unsigned char SET_DISPLAY_OFFSET = 0xD3;

    static const unsigned char SET_DISPLAY_CLOCK_DIVIDER = 0xD5;
    static const unsigned char DEFAULT_DISPLAY_CLOCK_DIVIDER = 0x80;

    static const unsigned char SET_PRECHARGE_PERIOD = 0xD9;
    static const unsigned char SET_COM_PINS_HW_CONFIG = 0xDA;
    static const unsigned char SET_VCOM_DESELECT_LEVEL = 0xDB;

    static const unsigned char SETLOWCOLUMN = 0x00;
    static const unsigned char SETHIGHCOLUMN = 0x10;
    static const unsigned char SET_START_LINE = 0x40;

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
        int size;
        bool isOn;
        bool inverted;
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
        bool turnOff();
        bool turnOn();
        bool lcdOn();
        bool setContrast(unsigned char value);
        bool setMultiplexRatio(unsigned char ratio);
        bool setMemoryAddressingMode(unsigned char mode);
        bool setColumnRange(unsigned char start, unsigned char end);
        bool setPageRange(unsigned char start, unsigned char end);
        bool invert();
        int lcdWidth();
        int lcdHeight();
    };
} // namespace SSD1306