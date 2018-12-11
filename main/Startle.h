#ifndef _STARTLE_H_
#define _STARTLE_H_

#include "Creature.h"
#include "State.h"

class Startle : public State {
 public:
  Startle(Creature& creature) : State(creature, "Startle", 255) {}
  uint8_t getNumRepeats() override;
  void loop(uint32_t dt) override;
  const uint8_t* getLocalWeights() override;
  float getStartleFactor() override;
protected:
  void startled(uint8_t strength, uint8_t id) override;
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES]  = { 
    /*Ambient1*/  20,
    /*Active1*/   12,
    /*Ambient2*/  24,
    /*Active2*/   14,
    /*Ambient3*/  22,
    /*Active3*/   13
  };
};

#endif  // _STARTLE_H_
