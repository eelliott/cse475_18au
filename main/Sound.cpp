#include "Sound.h"
#include "Midi.h"

// Define your new Midi sounds here! Make sure to add them to the header and Midi::SOUNDS.
Sound Midi::scale(
    VS1053_BANK_MELODY,
    VS1053_GM1_CELLO,
    127,
    true,
    8,
    (uint8_t[]) {64, 66, 68, 70, 72, 74, 76, 78},
    (uint8_t[]) {50, 50, 50, 50, 50, 50, 50, 50}
);

// Black-throated Blue Warbler
Sound Midi::bbwa(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    30,
    (uint8_t[]) {110, 108, 106, 112, 111, 110, 109, 108, 105, 109, 112, 114, 113, 114, 113, 112, 111, 108, 106, 104,
                 107, 115, 114, 115, 116, 115, 116, 115, 116, 115},
    (uint8_t[]) {21, 14, 7, 7, 10, 38, 3, 4, 3, 4, 3, 4, 3, 4, 7, 13, 18, 3, 3, 4, 4, 10, 4, 27, 4, 7, 3, 3, 4, 3},
    -20,
    1
);

// Blackpoll Warbler
Sound Midi::bpwa(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    21,
    (uint8_t[]) {120, 120, 120, 122, 121, 120, 121, 120, 119, 120, 122, 121, 120, 119, 120, 121, 120, 121, 120, 119,
                 120},
    (uint8_t[]) {3, 2, 14, 2, 5, 9, 4, 3, 7, 4, 2, 3, 2, 5, 7, 4, 14, 2, 3, 6, 2},
    -22,
    2
);

// Brown Creeper
Sound Midi::brcr(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    33,
    (uint8_t[]) {118, 117, 118, 117, 118, 117, 115, 114, 115, 115, 116, 115, 113, 112, 115, 115, 115, 115, 118, 115,
                 117, 116, 117, 117, 115, 117, 111, 111, 112, 111, 112, 114, 114},
    (uint8_t[]) {5, 4, 2, 2, 5, 14, 14, 2, 12, 2, 3, 2, 5, 2, 2, 18, 3, 2, 3, 2, 14, 2, 2, 3, 2, 3, 10, 2, 2, 2, 2, 5,
                 2},
    -22,
    1
);

// Northern Cardinal
Sound Midi::cardinal(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    58,
    (uint8_t[]) {97, 99, 101, 102, 102, 103, 104, 105, 107, 108, 109, 108, 109, 105, 94, 95, 96, 97, 98, 99, 100, 101,
                 102, 103, 104, 105, 106, 108, 109, 111, 105, 99, 98, 97, 96, 95, 93, 104, 105, 98, 97, 96, 95, 93, 94,
                 93, 104, 105, 99, 98, 97, 96, 95, 93, 105, 98, 97, 95},
    (uint8_t[]) {4, 3, 5, 2, 2, 7, 7, 4, 3, 2, 2, 3, 2, 2, 10, 11, 5, 5, 7, 4, 2, 7, 7, 5, 2, 5, 2, 7, 2, 3, 5, 2, 2, 5,
                 5, 9, 9, 3, 2, 3, 7, 2, 9, 3, 2, 5, 2, 2, 3, 2, 5, 3, 7, 4, 2, 2, 3, 5},
    -10,
    1
);

// Indigo Bunting
Sound Midi::indigobu(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    83,
    (uint8_t[]) {111, 110, 110, 111, 112, 116, 114, 116, 110, 103, 104, 110, 109, 107, 106, 105, 106, 115, 114, 115,
                 109, 102, 103, 110, 109, 108, 106, 115, 116, 119, 118, 116, 115, 113, 102, 103, 104, 105, 109, 111,
                 109, 114, 115, 116, 118, 116, 115, 114, 113, 112, 102, 103, 104, 108, 110, 116, 116, 113, 112, 111,
                 110, 108, 106, 104, 102, 105, 106, 107, 108, 113, 115, 116, 114, 113, 112, 111, 110, 109, 108, 106,
                 103, 105, 106},
    (uint8_t[]) {2, 5, 2, 3, 9, 2, 3, 2, 2, 3, 2, 3, 7, 2, 5, 2, 2, 2, 2, 3, 2, 2, 3, 5, 4, 3, 9, 7, 4, 2, 3, 2, 2, 7,
                 2, 2, 3, 2, 2, 3, 2, 3, 4, 5, 3, 2, 2, 2, 3, 2, 4, 3, 2, 2, 5, 2, 3, 2, 7, 7, 2, 3, 2, 2, 2, 4, 3, 2,
                 2, 3, 2, 2, 3, 2, 7, 5, 2, 2, 3, 2, 2, 2, 3},
    -15,
    1
);

