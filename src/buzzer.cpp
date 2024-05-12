#include <Arduino.h>
#include <stdint.h>

#include "buzzer.h"
#include "settings.h"

struct Buzzer::BuzzerState state;

namespace Buzzer {
    const int signalDuration = 200;
    const int signalTimeout = 200;

    void setup()
    {
    }

    void update() {
       if (state.isTurnOn)
       {
          int previousTime = state.changeTime;
          int currentTime = millis();
          int duration = currentTime - previousTime;
          Serial.println(duration);
          if (duration >= signalDuration)
          {
              digitalWrite(PIN_BUZZER, HIGH);
               state.isTurnOn = false;
          } else {
              digitalWrite(PIN_BUZZER, LOW);
          }
      }
    }

    void turnOn() {
      if (state.isTurnOn)
      {
        return;
      }

      state.changeTime = millis() + signalTimeout;
      state.isTurnOn = true;
    }
}
