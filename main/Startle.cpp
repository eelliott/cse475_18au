#include "Startle.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
  int MAX = 3;
  int MIN = 1;
  return rand() % (MAX - MIN + 1) + MIN;
}

// lightning/phone
void Startle::loop(uint32_t dt) {
  if (dt > 1000) {
    switch (rand() % 3) {
      case 0:
        Midi::setSound(0x12);
        break;
      case 1:
        Midi::setSound(0x25);
        break;
      case 2:
        Midi::setSound(0x27);
        break;
    }

    switch (rand() % 4) {
      case 0:
        Neopixel::setLight(0x09);
        break;
      case 1:
        Neopixel::setLight(0x0D);
        break;
      case 2:
        Neopixel::setLight(0x03);
        break;
      case 3:
        Neopixel::setLight(0x12);
        break;
    }
  }
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return 9999999999;
}

bool Startle::rxStartle(uint8_t len, uint8_t* payload) {}

void Startle::PIR() {}

void Startle::startled() {}
