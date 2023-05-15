#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <time.h>

void display_Anzeige(int *m, int *p){
    struct tm timeinfo;
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setFont();
    display.setTextsize(1);

    switch(*m){
        case 1:
            switch (*p){

            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(2);
                display.println("new Timer");
                display.setTextsize(1);
                display.println("")

                break;
            }

        default:
            display.setCursor(1, 10);
            display.setTextsize(2);
            display.printf("Fuchur \n");
            display.printf("von\nDie unendliche Geschichte");

            break;
        }


}