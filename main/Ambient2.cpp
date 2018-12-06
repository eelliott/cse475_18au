#include "Ambient2.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
  int MAX = 10;
  int MIN = 8;
  return rand() % (MAX - MIN + 1) + MIN;
}

// insects
void Ambient2::loop(uint32_t dt) {
  if (dt > 1000) {
    uint32_t soundIndex = rand() % (0x29 - 0x2A + 0x01) + 0x2A;
    Neopixel::setLight(0x06);
    Midi::setSound(soundIndex);
  }
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 0.003f;
}