// Dark-eyed Junco
Sound Midi::junco(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    76,
    (uint8_t[]) {113, 109, 113, 109, 113, 110, 108, 113, 110, 108, 112, 113, 111, 109, 112, 113, 109, 111, 112, 113,
                 109, 108, 113, 110, 108, 112, 113, 111, 109, 112, 113, 109, 110, 112, 113, 110, 108, 112, 113, 109,
                 110, 111, 113, 109, 108, 112, 113, 111, 109, 111, 113, 109, 112, 113, 110, 109, 112, 113, 109, 113,
                 110, 108, 112, 113, 109, 110, 113, 110, 109, 111, 113, 109, 112, 113, 111, 109},
    (uint8_t[]) {3, 2, 5, 2, 5, 2, 2, 5, 2, 2, 2, 3, 2, 2, 2, 5, 2, 3, 2, 5, 2, 2, 5, 2, 2, 2, 3, 2, 2, 2, 5, 2, 3, 3,
                 2, 2, 3, 2, 5, 2, 3, 2, 5, 2, 3, 3, 2, 2, 3, 3, 4, 5, 2, 2, 2, 3, 3, 4, 3, 4, 3, 2, 2, 5, 2, 2, 5, 2,
                 2, 2, 5, 2, 2, 3, 2, 2},
    -22,
    1
);

// Mourning Warbler
Sound Midi::mowa(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    57,
    (uint8_t[]) {105, 110, 111, 110, 103, 106, 103, 106, 104, 106, 109, 112, 109, 110, 109, 111, 110, 112, 111, 104,
                 111, 104, 105, 104, 106, 110, 109, 110, 109, 110, 109, 114, 110, 104, 106, 104, 106, 104, 107, 106,
                 110, 109, 110, 109, 104, 106, 104, 106, 104, 105, 106, 109, 108, 109, 112, 111, 109},
    (uint8_t[]) {3, 10, 4, 4, 3, 3, 4, 3, 4, 7, 3, 3, 4, 3, 4, 3, 3, 3, 4, 3, 4, 3, 4, 3, 3, 4, 3, 7, 4, 3, 3, 4, 3, 4,
                 3, 4, 3, 3, 4, 3, 7, 14, 7, 4, 3, 4, 3, 3, 4, 3, 4, 3, 4, 3, 3, 4, 3},
    -15,
    1
);

//   Baltimore Oriole
Sound Midi::oriole(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    25,
    (uint8_t[]) {101, 100, 99, 100, 98, 101, 100, 99, 100, 98, 100, 107, 105, 101, 99, 100, 99, 100, 98, 101, 100, 100,
                 101, 100, 99},
    (uint8_t[]) {4, 3, 7, 7, 17, 3, 10, 7, 3, 4, 14, 3, 3, 4, 4, 3, 4, 10, 17, 7, 17, 3, 7, 6, 14},
    -15,
    1
);

// Osprey
Sound Midi::osprey(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    23,
    (uint8_t[]) {96, 98, 97, 96, 99, 98, 97, 99, 98, 97, 100, 99, 98, 97, 100, 99, 98, 100, 99, 98, 100, 99, 98},
    (uint8_t[]) {5, 7, 2, 2, 2, 7, 2, 4, 5, 2, 2, 2, 5, 2, 7, 2, 2, 5, 2, 5, 7, 3, 2},
    -15,
    1
);

