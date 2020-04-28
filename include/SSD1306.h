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
static const unsigned char SET_PAGE_START_ADDRESS = 0xB0;

// Charge pump regulator setting
static const unsigned char CHARGE_PUMP_SETTING = 0x8D;
static const unsigned char CHARGE_PUMP_ENABLE = 0x14;
static const unsigned char CHARGE_PUMP_DISABLE = 0x10;

static const unsigned char SET_SEGMENT_REMAP = 0xA0;

static const unsigned char ENTIRE_DISPLAY_ON = 0xA4;

static const unsigned char SET_INVERSE = 0xA6;

static const unsigned char SET_MUX_RATIO = 0xA8;

static const unsigned char DISPLAY_OFF = 0xAE;
static const unsigned char DISPLAY_ON = 0xAF;

static const unsigned char SET_COM_OUTPUT_SCAN = 0xC0;

static const unsigned char SET_DISPLAY_OFFSET = 0xD3;

// Set Display Clock Divide Ratio/Oscillator Frequency
static const unsigned char SET_DISPLAY_CLOCK = 0xD5;

static const unsigned char SET_PRECHARGE_PERIOD = 0xD9;

static const unsigned char SET_COM_PINS_HW_CONFIG = 0xDA;

static const unsigned char SET_VCOM_DESELECT_LEVEL = 0xDB;

static const unsigned char SET_LOWER_COLUMN_START_ADDRESS = 0x00;
static const unsigned char SET_HIGHER_COLUMN_START_ADDRESS = 0x10;
static const unsigned char SET_START_LINE = 0x40;

static const unsigned char EXTERNALVCC = 0x01;
static const unsigned char SWITCHCAPVCC = 0x02;

