#include <Arduino_FreeRTOS.h>
#include <avr/pgmspace.h>

#include "Sound.h"

const int SOUND_PIN = 53;

const int SOUND_1_LENGTH = 88;

const PROGMEM uint16_t SOUND_1[] = {
  NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_GS4, NOTE_A4, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_A4, NOTE_E4, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_FS4, NOTE_A4, NOTE_GS4, NOTE_E4, NOTE_CS5, NOTE_D5, NOTE_E5, NOTE_E5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_A4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_E5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_CS5, NOTE_GS4, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_CS5, NOTE_B4, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_CS5, NOTE_E4, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_E4, NOTE_FS4, NOTE_A4, NOTE_GS4, NOTE_A4, NOTE_A4
};

const PROGMEM uint16_t BEAT_1[] = {
  545, 273, 273, 818, 136, 136, 545, 273, 273, 818, 136, 136, 545, 273, 273, 818, 136, 136, 545, 273, 273, 545, 545, 545, 273, 273, 818, 273, 545, 273, 273, 545, 545, 545, 273, 273, 818, 136, 136, 818, 136, 136, 1090, 409, 136, 273, 273, 409, 136, 273, 273, 409, 136, 273, 273, 1090, 409, 136, 273, 273, 545, 273, 273, 545, 273, 273, 1090, 409, 136, 273, 273, 545, 545, 545, 273, 273, 545, 545, 545, 273, 273, 545, 545, 273, 273, 273, 273, 1090
};

const int SOUND_2_LENGTH = 451;

const PROGMEM uint16_t SOUND_2[] = {
  NOTE_G5, NOTE_D5, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_D5, NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_A4, NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_D5, NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_D5, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_A4, NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_FS5, NOTE_G5, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_G4, 0, 0, 0, 0, 0, 0, 0, 0, NOTE_DS6, NOTE_G6, NOTE_GS6, NOTE_GS5, NOTE_GS6, NOTE_G6, NOTE_DS6, NOTE_GS5, NOTE_GS6, NOTE_G6, NOTE_GS6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_AS5, NOTE_G6, NOTE_GS6, NOTE_GS5, NOTE_GS6, NOTE_AS6, NOTE_C7, NOTE_AS6, NOTE_GS6, NOTE_AS6, NOTE_GS6, NOTE_G6, NOTE_GS6, NOTE_DS6, NOTE_G6, NOTE_GS6, NOTE_GS5, NOTE_GS6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_AS5, NOTE_GS5, NOTE_GS5, NOTE_DS6, NOTE_G6, NOTE_GS6, NOTE_GS5, NOTE_GS6, NOTE_G6, NOTE_DS6, NOTE_GS5, NOTE_GS6, NOTE_G6, NOTE_GS6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_AS5, NOTE_G6, NOTE_GS6, NOTE_GS5, NOTE_GS6, NOTE_AS6, NOTE_C7, NOTE_AS6, NOTE_GS6, NOTE_AS6, NOTE_GS6, NOTE_G6, NOTE_GS6, NOTE_DS6, NOTE_G6, NOTE_GS6, NOTE_GS5, NOTE_GS6, NOTE_G6, NOTE_F6, NOTE_DS6, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_C6, NOTE_AS5, NOTE_GS5, NOTE_AS5, NOTE_GS5, NOTE_GS5, 0, NOTE_G5, NOTE_D5, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4
};

const PROGMEM uint16_t BEAT_2[] = {
  954, 954, 954, 477, 477, 954, 954, 954, 2624, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 596, 119, 119, 119, 239, 119, 358, 239, 716, 239, 716, 239, 239, 477, 239, 239, 477, 239, 716, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 596, 119, 119, 119, 239, 119, 358, 239, 716, 239, 716, 239, 239, 477, 239, 239, 477, 239, 716, 239, 477, 239, 239, 596, 119, 119, 119, 596, 119, 119, 119, 239, 477, 239, 477, 239, 239, 596, 119, 119, 119, 239, 477, 239, 716, 119, 119, 477, 239, 239, 596, 119, 119, 119, 239, 477, 119, 119, 239, 477, 239, 477, 477, 239, 477, 239, 239, 477, 239, 716, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 596, 119, 119, 119, 239, 119, 358, 239, 716, 239, 716, 239, 239, 477, 239, 239, 477, 239, 716, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 596, 119, 119, 119, 239, 119, 358, 239, 716, 239, 716, 239, 239, 477, 239, 239, 477, 239, 716, 239, 477, 239, 239, 596, 119, 119, 119, 596, 119, 119, 119, 239, 477, 239, 477, 239, 239, 596, 119, 119, 119, 239, 477, 239, 716, 119, 119, 477, 239, 239, 596, 119, 119, 119, 239, 477, 119, 119, 239, 477, 239, 477, 477, 239, 477, 239, 239, 477, 239, 716, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 239, 477, 239, 716, 119, 119, 239, 477, 239, 716, 239, 596, 119, 119, 119, 239, 119, 358, 239, 716, 239, 716, 239, 239, 477, 239, 239, 477, 239, 716, 239, 716, 239, 477, 477, 477, 477, 477, 477, 477, 239, 239, 596, 119, 119, 119, 596, 119, 119, 119, 239, 477, 239, 477, 239, 239, 596, 119, 119, 119, 239, 477, 239, 716, 119, 119, 477, 239, 239, 596, 119, 119, 119, 239, 477, 119, 119, 239, 477, 239, 477, 477, 239, 477, 239, 239, 477, 239, 716, 239, 477, 239, 239, 596, 119, 119, 119, 596, 119, 119, 119, 239, 477, 239, 477, 239, 239, 596, 119, 119, 119, 239, 477, 239, 716, 119, 119, 477, 239, 239, 596, 119, 119, 119, 239, 477, 119, 119, 239, 477, 239, 477, 477, 239, 477, 239, 239, 477, 239, 716, 239, 716, 239, 954, 954, 954, 477, 477, 954, 954, 954, 4770
};

