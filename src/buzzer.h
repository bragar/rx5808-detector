#ifndef BUZZER_H
#define BUZZER_H

#include <stdint.h>

namespace Buzzer {
  struct BuzzerState {
      bool isTurnOn = false;
      unsigned long changeTime = 0;
    };

    void setup();
    void update();
    void turnOn();
}

#endif
