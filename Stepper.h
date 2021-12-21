#include <Arduino_FreeRTOS.h>
#include <Unistep2.h>

#define STEP 16

bool stepperRunning = false;

Unistep2 stepper(34, 35, 36, 37, STEP, 1000);

void cycle(double turn, bool reverse = false) {
  for (int i = 0; i < round(64 * turn); ++i) {
    stepper.move(reverse ? -STEP : STEP);
  }
}

void switchStepper() {
  stepperRunning = !stepperRunning;
}

void stepperTask(void* pvParameter) {
  (void) pvParameter;

  while (true) {
    stepper.run();
    if (stepperRunning) {
      cycle(1);
    }
    vTaskDelay(1);
  }
}
