#include "Active2.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Active2::_localWeights[];

uint8_t Active2::getNumRepeats() {
  int MAX = 6;
  int MIN = 2;
  return rand() % (MAX - MIN + 1) + MIN;
}

// bells
void Active2::loop(uint32_t dt) {
  if (dt > 1000) {
    uint32_t soundIndex = rand() % (0x24 - 0x21 + 0x01) + 0x21;
    Neopixel::setLight(0x04);
    Midi::setSound(soundIndex);
  }
}

const uint8_t* Active2::getLocalWeights() {
  return this->_localWeights;
}

float Active2::getStartleFactor() {
  return 0.0015f;
}
