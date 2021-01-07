#include "display.h"

#define NUM_TUBES (6 * 8)
int latchPin = 13;  // Pin connected to ST_CP of 74HC595
int clockPin = 16;  // Pin connected to SH_CP of 74HC595
int dataPin = 14;   // Pin connected to DS of 74HC595
int enablePin = 12; // Pin connected to the Cathode MOSFET

IV25Display dsp(NUM_TUBES, latchPin, dataPin, clockPin, enablePin);
uint8_t buf[NUM_TUBES]; // Create buffer with one byte for each tube

void setup() {

  // Fill buffer with some values
  for (int i = 0; i < NUM_TUBES; i++) {
    // Create chessboard pattern
    if (i % 2) {
      buf[i] = 0b00101010;
    } else {
      buf[i] = 0b01010101;
    }
  }

  // Display raw buffer
  dsp.raw(buf, NUM_TUBES);
}

void loop() {
  static int i = 0;

  // Turn display on and off repeatedly
  dsp.enable((i++) % 2);
  delay(1000);
}