const int SOUND_3_LENGTH = 1209;

const PROGMEM uint16_t SOUND_3[] = {
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_F5, NOTE_A4, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_F6, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5, NOTE_A5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_D4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_G4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_C6, NOTE_F6, NOTE_E6, NOTE_F6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G5, NOTE_F5, NOTE_A5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_A5, NOTE_G5, NOTE_D5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_A3, NOTE_D4, NOTE_0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_G4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_0, NOTE_D5, NOTE_0, NOTE_D5, NOTE_0, NOTE_D5, NOTE_0, NOTE_D5, NOTE_0, NOTE_D5, NOTE_0, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_FS4, NOTE_G4, NOTE_0, NOTE_G4, NOTE_0, NOTE_G4, NOTE_0, NOTE_G4, NOTE_0, NOTE_G4, NOTE_0, NOTE_G4, NOTE_0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_CS4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_0, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_C5, NOTE_F5, NOTE_E5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_F4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_F4, NOTE_D4, NOTE_AS4, NOTE_F4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_F4, NOTE_D4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_C4, NOTE_A4, NOTE_E4, NOTE_CS4, NOTE_A3, NOTE_CS4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_CS5, NOTE_E5, NOTE_A5, NOTE_E5, NOTE_CS5, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_A4, NOTE_F5, NOTE_D5, NOTE_A4, NOTE_F4, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_D5, NOTE_AS4, NOTE_G4, NOTE_DS4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_DS4, NOTE_G5, NOTE_D5, NOTE_AS4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_F4, NOTE_AS4, NOTE_C5, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_AS4, NOTE_F4, NOTE_AS5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_AS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F4, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_F4, NOTE_D5, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_0, NOTE_0, NOTE_A2, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_G4, NOTE_E4, NOTE_F4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_A3, NOTE_G3, NOTE_A3, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_0, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_G4, NOTE_F4, NOTE_A4, NOTE_D4, NOTE_F4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_E4, NOTE_G4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_G5, NOTE_FS5, NOTE_G5, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_B4, NOTE_A4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_0, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_0
};

const PROGMEM uint16_t BEAT_3[] = {
  296.25, 296.25, 197.5, 296.25, 296.25, 197.5, 296.25, 296.25, 197.5, 395, 395, 296.25, 296.25, 197.5, 296.25, 296.25, 197.5, 395, 395, 395, 395, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 98.75, 98.75, 197.5, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 395, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 296.25, 296.25, 197.5, 395, 395, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 395, 98.75, 197.5, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 98.75, 197.5, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 98.75, 197.5, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 395, 395, 395, 395, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 790, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 790, 395, 395, 395, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 395, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 395, 592.5, 592.5, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 197.5, 197.5, 790, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 296.25, 296.25, 197.5, 395, 395, 98.75, 197.5, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 98.75, 197.5, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 395, 98.75, 197.5, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 395, 395, 395, 395, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 790, 197.5, 197.5, 197.5, 197.5, 395, 395, 197.5, 197.5, 197.5, 197.5, 790, 395, 395, 395, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 395, 790, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 197.5, 197.5, 790, 49.375, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 49.375, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 49.375, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 79, 79, 79, 79, 79, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 98.75, 98.75, 98.75, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 56.4297, 98.75, 98.75, 98.75, 98.75, 79, 79, 79, 79, 79, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 71.8189, 71.8189, 71.8189, 71.8189, 71.8189, 71.8189, 71.8189, 71.8189, 71.8189, 71.8189, 71.8189, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 790, 98.75, 98.75, 98.75, 296.25, 98.75, 197.5, 197.5, 296.25, 98.75, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 395, 395, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 790, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 790, 395, 395, 395, 395, 197.5, 98.75, 98.75, 197.5, 197.5, 395, 197.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 395, 790, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 296.25, 296.25, 197.5, 592.5, 197.5, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 395, 395, 395, 395, 197.5, 197.5, 197.5, 197.5, 395, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 98.75, 98.75, 197.5, 98.75, 98.75, 790, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 395, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 197.5, 65.8347, 65.8347, 65.8465, 197.5, 197.5, 197.5, 98.75, 98.75, 98.75, 98.75, 98.75, 98.75, 197.5, 197.5, 197.5, 197.5, 296.25, 296.25, 197.5, 395, 395, 296.25, 296.25, 197.5, 395, 395
};

