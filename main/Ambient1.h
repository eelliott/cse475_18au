#ifndef _AMBIENT1_H_
#define _AMBIENT1_H_

#include "Creature.h"
#include "State.h"

class Ambient1 : public State {
 public:
  Ambient1(Creature& creature) : State(creature, "Ambient1", 1) {}
  uint8_t getNumRepeats();  // 15
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif  // _AMBIENT1_H_
