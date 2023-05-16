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
        case 1://kein Timer aktiv
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(2);
                display.println("new Timer");
                display.setTextsize(1);
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(1);
                display.println("new Timer");
                display.setTextsize(2);
                display.println("WiFi");

                break;
            
            default:
                break;
            }

        case 2://ein Timer aktiv
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(2);
                display.println("Timer 1");
                display.setTextsize(1);
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.setTextsize(2);
                display.println("new Timer");
                display.setTextsize(1);
                display.println("WiFi");

                break;

            case 3:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(1);
                display.println("Timer 1");
                display.println("new Timer");
                display.setTextsize(2);
                display.println("WiFi");

                break;
            
            default:
                break;
            }
        
        case 3://zwei Timer aktiv
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(2);
                display.println("Timer 1");
                display.setTextsize(1);
                display.println("Timer 2");
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.setTextsize(2);
                display.println("Timer 2");
                display.setTextsize(1);
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 3:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.setTextsize(2);
                display.println("new Timer");
                display.setTextsize(1);
                display.println("WiFi");

                break;

            case 4:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("new Timer");
                display.setTextsize(2);
                display.println("WiFi");

                break;
            
            default:
                break;
            }

        case 4://drei Timer aktiv
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(2);
                display.println("Timer 1");
                display.setTextsize(1);
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.setTextsize(2);
                display.println("Timer 2");
                display.setTextsize(1);
                display.println("Timer 3");
                display.println("new Timer");
                display.println("WiFi");

                break;
            
            case 3:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.setTextsize(2);
                display.println("Timer 3");
                display.setTextsize(1);
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 4:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.setTextsize(2);
                display.println("new Timer");
                display.setTextsize(1);
                display.println("WiFi");

                break;

            case 5:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("new Timer");
                display.setTextsize(2);
                display.println("WiFi");

                break;
            
            default:
                break;
            }

        case 5://vier Timer aktiv
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(2);
                display.println("Timer 1");
                display.setTextsize(1);
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.setTextsize(2);
                display.println("Timer 2");
                display.setTextsize(1);
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("new Timer");
                display.println("WiFi");

                break;
            
            case 3:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.setTextsize(2);
                display.println("Timer 3");
                display.setTextsize(1);
                display.println("Timer 4");
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 4:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.setTextsize(2);
                display.println("Timer 4");
                display.setTextsize(1);
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 5:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.setTextsize(2);
                display.println("new Timer");
                display.setTextsize(1);
                display.println("WiFi");

                break;

            case 6:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("new Timer");
                display.setTextsize(2);
                display.println("WiFi");

                break;
            
            default:
                break;
            }

            case 6://fünf Timer aktiv
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(2);
                display.println("Timer 1");
                display.setTextsize(1);
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("Timer 5");
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.setTextsize(2);
                display.println("Timer 2");
                display.setTextsize(1);
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("Timer 5");
                display.println("WiFi");

                break;
            
            case 3:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.setTextsize(2);
                display.println("Timer 3");
                display.setTextsize(1);
                display.println("Timer 4");
                display.println("Timer 5");
                display.println("WiFi");

                break;

            case 4:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.setTextsize(2);
                display.println("Timer 4");
                display.setTextsize(1);
                display.println("Timer 5");
                display.println("WiFi");

                break;

            case 5:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.setTextsize(2);
                display.println("Timer 5");
                display.setTextsize(1);
                display.println("WiFi");

                break;

            case 6:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextsize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("Timer 5");
                display.setTextsize(2);
                display.println("WiFi");

                break;
            
            default:
                break;
            }

        case 10://Wifi Setup
            switch (*p)
            {
            case 1:
                /* code */
                break;
            
            default:
                break;
            }

        default://Start und Standby Bildschirm
            display.setCursor(1, 10);
            display.setTextsize(2);
            display.printf("Fuchur \n");
            display.printf("von\nDie unendliche Geschichte");

            break;
        }


}