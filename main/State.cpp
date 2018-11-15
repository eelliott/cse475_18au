#include "Creature.h"
#include "State.h"
#include "Debug.h"
#include <cmath>

State::State(Creature& creature, char* const name, const uint8_t id) : _creature(creature), _id(id) {
  strncpy(_name, name, MAX_NAME_LEN);
  _name[MAX_NAME_LEN] = 0;
};

uint8_t State::getId() {
  return _id;
}

char* State::getName() {
  return _name;
}

void State::playSound(uint8_t sound_idx) {
  // TODO: implement
}

void State::playEffect(uint8_t effect_idx) {
  // TODO: implement
}

bool State::rxPlaySound(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

bool State::rxPlayEffect(uint8_t len, uint8_t* payload) {
  // TODO: implement
}

bool State::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {
  if (len != 2) {
    dprint("Invalid length of ");
    dprint(len);
    dprintln(" was recieved in rxStartle.");
    return false;
  }
  float x = (_creature.GLOBALS.STARTLE_DECAY - rssi)/_creature.GLOBALS.STARTLE_DECAY;
  float startleFactor = getStartleFactor();
  float decay = startleFactor/(1+exp(-x));
  State::startled(decay*payload[0], payload[1]);
  return true;
}

void State::txStartle(uint8_t strength, uint8_t id) {
  uint8_t payload[2] = {strength, id};
  uint8_t len = 2;
  _creature.tx(PID_STARTLE, BROADCAST_ADDR, 2, payload);
}

State* State::transition() {
  uint8_t len = ACTIVE_STATES + AMBIENT_STATES + 1;
  int randNum = rand() % 100;
  
}

void State::PIR() {
  // TODO: implement
}

void State::startled(uint8_t strength, uint8_t id) {
  if (_creature.getLastStartleId() == _id) {
    uint32_t time = millis();
    uint8_t startleThreshold = _creature.GLOBALS.STARTLE_THRESHOLD;
    startleThreshold =  startleThreshold - startleThreshold*(time-_creature.getLastStartle())
                        *_creature.GLOBALS.STARTLE_THRESHOLD_DECAY*getStartleFactor();
    if (strength >= startleThreshold) {
      dprint("Startled! new startle id = ");
      dprintln(_id);
    }
    _creature.setLastStartlee(time);                             
  }
}

int8_t* State::getGlobalWeights() {
  return _globalWeights;
}
