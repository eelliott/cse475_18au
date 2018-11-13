#ifndef _AMBIENT2_H_
#define _AMBIENT2_H_

#include "Creature.h"
#include "Ambient2.h"

class Ambient2 : public State {
 public:
  Ambient2(Creature& creature) : State(creature, "Ambient2", 3) {}
  uint8_t getNumRepeats();  // 14
//   State* transition();
  void loop(uint32_t dt);
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  bool rxStartle(int8_t rssi, uint8_t len, uint8_t* payload);
  void txStartle(uint8_t strength, uint8_t id);
  void PIR();
  void startled(uint8_t strength, uint8_t id);
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif  // _AMBIENT2_H_
