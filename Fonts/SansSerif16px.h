#pragma once

namespace SSD1306 {
static const int SANS_SERIF_16PX_DATA_LENGTH = 1814;
static unsigned char SANS_SERIF_16PX_DATA[] = {
    // Space
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // !
    0x00, 0x00, 0x00, 0x00, 0xfc, 0x33, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // "
    0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
    // #
    0x00, 0x00, 0x00, 0x04, 0x40, 0x04, 0x40, 0x3c, 0xc0, 0x0f, 0xf8, 0x04,
    0x48, 0x24, 0x40, 0x3e, 0xe0, 0x07, 0x78, 0x04, 0x40, 0x04, 0x40, 0x00,
    0x00, 0x00,
    // $
    0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x30, 0x21, 0x10, 0x21, 0xfc, 0xff,
    0x10, 0x22, 0x10, 0x32, 0x20, 0x1c, 0x00, 0x00,
    // %
    0x00, 0x00, 0x78, 0x00, 0x84, 0x00, 0x84, 0x00, 0x84, 0x30, 0x78, 0x0c,
    0x00, 0x06, 0x80, 0x01, 0x60, 0x00, 0x30, 0x1e, 0x0c, 0x21, 0x00, 0x21,
    0x00, 0x21, 0x00, 0x1e, 0x00, 0x00,
    // &
    0x00, 0x00, 0x00, 0x0f, 0xb8, 0x10, 0x4c, 0x20, 0x84, 0x20, 0x04, 0x21,
    0x04, 0x22, 0x08, 0x24, 0x00, 0x18, 0x00, 0x18, 0x00, 0x27, 0x00, 0x00,
    // '
    0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
    // (
    0x00, 0x00, 0xc0, 0x0f, 0x38, 0x70, 0x0c, 0xc0, 0x04, 0x80, 0x00, 0x00,
    // )
    0x00, 0x00, 0x04, 0x80, 0x0c, 0xc0, 0x38, 0x70, 0xc0, 0x0f, 0x00, 0x00,
    // *
    0x00, 0x00, 0x90, 0x00, 0xa0, 0x00, 0x60, 0x00, 0xfc, 0x03, 0x60, 0x00,
    0xa0, 0x00, 0x90, 0x00,
    // +
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02,
    0xe0, 0x3f, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00,
    0x00, 0x00,
    // ´
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x0c, 0x00, 0x06, 0x00,
    0x02, 0x00, 0x00, 0x00,
    // -
    0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x00,
    // .
    0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
    // /
    0x00, 0x60, 0x00, 0x3c, 0x80, 0x03, 0x70, 0x00, 0x0c, 0x00,
    // 0
    0x00, 0x00, 0xe0, 0x07, 0x18, 0x18, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x18, 0x18, 0xe0, 0x07, 0x00, 0x00,
    // 1
    0x00, 0x00, 0x00, 0x00, 0x08, 0x20, 0x0c, 0x20, 0x04, 0x20, 0xfc, 0x3f,
    0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x00,
    // 2
    0x00, 0x00, 0x18, 0x30, 0x0c, 0x28, 0x04, 0x24, 0x04, 0x22, 0x04, 0x21,
    0x88, 0x20, 0x70, 0x20, 0x00, 0x00, 0x00, 0x00,
    // 3
    0x00, 0x00, 0x08, 0x10, 0x04, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20,
    0x84, 0x20, 0x48, 0x11, 0x78, 0x0f, 0x00, 0x00,
    // 4
    0x00, 0x00, 0x00, 0x06, 0x80, 0x05, 0x40, 0x04, 0x20, 0x04, 0x18, 0x04,
    0x04, 0x04, 0xfc, 0x3f, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00,
    // 5
    0x00, 0x00, 0x00, 0x10, 0xfc, 0x20, 0x44, 0x20, 0x44, 0x20, 0x44, 0x20,
    0x44, 0x20, 0x84, 0x10, 0x00, 0x0f, 0x00, 0x00,
    // 6
    0x00, 0x00, 0xe0, 0x0f, 0x98, 0x10, 0x48, 0x20, 0x44, 0x20, 0x44, 0x20,
    0x44, 0x20, 0x88, 0x10, 0x00, 0x0f, 0x00, 0x00,
    // 7
    0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x20, 0x04, 0x18, 0x04, 0x07,
    0xc4, 0x00, 0x34, 0x00, 0x0c, 0x00, 0x00, 0x00,
    // 8
    0x00, 0x00, 0x78, 0x0f, 0x48, 0x11, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20,
    0x84, 0x20, 0x48, 0x11, 0x78, 0x0f, 0x00, 0x00,
    // 9
    0x00, 0x00, 0xf0, 0x00, 0x08, 0x11, 0x04, 0x22, 0x04, 0x22, 0x04, 0x22,
    0x04, 0x12, 0x18, 0x19, 0xe0, 0x07, 0x00, 0x00,
    // :
    0x00, 0x00, 0x00, 0x00, 0xc0, 0x30, 0x00, 0x00, 0x00, 0x00,
    // ;
    0x00, 0x00, 0x00, 0x80, 0xc0, 0x70, 0x00, 0x00, 0x00, 0x00,
    // <
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x05, 0x00, 0x05, 0x80, 0x0d,
    0x80, 0x08, 0x80, 0x08, 0x40, 0x10, 0x40, 0x10, 0x40, 0x10, 0x20, 0x20,
    0x00, 0x00,
    // =
    0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x80, 0x04, 0x80, 0x04, 0x80, 0x04,
    0x80, 0x04, 0x80, 0x04, 0x80, 0x04, 0x80, 0x04, 0x80, 0x04, 0x80, 0x04,
    0x00, 0x00,
    // >
    0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x40, 0x10, 0x40, 0x10, 0x40, 0x10,
    0x80, 0x08, 0x80, 0x08, 0x80, 0x0d, 0x00, 0x05, 0x00, 0x05, 0x00, 0x02,
    0x00, 0x00,
    // ?
    0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x04, 0x37, 0x84, 0x01, 0xc4, 0x00,
    0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
    // @
    0x00, 0x00, 0xc0, 0x0f, 0x60, 0x18, 0x10, 0x20, 0x88, 0x47, 0x4c, 0x48,
    0x24, 0x90, 0x24, 0x90, 0x24, 0x90, 0x24, 0x90, 0x44, 0x88, 0xe8, 0xdf,
    0x18, 0x50, 0x30, 0x08, 0xc0, 0x07, 0x00, 0x00,
    // A
    0x00, 0x20, 0x00, 0x18, 0x00, 0x07, 0xc0, 0x04, 0x30, 0x04, 0x0c, 0x04,
    0x30, 0x04, 0xc0, 0x04, 0x00, 0x07, 0x00, 0x18, 0x00, 0x20,
    // B
    0x00, 0x00, 0xfc, 0x3f, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20,
    0x84, 0x20, 0x84, 0x20, 0xc8, 0x11, 0x78, 0x0f, 0x00, 0x00,
    // C
    0x00, 0x00, 0xe0, 0x07, 0x10, 0x08, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x0c, 0x30, 0x08, 0x10, 0x00, 0x00,
    // D
    0x00, 0x00, 0xfc, 0x3f, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x0c, 0x30, 0x08, 0x10, 0x10, 0x08, 0xe0, 0x07, 0x00, 0x00,
    // E
    0x00, 0x00, 0xfc, 0x3f, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x84, 0x20,
    0x84, 0x20, 0x84, 0x20, 0x84, 0x20, 0x00, 0x00,
    // F
    0x00, 0x00, 0xfc, 0x3f, 0x84, 0x00, 0x84, 0x00, 0x84, 0x00, 0x84, 0x00,
    0x84, 0x00, 0x04, 0x00, 0x00, 0x00,
    // G
    0x00, 0x00, 0xe0, 0x07, 0x10, 0x08, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x21, 0x04, 0x21, 0x0c, 0x21, 0x18, 0x1f, 0x00, 0x00,
    // H
    0x00, 0x00, 0xfc, 0x3f, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00,
    0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0x80, 0x00, 0xfc, 0x3f, 0x00, 0x00,
    // I
    0x00, 0x00, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x00, 0x00,
    // J
    0x00, 0x80, 0x00, 0x80, 0xfc, 0x7f, 0x00, 0x00, 0x00, 0x00,
    // K
    0x00, 0x00, 0xfc, 0x3f, 0x80, 0x00, 0x80, 0x01, 0x40, 0x02, 0x20, 0x04,
    0x10, 0x08, 0x08, 0x10, 0x04, 0x20, 0x00, 0x00,
    // L
    0x00, 0x00, 0xfc, 0x3f, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20,
    0x00, 0x20, 0x00, 0x20, 0x00, 0x00,
    // M
    0x00, 0x00, 0xfc, 0x3f, 0x0c, 0x00, 0x70, 0x00, 0x80, 0x01, 0x00, 0x06,
    0x00, 0x08, 0x00, 0x06, 0x80, 0x01, 0x70, 0x00, 0x0c, 0x00, 0xfc, 0x3f,
    0x00, 0x00,
    // N
    0x00, 0x00, 0xfc, 0x3f, 0x04, 0x00, 0x18, 0x00, 0x20, 0x00, 0xc0, 0x00,
    0x00, 0x01, 0x00, 0x06, 0x00, 0x18, 0x00, 0x20, 0xfc, 0x3f, 0x00, 0x00,
    // O
    0x00, 0x00, 0xe0, 0x07, 0x10, 0x08, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x08, 0x10, 0x10, 0x08, 0xe0, 0x07,
    0x00, 0x00,
    // P
    0x00, 0x00, 0xfc, 0x3f, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01,
    0x04, 0x01, 0x88, 0x00, 0x70, 0x00, 0x00, 0x00,
    // Q
    0x00, 0x00, 0xe0, 0x07, 0x10, 0x08, 0x08, 0x10, 0x04, 0x20, 0x04, 0x20,
    0x04, 0x20, 0x04, 0x20, 0x04, 0x20, 0x08, 0x50, 0x10, 0x98, 0xe0, 0x07,
    0x00, 0x00,
    // R
    0x00, 0x00, 0xfc, 0x3f, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01, 0x04, 0x01,
    0x04, 0x01, 0x88, 0x03, 0x70, 0x0c, 0x00, 0x30, 0x00, 0x00,
    // S
    0x00, 0x00, 0x78, 0x18, 0x88, 0x30, 0x84, 0x20, 0x84, 0x21, 0x04, 0x21,
    0x0c, 0x21, 0x08, 0x13, 0x00, 0x1e, 0x00, 0x00,
    // T
    0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0xfc, 0x3f, 0x04, 0x00,
    0x04, 0x00, 0x04, 0x00, 0x04, 0x00,
    // U
    0x00, 0x00, 0xfc, 0x0f, 0x00, 0x10, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20,
    0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00, 0x10, 0xfc, 0x0f, 0x00, 0x00,
    // V
    0x00, 0x00, 0x0c, 0x00, 0x30, 0x00, 0xc0, 0x00, 0x00, 0x07, 0x00, 0x18,
    0x00, 0x20, 0x00, 0x18, 0x00, 0x07, 0xc0, 0x00, 0x30, 0x00, 0x0c, 0x00,
    // W
    0x00, 0x00, 0x0c, 0x00, 0x70, 0x00, 0x80, 0x03, 0x00, 0x0c, 0x00, 0x30,
    0x00, 0x0f, 0xf0, 0x00, 0x0c, 0x00, 0xf0, 0x00, 0x00, 0x0f, 0x00, 0x30,
    0x00, 0x0c, 0x80, 0x03, 0x70, 0x00, 0x0c, 0x00, 0x00, 0x00,
    // X
    0x00, 0x00, 0x04, 0x20, 0x0c, 0x10, 0x30, 0x0c, 0x40, 0x02, 0x80, 0x01,
    0x40, 0x02, 0x30, 0x0c, 0x0c, 0x10, 0x04, 0x20, 0x00, 0x00,
    // Y
    0x04, 0x00, 0x08, 0x00, 0x30, 0x00, 0x40, 0x00, 0x80, 0x3f, 0x40, 0x00,
    0x30, 0x00, 0x08, 0x00, 0x04, 0x00,
    // Z
    0x00, 0x00, 0x04, 0x30, 0x04, 0x28, 0x04, 0x24, 0x04, 0x22, 0x04, 0x21,
    0x84, 0x20, 0x44, 0x20, 0x24, 0x20, 0x14, 0x20, 0x0c, 0x20, 0x00, 0x00,
    // [
    0x00, 0x00, 0xfc, 0xff, 0x04, 0x80, 0x04, 0x80, 0x00, 0x00, 0x00, 0x00,
    // backslash
    0x0c, 0x00, 0x78, 0x00, 0x80, 0x03, 0x00, 0x1c, 0x00, 0x60,
    // ]
    0x00, 0x00, 0x00, 0x00, 0x04, 0x80, 0x04, 0x80, 0xfc, 0xff, 0x00, 0x00,
    // ^
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x10, 0x00, 0x08, 0x00,
    0x0c, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x10, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00,
    // _
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xff,
    // `
    0x00, 0x00, 0x02, 0x00, 0x06, 0x00, 0x0c, 0x00, 0x08, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    // a
    0x00, 0x00, 0x00, 0x1e, 0x40, 0x33, 0x20, 0x21, 0x20, 0x21, 0x20, 0x21,
    0x60, 0x11, 0xc0, 0x3f, 0x00, 0x00,
    // b
    0x00, 0x00, 0xfc, 0x3f, 0x40, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x40, 0x10, 0x80, 0x0f, 0x00, 0x00,
    // c
    0x00, 0x00, 0x80, 0x0f, 0x40, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x40, 0x10, 0x00, 0x00,
    // d
    0x00, 0x00, 0x80, 0x0f, 0x40, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x40, 0x10, 0xfc, 0x3f, 0x00, 0x00,
    // e
    0x00, 0x00, 0x80, 0x0f, 0x40, 0x12, 0x20, 0x22, 0x20, 0x22, 0x20, 0x22,
    0x40, 0x22, 0x80, 0x13, 0x00, 0x00,
    // f
    0x00, 0x00, 0x20, 0x00, 0xf8, 0x3f, 0x24, 0x00, 0x24, 0x00, 0x04, 0x00,
    // g
    0x00, 0x00, 0xc0, 0x07, 0x20, 0x48, 0x10, 0x90, 0x10, 0x90, 0x10, 0x90,
    0x10, 0x90, 0x20, 0x48, 0xf0, 0x3f, 0x00, 0x00,
    // h
    0x00, 0x00, 0xfc, 0x3f, 0x40, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
    0x20, 0x00, 0x40, 0x00, 0x80, 0x3f, 0x00, 0x00,
    // i
    0x00, 0x00, 0xec, 0x3f, 0x00, 0x00,
    // j
    0x00, 0x80, 0x00, 0x80, 0xec, 0x7f, 0x00, 0x00,
    // k
    0x00, 0x00, 0xfc, 0x3f, 0x00, 0x02, 0x00, 0x02, 0x00, 0x05, 0x80, 0x08,
    0x40, 0x10, 0x20, 0x20, 0x00, 0x00,
    // l
    0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00,
    // m
    0x00, 0x00, 0xe0, 0x3f, 0x40, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
    0x60, 0x00, 0xc0, 0x3f, 0x40, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
    0x60, 0x00, 0xc0, 0x3f, 0x00, 0x00,
    // n
    0x00, 0x00, 0xe0, 0x3f, 0x40, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
    0x20, 0x00, 0x40, 0x00, 0x80, 0x3f, 0x00, 0x00,
    // o
    0x00, 0x00, 0x80, 0x0f, 0x40, 0x10, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x40, 0x10, 0x80, 0x0f, 0x00, 0x00,
    // p
    0x00, 0x00, 0xf0, 0xff, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x20, 0x08, 0xc0, 0x07, 0x00, 0x00,
    // q
    0x00, 0x00, 0xc0, 0x07, 0x20, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x20, 0x08, 0xf0, 0xff, 0x00, 0x00,
    // r
    0x00, 0x00, 0xe0, 0x3f, 0x40, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20, 0x00,
    0x00, 0x00,
    // s
    0x00, 0x00, 0xc0, 0x11, 0x20, 0x23, 0x20, 0x22, 0x20, 0x22, 0x20, 0x22,
    0x20, 0x24, 0x40, 0x1c, 0x00, 0x00,
    // t
    0x20, 0x00, 0xf8, 0x1f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00,
    // u
    0x00, 0x00, 0xe0, 0x0f, 0x00, 0x10, 0x00, 0x20, 0x00, 0x20, 0x00, 0x20,
    0x00, 0x20, 0x00, 0x10, 0xe0, 0x3f, 0x00, 0x00,
    // v
    0x00, 0x00, 0x60, 0x00, 0x80, 0x01, 0x00, 0x06, 0x00, 0x18, 0x00, 0x30,
    0x00, 0x18, 0x00, 0x06, 0x80, 0x01, 0x60, 0x00,
    // w
    0x00, 0x00, 0x60, 0x00, 0x80, 0x03, 0x00, 0x0c, 0x00, 0x30, 0x00, 0x0e,
    0x80, 0x01, 0x60, 0x00, 0x80, 0x01, 0x00, 0x0e, 0x00, 0x30, 0x00, 0x0c,
    0x80, 0x03, 0x60, 0x00,
    // x
    0x00, 0x00, 0x20, 0x20, 0x60, 0x30, 0x80, 0x0d, 0x00, 0x02, 0x00, 0x02,
    0x80, 0x0d, 0x60, 0x30, 0x20, 0x20, 0x00, 0x00,
    // y
    0x10, 0x00, 0x60, 0x80, 0x80, 0x83, 0x00, 0x8c, 0x00, 0x70, 0x00, 0x1c,
    0x00, 0x03, 0xe0, 0x00, 0x10, 0x00, 0x00, 0x00,
    // z
    0x00, 0x00, 0x20, 0x30, 0x20, 0x28, 0x20, 0x24, 0x20, 0x22, 0x20, 0x21,
    0xa0, 0x20, 0x60, 0x20, 0x00, 0x00,
    // {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0xfc, 0x7e, 0x02, 0x80,
    0x02, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // |
    0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0x00, 0x00, 0x00, 0x00,
    // }
    0x00, 0x00, 0x00, 0x00, 0x02, 0x80, 0x02, 0x80, 0xfc, 0x7e, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    // ~
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x01,
    0x00, 0x00,
    // °
    0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x44, 0x00, 0x44, 0x00, 0x44, 0x00,
    0x38, 0x00, 0x00, 0x00,
    // End
    0x00};

static const int SANS_SERIF_16PX_POINTERS_LENGTH = 97;
static unsigned char *SANS_SERIF_16PX_POINTERS[] = {
    SANS_SERIF_16PX_DATA,        SANS_SERIF_16PX_DATA + 10,
    SANS_SERIF_16PX_DATA + 22,   SANS_SERIF_16PX_DATA + 34,
    SANS_SERIF_16PX_DATA + 60,   SANS_SERIF_16PX_DATA + 80,
    SANS_SERIF_16PX_DATA + 110,  SANS_SERIF_16PX_DATA + 134,
    SANS_SERIF_16PX_DATA + 140,  SANS_SERIF_16PX_DATA + 152,
    SANS_SERIF_16PX_DATA + 164,  SANS_SERIF_16PX_DATA + 180,
    SANS_SERIF_16PX_DATA + 206,  SANS_SERIF_16PX_DATA + 222,
    SANS_SERIF_16PX_DATA + 234,  SANS_SERIF_16PX_DATA + 244,
    SANS_SERIF_16PX_DATA + 254,  SANS_SERIF_16PX_DATA + 274,
    SANS_SERIF_16PX_DATA + 294,  SANS_SERIF_16PX_DATA + 314,
    SANS_SERIF_16PX_DATA + 334,  SANS_SERIF_16PX_DATA + 356,
    SANS_SERIF_16PX_DATA + 376,  SANS_SERIF_16PX_DATA + 396,
    SANS_SERIF_16PX_DATA + 416,  SANS_SERIF_16PX_DATA + 436,
    SANS_SERIF_16PX_DATA + 456,  SANS_SERIF_16PX_DATA + 466,
    SANS_SERIF_16PX_DATA + 476,  SANS_SERIF_16PX_DATA + 502,
    SANS_SERIF_16PX_DATA + 528,  SANS_SERIF_16PX_DATA + 554,
    SANS_SERIF_16PX_DATA + 572,  SANS_SERIF_16PX_DATA + 604,
    SANS_SERIF_16PX_DATA + 626,  SANS_SERIF_16PX_DATA + 648,
    SANS_SERIF_16PX_DATA + 670,  SANS_SERIF_16PX_DATA + 694,
    SANS_SERIF_16PX_DATA + 714,  SANS_SERIF_16PX_DATA + 732,
    SANS_SERIF_16PX_DATA + 756,  SANS_SERIF_16PX_DATA + 780,
    SANS_SERIF_16PX_DATA + 790,  SANS_SERIF_16PX_DATA + 800,
    SANS_SERIF_16PX_DATA + 820,  SANS_SERIF_16PX_DATA + 838,
    SANS_SERIF_16PX_DATA + 864,  SANS_SERIF_16PX_DATA + 888,
    SANS_SERIF_16PX_DATA + 914,  SANS_SERIF_16PX_DATA + 934,
    SANS_SERIF_16PX_DATA + 960,  SANS_SERIF_16PX_DATA + 982,
    SANS_SERIF_16PX_DATA + 1002, SANS_SERIF_16PX_DATA + 1020,
    SANS_SERIF_16PX_DATA + 1044, SANS_SERIF_16PX_DATA + 1068,
    SANS_SERIF_16PX_DATA + 1102, SANS_SERIF_16PX_DATA + 1124,
    SANS_SERIF_16PX_DATA + 1142, SANS_SERIF_16PX_DATA + 1166,
    SANS_SERIF_16PX_DATA + 1178, SANS_SERIF_16PX_DATA + 1188,
    SANS_SERIF_16PX_DATA + 1200, SANS_SERIF_16PX_DATA + 1226,
    SANS_SERIF_16PX_DATA + 1242, SANS_SERIF_16PX_DATA + 1258,
    SANS_SERIF_16PX_DATA + 1276, SANS_SERIF_16PX_DATA + 1296,
    SANS_SERIF_16PX_DATA + 1314, SANS_SERIF_16PX_DATA + 1334,
    SANS_SERIF_16PX_DATA + 1352, SANS_SERIF_16PX_DATA + 1364,
    SANS_SERIF_16PX_DATA + 1384, SANS_SERIF_16PX_DATA + 1404,
    SANS_SERIF_16PX_DATA + 1410, SANS_SERIF_16PX_DATA + 1418,
    SANS_SERIF_16PX_DATA + 1436, SANS_SERIF_16PX_DATA + 1442,
    SANS_SERIF_16PX_DATA + 1472, SANS_SERIF_16PX_DATA + 1492,
    SANS_SERIF_16PX_DATA + 1512, SANS_SERIF_16PX_DATA + 1532,
    SANS_SERIF_16PX_DATA + 1552, SANS_SERIF_16PX_DATA + 1566,
    SANS_SERIF_16PX_DATA + 1584, SANS_SERIF_16PX_DATA + 1596,
    SANS_SERIF_16PX_DATA + 1616, SANS_SERIF_16PX_DATA + 1636,
    SANS_SERIF_16PX_DATA + 1664, SANS_SERIF_16PX_DATA + 1684,
    SANS_SERIF_16PX_DATA + 1704, SANS_SERIF_16PX_DATA + 1722,
    SANS_SERIF_16PX_DATA + 1742, SANS_SERIF_16PX_DATA + 1752,
    SANS_SERIF_16PX_DATA + 1772, SANS_SERIF_16PX_DATA + 1798,
    SANS_SERIF_16PX_DATA + 1814,
};
} // namespace SSD1306