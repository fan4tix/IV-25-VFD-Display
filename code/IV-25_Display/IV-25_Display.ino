
//**************************************************************//
//  Name    : shiftOutCode, Hello World
//  Author  : Carlyn Maw,Tom Igoe, David A. Mellis
//  Date    : 25 Oct, 2006
//  Modified: 23 Mar 2010
//  Version : 2.0
//  Notes   : Code for using a 74HC595 Shift Register           //
//          : to count from 0 to 255
//****************************************************************
#include "display.h"
//Pin connected to ST_CP of 74HC595
int latchPin = 13;
//Pin connected to SH_CP of 74HC595
int clockPin = 16;
////Pin connected to DS of 74HC595
int dataPin = 14;
 char buf[100];
 int i = 1330;
IV25Display dsp( 6 * 8, latchPin, dataPin, clockPin);
void setup() {
  Serial.begin(115200);
}

void loop() {
  dsp.print("Hello World!")
  delay(1000);

}