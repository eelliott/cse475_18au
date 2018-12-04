#include "Active1.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
  int MAX = 8;
  int MIN = 4;
 return rand() % (MAX - MIN + 1) + MIN;
}

// birds
void Active1::loop(uint32_t dt) {
  if (dt > 1000) {
    uint32_t soundIndex = rand() % (0x11 - 0x01 + 1) + 0x01;
    Neopixel::setLight(0x10);
    Midi::setSound(soundIndex);
  }
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 0.001f;
}
