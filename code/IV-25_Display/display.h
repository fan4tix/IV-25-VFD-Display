
#ifndef _display_h_
#define _display_h_
#include <stdint.h>
#include "Arduino.h"
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define SET_BIT(var,pos) ((var) = (var) | (1<<(pos)))


    class IV25Display
    {
      public:
        IV25Display(uint16_t len, uint8_t latch, uint8_t data, uint8_t clock, uint8_t enable);

        void print(char * str);
        void raw(char * str, uint16_t buf_len);
        void clear();
        void enable(uint8_t on);
        
      protected:
        void write_buffer();
        uint8_t convert_screen_to_byte(uint8_t screen, uint8_t odd);
        void clear_buffer();

        uint8_t * _buffer;
        uint8_t _latch, _data, _clock, _enable;
        uint16_t _length;
    };



#endif
