#include "display.h"
#include "iv25_font.h"

#define NUM_TUBES (6 * 8)

int latchPin = 13;  // Pin connected to ST_CP of 74HC595
int clockPin = 16;  // Pin connected to SH_CP of 74HC595
int dataPin = 14;   // Pin connected to DS of 74HC595
int enablePin = 12; // Pin connected to the Cathode MOSFET

IV25Display dsp(NUM_TUBES, latchPin, dataPin, clockPin, enablePin);

char str[] = "so long and thanks for all the fish!";

void setup() {}

void loop() {
  dsp.print(str);
  delay(1000);
  while (!dsp.fully_scrolled()) {
    dsp.scroll();
    delay(200);
  }
  delay(2000);
}
