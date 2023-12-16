#include "M5Atom.h"
#include <WiFi.h>
#include <time.h>

const char* ssid       = "Yakki_LAN4";
const char* password   = "yakkirin311";

void setup()
{
    M5.begin(true, false, true);
    delay(50);
    for(int i=0; i<25; i++){
      M5.dis.drawpix(i, 0xa0a0a0);
    }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  configTime(9 * 3600L, 0, "ntp.nict.jp", "time.google.com", "ntp.jst.mfeed.ad.jp");

}

uint8_t FSM = 1;
uint8_t d = 1;


int red = 0xf00000;
int green = 0x00f000;
int black = 0x000000;

void led_pattern(int pattern)
{
  int color_1 = green;
  int color_2 = green;
  int color_3 = black;
  int color_4 = red;
  int color_5 = red;
    
  switch (pattern)
  {
  case 1:
    color_1 = green;
    color_2 = black;
    color_3 = black;
    color_4 = black;
    color_5 = red;
    break;
  case 2:
    color_1 = black;
    color_2 = black;
    color_3 = green;
    color_4 = red;
    color_5 = black;
    break;
  default:
    break;
  }
  
    for(int led=0; led<2; led++){
      M5.dis.drawpix(led * 5, color_1);
      M5.dis.drawpix(led * 5 + 1, color_1);
      M5.dis.drawpix(led * 5 + 2, color_2);
      M5.dis.drawpix(led * 5 + 3, color_3);
      M5.dis.drawpix(led * 5 + 4, color_3);
    } 
    for(int led=10; led<15; led++){
      M5.dis.drawpix(led, black);
    } 
    for(int led=3; led<5; led++){
      M5.dis.drawpix(led * 5, color_4);
      M5.dis.drawpix(led * 5 + 1, color_4);
      M5.dis.drawpix(led * 5 + 2, color_2);
      M5.dis.drawpix(led * 5 + 3, color_5);
      M5.dis.drawpix(led * 5 + 4, color_5);
    } 
}

void loop()
{
  struct tm timeInfo;
  getLocalTime(&timeInfo);

  uint8_t sec = timeInfo.tm_sec ;
  FSM = sec % 2 + 1 ;
  led_pattern(FSM);

//    if (M5.Btn.wasPressed())
//    {
//        FSM++;
//        if (FSM >= 3)
//        {
//            FSM = 1;
//        }
//    }

    delay(50);
    M5.update();
}
