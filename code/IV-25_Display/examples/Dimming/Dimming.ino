#include "display.h"

int latchPin = 13;  // Pin connected to ST_CP of 74HC595
int clockPin = 16;  // Pin connected to SH_CP of 74HC595
int dataPin = 14;   // Pin connected to DS of 74HC595
int enablePin = 12; // Pin connected to the Cathode MOSFET

IV25Display dsp(6 * 8, latchPin, dataPin, clockPin, enablePin);

void setup() { dsp.print("Hello World!"); }

void loop() {

  for (int i = 0; i < 1024;) {
    // Turn display on and off repeatedly
    dsp.dim(i++);
    delay(10);
  }
  delay(2000);
  for (int i = 1024 - 1; i >= 0;) {
    // Turn display on and off repeatedly
    dsp.dim(i--);
    delay(10);
  }
  delay(2000);
}
