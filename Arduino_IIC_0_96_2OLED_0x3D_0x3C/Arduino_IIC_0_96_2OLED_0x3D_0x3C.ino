#include <Wire.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2_1(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // 第一个屏幕对象
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2_2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // 第二个屏幕对象

void setup() {
  Wire.begin();
  
  // 初始化第一个 OLED 屏幕，地址为 0x3D
  u8g2_1.setI2CAddress(0x3D << 1);
  u8g2_1.begin();
  
  // 初始化第二个 OLED 屏幕，地址为 0x3C
  u8g2_2.setI2CAddress(0x3C << 1);
  u8g2_2.begin();
}

void loop() {
  // 在屏幕1上显示 "OLED1"
  u8g2_1.firstPage();
  do {
    u8g2_1.setFont(u8g2_font_ncenB10_tr);
    u8g2_1.drawStr(0, 15, "OLED1");
  } while (u8g2_1.nextPage());
  
  // 在屏幕2上显示 "OLED2"
  u8g2_2.firstPage();
  do {
    u8g2_2.setFont(u8g2_font_ncenB10_tr);
    u8g2_2.drawStr(0, 15, "OLED2");
  } while (u8g2_2.nextPage());
  
  delay(2000); // 延时2秒
}
