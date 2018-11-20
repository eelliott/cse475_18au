#include "Creature.h"
#include "State.h"
#include "Debug.h"
#include "Startle.h"
#include "Midi.h"
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
    case 0: //AMBIENT1
      Midi::setSound(19);
    case 1: //ACTIVE1
      Midi::setSound(18);
    case 2: //AMBIENT2
      Midi::setSound(22);
    case 3: //ACTIVE2
      Midi::setSound(21);
    case 4: //AMBIENT3
      Midi::setSound(23);
    case 5: //ACTIVE3
      Midi::setSound(20);
    case 6: //STARTLE
      Midi::setSound(24);
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
  _creature.tx(6, 255, 2, payload);
}

State* State::transition() {

  // Get total number of active creatures (i.e. they've recently communicated & are not in Wait or Startle)
  // Get the total number of creatures in each state
  // Get the total sum of the inverse absolute value of the RSSI
  uint8_t numActiveCreature = 0;
  uint8_t stateSums[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
  float distanceStateSums[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
  for (uint8_t i = 1; i < _creature.GLOBALS.NUM_CREATURES + 1; i++) {
    if (_creature.getCreatureStates()[i] > 0 && _creature.getCreatureStates()[i] <= (ACTIVE_STATES + AMBIENT_STATES)) {
      numActiveCreature += 1;
      float creatureInverseDistance = _creature.getCreatureDistances()[i] ? -1.f / _creature.getCreatureDistances()[i] : 0;
      stateSums[_creature.getCreatureStates()[i] - 1] += 1;
      distanceStateSums[_creature.getCreatureStates()[i] - 1] += creatureInverseDistance;
    }
  }

  // Calculate the global scalar values taking into account the states of other creatures
  float stateGlobalScalars[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
  for (uint8_t i = 0; i < ACTIVE_STATES + AMBIENT_STATES; i++) {
    stateGlobalScalars[i] = numActiveCreature ? _globalWeights[i] * ((numActiveCreature - stateSums[i]) / (float) numActiveCreature) : 0;
  }

  float stateLikelihoods[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
  for (uint8_t i = 0; i < ACTIVE_STATES + AMBIENT_STATES; i++) {
    stateLikelihoods[i] = getLocalWeights()[i] + stateGlobalScalars[i] * distanceStateSums[i];
  }

  Serial.print(stateLikelihoods[0]);
  Serial.print("\t");
  for (uint8_t i = 1; i < ACTIVE_STATES + AMBIENT_STATES; i++) {
    stateLikelihoods[i] += stateLikelihoods[i - 1];
    Serial.print(stateLikelihoods[i]);
    Serial.print("\t");
  }
  Serial.println();

  float randomVal = static_cast <float> (rand()) / ( static_cast <float> (RAND_MAX / (stateLikelihoods[ACTIVE_STATES + AMBIENT_STATES - 1])));

  uint8_t stateID = 0;
  for (uint8_t i = 0; i < ACTIVE_STATES + AMBIENT_STATES; i++) {
    if (randomVal < stateLikelihoods[i]) {
      stateID = i + 1;
      break;
    }
  }

  Serial.print(randomVal);
  Serial.print(" --> ");
  Serial.println(stateID);


  return _creature._getStateFromId(stateID);
}

void State::PIR() {
  uint8_t id = rand() % 256;
  uint8_t strength = min(255, (rand() % (_creature.GLOBALS.STARTLE_RAND_MAX - _creature.GLOBALS.STARTLE_RAND_MIN + 1) + _creature.GLOBALS.STARTLE_RAND_MIN) * (1.f - (255.f / _creature.GLOBALS.STARTLE_THRESHOLD) * 0.5 + 1.f));

  startled(strength, id);
}

void State::startled(uint8_t strength, uint8_t id) {
  uint8_t last = _creature.getLastStartleId();
  if (last != _id) {
    _creature.updateThreshold();
    if (strength >= _creature.getStartleThreshold()) {
      _creature.setNextState(new Startle(_creature));
      txStartle(strength, id);
      _creature.setLastStartleId(id);
      _creature.setStartleThreshold(255);
    }
  }
}

int8_t* State::getGlobalWeights() {
  return _globalWeights;
}
