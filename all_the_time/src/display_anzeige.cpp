#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

void display_Anzeige(int *i){
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setFont();

    switch (*i)
    {
    case 1:
        /* code */
        break;
    
    default:
        

        break;
    }


}