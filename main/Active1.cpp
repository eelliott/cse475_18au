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

void Active1::loop(uint32_t dt) {
//  dprintln(F("Active1"));
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 0.001f;
}