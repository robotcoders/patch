#include <Wire.h>
#include <U8g2lib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2_1(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // First screen object
U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2_2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE); // Second screen object

void setup() {
  Wire.begin();
  
  // Initialize the first OLED screen, address 0x3D
  u8g2_1.setI2CAddress(0x3D << 1);
  u8g2_1.begin();
  
  // Initialize the second OLED screen, address 0x3C
  u8g2_2.setI2CAddress(0x3C << 1);
  u8g2_2.begin();
}

void loop() {
  // Display "OLED1" on screen 1
  u8g2_1.firstPage();
  do {
    u8g2_1.setFont(u8g2_font_ncenB10_tr);
    u8g2_1.drawStr(0, 15, "OLED1");
  } while (u8g2_1.nextPage());
  
  // Display "OLED2" on screen 2
  u8g2_2.firstPage();
  do {
    u8g2_2.setFont(u8g2_font_ncenB10_tr);
    u8g2_2.drawStr(0, 15, "OLED2");
  } while (u8g2_2.nextPage());
  
  delay(2000); // Delay for 2 seconds
}
