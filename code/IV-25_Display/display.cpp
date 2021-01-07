#include "display.h"
#include "iv25_font.h"
#include "math.h"

IV25Display::IV25Display(uint16_t numtubes, uint8_t latch, uint8_t data,
                         uint8_t clock, uint8_t enable) {

  // Allocate RAM for screen buffer
  _buffer = (uint8_t *)malloc(numtubes * sizeof(uint8_t));

  _numtubes = numtubes;

  _latch = latch;
  _data = data;
  _clock = clock;
  _enable = enable;
  _alignment = ALIGN_LEFT;
  _scroll_offset = 0;

  pinMode(_latch, OUTPUT);
  pinMode(_data, OUTPUT);
  pinMode(_clock, OUTPUT);
  pinMode(_enable, OUTPUT);

  this->enable(true);
}

void IV25Display::enable(uint8_t on) {
  if (on) {
    digitalWrite(_enable, HIGH);
  } else {
    digitalWrite(_enable, LOW);
  }
}

int8_t IV25Display::print(char *str) {
  // Allocate proper size buffer
  _buf_length = max(buflen(str), _numtubes);

  _buffer = (uint8_t *)realloc(_buffer, _buf_length);
  clear_buffer(); // Trailing / leading blank space

  // Check if realloc was successfull
  if (_buffer == NULL) {
    return -1;
  }
  // Put string into buffer
  uint16_t strl = strlen(str);

  if (_alignment == ALIGN_RIGHT) {
    uint16_t buffptr = 0;
    char c = str[strl - 1];
    for (uint16_t i = strl - 1; i >= 0 && buffptr < _buf_length;) {

      // Load Character Bitmap from Font
      uint8_t bufdata = font_data[font_offset[c]];
      for (uint8_t j = 1; bufdata != 0xFF && buffptr < _buf_length;) {
        _buffer[buffptr++] = bufdata;
        bufdata = font_data[font_offset[c] + j];
        j++;
      }
      if (buffptr < _buf_length) { // Space after every character
        _buffer[buffptr++] = 0b00000000;
      } else {
        break;
      }
      c = str[--i]; // Next character
    }
  } else if (_alignment == ALIGN_LEFT) {
    int16_t buffptr = _buf_length - 1;
    char c = str[0];
    for (uint16_t i = 0; i < strl && buffptr >= 0;) {
      // Fast forward to the end of the data
      int8_t j;
      for (j = 0; font_data[font_offset[c] + j + 1] != 0xFF; j++)
        ;
      // Insert character
      uint8_t bufdata = font_data[font_offset[c] + j];
      for (; j >= 0 && buffptr >= 0;) {
        _buffer[buffptr--] = bufdata;

        bufdata = font_data[font_offset[c] + --j];
      }
      if (buffptr >= 0) { // Space after every character
        _buffer[buffptr--] = 0b00000000;

      } else {
        break;
      }
      c = str[++i]; // Next character
    }
  }
  _scroll_offset = 0;
  this->write_buffer();
}

// Calculates amount of raw bytes (tubes) needed to display str
uint16_t IV25Display::buflen(char *str) {
  uint16_t ret = 0;
  for (uint8_t iStr = 0; iStr < strlen(str); iStr++) {
    char Char = str[iStr];
    uint8_t iChar = 0;
    for (; font_data[font_offset[Char] + iChar] != 0b11111111; iChar++) {
    }
    ret += iChar + 1; // +1 for trailing space
  }
  return ret;
}

void IV25Display::raw(uint8_t *data, uint16_t buf_len) {
  buf_len = max(buf_len, _numtubes);
  _buf_length = buf_len;
  clear_buffer();

  uint16_t buffptr = 0;
  while (buffptr < _buf_length) {
    _buffer[buffptr] = data[buffptr];
    buffptr++;
  }
  this->write_buffer();
}

void IV25Display::clear() {
  digitalWrite(_latch, LOW);

  for (int i = 0; i < _numtubes; i++) {
    shiftOut(_data, _clock, MSBFIRST, 0x00);
  }

  digitalWrite(_latch, HIGH);
  /*this->clear_buffer();
  this->write_buffer();*/
}

void IV25Display::dim(uint8_t brightness) { analogWrite(_enable, brightness); }

void IV25Display::set_alignment(int8_t alignment) { _alignment = alignment; }

void IV25Display::scroll() {
  if (_alignment != ALIGN_LEFT) {
    return;
  }
  if (!fully_scrolled()) {
    _scroll_offset++;
  }
  this->write_buffer();
}
uint8_t IV25Display::fully_scrolled() {
  return _scroll_offset + _numtubes >= _buf_length;
}
void IV25Display::write_buffer() {
  // Shift out Buffer

  digitalWrite(_latch, LOW);

  // shift out the bits:

  for (uint16_t i = 0; i < _numtubes; i++) {
    shiftOut(_data, _clock, MSBFIRST,
             convert_screen_to_byte(
                 _buffer[_numtubes - (i + 1) +
                         (_buf_length - _numtubes - _scroll_offset)]
                     << 1,
                 (i % 2 == 1)));
    // shiftOut(_data, _clock, MSBFIRST, _buffer[_numtubes - (i + 1)]);
  }

  digitalWrite(_latch, HIGH);
}

void IV25Display::clear_buffer() {
  for (uint16_t i = 0; i < _buf_length; i++) {
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
