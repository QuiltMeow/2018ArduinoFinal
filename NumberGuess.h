#include <Arduino_FreeRTOS.h>

const int STATUS_LED = 6;
const int SOUND_BEEP = 52;

const int RANDOM_CHANCE = 5;
const int RANDOM_RANGE = 100;

const int FOUR_CHANCE = 9;

int mode = 0;
int currentChance;
int answer;
int bestRank = 0;

int userGuess = 0;

int guessCheckArray[4];
int answerCheckArray[4];

void parseAnswerFourNumber() {
  int current = answer;
  for (int i = 3; i >= 0; --i) {
    answerCheckArray[i] = current % 10;
    current /= 10;
  }
}

void writeGuessRank() {
  if (currentChance > bestRank) {
    writeNumber(currentChance);
    bestRank = currentChance;
  }
}

void showGuessChance() {
  lcd.setCursor(14, 1);
  lcd.print(currentChance);
}

void generateRandom() {
  if (mode == 0) {
    answer = (int) random(1, RANDOM_RANGE + 1);
  } else {
    for (int i = 0; i < 4; ++i) {
      if (i == 0) {
        answerCheckArray[i] = random(1, 9 + 1);
      } else {
        bool success = false;
        while (!success) {
          success = true;
          answerCheckArray[i] = random(0, 9 + 1);
          for (int j = 0; j < i; ++j) {
            if (answerCheckArray[i] == answerCheckArray[j]) {
              success = false;
              break;
            }
          }
        }
      }
    }
    answer = 0;
    for (int i = 0; i < 4; ++i) {
      answer = answer * 10 + answerCheckArray[i];
    }
    Serial.println(answer);
  }
  lcd.setCursor(0, 0);
  lcd.print("Guess Mode ");

  lcd.setCursor(11, 0);
  lcd.print(mode == 0 ? "A" : "B");
}

void initNumberGuess() {
  pinMode(STATUS_LED, OUTPUT);
  pinMode(SOUND_BEEP, OUTPUT);

  currentChance = RANDOM_CHANCE;
  generateRandom();
  showGuessChance();
}

void processBlink(int pin, int delayTime) {
  digitalWrite(pin, HIGH);
  vTaskDelay(delayTime / portTICK_PERIOD_MS);
  digitalWrite(pin, LOW);
  vTaskDelay(delayTime / portTICK_PERIOD_MS);
}

void processClear() {
  lcd.setCursor(0, 0);
  lcd.print("Please Wait ");
  for (int i = 1; i <= 50; ++i) {
    processBlink(STATUS_LED, 100);
  }
  if (mode == 0) {
    currentChance = RANDOM_CHANCE;
  } else {
    currentChance = FOUR_CHANCE;
  }
  generateRandom();
}

void processChance() {
  vTaskDelay(1000 / portTICK_PERIOD_MS);
  --currentChance;
  clearLCDLine(1);
  if (currentChance > 0) {
    lcd.setCursor(14, 1);
    lcd.print(currentChance);
  } else {
    lcd.setCursor(0, 1);
    lcd.print("GAME OVER");

    lcd.setCursor(12, 1);
    lcd.print(answer);
    processClear();
  }
}

void parseGuessFourNumber(int input, bool forCheck = false) {
  for (int i = 3; i >= 0; --i) {
    if (forCheck) {
      if (input <= 0) {
        guessCheckArray[i] = -1;
      } else {
        guessCheckArray[i] = input % 10;
        input /= 10;
      }
      Serial.println(guessCheckArray[i]);
    } else {
      guessCheckArray[i] = input % 10;
      input /= 10;
    }
  }
}

void updateGuessLCD() {
  lcd.setCursor(0, 1);
  lcd.print(userGuess);
}

void inputNumberGuess(int value) {
  parseGuessFourNumber(userGuess, true);

  int currentLength = 0;
  for (int i = 3; i >= 0; --i) {
    if (guessCheckArray[i] == -1) {
      break;
    }
    ++currentLength;
  }

  if (currentLength >= 4) {
    return;
  }

  userGuess = userGuess * 10 + value;
  updateGuessLCD();
}

void clearUserGuess() {
  userGuess = 0;
  clearLCDLine(1);
  showGuessChance();
}

void changeGuessMode() {
  processClear();
  showGuessChance();
}

void nextGuessMode() {
  if (mode >= 1) {
    mode = 0;
  } else {
    ++mode;
  }
  changeGuessMode();
}

void prevGuessMode() {
  if (mode < 0) {
    mode = 1;
  } else {
    --mode;
  }
  changeGuessMode();
}

void correctBeep() {
  digitalWrite(SOUND_BEEP, HIGH);
  vTaskDelay(500 / portTICK_PERIOD_MS);
  digitalWrite(SOUND_BEEP, LOW);
}

void guess() {
  if (mode == 0) {
    if (userGuess > 0 && userGuess <= RANDOM_RANGE) {
      if (userGuess < answer) {
        lcd.setCursor(5, 1);
        lcd.print("Low");
        processChance();
      } else if (userGuess > answer) {
        lcd.setCursor(5, 1);
        lcd.print("High");
        processChance();
      } else {
        writeGuessRank();
        lcd.setCursor(5, 1);
        lcd.print("Correct    ");
        correctBeep();
        processClear();
      }
      clearUserGuess();
    } else {
      clearUserGuess();
    }
  } else {
    if (userGuess / 1000 > 0) {
      parseGuessFourNumber(userGuess);
      for (int i = 0; i < 4; ++i) {
        int now = guessCheckArray[i];
        for (int j = 0; j < 4; ++j) {
          if (i == j) {
            continue;
          }
          int another = guessCheckArray[j];
          if (now == another) {
            clearUserGuess();
            return;
          }
        }
      }

      int a = 0, b = 0;
      for (int i = 0; i < 4; ++i) {
        int now = guessCheckArray[i];
        if (now == answerCheckArray[i]) {
          ++a;
        }

        for (int j = 0; j < 4; ++j) {
          if (i == j) {
            continue;
          }
          if (now == answerCheckArray[j]) {
            ++b;
          }
        }
      }

      if (a == 4) {
        writeGuessRank();
        lcd.setCursor(5, 1);
        lcd.print("Correct    ");
        correctBeep();
        processClear();
      } else {
        lcd.setCursor(5, 1);
        lcd.print(a);

        lcd.setCursor(6, 1);
        lcd.print("A");

        lcd.setCursor(7, 1);
        lcd.print(b);

        lcd.setCursor(8, 1);
        lcd.print("B");
        processChance();
      }
      clearUserGuess();
    } else {
      clearUserGuess();
    }
  }
}