static const unsigned char HORIZONTAL_SCROLL_SETUP = 0x26;
static const unsigned char VERTICAL_AND_HORIZONTAL_SCROLL_SETUP = 0x29;
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
      unsigned long frequency = 400000U, unsigned char address = I2C_ADDRESS);
  ~LCD();
  bool init();
  // Pixels displayed on screen
  bool sendData(const unsigned char* data, int size);
  bool sendData(const unsigned char data);
  bool sendCommand(const unsigned char cmd);
  /*
    Because byte orientation in SSD1306 RAM is vertical, the normal orientation
    of images is 90° left.
  */
  bool drawXbitmap(const unsigned char* bitmap, int x, int y, int width,
                   int height);
  bool drawXbitmap(Graphic* graphic);
  bool drawXbitmap(Graphic graphic);
  bool writeText(const char* text, int length);
  bool setWritingArea(int x, int y, int width, int height);
  bool setWritingArea(TextBox textBox);
  bool fillRectangle(int x, int y, int width, int height, bool color);
  bool drawLine(unsigned char x1, unsigned char y1, unsigned char x2,
                unsigned char y2, unsigned char width);
  bool print(TextBox textBox, const char* text);
  bool clearScreen();
  /*
    This command specifies the lower nibble of the 8-bit column start address
    for the display data RAM under Page Addressing Mode. The column address
    will be incremented by each data access.
  */
  bool setLowerColumnStartAddress(unsigned char address = 0x00);

  /*
    This command specifies the higher nibble of the 8-bit column start address
    for the display data RAM under Page Addressing Mode. The column address will
    be incremented by each data access.
  */
  bool setHigherColumnStartAddress(unsigned char address = 0x00);

  /*
    There are 3 different memory addressing mode in SSD1306: page addressing
    mode, horizontal addressing mode and vertical addressing mode. This command
    sets the way of memory addressing into one of the above three modes. In
    there, “COL” means the graphic display data RAM column.
  */
  bool setMemoryAddressingMode(unsigned char mode = MEMORY_ADDRESSING_VERTICAL);

  /*
    This triple byte command specifies column start address and end address of
    the display data RAM. This command also sets the column address pointer to
    column start address. This pointer is used to define the current read/write
    column address in graphic display data RAM. If horizontal address increment
    mode is enabled by command 20h, after finishing read/write one column data,
    it is incremented automatically to the next column address. Whenever the
    column address pointer finishes accessing the end column address, it is
    reset back to start column address and the row address is incremented to the
    next row.
  */
  bool setColumnRange(unsigned char start = 0x00, unsigned char end = 0x7F);

  /*
    This triple byte command specifies page start address and end address of the
    display data RAM. This command also sets the page address pointer to page
    start address. This pointer is used to define the current read/write page
    address in graphic display data RAM. If vertical address increment mode is
    enabled by command 20h, after finishing read/write one page data, it is
    incremented automatically to the next page address. Whenever the page
    address pointer finishes accessing the end page address, it is reset back to
    start page address.
  */
  bool setPageRange(unsigned char start = 0x00, unsigned char end = 0x07);

  /*
    This command sets the Display Start Line register to determine starting
    address of display RAM, by selecting a value from 0 to 63. With value equal
    to 0, RAM row 0 is mapped to COM0. With value equal to 1, RAM row 1 is
    mapped to COM0 and so on.
  */
  bool setDisplayStartLine(unsigned char start = 0x00);

  /*
    This command sets the Contrast Setting of the display. The chip has 256
    contrast steps from 00h to FFh. The segment output current increases as the
    contrast step value increases.
  */
  bool setContrast(unsigned char value = 0x7F);

  /*
    This command changes the mapping between the display data column address and
    the segment driver. It allows flexibility in OLED module design.
  */
  bool setSegmentRemap(bool remap = false);

  /*
    A4h command enable display outputs according to the GDDRAM contents.
    If A5h command is issued, then by using A4h command, the display will resume
    to the GDDRAM contents. In other words, A4h command resumes the display from
    entire display “ON” stage. A5h command forces the entire display to be “ON”,
    regardless of the contents of the display data RAM.
  */
  bool entireDisplayOn(bool resumeRam = false);

  /*
    This command sets the display to be either normal or inverse. In normal
    display a RAM data of 1 indicates an “ON” pixel while in inverse display a
    RAM data of 0 indicates an “ON” pixel.
  */
  bool invert(bool invert);
  // Toggle inverse
  bool invert();

  /*
    This command switches the default 63 multiplex mode to any multiplex ratio,
    ranging from 16 to 63. The output pads COM0~COM63 will be switched to the
    corresponding COM signal.
  */
  bool setMultiplexRatio(unsigned char ratio = 0x3F);

  /*
    When the display is OFF, the selected circuits by Set Master Configuration
    command will be turned OFF and the segment and common output are in Vss
    state and high impedance state, respectively.
  */
  bool turnOff();

  /*
    When the display is ON, the selected circuits by Set Master Configuration
    command will be turned ON.
  */
  bool turnOn();

  /*
    Indicate wether LCD is on
  */
  bool lcdIsOn();

  /*
    This command positions the page start address from 0 to 7 in GDDRAM under
    Page Addressing Mode.
  */
  bool setPageStartAddress(unsigned char address = 0x00);

  /*
    This command sets the scan direction of the COM output, allowing layout
    flexibility in the OLED module design. Additionally, the display will show
    once this command is issued. For example, if this command is sent during
    normal display then the graphic display will be vertically flipped
    immediately.
  */
  bool setComOutputScanDirection(bool remapped = false);

  /*
    This is a double byte command. The second command specifies the mapping of
    the display start line to one of COM0~COM63 (assuming that COM0 is the
    display start line then the display start line register is equal to 0).
  */
  bool setDisplayOffset(unsigned char offset = 0x00);

  /*
    This command consists of two functions:
    •   Display Clock Divide Ratio (D)(A[3:0])
        Set the divide ratio to generate DCLK (Display Clock) from CLK. The
        divide ratio is from 1 to 16, with reset value = 1. Please refer to
        section 8.3 for the details relationship of DCLK and CLK.

    •   Oscillator Frequency (A[7:4])
        Program the oscillator frequency Fosc that is the source of CLK if CLS
        pin is pulled high. The 4-bit value results in 16 different frequency
        settings available as shown below. The default setting is 1000b.
  */
  bool setDisplayClock(unsigned char ratio = 0x00,
                       unsigned char frequency = 0x08);

  /*
    This command is used to set the duration of the pre-charge period. The
    interval is counted in number of DCLK, where RESET equals 2 DCLKs.
  */
  bool setPreChargePeriod(unsigned char phase1 = 0x02,
                          unsigned char phase2 = 0x02);

  /*
    This command sets the COM signals pin configuration to match the OLED panel
    hardware layout.
  */
  bool setComPinsHwConfig(bool alternative = true, bool leftRightRemap = false);

  /*
    This command adjusts the V COMH regulator output.
  */
  bool setVcomhDeselectLevel(unsigned char level = 0x20);

  /*
    This command consists of consecutive bytes to set up the horizontal scroll
    parameters and determines the scrolling start page, end page and scrolling
    speed. Before issuing this command the horizontal scroll must be deactivated
    (2Eh). Otherwise, RAM content may be corrupted.
  */
  bool horizontalScrollSetup(unsigned char direction, unsigned char start,
                             unsigned char end, unsigned char interval);

  /*
    This command consists of 6 consecutive bytes to set up the continuous
    vertical scroll parameters and determines the scrolling start page, end
    page, scrolling speed and vertical scrolling offset.
  */
  bool verticalAndHorizontalScrollSetup(unsigned char direction,
                                        unsigned char start, unsigned char end,
                                        unsigned char interval,
                                        unsigned char verticalOffset);

  /*
    This command stops the motion of scrolling. After sending 2Eh command to
    deactivate the scrolling action, the ram data needs to be rewritten.
  */
  bool deactivateScroll();

  /*
    This command starts the motion of scrolling and should only be issued after
    the scroll setup parameters have been defined by the scrolling setup
    commands :26h/27h/29h/2Ah . The setting in the last scrolling setup command
    overwrites the setting in the previous scrolling setup commands.
  */
  bool activateScroll();

  /*
    This command consists of 3 consecutive bytes to set up the vertical scroll
    area. For the continuous vertical scroll function (command 29/2Ah), the
    number of rows that in vertical scrolling can be set smaller or equal to the
    MUX ratio.
  */
  bool setVerticalScrollArea(unsigned char topRows = 0,
                             unsigned char scrollAreaRows = 64);

  /*
    The internal regulator circuit in SSD1306 accompanying only 2 external
    capacitors can generate a 7.5V voltage supply, Vcc, from a low voltage
    supply input, Vbat. The Vcc is the voltage supply to the OLED driver
    block. This is a switching capacitor regulator circuit, designed for
    handheld applications.
  */
  bool setChargePumpSetting(bool enableChargePump = true);

  // Width of LCD in pixels
  int lcdWidth();
  // Height of LCD in pixels
  int lcdHeight();
  // Total number of bytes the lcd can display
  int lcdSize();
};
}  // namespace SSD1306