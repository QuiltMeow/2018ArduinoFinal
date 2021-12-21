#include <Arduino_FreeRTOS.h>

const int LIGHT_LED_DELAY = 100;

void lightTask(void* pvParameter) {
  (void) pvParameter;

  while (true) {
    int value = 1;
    for (int i = 0; i < 8; ++i) {
      sendData(value);
      value <<= 1;
      ++value;
      vTaskDelay(LIGHT_LED_DELAY / portTICK_PERIOD_MS);
    }

    value = 255;
    for (int i = 0; i < 8; ++i) {
      sendData(value);
      value >>= 1;
      vTaskDelay(LIGHT_LED_DELAY / portTICK_PERIOD_MS);
    }

    value = 128;
    int value_2 = 1;
    for (int i = 0; i < 8; ++i) {
      sendData(value + value_2);
      value >>= 1;
      value_2 <<= 1;
      vTaskDelay(LIGHT_LED_DELAY / portTICK_PERIOD_MS);
    }

    value = 1;
    for (int i = 0; i < 8; ++i) {
      sendData(value);
      value <<= 1;
      vTaskDelay(LIGHT_LED_DELAY / portTICK_PERIOD_MS);
    }

    value = 128;
    for (int i = 0; i < 8; ++i) {
      sendData(value);
      value >>= 1;
      vTaskDelay(LIGHT_LED_DELAY / portTICK_PERIOD_MS);
    }
  }
}
