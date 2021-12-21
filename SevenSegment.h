const byte SEVEN_SEGMENT_SETTING[16][7] = {
  { 1, 1, 1, 1, 1, 1, 0 }, // 0
  { 0, 1, 1, 0, 0, 0, 0 }, // 1
  { 1, 1, 0, 1, 1, 0, 1 }, // 2
  { 1, 1, 1, 1, 0, 0, 1 }, // 3
  { 0, 1, 1, 0, 0, 1, 1 }, // 4
  { 1, 0, 1, 1, 0, 1, 1 }, // 5
  { 1, 0, 1, 1, 1, 1, 1 }, // 6
  { 1, 1, 1, 0, 0, 0, 0 }, // 7
  { 1, 1, 1, 1, 1, 1, 1 }, // 8
  { 1, 1, 1, 0, 0, 1, 1 }, // 9
  { 1, 1, 1, 0, 1, 1, 1 }, // A
  { 0, 0, 1, 1, 1, 1, 1 }, // B
  { 1, 0, 0, 1, 1, 1, 0 }, // C
  { 0, 1, 1, 1, 1, 0, 1 }, // D
  { 1, 0, 0, 1, 1, 1, 1 }, // E
  { 1, 0, 0, 0, 1, 1, 1 } // F
};

// A B C D E F G POINT
const int SEVEN_SEGMENT[] = {22, 23, 24, 25, 26, 27, 28, 29};

void writeNumber(byte value, boolean type) {
  if (value >= 0 && value <= 15) {
    byte pin = SEVEN_SEGMENT[0];
    for (byte i = 0; i < 7; ++i, ++pin) {
      digitalWrite(pin, type ? SEVEN_SEGMENT_SETTING[value][i] : !SEVEN_SEGMENT_SETTING[value][i]);
    }
  }
}

void writeNumber(byte value) {
  writeNumber(value, false);
}

void initSevenSegment() {
  for (int i = 0; i < 8; ++i) { // 七段顯示器
    pinMode(SEVEN_SEGMENT[i], OUTPUT);
  }
  digitalWrite(SEVEN_SEGMENT[7], HIGH); // 關閉小數點
  writeNumber(0);
}
