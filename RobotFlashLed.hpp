#include "RobotCmd.hpp"
#include "RobotRunner.hpp"
#include "SubsystemLED.hpp"

class RobotFlashLed: public RobotCmd {
private:
  SubsystemLED *_led;
  unsigned long _rate;
  bool on = false;
  unsigned long nextFlash;

public:
  RobotFlashLed::RobotFlashLed(SubsystemLED *led, unsigned long rate) {
    _led = led;
    _rate = rate;
  }
  
  void initialise() {
    nextFlash = millis() + _rate;
    _led->setLED(on);
    on = !on;
  }

  bool execute() {
    unsigned long curTime = millis();

    if (curTime > nextFlash) {
      nextFlash += _rate;
      _led->setLED(on);
      on = !on;
    }
    return false;
  }

  void end() {
  }
};
