#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel neo = Adafruit_NeoPixel(56, 5, NEO_GRB + NEO_KHZ800);

uint32_t red = (255, 255, 255);
uint32_t yellow = (255, 255, 0);
uint32_t green = (0, 204, 0);
uint32_t white = (255, 255, 255);
uint32_t off = (0, 0, 0);

unsigned long blink = 0;
int blink_ = 0;
int led_on = 8;
int neopixel_active = 1;
int brightness = 100;

void neopixel_start(int neopixel_anz,int neopixel_pin){
    neo.begin();
    neo.clear();
    neo.show();
    neo.setBrightness(brightness);
}

void ledoff(){
    if(neopixel_active){
        neopixel_active = 0;
        neo.clear();
        neo.show();
    }
    else{
        neopixel_active = 1;
    }
}

void brightness_increase(){
    if(brightness < 255){
        brightness++;
    }
    neo.setBrightness(brightness);
}

void brighness_decrease(){
    if(brightness > 1){
        brightness--;
    }
    neo.setBrightness(brightness);
}

void neopixel_time(unsigned long t1, unsigned long t2, unsigned long t3, unsigned long t4, unsigned long t5, unsigned long *t, int t_out, int t_anz, unsigned long mil){// led 32-55
    unsigned long t1_ = t[0]/t1;
    unsigned long t2_ = t[1]/t2;
    unsigned long t3_ = t[2]/t3;
    unsigned long t4_ = t[3]/t4;
    unsigned long t5_ = t[4]/t5;
    if(neopixel_active){
        if(t_out != 0){
            if(mil > blink+1000){
                if(blink_ = 0){
                    for(int i=32; i<55; i++){
                    neo.setPixelColor(i, white);
                    }
                }
                else{
                    for(int i=32; i<55; i++){
                    neo.setPixelColor(i, off);
                    }
                }
                blink = mil;
            }
        }
        else{
            switch (t_anz)
            {
            case 1:
                if(t1_ > 0,96){neo.setPixelColor(55, green);}
                else{neo.setPixelColor(55, off);}
                if(t1_ > 0,92){neo.setPixelColor(54, green);}
                else{neo.setPixelColor(54, off);}
                if(t1_ > 0,88){neo.setPixelColor(53, green);}
                else{neo.setPixelColor(53, off);}
                if(t1_ > 0,84){neo.setPixelColor(52, green);}
                else{neo.setPixelColor(52, off);}
                if(t1_ > 0,80){neo.setPixelColor(51, green);}
                else{neo.setPixelColor(51, off);}
                if(t1_ > 0,76){neo.setPixelColor(50, green);}
                else{neo.setPixelColor(50, off);}
                if(t1_ > 0,72){neo.setPixelColor(49, green);}
                else{neo.setPixelColor(49, off);}
                if(t1_ > 0,68){neo.setPixelColor(48, green);}
                else{neo.setPixelColor(48, off);}
                if(t1_ > 0,64){neo.setPixelColor(47, green);}
                else{neo.setPixelColor(47, off);}
                if(t1_ > 0,60){neo.setPixelColor(46, green);}
                else{neo.setPixelColor(46, off);}
                if(t1_ > 0,56){neo.setPixelColor(45, green);}
                else{neo.setPixelColor(45, off);}
                if(t1_ > 0,52){neo.setPixelColor(44, green);}
                else{neo.setPixelColor(44, off);}
                if(t1_ > 0,48){neo.setPixelColor(43, green);}
                else{neo.setPixelColor(43, off);}
                if(t1_ > 0,44){neo.setPixelColor(42, green);}
                else{neo.setPixelColor(42, off);}
                if(t1_ > 0,40){neo.setPixelColor(41, green);}
                else{neo.setPixelColor(41, off);}
                if(t1_ > 0,36){neo.setPixelColor(40, green);}
                else{neo.setPixelColor(40, off);}
                if(t1_ > 0,32){neo.setPixelColor(39, green);}
                else{neo.setPixelColor(39, off);}
                if(t1_ > 0,28){neo.setPixelColor(38, green);}
                else{neo.setPixelColor(38, off);}
                if(t1_ > 0,24){neo.setPixelColor(37, green);}
                else{neo.setPixelColor(37, off);}
                if(t1_ > 0,20){neo.setPixelColor(36, green);}
                else{neo.setPixelColor(36, off);}
                if(t1_ > 0,16){neo.setPixelColor(35, green);}
                else{neo.setPixelColor(35, off);}
                if(t1_ > 0,12){neo.setPixelColor(34, green);}
                else{neo.setPixelColor(34, off);}
                if(t1_ > 0,06){neo.setPixelColor(33, green);}
                else{neo.setPixelColor(33, off);}
                if(t1_ > 0,00){neo.setPixelColor(32, green);}
                else{neo.setPixelColor(32, off);}
                break;
                
            case 2:
                if(t2_ > 0,96){neo.setPixelColor(55, green);}
                else{neo.setPixelColor(55, off);}
                if(t2_ > 0,92){neo.setPixelColor(54, green);}
                else{neo.setPixelColor(54, off);}
                if(t2_ > 0,88){neo.setPixelColor(53, green);}
                else{neo.setPixelColor(53, off);}
                if(t2_ > 0,84){neo.setPixelColor(52, green);}
                else{neo.setPixelColor(52, off);}
                if(t2_ > 0,80){neo.setPixelColor(51, green);}
                else{neo.setPixelColor(51, off);}
                if(t2_ > 0,76){neo.setPixelColor(50, green);}
                else{neo.setPixelColor(50, off);}
                if(t2_ > 0,72){neo.setPixelColor(49, green);}
                else{neo.setPixelColor(49, off);}
                if(t2_ > 0,68){neo.setPixelColor(48, green);}
                else{neo.setPixelColor(48, off);}
                if(t2_ > 0,64){neo.setPixelColor(47, green);}
                else{neo.setPixelColor(47, off);}
                if(t2_ > 0,60){neo.setPixelColor(46, green);}
                else{neo.setPixelColor(46, off);}
                if(t2_ > 0,56){neo.setPixelColor(45, green);}
                else{neo.setPixelColor(45, off);}
                if(t2_ > 0,52){neo.setPixelColor(44, green);}
                else{neo.setPixelColor(44, off);}
                if(t2_ > 0,48){neo.setPixelColor(43, green);}
                else{neo.setPixelColor(43, off);}
                if(t2_ > 0,44){neo.setPixelColor(42, green);}
                else{neo.setPixelColor(42, off);}
                if(t2_ > 0,40){neo.setPixelColor(41, green);}
                else{neo.setPixelColor(41, off);}
                if(t2_ > 0,36){neo.setPixelColor(40, green);}
                else{neo.setPixelColor(40, off);}
                if(t2_ > 0,32){neo.setPixelColor(39, green);}
                else{neo.setPixelColor(39, off);}
                if(t2_ > 0,28){neo.setPixelColor(38, green);}
                else{neo.setPixelColor(38, off);}
                if(t2_ > 0,24){neo.setPixelColor(37, green);}
                else{neo.setPixelColor(37, off);}
                if(t2_ > 0,20){neo.setPixelColor(36, green);}
                else{neo.setPixelColor(36, off);}
                if(t2_ > 0,16){neo.setPixelColor(35, green);}
                else{neo.setPixelColor(35, off);}
                if(t2_ > 0,12){neo.setPixelColor(34, green);}
                else{neo.setPixelColor(34, off);}
                if(t2_ > 0,06){neo.setPixelColor(33, green);}
                else{neo.setPixelColor(33, off);}
                if(t2_ > 0,00){neo.setPixelColor(32, green);}
                else{neo.setPixelColor(32, off);}
                break;
                
            case 3:
                if(t3_ > 0,96){neo.setPixelColor(55, green);}
                else{neo.setPixelColor(55, off);}
                if(t3_ > 0,92){neo.setPixelColor(54, green);}
                else{neo.setPixelColor(54, off);}
                if(t3_ > 0,88){neo.setPixelColor(53, green);}
                else{neo.setPixelColor(53, off);}
                if(t3_ > 0,84){neo.setPixelColor(52, green);}
                else{neo.setPixelColor(52, off);}
                if(t3_ > 0,80){neo.setPixelColor(51, green);}
                else{neo.setPixelColor(51, off);}
                if(t3_ > 0,76){neo.setPixelColor(50, green);}
                else{neo.setPixelColor(50, off);}
                if(t3_ > 0,72){neo.setPixelColor(49, green);}
                else{neo.setPixelColor(49, off);}
                if(t3_ > 0,68){neo.setPixelColor(48, green);}
                else{neo.setPixelColor(48, off);}
                if(t3_ > 0,64){neo.setPixelColor(47, green);}
                else{neo.setPixelColor(47, off);}
                if(t3_ > 0,60){neo.setPixelColor(46, green);}
                else{neo.setPixelColor(46, off);}
                if(t3_ > 0,56){neo.setPixelColor(45, green);}
                else{neo.setPixelColor(45, off);}
                if(t3_ > 0,52){neo.setPixelColor(44, green);}
                else{neo.setPixelColor(44, off);}
                if(t3_ > 0,48){neo.setPixelColor(43, green);}
                else{neo.setPixelColor(43, off);}
                if(t3_ > 0,44){neo.setPixelColor(42, green);}
                else{neo.setPixelColor(42, off);}
                if(t3_ > 0,40){neo.setPixelColor(41, green);}
                else{neo.setPixelColor(41, off);}
                if(t3_ > 0,36){neo.setPixelColor(40, green);}
                else{neo.setPixelColor(40, off);}
                if(t3_ > 0,32){neo.setPixelColor(39, green);}
                else{neo.setPixelColor(39, off);}
                if(t3_ > 0,28){neo.setPixelColor(38, green);}
                else{neo.setPixelColor(38, off);}
                if(t3_ > 0,24){neo.setPixelColor(37, green);}
                else{neo.setPixelColor(37, off);}
                if(t3_ > 0,20){neo.setPixelColor(36, green);}
                else{neo.setPixelColor(36, off);}
                if(t3_ > 0,16){neo.setPixelColor(35, green);}
                else{neo.setPixelColor(35, off);}
                if(t3_ > 0,12){neo.setPixelColor(34, green);}
                else{neo.setPixelColor(34, off);}
                if(t3_ > 0,06){neo.setPixelColor(33, green);}
                else{neo.setPixelColor(33, off);}
                if(t3_ > 0,00){neo.setPixelColor(32, green);}
                else{neo.setPixelColor(32, off);}
                break;
                
            case 4:
                if(t4_ > 0,96){neo.setPixelColor(55, green);}
                else{neo.setPixelColor(55, off);}
                if(t4_ > 0,92){neo.setPixelColor(54, green);}
                else{neo.setPixelColor(54, off);}
                if(t4_ > 0,88){neo.setPixelColor(53, green);}
                else{neo.setPixelColor(53, off);}
                if(t4_ > 0,84){neo.setPixelColor(52, green);}
                else{neo.setPixelColor(52, off);}
                if(t4_ > 0,80){neo.setPixelColor(51, green);}
                else{neo.setPixelColor(51, off);}
                if(t4_ > 0,76){neo.setPixelColor(50, green);}
                else{neo.setPixelColor(50, off);}
                if(t4_ > 0,72){neo.setPixelColor(49, green);}
                else{neo.setPixelColor(49, off);}
                if(t4_ > 0,68){neo.setPixelColor(48, green);}
                else{neo.setPixelColor(48, off);}
                if(t4_ > 0,64){neo.setPixelColor(47, green);}
                else{neo.setPixelColor(47, off);}
                if(t4_ > 0,60){neo.setPixelColor(46, green);}
                else{neo.setPixelColor(46, off);}
                if(t4_ > 0,56){neo.setPixelColor(45, green);}
                else{neo.setPixelColor(45, off);}
                if(t4_ > 0,52){neo.setPixelColor(44, green);}
                else{neo.setPixelColor(44, off);}
                if(t4_ > 0,48){neo.setPixelColor(43, green);}
                else{neo.setPixelColor(43, off);}
                if(t4_ > 0,44){neo.setPixelColor(42, green);}
                else{neo.setPixelColor(42, off);}
                if(t4_ > 0,40){neo.setPixelColor(41, green);}
                else{neo.setPixelColor(41, off);}
                if(t4_ > 0,36){neo.setPixelColor(40, green);}
                else{neo.setPixelColor(40, off);}
                if(t4_ > 0,32){neo.setPixelColor(39, green);}
                else{neo.setPixelColor(39, off);}
                if(t4_ > 0,28){neo.setPixelColor(38, green);}
                else{neo.setPixelColor(38, off);}
                if(t4_ > 0,24){neo.setPixelColor(37, green);}
                else{neo.setPixelColor(37, off);}
                if(t4_ > 0,20){neo.setPixelColor(36, green);}
                else{neo.setPixelColor(36, off);}
                if(t4_ > 0,16){neo.setPixelColor(35, green);}
                else{neo.setPixelColor(35, off);}
                if(t4_ > 0,12){neo.setPixelColor(34, green);}
                else{neo.setPixelColor(34, off);}
                if(t4_ > 0,06){neo.setPixelColor(33, green);}
                else{neo.setPixelColor(33, off);}
                if(t4_ > 0,00){neo.setPixelColor(32, green);}
                else{neo.setPixelColor(32, off);}
                break;
                
            case 5:
                if(t5_ > 0,96){neo.setPixelColor(55, green);}
                else{neo.setPixelColor(55, off);}
                if(t5_ > 0,92){neo.setPixelColor(54, green);}
                else{neo.setPixelColor(54, off);}
                if(t5_ > 0,88){neo.setPixelColor(53, green);}
                else{neo.setPixelColor(53, off);}
                if(t5_ > 0,84){neo.setPixelColor(52, green);}
                else{neo.setPixelColor(52, off);}
                if(t5_ > 0,80){neo.setPixelColor(51, green);}
                else{neo.setPixelColor(51, off);}
                if(t5_ > 0,76){neo.setPixelColor(50, green);}
                else{neo.setPixelColor(50, off);}
                if(t5_ > 0,72){neo.setPixelColor(49, green);}
                else{neo.setPixelColor(49, off);}
                if(t5_ > 0,68){neo.setPixelColor(48, green);}
                else{neo.setPixelColor(48, off);}
                if(t5_ > 0,64){neo.setPixelColor(47, green);}
                else{neo.setPixelColor(47, off);}
                if(t5_ > 0,60){neo.setPixelColor(46, green);}
                else{neo.setPixelColor(46, off);}
                if(t5_ > 0,56){neo.setPixelColor(45, green);}
                else{neo.setPixelColor(45, off);}
                if(t5_ > 0,52){neo.setPixelColor(44, green);}
                else{neo.setPixelColor(44, off);}
                if(t5_ > 0,48){neo.setPixelColor(43, green);}
                else{neo.setPixelColor(43, off);}
                if(t5_ > 0,44){neo.setPixelColor(42, green);}
                else{neo.setPixelColor(42, off);}
                if(t5_ > 0,40){neo.setPixelColor(41, green);}
                else{neo.setPixelColor(41, off);}
                if(t5_ > 0,36){neo.setPixelColor(40, green);}
                else{neo.setPixelColor(40, off);}
                if(t5_ > 0,32){neo.setPixelColor(39, green);}
                else{neo.setPixelColor(39, off);}
                if(t5_ > 0,28){neo.setPixelColor(38, green);}
                else{neo.setPixelColor(38, off);}
                if(t5_ > 0,24){neo.setPixelColor(37, green);}
                else{neo.setPixelColor(37, off);}
                if(t5_ > 0,20){neo.setPixelColor(36, green);}
                else{neo.setPixelColor(36, off);}
                if(t5_ > 0,16){neo.setPixelColor(35, green);}
                else{neo.setPixelColor(35, off);}
                if(t5_ > 0,12){neo.setPixelColor(34, green);}
                else{neo.setPixelColor(34, off);}
                if(t5_ > 0,06){neo.setPixelColor(33, green);}
                else{neo.setPixelColor(33, off);}
                if(t5_ > 0,00){neo.setPixelColor(32, green);}
                else{neo.setPixelColor(32, off);}
                break;
            
            default:
                break;
            }
        }

        neo.show();
    }
}

