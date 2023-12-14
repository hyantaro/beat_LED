#include "M5Atom.h"

void setup()
{
    M5.begin(true, false, true);
    delay(50);
    for(int i=0; i<25; i++){
      M5.dis.drawpix(i, 0xa0a0a0);
    }
}

uint8_t FSM = 1;
//uint8_t brightness = 2;
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

  led_pattern(FSM);

    if (M5.Btn.wasPressed())
    {
//
//        switch (FSM)
//        {
//        case 0:
//            for(int i=0; i<25; i++){
//              M5.dis.drawpix(i, 0xf00000);
//            }
//            break;
//        case 1:
//            for(int i=0; i<25; i++){
//              M5.dis.drawpix(i, 0x00f000);
//            }
//            break;
//        case 2:
//            for(int i=0; i<25; i++){
//              M5.dis.drawpix(i, 0x000aff);
//            }
//            break;
//        case 3:
//            for(int i=0; i<25; i++){
//              M5.dis.drawpix(i, 0xa0a0a0);
//            }
//            break;
//        default:
//            break;
//        }
        FSM++;
        if (FSM >= 3)
        {
            FSM = 1;
        }
    }

//    brightness = brightness + d;
//    if ( brightness > 30) {
//      d = -1;
//    }
//    if ( brightness < 3) {
//      d = 1;
//    }
//    M5.dis.setBrightness(brightness);

    delay(50);
    M5.update();
}
