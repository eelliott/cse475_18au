#ifndef _AMBIENT4_H_
#define _AMBIENT4_H_

#include "Creature.h"
#include "State.h"

class Ambient4 : public State {
 public:
  Ambient4(Creature& creature) : State(creature, "Ambient4", 7) {}
  uint8_t getNumRepeats();  // 10
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

#endif  // _AMBIENT4_H_
