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
  switch (sound_idx) {
    case 0:
      Serial.println("Playing sound 0...");
    default:
      Serial.print("No sound of ID ");
      Serial.println(sound_idx);
  }
}

void State::playEffect(uint8_t effect_idx) {
  switch (effect_idx) {
    case 0:
      Serial.println("Playing effect 0...");
    default:
      Serial.print("No effect of ID ");
      Serial.println(effect_idx);
  }
}

bool State::rxPlaySound(uint8_t len, uint8_t* payload) {
  if (len < 1) {
    return false;
  }
  playSound(payload[0]);
  return true;
}

bool State::rxPlayEffect(uint8_t len, uint8_t* payload) {
  if (len < 1) {
    return false;
  }
  playEffect(payload[0]);
  return true;
}

bool State::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {
  if (len != 2) {
    dprint("Invalid length of ");
    dprint(len);
    dprintln(" was recieved in rxStartle.");
    return false;
  }
  uint8_t strength = payload[0];
  uint8_t id = payload[1];  

  float x = (_creature.GLOBALS.STARTLE_DECAY - rssi)/_creature.GLOBALS.STARTLE_DECAY;
  float decay =  getStartleFactor()/(1+exp(-x));
  strength = (uint8_t)round(decay * strength);
  startled(strength, id);
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
  uint8_t id = rand() % 256;
  uint8_t strength = min(255, (rand() % (_creature.GLOBALS.STARTLE_RAND_MAX - _creature.GLOBALS.STARTLE_RAND_MIN + 1) + _creature.GLOBALS.STARTLE_RAND_MIN) * (1.f - (255.f / _creature.GLOBALS.STARTLE_THRESHOLD) * 0.5 + 1.f));

  startled(strength, id);
}

void State::startled(uint8_t strength, uint8_t id) {
  uint8_t last = _creature.getLastStartleId();
  if ( != _id) {
    
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
