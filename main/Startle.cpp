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

void Startle::loop(uint32_t dt) {
  // TODO

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
