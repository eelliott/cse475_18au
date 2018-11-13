#include "Active3.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Active3::_localWeights[];

uint8_t Active3::getNumRepeats() {
 return 27;
}

// State* Active3::transition() { // not sure if it needed to be implemented
  
//   return this;
// }

void Active3::loop(uint32_t dt) {
//  dprintln(F("Active3"));
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 9999999999;
}

bool Active3::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Active3::txStartle(uint8_t strength, uint8_t id) {}

void Active3::PIR() {
  dprintln("PIR triggered!");
}

void Active3::startled(uint8_t strength, uint8_t id) {
    dprintln("Startled in Active3");
}