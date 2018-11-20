#ifndef _ACTIVE2_H_
#define _ACTIVE2_H_

#include "Creature.h"
#include "State.h"

class Active2 : public State {
 public:
  Active2(Creature& creature) : State(creature, "Active2", 4) {}
  uint8_t getNumRepeats();  // 22
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES]  = { 
    /*Ambient1*/  24,
    /*Active1*/   8,
    /*Ambient2*/  30,
    /*Active2*/   9,
    /*Ambient3*/  26,
    /*Active3*/   10
  };
};

#endif  // _ACTIVE2_H_