// Ovenbird
Sound Midi::oven(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    73,
    (uint8_t[]) {108, 107, 108, 107, 108, 107, 108, 107, 106, 103, 104, 107, 111, 111, 113, 108, 107, 106, 103, 104,
                 109, 111, 111, 115, 108, 107, 104, 103, 106, 116, 108, 111, 115, 116, 109, 108, 107, 106, 104, 106,
                 107, 108, 109, 111, 116, 113, 114, 113, 108, 107, 106, 107, 108, 107, 117, 115, 108, 111, 110, 113,
                 115, 109, 108, 107, 107, 109, 111, 115, 113, 108, 107, 108, 107},
    (uint8_t[]) {2, 2, 2, 2, 2, 5, 2, 2, 3, 2, 2, 3, 2, 3, 2, 2, 3, 2, 2, 3, 2, 2, 2, 2, 5, 2, 2, 3, 4, 2, 2, 7, 5, 2,
                 2, 3, 2, 2, 3, 2, 2, 2, 3, 7, 3, 2, 2, 3, 2, 2, 2, 5, 2, 3, 2, 2, 3, 7, 2, 2, 2, 2, 2, 12, 3, 2, 7, 4,
                 2, 5, 2, 2, 3},
    -19,
    1
);

// Song Sparrow
Sound Midi::songspar(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    61,
    (uint8_t[]) {117, 117, 117, 117, 117, 112, 111, 112, 111, 112, 112, 113, 112, 113, 112, 113, 112, 111, 112, 111,
                 112, 113, 112, 108, 104, 101, 113, 107, 104, 103, 101, 100, 113, 107, 104, 101, 113, 107, 104, 113,
                 113, 112, 113, 112, 113, 112, 112, 113, 112, 112, 103, 104, 103, 104, 103, 104, 103, 104, 117, 103,
                 102},
    (uint8_t[]) {16, 13, 14, 11, 9, 7, 2, 19, 2, 5, 12, 2, 9, 3, 4, 3, 4, 3, 41, 3, 2, 10, 2, 2, 9, 4, 9, 2, 7, 2, 2, 2,
                 9, 2, 10, 5, 10, 3, 9, 3, 3, 2, 3, 2, 3, 2, 2, 2, 2, 5, 9, 2, 16, 5, 7, 2, 3, 2, 11, 2, 14},
    -20,
    1
);

// Rufous-sided Towhee
Sound Midi::towhee(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    47,
    (uint8_t[]) {117, 114, 112, 111, 107, 108, 112, 111, 109, 110, 112, 110, 106, 112, 111, 110, 112, 111, 107, 109,
                 111, 110, 107, 112, 111, 107, 111, 106, 105, 106, 107, 117, 113, 111, 110, 107, 108, 107, 108, 107,
                 106, 105, 107, 108, 107, 106, 105},
    (uint8_t[]) {3, 2, 2, 3, 5, 5, 3, 2, 2, 2, 3, 2, 2, 2, 3, 2, 2, 2, 3, 3, 2, 2, 3, 3, 2, 2, 5, 3, 2, 14, 2, 2, 3, 2,
                 2, 7, 2, 4, 7, 3, 4, 3, 5, 2, 14, 3, 2},
    -15,
    1
);

// Tufted Titmouse
Sound Midi::tuftedti(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    47,
    (uint8_t[]) {101, 100, 101, 100, 99, 98, 97, 101, 100, 99, 97, 98, 101, 100, 98, 97, 102, 101, 100, 99, 98, 97, 101,
                 100, 99, 98, 97, 101, 100, 101, 100, 99, 98, 97, 102, 101, 100, 99, 98, 97, 98, 102, 101, 100, 99, 98,
                 98},
    (uint8_t[]) {7, 3, 7, 7, 2, 2, 5, 21, 2, 3, 2, 2, 18, 7, 3, 2, 2, 19, 4, 3, 2, 2, 11, 7, 3, 2, 5, 2, 3, 7, 11, 3, 2,
                 2, 2, 19, 5, 2, 2, 2, 3, 3, 21, 2, 2, 3, 2},
    -15,
    1
);