void neopixel_rotary_rotate(int led_on_){//led 8-31
    if(neopixel_active){
        if(led_on == 31 && led_on_ == 1){
            led_on = 8;
        }
        else if(led_on == 8 && led_on_ == -1){
            led_on = 31;
        }
        else{
            led_on += led_on_;
        }
        for(int i=8; i<31; i++){
            neo.setPixelColor(i, off);
        }
        neo.setPixelColor(led_on, white);

        neo.show();
    }
    return;
}

void neopixel_rotary_press(int p){//led 8-31
    if(neopixel_active){
        if(p){
            for(int i=8; i<31; i++){
                neo.setPixelColor(i, white);
            }
        }

        if(!p){
            for(int i=8; i<31; i++){
                neo.setPixelColor(i, off);
            }
        }
        neo.show();
    }
}

void neopixel_leiste(int wi_fi, int wi_fi_act, int web_server, int web_server_act, unsigned long t1, unsigned long t2, unsigned long t3, unsigned long t4, unsigned long t5, unsigned long *t){//led 0-7
    unsigned long t1_ = t[0]/t1;
    unsigned long t2_ = t[1]/t2;
    unsigned long t3_ = t[2]/t3;
    unsigned long t4_ = t[3]/t4;
    unsigned long t5_ = t[4]/t5;

    if(neopixel_active){
        neo.setPixelColor(7, white);//power-led
        neo.show();
        if(wi_fi){
            if(wi_fi_act){
                neo.setPixelColor(6, green);
            }
            else{
                neo.setPixelColor(6, red);
            }
        }
        else{
            neo.setPixelColor(6, off);
        }

        if(web_server){
            if(web_server_act){
                neo.setPixelColor(6, green);
            }
            else{
                neo.setPixelColor(6, red);
            }
        }
        else{
            neo.setPixelColor(6, off);
        }

        if(t5 == 0){
            neo.setPixelColor(5, off);
        }
        else if(t5_ > 0.6){
            neo.setPixelColor(5, green);
        }
        else if(t5_ > 0.3){
            neo.setPixelColor(5, yellow);
        }
        else{
            neo.setPixelColor(5, red);
        }

        if(t4 == 0){
            neo.setPixelColor(5, off);
        }
        else if(t4_ > 0.6){
            neo.setPixelColor(5, green);
        }
        else if(t4_ > 0.3){
            neo.setPixelColor(5, yellow);
        }
        else{
            neo.setPixelColor(5, red);
        }

        if(t3 == 0){
            neo.setPixelColor(5, off);
        }
        else if(t3_ > 0.6){
            neo.setPixelColor(5, green);
        }
        else if(t3_ > 0.3){
            neo.setPixelColor(5, yellow);
        }
        else{
            neo.setPixelColor(5, red);
        }

        if(t2 == 0){
            neo.setPixelColor(5, off);
        }
        else if(t2_ > 0.6){
            neo.setPixelColor(5, green);
        }
        else if(t2_ > 0.3){
            neo.setPixelColor(5, yellow);
        }
        else{
            neo.setPixelColor(5, red);
        }

        if(t1 == 0){
            neo.setPixelColor(5, off);
        }
        else if(t1_ > 0.6){
            neo.setPixelColor(5, green);
        }
        else if(t1_ > 0.3){
            neo.setPixelColor(5, yellow);
        }
        else{
            neo.setPixelColor(5, red);
        }

        neo.show();
    }
}