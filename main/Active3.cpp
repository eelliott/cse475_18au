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

void Active3::loop(uint32_t dt) {
//  dprintln(F("Active3"));
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 0.002f;
}