// Veery
Sound Midi::veery(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    56,
    (uint8_t[]) {101, 105, 106, 104, 104, 106, 105, 104, 103, 106, 103, 104, 109, 111, 111, 109, 107, 105, 104, 104,
                 106, 107, 106,
                 107, 109, 108, 109, 111, 109, 108, 109, 107, 105, 104, 106, 102, 104, 107, 106, 105, 103, 102, 101,
                 100, 100, 102,
                 104, 106, 107, 107, 106, 104, 103, 102, 99, 100},
    (uint8_t[]) {2, 2, 3, 2, 5, 3, 2, 2, 2, 2, 2, 2, 2, 4, 2, 7, 5, 2, 3, 2, 3, 2, 2, 3, 2, 5, 2, 9, 5, 2, 3, 4, 3, 7,
                 7, 5, 7, 7,
                 4, 7, 3, 7, 2, 2, 7, 7, 5, 2, 2, 2, 2, 7, 2, 5, 4, 2},
    -15,
    1
);

// White-throated Sparrow
Sound Midi::whthsprw(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    34,
    (uint8_t[]) {107, 106, 107, 106, 107, 106, 107, 106, 106, 107, 106, 107, 105, 104, 105, 106, 105, 106, 107, 106,
                 105, 106, 107, 106, 105, 106, 105, 105, 104, 105, 105, 105, 106, 105},
    (uint8_t[]) {4, 12, 2, 2, 3, 2, 5, 4, 21, 3, 18, 2, 2, 2, 3, 2, 5, 34, 5, 7, 2, 10, 7, 30, 2, 10, 2, 33, 2, 3, 12,
                 16, 3, 4},
    -15,
    1
);

// Wilson's Warbler
Sound Midi::wiwa(
    VS1053_BANK_MELODY,
    124,
    127,
    false,
    52,
    (uint8_t[]) {109, 107, 111, 111, 111, 112, 116, 111, 108, 116, 112, 116, 111, 109, 105, 113, 112, 115, 111, 108,
                 112, 109, 108, 116, 112, 116, 111, 108, 114, 112, 116, 109, 108, 106, 107, 111, 116, 111, 107, 106,
                 110, 111, 114, 111, 107, 109, 114, 111, 109, 106, 110, 111},
    (uint8_t[]) {3, 2, 2, 2, 2, 3, 2, 2, 3, 2, 3, 2, 2, 3, 2, 3, 2, 2, 3, 2, 7, 2, 2, 3, 2, 2, 3, 4, 2, 2, 3, 2, 2, 3,
                 5, 2, 2, 3, 2, 3, 2, 2, 3, 2, 2, 3, 2, 2, 3, 2, 2, 3},
    -15,
    1
);

Sound Midi::bird1( // Active1
    VS1053_BANK_MELODY,
    124,
    120,
    false,
    8,
    (uint8_t[]) {94, 94, 94, 88, 90, 96, 90, 76},
    (uint8_t[]) {50, 50, 50, 50, 50, 50, 50, 50}
);

Sound Midi::ocarina( // Active2
    VS1053_BANK_MELODY,
    80,
    120,
    false,
    6,
    (uint8_t[]) {74, 71, 69, 74, 71, 69},
    (uint8_t[]) {50, 50, 50, 50, 50, 50}
);

Sound Midi::musicBox( // Active3
    VS1053_BANK_MELODY,
    11,
    120,
    false,
    5,
    (uint8_t[]) {96, 92, 94, 98, 96},
    (uint8_t[]) {50, 50, 50, 50, 50}
);

Sound Midi::bird2( // Ambient1
    VS1053_BANK_MELODY,
    124,
    120,
    false,
    3,
    (uint8_t[]) {84, 96, 90},
    (uint8_t[]) {50, 50, 50}
);

Sound Midi::harp( // Ambient2
    VS1053_BANK_MELODY,
    47,
    120,
    false,
    4,
    (uint8_t[]) {71, 69, 73, 76},
    (uint8_t[]) {50, 50, 50, 50}
);

Sound Midi::seashore( // Ambient3
    VS1053_BANK_MELODY,
    123,
    120,
    false,
    1,
    (uint8_t[]){64},
    (uint8_t[]){255}
);

Sound Midi::heavyRain( // Startle 
    VS1053_BANK_MELODY,
    127,
    120,
    false,
    1,
    (uint8_t[]){64},
    (uint8_t[]){255}
);