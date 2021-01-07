
#ifndef _font_h_
#define _font_h_

const uint16_t font_offset[] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0, /* 0 */
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0, /* 1 */
    0,
    2,
    4,
    7,
    0,
    0,
    0,
    13,
    15,
    18,
    21,
    25,
    0,
    29,
    328,
    33, /* 2 */
    37,
    42,
    46,
    51,
    56,
    61,
    66,
    71,
    76,
    81,
    86,
    0,
    0,
    0,
    0,
    0, /* 3 */
    0,
    88,
    93,
    98,
    103,
    108,
    113,
    118,
    123,
    128,
    132,
    137,
    142,
    147,
    153,
    37, /* 4 */
    /*P ->*/ 159,
    164,
    169,
    174,
    179,
    185,
    190,
    196,
    202,
    206,
    212,
    0,
    0,
    0,
    0,
    0, /* 5 */
    0,
    217,
    221,
    226,
    230,
    235,
    240,
    243,
    247,
    251,
    253,
    256,
    260,
    263,
    269,
    273, /* 6 */
    277,
    281,
    285,
    289,
    293,
    297,
    301,
    305,
    311,
    315,
    319,
    0,
    0,
    0,
    0,
    0, /* 7 */
};
const uint8_t font_data[] = {

    /* ' ' */
    0b00000000,
    0b11111111,

    /* ! */
    0b01111101,
    0b11111111,

    /* " */
    0b01000000,
    0b01000000,
    0b11111111,

    /* # */
    0b00010100,
    0b00111110,
    0b00010100,
    0b00111110,
    0b00010100,
    0b11111111,

    /* ' */
    0b01000000,
    0b11111111,

    /* ( */
    0b01000001,
    0b00111110,
    0b11111111,

    /* ) */
    0b00111110,
    0b01000001,
    0b11111111,

    /* * */
    0b00010100,
    0b00001000,
    0b00010100,
    0b11111111,

    /* + */
    0b00001000,
    0b00011100,
    0b00001000,
    0b11111111,

    /* - */
    0b00001000,
    0b00001000,
    0b00001000,
    0b11111111,

    /* / */
    0b01110000,
    0b00001110,
    0b00000001,
    0b11111111,

    /* 0 */
    0b00111110,
    0b01000001,
    0b01000001,
    0b00111110,
    0b11111111,

    /* 1 */
    0b00000001,
    0b01111111,
    0b00100001,
    0b11111111,

    /* 2 */
    0b00110001,
    0b01001001,
    0b01000101,
    0b00100011,
    0b11111111,

    /* 3 */
    0b00110110,
    0b01001001,
    0b01000001,
    0b00100010,
    0b11111111,

    /* 4 */
    0b00000100,
    0b01001111,
    0b00100100,
    0b00011100,
    0b11111111,

    /* 5 */
    0b01000110,
    0b01001001,
    0b01001001,
    0b01111010,
    0b11111111,

    /* 6 */
    0b00100110,
    0b01001001,
    0b01001001,
    0b00111110,
    0b11111111,

    /* 7 */
    0b01100000,
    0b01011000,
    0b01000111,
    0b01000000,
    0b11111111,

    /* 8 */
    0b00110110,
    0b01001001,
    0b01001001,
    0b00110110,
    0b11111111,

    /* 9 */
    0b00111110,
    0b01001001,
    0b01001001,
    0b00110010,
    0b11111111,

    /* : */
    0b00010100,
    0b11111111,

    /* A */
    0b00111111,
    0b01001000,
    0b01001000,
    0b00111111,
    0b11111111,

    /* B */
    0b00110110,
    0b01001001,
    0b01001001,
    0b01111111,
    0b11111111,

    /* C */
    0b00100010,
    0b01000001,
    0b01000001,
    0b00111110,
    0b11111111,

    /* D */
    0b00111110,
    0b01000001,
    0b01000001,
    0b01111111,
    0b11111111,

    /* E */
    0b01000001,
    0b01001001,
    0b01001001,
    0b01111111,
    0b11111111,

    /* F */
    0b01000000,
    0b01001000,
    0b01001000,
    0b01111111,
    0b11111111,

    /* G */
    0b01000110,
    0b01000101,
    0b01000001,
    0b00111110,
    0b11111111,

    /* H */
    0b01111111,
    0b00001000,
    0b00001000,
    0b01111111,
    0b11111111,

    /* I */
    0b01000001,
    0b01111111,
    0b01000001,
    0b11111111,

    /* J */
    0b01000000,
    0b01111110,
    0b01000001,
    0b00000001,
    0b11111111,

    /* K */
    0b01100011,
    0b00010100,
    0b00001000,
    0b01111111,
    0b11111111,

    /* L */
    0b00000001,
    0b00000001,
    0b00000001,
    0b01111111,
    0b11111111,

    /* M */
    0b01111111,
    0b00100000,
    0b00010000,
    0b00100000,
    0b01111111,
    0b11111111,

    /* N */
    0b01111111,
    0b00000010,
    0b00001100,
    0b00110000,
    0b01111111,
    0b11111111,

    /* P */
    0b00110000,
    0b01001000,
    0b01001000,
    0b01111111,
    0b11111111,

    /* Q */
    0b00111111,
    0b01000011,
    0b01000001,
    0b00111110,
    0b11111111,

    /* R */
    0b00110001,
    0b01001010,
    0b01001100,
    0b01111111,
    0b11111111,

    /* S */
    0b00100110,
    0b01001001,
    0b01001001,
    0b00110010,
    0b11111111,

    /* T */
    0b01000000,
    0b01000000,
    0b01111111,
    0b01000000,
    0b01000000,
    0b11111111,

    /* U */
    0b01111110,
    0b00000001,
    0b00000001,
    0b01111110,
    0b11111111,

    /* V */
    0b01111100,
    0b00000010,
    0b00000001,
    0b00000010,
    0b01111100,
    0b11111111,

    /* W */
    0b01111110,
    0b00000001,
    0b00000010,
    0b00000001,
    0b01111110,
    0b11111111,

    /* X */
    0b01110111,
    0b00001000,
    0b01110111,
    0b11111111,

    /* Y */
    0b01100000,
    0b00010000,
    0b00001111,
    0b00010000,
    0b01100000,
    0b11111111,

    /* Z */
    0b01100001,
    0b01010001,
    0b01001101,
    0b01000011,
    0b11111111,

    /* a */
    0b00000111,
    0b00001001,
    0b00000110,
    0b11111111,

    /* b */
    0b00000110,
    0b00001001,
    0b00001001,
    0b00111111,
    0b11111111,

    /* c */
    0b00001001,
    0b00001001,
    0b00000110,
    0b11111111,

    /* d */
    0b00111111,
    0b00001001,
    0b00001001,
    0b00000110,
    0b11111111,

    /* e */
    0b00001100,
    0b00010101,
    0b00010101,
    0b00001110,
    0b11111111,

    /* f */
    0b00101000,
    0b00011111,
    0b11111111,

    /* g */
    0b00001110,
    0b00010101,
    0b00001001,
    0b11111111,

    /* h */
    0b00000111,
    0b00001000,
    0b00111111,
    0b11111111,

    /* i */
    0b00101111,
    0b11111111,

    /* j */
    0b00101110,
    0b00000001,
    0b11111111,

    /* k */
    0b00001101,
    0b00000010,
    0b00111111,
    0b11111111,

    /* l */
    0b00000001,
    0b00111110,
    0b11111111,

    /* m */
    0b00000111,
    0b00001000,
    0b00000111,
    0b00001000,
    0b00001111,
    0b11111111,

    /* n */
    0b00000111,
    0b00001000,
    0b00001111,
    0b11111111,

    /* o */
    0b00000110,
    0b00001001,
    0b00000110,
    0b11111111,

    /* p */
    0b00001100,
    0b00010010,
    0b00001111,
    0b11111111,

    /* q */
    0b00001111,
    0b00010010,
    0b00001100,
    0b11111111,

    /* r */
    0b00001000,
    0b00000100,
    0b00001111,
    0b11111111,

    /* s */
    0b00010010,
    0b00010101,
    0b00001001,
    0b11111111,

    /* t */
    0b00010001,
    0b00111110,
    0b00010000,
    0b11111111,

    /* u */
    0b00001111,
    0b00000001,
    0b00001110,
    0b11111111,

    /* v */
    0b00001110,
    0b00000001,
    0b00001110,
    0b11111111,

    /* w */
    0b00001110,
    0b00000001,
    0b00000110,
    0b00000001,
    0b00001110,
    0b11111111,

    /* x */
    0b00001001,
    0b00000110,
    0b00001001,
    0b11111111,

    /* y */
    0b00001110,
    0b00000101,
    0b00001001,
    0b11111111,

    /* z */
    0b00001101,
    0b00001011,
    0b00001001,
    0b11111111,
    /*  */
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11111111,

    /* . */
    0b00000001,
    0b11111111,

};

#endif
