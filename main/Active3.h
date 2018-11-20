#ifndef _ACTIVE3_H_
#define _ACTIVE3_H_

#include "Creature.h"
#include "State.h"

class Active3 : public State {
 public:
  Active3(Creature& creature) : State(creature, "Active3", 6) {}
  uint8_t getNumRepeats();  // 27
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES]  = { 
    /*Ambient1*/  27,
    /*Active1*/   10,
    /*Ambient2*/  30,
    /*Active2*/   7,
    /*Ambient3*/  26,
    /*Active3*/   9
  };
};
#endif  // _ACTIVE3_H_
