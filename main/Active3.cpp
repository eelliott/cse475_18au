#include "Active3.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Active3::_localWeights[];

uint8_t Active3::getNumRepeats() {
  int MAX = 9;
  int MIN = 3;
  return rand() % (MAX - MIN + 1) + MIN;
}

// melodics
void Active3::loop(uint32_t dt) {
  if (dt > 1000) {
    uint32_t soundIndex = rand() % (0x20 - 0x19 + 0x01) + 0x19;
    Neopixel::setLight(0x05);
    Midi::setSound(soundIndex);
  }
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 0.002f;
}
