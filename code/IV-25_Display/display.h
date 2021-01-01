
#ifndef _display_h_
#define _display_h_
#include <stdint.h>
#include "Arduino.h"
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define SET_BIT(var,pos) ((var) = (var) | (1<<(pos)))





    class IV25Display
    {
      public:
        IV25Display(uint16_t len, uint8_t latch, uint8_t data, uint8_t clock);
        void print(char * str);
        void raw(char * str);
        
        void clear();


      protected:
        void write_buffer();
        uint8_t convert_screen_to_byte(uint8_t screen, uint8_t odd);
        void clear_buffer();
    //    void publish(std_msgs::Float32* msg, void* arg);
        uint8_t * _buffer;
        uint8_t _latch, _data, _clock;
        uint16_t _length;
    };



#endif
