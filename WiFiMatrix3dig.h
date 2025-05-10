#ifndef WiFiMatrix3dig
#define WiFiMatrix3dig

//#include "Arduino_LED_Matrix.h"

void add_to_frame(int index, int pos);

byte fonts[][8] = {
  { 0, 7, 5, 5, 5, 7, 0, 0}, // 0
  { 0, 2, 6, 2, 2, 7, 0, 0}, // 1
  { 0, 7, 1, 7, 4, 7, 0, 0}, // 2
  { 0, 7, 1, 7, 1, 7, 0, 0}, // 3
  { 0, 5, 5, 7, 1, 1, 0, 0}, // 4
  { 0, 7, 4, 7, 1, 7, 0, 0}, // 5
  { 0, 7, 4, 7, 5, 7, 0, 0}, // 6
  { 0, 7, 1, 1, 1, 1, 0, 0}, // 7
  { 0, 7, 5, 7, 5, 7, 0, 0}, // 8
  { 0, 7, 5, 7, 1, 7, 0, 0}, // 9
};

byte empty[8][12], frame[8][12];

void show3dig(ArduinoLEDMatrix &m, int x) {
  byte hun = x / 100;
  byte rem = x % 100;
  byte ten = rem / 10;
  byte one = rem % 10;
  memcpy(frame, empty, sizeof empty);
  add_to_frame(hun, -1);
  add_to_frame(ten, 3);
  add_to_frame(one, 7);
  m.renderBitmap(frame, 8, 12);
}

void add_to_frame(int index, int pos) {
  for (int row = 0; row < 8; row++) {
    long temp = fonts[index][row] << (7 - pos);
    for (int col = 0; col < 12; col++) {
      frame[row][col] |= (temp >> (11 - col)) & 1;
    }
  }
}

#endif
