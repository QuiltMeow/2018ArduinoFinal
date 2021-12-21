#include <Arduino_FreeRTOS.h>

const int TEMPERATURE_PIN = A0;

void initTemperature() {
  pinMode(TEMPERATURE_PIN, INPUT);
}

void temperatureTask(void* pvParameter) {
  (void) pvParameter;

  while (true) {
    // double value = (125 * analogRead(0)) >> 8;
    double value = analogRead(TEMPERATURE_PIN) * 0.0048828125 * 100;

    lcd.setCursor(14, 0);
    lcd.print((int) value);
    vTaskDelay(3000 / portTICK_PERIOD_MS);
  }
}
