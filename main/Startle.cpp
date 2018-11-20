#include "Startle.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
 return 10;
}

// State* Startle::transition() { // not sure if it needed to be implemented
  
//   return this;
// }

void Startle::loop(uint32_t dt) {
//  dprintln(F("Startle"));
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return 9999999999;
}

bool Startle::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Startle::PIR() {}

void Startle::startled() {}