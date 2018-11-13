#include "Active1.h"
#include "Neopixel.h"
#include "Midi.h"
#include "Debug.h"

constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
 return 25;
}

// State* Active1::transition() { // not sure if it needed to be implemented
  
//   return this;
// }

void Active1::loop(uint32_t dt) {
//  dprintln(F("Active1"));
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 9999999999;
}

bool Active1::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {}

void Active1::txStartle(uint8_t strength, uint8_t id) {}

void Active1::PIR() {
  dprintln("PIR triggered!");
}

void Active1::startled(uint8_t strength, uint8_t id) {
    dprintln("Startled in Active1");
}