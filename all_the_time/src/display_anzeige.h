#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>
#include <time.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
    Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void timer_output(unsigned long time){
    int hours = time / 3600000;
    int minutes = (time - hours*3600000)/60000;
    int seconds = (time - hours*3600000 - minutes*60000)/1000;

    display.setTextSize(2);
    display.printf("%2i:%2i:%2i\n", hours, minutes, seconds);
}

void display_Anzeige(int *m, int *p, int *p_max, int * t, unsigned long *t1, unsigned long *t2, unsigned long *t3, unsigned long *t4, unsigned long *t5){

    struct tm timeinfo;
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setFont();
    display.setTextSize(1);

    switch(*m){
        case 1://kein Timer aktiv
            *p_max = 2;
            switch (*p)
            {
            case 1: 
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(2);
                display.println("new Timer");
                display.setTextSize(1);
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(1);
                display.println("new Timer");
                display.setTextSize(2);
                display.println("WiFi");

                break;
            
            default:
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;

        case 2://ein Timer aktiv
            *p_max = 3;
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(2);
                display.println("Timer 1");
                display.setTextSize(1);
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.setTextSize(2);
                display.println("new Timer");
                display.setTextSize(1);
                display.println("WiFi");

                break;

            case 3:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(1);
                display.println("Timer 1");
                display.println("new Timer");
                display.setTextSize(2);
                display.println("WiFi");

                break;
            
            default:
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;
        
        case 3://zwei Timer aktiv
            *p_max = 4;
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(2);
                display.println("Timer 1");
                display.setTextSize(1);
                display.println("Timer 2");
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 2:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.setTextSize(2);
                display.println("Timer 2");
                display.setTextSize(1);
                display.println("new Timer");
                display.println("WiFi");

                break;

            case 3:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.println("Timer 1");
                display.println("Timer 2");
                display.setTextSize(2);
                display.println("new Timer");
                display.setTextSize(1);
                display.println("WiFi");

                break;

            case 4:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("new Timer");
                display.setTextSize(2);
                display.println("WiFi");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;

        case 4://drei Timer aktiv
            *p_max = 5;
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(2);
                display.println("Timer 1");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 2");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 3");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("new Timer");
                display.setTextSize(1);
                display.println("WiFi");

                break;

            case 5:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("new Timer");
                display.setTextSize(2);
                display.println("WiFi");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;

        case 5://vier Timer aktiv
            *p_max = 6;
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(2);
                display.println("Timer 1");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 2");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 3");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 4");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("new Timer");
                display.setTextSize(1);
                display.println("WiFi");

                break;

            case 6:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("new Timer");
                display.setTextSize(2);
                display.println("WiFi");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;

        case 6://fünf Timer aktiv
            *p_max = 6;
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(2);
                display.println("Timer 1");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 2");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 3");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 4");
                display.setTextSize(1);
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
                display.setTextSize(2);
                display.println("Timer 5");
                display.setTextSize(1);
                display.println("WiFi");

                break;

            case 6:
                display.setCursor(0,10);
                display.println(&timeinfo, "Date: %B.%d.%Y");
                display.println(&timeinfo, "Time: %H:%M:%S");
                display.setTextSize(1);
                display.println("Timer 1");
                display.println("Timer 2");
                display.println("Timer 3");
                display.println("Timer 4");
                display.println("Timer 5");
                display.setTextSize(2);
                display.println("WiFi");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;
    	
        case 7://new Timer
            *p_max = 2;
            switch(*p)
            {
            case 1:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("variabler Timer");
                display.setTextSize(1);
                display.println("feste\nTimer");

                break;

            case 2:
                display.setCursor(0,10);
                display.setTextSize(1);
                display.println("variabler Timer");
                display.setTextSize(2);
                display.println("feste Timer");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;
        
        case 8://variabler Timer
            display.setCursor(0,10);
            display.println("Timer:");
            switch (*t)
            {
            case 0:
                timer_output(*t1);
                break;
            
            case 1:
                timer_output(*t2);
                break;
            
            case 2:
                timer_output(*t2);
                break;
            
            case 3:
                timer_output(*t3);
                break;
            
            case 4:
                timer_output(*t4);
                break;
            
            default:
                break;
            }
            break;
        
        case 9:

            break;

        case 10://Wifi Setup
            *p_max = 3;
            switch (*p)
            {
            case 1:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("WiFi I/0");
                display.setTextSize(1);
                display.println("Web Server I/0");
                display.println("back");

                break;

            case 2:
                display.setCursor(0,10);
                display.setTextSize(1);
                display.println("WiFi I/0");
                display.setTextSize(2);
                display.println("Web Server I/0");
                display.setTextSize(1);
                display.println("back");

                break;
            
            case 3:
                display.setCursor(0,10);
                display.setTextSize(1);
                display.println("WiFi I/0");
                display.println("Web Server I/0");
                display.setTextSize(2);
                display.println("back");

                break;

            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;
            }
            break;

        case 11://Timer 1
            switch(*p)
            {
            case 1:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("Timer 1:");
                timer_output(*t1);

                break;
            
            case 2:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("back");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;

            }
            break;

        case 12://Timer 2
            switch(*p)
            {
            case 1:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("Timer 2:");
                timer_output(*t2);

                break;
            
            case 2:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("back");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;

            }
            break;
        
        case 13://Timer 3
            switch(*p)
            {
            case 1:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("Timer 3:");
                timer_output(*t3);

                break;
            
            case 2:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("back");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;

            }
            break;
        
        case 14://Timer 4
            switch(*p)
            {
            case 1:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("Timer 4:");
                timer_output(*t4);

                break;
            
            case 2:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("back");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;

            }
            break;

        case 15://Timer 5
            switch(*p)
            {
            case 1:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("Timer 5:");
                timer_output(*t5);

                break;
            
            case 2:
                display.setCursor(0,10);
                display.setTextSize(2);
                display.println("back");

                break;
            
            default:
                display.setCursor(0,10);
                display.setTextSize(3);
                display.println("Error");
                break;

            }
            break;

        default://Start und Standby Bildschirm
            display.setCursor(1, 10);
            display.setTextSize(2);
            display.setCursor(30, 5);
            display.printf("Fuchur \n");
            display.setTextSize(1);
            display.setCursor(55, 25);
            display.printf("von\n");
            display.setCursor(22, 35);
            display.printf("Die unendliche\n      Geschichte");

            break;
        }
  display.display();


}
