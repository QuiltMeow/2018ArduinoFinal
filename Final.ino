#include <Arduino_FreeRTOS.h>

#include "Tone.h"
#include "RTC.h"

#include "LCDControl.h"
#include "Sensor.h"
#include "Stepper.h"

#include "MultiLEDControl.h"
#include "SevenSegment.h"
#include "NumberGuess.h"
#include "IRHandler.h"

#include "LightShow.h"
#include "LightLove.h"

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }

  randomSeed(analogRead(A7));

  initIR();
  initRTC();
  initSound();
  initLCD();
  initSevenSegment();
  init74HC595();
  initNumberGuess();
  initTemperature();
  initLightLove();

  xTaskCreate(IRTask, (const portCHAR *) "IRTask", 256, NULL, 2, NULL);
  xTaskCreate(RTCTask, (const portCHAR *) "RTCTask", 128, NULL, 1, NULL);
  xTaskCreate(soundTask, (const portCHAR *) "soundTask", 128, NULL, 1, NULL);
  xTaskCreate(temperatureTask, (const portCHAR *) "temperatureTask", 128, NULL, 1, NULL);
  xTaskCreate(lightTask, (const portCHAR *) "lightTask", 128, NULL, 1, NULL);
  xTaskCreate(lightLoveTask, (const portCHAR *) "lightLoveTask", 128, NULL, 1, NULL);
  xTaskCreate(stepperTask, (const portCHAR *) "stepperTask", 128, NULL, 1, NULL);
}

void loop() {
}
