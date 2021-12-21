#include <Arduino_FreeRTOS.h>
#include <IRremote.h>

const int RECV_PIN = 10;

IRrecv IRRecv(RECV_PIN);
decode_results result;

void initIR() {
  pinMode(RECV_PIN, INPUT);
  IRRecv.enableIRIn();
}

void translateIR() {
  switch (result.value) {
    case 0xFFA25D: { // CH -
        break;
      }
    case 0xFF629D: { // CH
        switchStepper();
        break;
      }
    case 0xFFE21D: { // CH +
        break;
      }
    case 0xFF22DD: { // PREV
        prevSound();
        break;
      }
    case 0xFF02FD: { // NEXT
        nextSound();
        break;
      }
    case 0xFFC23D: { // PLAY / PAUSE
        switchPlay();
        break;
      }
    case 0xFFE01F: { // VOL -
        prevGuessMode();
        break;
      }
    case 0xFFA857: { // VOL +
        nextGuessMode();
        break;
      }
    case 0xFF906F: { // EQ
        guess();
        break;
      }
    case 0xFF6897: { // 0
        inputNumberGuess(0);
        break;
      }
    case 0xFF9867: { // 100 +
        clearUserGuess();
        break;
      }
    case 0xFFB04F: { // 200 +
        break;
      }
    case 0xFF30CF: { // 1
        inputNumberGuess(1);
        break;
      }
    case 0xFF18E7: { // 2
        inputNumberGuess(2);
        break;
      }
    case 0xFF7A85: { // 3
        inputNumberGuess(3);
        break;
      }
    case 0xFF10EF: { // 4
        inputNumberGuess(4);
        break;
      }
    case 0xFF38C7: { // 5
        inputNumberGuess(5);
        break;
      }
    case 0xFF5AA5: { // 6
        inputNumberGuess(6);
        break;
      }
    case 0xFF42BD: { // 7
        inputNumberGuess(7);
        break;
      }
    case 0xFF4AB5: { // 8
        inputNumberGuess(8);
        break;
      }
    case 0xFF52AD: { // 9
        inputNumberGuess(9);
        break;
      }
    case 0xFFFFFFFF: { // END
        break;
      }
    default: { // UNKNOWN
        break;
      }
  }
}

void IRTask(void* pvParameter) {
  (void) pvParameter;

  while (true) {
    if (IRRecv.decode(&result)) {
      translateIR();
      IRRecv.resume();
    }
    vTaskDelay(1);
  }
}
