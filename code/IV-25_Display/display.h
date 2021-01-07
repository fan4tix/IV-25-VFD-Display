
#ifndef _display_h_
#define _display_h_
#include "Arduino.h"
#include <stdint.h>

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define SET_BIT(var, pos) ((var) = (var) | (1 << (pos)))

#define ALIGN_LEFT 1
#define ALIGN_RIGHT -1
// #define ALIGN_CENTER = 0

class IV25Display {
public:
  IV25Display(uint16_t len, uint8_t latch, uint8_t data, uint8_t clock,
              uint8_t enable);

  int8_t print(char *str);
  void raw(uint8_t *data, uint16_t buf_len);
  void clear();
  void enable(uint8_t on);
  void dim(uint8_t brightness);
  void set_alignment(int8_t alignment);
  void scroll();
  uint8_t fully_scrolled();

protected:
  void write_buffer();
  uint8_t convert_screen_to_byte(uint8_t screen, uint8_t odd);
  void clear_buffer();
  uint16_t buflen(char *str);

  int8_t _alignment;
  uint8_t *_buffer;
  uint8_t _latch, _data, _clock, _enable;
  uint16_t _numtubes;
  int16_t _scroll_offset;
  uint16_t _buf_length;
};

#endif
