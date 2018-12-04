#include "Ambient3.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Ambient3::_localWeights[];

uint8_t Ambient3::getNumRepeats() {
  int MAX = 14;
  int MIN = 10;
  return rand() % (MAX - MIN + 1) + MIN;
}

void Ambient3::loop(uint32_t dt) {
  Neopixel::setLight(0x0A);
  Midi::setSound(0x15);

}

const uint8_t* Ambient3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient3::getStartleFactor() {
  return 0.00275f;
}
