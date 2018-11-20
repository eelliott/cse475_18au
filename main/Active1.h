#ifndef _ACTIVE1_H_
#define _ACTIVE1_H_

#include "Creature.h"
#include "State.h"

class Active1 : public State {
 public:
  Active1(Creature& creature) : State(creature, "Active1", 2) {}
  uint8_t getNumRepeats();  // 25
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif  // _ACTIVE1_H_
