#include <Arduino_FreeRTOS.h>

#include <DS1302.h>
#include <TM1637Display.h>

// DS 1302 初始化設定
DS1302 rtc(30, 31, 32);

// 設定 TM1637 接腳
#define CLK 45
#define DIO 44

TM1637Display display(CLK, DIO);

void initRTC() {
  // 設定時鐘執行模式
  rtc.halt(false);

  // 取消寫入保護
  // rtc.writeProtect(false);

  // 設定四位元七段顯示器亮度
  display.setBrightness(0xA);

  // 第一次設定寫入 DS 1302 RTC 時鐘 之後可以加上註解
  // rtc.setDOW(SUNDAY); // 設定星期幾
  // rtc.setTime(0, 0, 0); // 設定 24 小時時間 00 : 00 : 00
  // rtc.setDate(1, 1, 2018); // 設定日期 (日 月 年)
}

void RTCTask(void* pvParameter) {
  (void) pvParameter;

  while (true) {
    // Serial.print(rtc.getDOWStr());
    // Serial.print(" ");

    // 取得日期
    // Serial.print(rtc.getDateStr());
    // Serial.print(" ");

    // 取得時間
    // Serial.println(rtc.getTimeStr());

    Time rtcTime = rtc.getTime();
    int hh = rtcTime.hour;
    int mm = rtcTime.min;
    int ss = rtcTime.sec;

    // 顯示四位元七段顯示器中間的冒號
    uint8_t data;

    // 顯示 時 : 分
    int now = hh * 100 + mm;

    // 顯示 分 : 秒
    // int now = mm * 100 + ss;

    data = 0x80 | display.encodeDigit((now / 100) % 10);
    display.setSegments(&data, 1, 1);
    vTaskDelay(500 / portTICK_PERIOD_MS);

    // 顯示時間
    display.showNumberDec(now, true);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
