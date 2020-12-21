#include "M5Atom.h"

void setup()
{
    M5.begin(true, false, true);
    delay(50);
    for(int i=0; i<25; i++){
      M5.dis.drawpix(i, 0xa0a0a0);
    }
}

uint8_t FSM = 0;
uint8_t brightness = 2;
uint8_t d = 1;

void loop()
{
    if (M5.Btn.wasPressed())
    {

        switch (FSM)
        {
        case 0:
            for(int i=0; i<25; i++){
              M5.dis.drawpix(i, 0xf00000);
            }
            break;
        case 1:
            for(int i=0; i<25; i++){
              M5.dis.drawpix(i, 0x00f000);
            }
            break;
        case 2:
            for(int i=0; i<25; i++){
              M5.dis.drawpix(i, 0x000aff);
            }
            break;
        case 3:
            for(int i=0; i<25; i++){
              M5.dis.drawpix(i, 0xa0a0a0);
            }
            break;
        default:
            break;
        }
        FSM++;
        if (FSM >= 4)
        {
            FSM = 0;
        }
    }

    brightness = brightness + d;
    if ( brightness > 30) {
      d = -1;
    }
    if ( brightness < 3) {
      d = 1;
    }
    M5.dis.setBrightness(brightness);

    delay(50);
    M5.update();
}
