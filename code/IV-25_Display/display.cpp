#include "math.h"
#include "display.h"
#include "font.h"
IV25Display::IV25Display(uint16_t len, uint8_t latch, uint8_t data, uint8_t clock) {

  // Allocate RAM for screen buffer
  _buffer = (uint8_t *) malloc(len * sizeof(uint8_t));

  _length = len;

  _latch = latch;
  _data = data;
  _clock = clock;

  pinMode(_latch, OUTPUT);
  pinMode(_data, OUTPUT);
  pinMode(_clock, OUTPUT);

}

void IV25Display::print(char * str) {
  // Put string into buffer
  clear_buffer();

  uint16_t buffptr = 0;
  uint16_t strl = strlen(str);
  char c = str[strl - 1];
  for (uint16_t i = strl - 1; i >= 0 && buffptr < _length;) {

    // Load Character Bitmap from Font
    uint8_t bufdata = font_data[font_offset[c]];
    for ( uint8_t j = 1; bufdata != 0xFF && buffptr < _length;) {
      _buffer[buffptr++] = bufdata;
      bufdata =  font_data[font_offset[c] + j];
      j++;
    }
    if (buffptr < _length) { // Space after every character
      _buffer[buffptr++] = 0b00000000;
    } else {
      break;
    }
    c = str[--i]; // Next character

  }

  this->write_buffer();
}

void IV25Display::raw(char * str) {
  clear_buffer();
  uint16_t len = min((uint16_t) strlen(str), _length);
  Serial.print(len);
  uint16_t buffptr = 0;
  while (buffptr<len){
    _buffer[buffptr] = str[buffptr];  
    buffptr++;
  }
  this->write_buffer();
}

void IV25Display::clear(){
  this->clear_buffer();
  this->write_buffer();
}

void IV25Display::write_buffer() {
  // Shift out Buffer

  digitalWrite(_latch, LOW);

  // shift out the bits:

  for (uint16_t i = 0; i < _length; i++) {
    shiftOut(_data, _clock, MSBFIRST, convert_screen_to_byte(_buffer[_length - (i + 1)] << 1, (i % 2 == 1)));
    //shiftOut(_data, _clock, MSBFIRST, _buffer[_length - (i + 1)]);
  }

  digitalWrite(_latch, HIGH);

}

void IV25Display::clear_buffer() {
  for (uint16_t i = 0; i < _length; i++) {
    _buffer[i] = 0;
  }
}

uint8_t IV25Display::convert_screen_to_byte(uint8_t screen, uint8_t odd) {
  uint8_t ret = 0;
  if (odd) {
    if (CHECK_BIT(screen, 4))
      SET_BIT(ret, 1);
    if (CHECK_BIT(screen, 1))
      SET_BIT(ret, 2);
    if (CHECK_BIT(screen, 2))
      SET_BIT(ret, 3);
    if (CHECK_BIT(screen, 5))
      SET_BIT(ret, 4);
    if (CHECK_BIT(screen, 6))
      SET_BIT(ret, 5);
    if (CHECK_BIT(screen, 3))
      SET_BIT(ret, 6);
    if (CHECK_BIT(screen, 7))
      SET_BIT(ret, 7);

  } else {
    if (CHECK_BIT(screen, 3))
      SET_BIT(ret, 1);
    if (CHECK_BIT(screen, 7))
      SET_BIT(ret, 2);
    if (CHECK_BIT(screen, 6))
      SET_BIT(ret, 3);
    if (CHECK_BIT(screen, 2))
      SET_BIT(ret, 4);
    if (CHECK_BIT(screen, 5))
      SET_BIT(ret, 5);
    if (CHECK_BIT(screen, 1))
      SET_BIT(ret, 6);
    if (CHECK_BIT(screen, 4))
      SET_BIT(ret, 7);
  }
  return ret;
}
