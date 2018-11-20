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

void Ambient1::loop(uint32_t dt) {
//  dprintln(F("Ambient1"));
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.0025f;
}
