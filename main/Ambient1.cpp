#include "Ambient1.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
  int MAX = 12;
  int MIN = 8;
  return rand() % (MAX - MIN + 1) + MIN;
}

// weather
void Ambient1::loop(uint32_t dt) {
  if (dt > 1000) {
    switch (rand() % 5) {
      case 0:
        Midi::setSound(0x13);
        break;
      case 1:
        Midi::setSound(0x14);
        break;
      case 2:
        Midi::setSound(0x16);
        break;
      case 3:
        Midi::setSound(0x17);
        break;
      case 4:
        Midi::setSound(0x18);
        break;
    }

    switch (rand() % 4) {
      case 0:
        Neopixel::setLight(0x0F);
        break;
      case 1:
        Neopixel::setLight(0x07);
        break;
      case 2:
        Neopixel::setLight(0x0C);
        break;
      case 3:
        Neopixel::setLight(0x0E);
        break;
    }
  }
  
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.0025f;
}
