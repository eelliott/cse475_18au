#ifndef _AMBIENT3_H_
#define _AMBIENT3_H_

#include "Creature.h"
#include "State.h"

class Ambient3 : public State {
 public:
  Ambient3(Creature& creature) : State(creature, "Ambient 3", 5) {}
  uint8_t getNumRepeats();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES]  = { 
    /*Ambient1*/  26,
    /*Active1*/   15,
    /*Ambient2*/  28,
    /*Active2*/   13,
    /*Ambient3*/  25,
    /*Active3*/   12
  };
};

#endif  // _AMBIENT3_H_
