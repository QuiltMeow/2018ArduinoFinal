#include <Arduino_FreeRTOS.h>
#include <LedControl.h>

// [Data In] [Clock] [CS (Load)]
LedControl ledLove = LedControl(42, 41, 40, 1);

const unsigned int bigLove[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0}
};

const unsigned int smallLove[8][8] = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 1, 1, 1, 1, 1, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
};

void initLightLove() {
  ledLove.shutdown(0, false);
  ledLove.setIntensity(0, 8);
  ledLove.clearDisplay(0);
}

void clear() {
  for (int c = 0; c < 8; ++c) {
    for (int r = 0; r < 8; ++r) {
      ledLove.setLed(0, c, r, 0);
    }
  }
  vTaskDelay(1);
}

void displayLightLove(const unsigned int data[8][8]) { // 顯示函式
  for (int c = 0; c < 8; ++c) {
    for (int r = 0; r < 8; ++r) {
      ledLove.setLed(0, c, r, data[r][c]);
    }
  }
  vTaskDelay(500 / portTICK_PERIOD_MS);
  // clear();
}

void lightLoveTask(void* pvParameter) {
  (void) pvParameter;

  while (true) {
    if (playing) {
      displayLightLove(bigLove);
      displayLightLove(smallLove);
    } else {
      clear();
    }
  }
}
