#include "Ambient2.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
 return 14;
}

// State* Ambient2::transition() { // not sure if it needed to be implemented
  
//   return this;
// }

void Ambient2::loop(uint32_t dt) {
//  dprintln(F("Ambient2"));
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 9999999999;
}

bool Ambient2::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Ambient2::txStartle(uint8_t strength, uint8_t id) {}

void Ambient2::PIR() {
  dprintln("PIR triggered!");
}

void Ambient2::startled(uint8_t strength, uint8_t id) {
    dprintln("Startled in Ambient2");
}