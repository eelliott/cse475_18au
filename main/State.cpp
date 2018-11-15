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

// The number of creatures in a given state (the distribution) divided by the total number
// of creatures would make common states more likely. In fact, we want the opposite, so
// calculate the inverse of this value. Sum all of these values for each state.
// A simple example would be 6 creatures and 3 states. The stateDistribution is [1, 2, 3] (1 in state 0, 2 in state 1, 3 in state 2)
// Therefore the individual probabilities are [6, 3, 2], and when we sum these, probs becomes [6, 9, 11]
// Then we generate a random number from 0 to 10 (11 values). If the random number is less than 6
// we go to state 0, else if less than 9 we go to state 1, else we go to state 2. This gives the desired behavior
// of being more likely to transition into less common states.
State* State::transition() {
  // WAIT, active states, ambient states, and STARTLE
  uint8_t len = ACTIVE_STATES + AMBIENT_STATES + 2;
  // WAIT is 0, active and ambient are 1 to (len - 2), STARTLE will go in len - 1
  uint8_t stateDistribution[len];
  uint8_t *creatureStates = _creature.getCreatureStates();
  uint8_t numCreatures = _creature.GLOBALS.NUM_CREATURES;
  for (int c = 0; c < numCreatures; c++) {
    uint8_t cState = creatureStates[c];
    if (cState == STARTLE) {
      // Convert from STARTLE to len - 1 to fit in stateDistribution
      cState = len - 1;
    }
    stateDistribution[cState]++;
    numCreatures++;
  }

  uint8_t probSum = 0;
  uint8_t probs[len];
  for (int i = 0; i < len; i++) {
    // The probability for state i is the inverse of the percentage of creatures in state i
    uint8_t prob = ((uint8_t) ((float) numCreatures / (float) stateDistribution[i]));
    probSum += prob;
    probs[i] = probSum;
  }

  // Pick a random number 0 to probSum - 1
  // Any number in the range is equally likely, so values with a longer range (probability) are more likely
  uint8_t randNum = rand() % probSum;
  uint8_t newStateId = 0;
  for (int i = 0; i < len; i++) {
    // probs[i] contains the sums up to state i, so randNum must be less than at least one of these values
    // We transition if randNum is in the range [probs[i - 1] .. probs[i]), for i = 0 that's [0 .. probs[0]) 
    if (randNum < probs[i]) {
      newStateId = i;
      break;
    }
  }

  if (newStateId == len - 1) {
    // Undo the earlier transformation
    newStateId = STARTLE;
  }

  return _creature.getStateFromId(newStateId);
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
