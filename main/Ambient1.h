#ifndef _AMBIENT1_H_
#define _AMBIENT1_H_

#include "Creature.h"
#include "State.h"

class Ambient1 : public State {
 public:
  Ambient1(Creature& creature) : State(creature, "Ambient 1", 1) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES]  = { 
    /*Ambient1*/  22,
    /*Active1*/   13,
    /*Ambient2*/  25,
    /*Active2*/   14,
    /*Ambient3*/  23,
    /*Active3*/   12
  };
};

#endif  // _AMBIENT1_H_
