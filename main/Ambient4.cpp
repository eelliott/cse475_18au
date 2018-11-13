#include "Ambient4.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Ambient4::_localWeights[];

uint8_t Ambient4::getNumRepeats() {
 return 10;
}

// State* Ambient4::transition() { // not sure if it needed to be implemented
  
//   return this;
// }

void Ambient4::loop(uint32_t dt) {
//  dprintln(F("Ambient4"));
}

const uint8_t* Ambient4::getLocalWeights() {
  return this->_localWeights;
}

float Ambient4::getStartleFactor() {
  return 9999999999;
}

bool Ambient4::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Ambient4::txStartle(uint8_t strength, uint8_t id) {}

void Ambient4::PIR() {
  dprintln("PIR triggered!");
}

void Ambient4::startled(uint8_t strength, uint8_t id) {
    dprintln("Startled in Ambient4");
}