const int SOUND_LED_LENGTH = 3;

const int SOUND_LED_PIN[] = { 49, 50, 51 };

void initSound() {
  pinMode(SOUND_PIN, OUTPUT);

  for (int i = 0; i < SOUND_LED_LENGTH; ++i) {
    pinMode(SOUND_LED_PIN[i], OUTPUT);
  }
}

int currentSound = 0;
int currentSoundLED = -1;

int currentPlay = -1;
unsigned long lastPlay;

bool playing = false;

bool shouldPlayNext_1() {
  if (lastPlay + pgm_read_word_near(BEAT_1 + currentPlay) < millis()) {
    lastPlay = millis();
    return true;
  }
  return false;
}

bool shouldPlayNext_2() {
  if (lastPlay + pgm_read_word_near(BEAT_2 + currentPlay) < millis()) {
    lastPlay = millis();
    return true;
  }
  return false;
}

bool shouldPlayNext_3() {
  if (lastPlay + pgm_read_word_near(BEAT_3 + currentPlay) < millis()) {
    lastPlay = millis();
    return true;
  }
  return false;
}

void clearSound() {
  currentPlay = -1;
  digitalWrite(SOUND_LED_PIN[currentSoundLED], LOW);
  currentSoundLED = -1;
}

void nextSound() {
  if (currentSound >= 2) {
    currentSound = 0;
  } else {
    ++currentSound;
  }
  clearSound();
}

void prevSound() {
  if (currentSound < 0) {
    currentSound = 2;
  } else {
    --currentSound;
  }
  clearSound();
}

void switchPlay() {
  playing = !playing;
}

void updateSoundLED() {
  if (currentSoundLED == -1) {
    digitalWrite(SOUND_LED_PIN[++currentSoundLED], HIGH);
  } else {
    digitalWrite(SOUND_LED_PIN[currentSoundLED], LOW);
    if (currentSoundLED + 1 >= SOUND_LED_LENGTH) {
      currentSoundLED = 0;
    } else {
      ++currentSoundLED;
    }
    digitalWrite(SOUND_LED_PIN[currentSoundLED], HIGH);
  }
}

void soundTask(void* pvParameter) {
  (void) pvParameter;

  while (true) {
    if (playing) {
      if (currentSound == 0) {
        if (currentPlay == -1) {
          updateSoundLED();
          unsigned int freq = pgm_read_word_near(SOUND_1 + (++currentPlay));
          unsigned int beat = pgm_read_word_near(BEAT_1 + currentPlay);
          tone(SOUND_PIN, freq, beat - 1);
          lastPlay = millis();
        } else if (shouldPlayNext_1()) {
          updateSoundLED();
          if (++currentPlay >= SOUND_1_LENGTH) {
            currentPlay = 0;
          }
          unsigned int freq = pgm_read_word_near(SOUND_1 + currentPlay);
          unsigned int beat = pgm_read_word_near(BEAT_1 + currentPlay);
          tone(SOUND_PIN, freq, beat - 1);
        }
      } else if (currentSound == 1) {
        if (currentPlay == -1) {
          updateSoundLED();
          unsigned int freq = pgm_read_word_near(SOUND_2 + (++currentPlay));
          unsigned int beat = pgm_read_word_near(BEAT_2 + currentPlay);
          tone(SOUND_PIN, freq, beat - 1);
          lastPlay = millis();
        } else if (shouldPlayNext_2()) {
          updateSoundLED();
          if (++currentPlay >= SOUND_2_LENGTH) {
            currentPlay = 0;
          }
          unsigned int freq = pgm_read_word_near(SOUND_2 + currentPlay);
          unsigned int beat = pgm_read_word_near(BEAT_2 + currentPlay);
          tone(SOUND_PIN, freq, beat - 1);
        }
      } else {
        if (currentPlay == -1) {
          updateSoundLED();
          unsigned int freq = pgm_read_word_near(SOUND_3 + (++currentPlay));
          unsigned int beat = pgm_read_word_near(BEAT_3 + currentPlay);
          tone(SOUND_PIN, freq, beat - 1);
          lastPlay = millis();
        } else if (shouldPlayNext_3()) {
          updateSoundLED();
          if (++currentPlay >= SOUND_3_LENGTH) {
            currentPlay = 0;
          }
          unsigned int freq = pgm_read_word_near(SOUND_3 + currentPlay);
          unsigned int beat = pgm_read_word_near(BEAT_3 + currentPlay);
          tone(SOUND_PIN, freq, beat - 1);
        }
      }
    }
    vTaskDelay(1);
  }
}