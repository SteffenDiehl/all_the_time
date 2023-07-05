#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel neo(58, 5, NEO_GRB + NEO_KHZ800);

uint32_t red = neo.Color(255, 0, 0);
uint32_t yellow = neo.Color(255, 255, 0);
uint32_t green = neo.Color(0, 255, 0);
uint32_t white = neo.Color(255, 255, 255);
uint32_t off = neo.Color(0, 0, 0);

unsigned long blink = 0;
int blink_ = 0;
int led_on = 8;
int neopixel_active = 1;
int brightness = 50;

void neopixel_start(int neopixel_anz,int neopixel_pin){
    neo.begin();
    neo.clear();
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

void brightness_increase(){//heller
    if(brightness < 255){
        brightness += 5;
    }
    neo.setBrightness(brightness);
}

void brighness_decrease(){//dunkler
    if(brightness > 1){
        brightness -= 5;
    }
    neo.setBrightness(brightness);
}

void neopixel_time_blink(unsigned long mil){
    if(mil >= blink+500){
        if(blink_ = 0){
            for(int i=32; i<55; i++){
            neo.setPixelColor(i, white);
            }
            blink_ = 1;
        }
        else{
            for(int i=32; i<55; i++){
            neo.setPixelColor(i, off);
            }
            blink_ = 0;
        }
        blink = mil;
    }
}

void neopixel_time(unsigned long t1, unsigned long t2, unsigned long t3, unsigned long t4, unsigned long t5, unsigned long *t, int t_out, int t_anz){// led 33-56
    float t1_ = float(t[0])/float(t1);
    float t2_ = float(t[1])/float(t2);
    float t3_ = float(t[2])/float(t3);
    float t4_ = float(t[3])/float(t4);
    float t5_ = float(t[4])/float(t5);
    if(neopixel_active && t_out == 0){
        switch (t_anz)
        {
        case 1:
            if(t1_ >= 0,96){neo.setPixelColor(56, green);}
            if(t1_ >= 0,92){neo.setPixelColor(55, green);}
            if(t1_ >= 0,88){neo.setPixelColor(54, green);}
            if(t1_ >= 0,84){neo.setPixelColor(53, green);}
            if(t1_ >= 0,80){neo.setPixelColor(52, green);}
            if(t1_ >= 0,76){neo.setPixelColor(51, green);}
            if(t1_ >= 0,72){neo.setPixelColor(50, green);}
            if(t1_ >= 0,68){neo.setPixelColor(49, green);}
            if(t1_ >= 0,64){neo.setPixelColor(48, yellow);}
            if(t1_ >= 0,60){neo.setPixelColor(47, yellow);}
            if(t1_ >= 0,56){neo.setPixelColor(46, yellow);}
            if(t1_ >= 0,52){neo.setPixelColor(45, yellow);}
            if(t1_ >= 0,48){neo.setPixelColor(44, yellow);}
            if(t1_ >= 0,44){neo.setPixelColor(43, yellow);}
            if(t1_ >= 0,40){neo.setPixelColor(42, yellow);}
            if(t1_ >= 0,36){neo.setPixelColor(41, yellow);}
            if(t1_ >= 0,32){neo.setPixelColor(40, yellow);}
            if(t1_ >= 0,28){neo.setPixelColor(39, red);}
            if(t1_ >= 0,24){neo.setPixelColor(38, red);}
            if(t1_ >= 0,20){neo.setPixelColor(37, red);}
            if(t1_ >= 0,16){neo.setPixelColor(36, red);}
            if(t1_ >= 0,12){neo.setPixelColor(35, red);}
            if(t1_ >= 0,07){neo.setPixelColor(34, red);}
            if(t1_ >= 0,04){neo.setPixelColor(33, red);}
            if(t1_ >= 0,00){neo.setPixelColor(32, red);}
            break;
            
        case 2:
            if(t2_ > 0,96){neo.setPixelColor(56, green);}
            else{neo.setPixelColor(56, off);}
            if(t2_ > 0,92){neo.setPixelColor(55, green);}
            else{neo.setPixelColor(55, off);}
            if(t2_ > 0,88){neo.setPixelColor(54, green);}
            else{neo.setPixelColor(54, off);}
            if(t2_ > 0,84){neo.setPixelColor(53, green);}
            else{neo.setPixelColor(53, off);}
            if(t2_ > 0,80){neo.setPixelColor(52, green);}
            else{neo.setPixelColor(52, off);}
            if(t2_ > 0,76){neo.setPixelColor(51, green);}
            else{neo.setPixelColor(51, off);}
            if(t2_ > 0,72){neo.setPixelColor(50, green);}
            else{neo.setPixelColor(50, off);}
            if(t2_ > 0,68){neo.setPixelColor(49, green);}
            else{neo.setPixelColor(49, off);}
            if(t2_ > 0,64){neo.setPixelColor(48, yellow);}
            else{neo.setPixelColor(48, off);}
            if(t2_ > 0,60){neo.setPixelColor(47, yellow);}
            else{neo.setPixelColor(47, off);}
            if(t2_ > 0,56){neo.setPixelColor(46, yellow);}
            else{neo.setPixelColor(46, off);}
            if(t2_ > 0,52){neo.setPixelColor(45, yellow);}
            else{neo.setPixelColor(45, off);}
            if(t2_ > 0,48){neo.setPixelColor(44, yellow);}
            else{neo.setPixelColor(44, off);}
            if(t2_ > 0,44){neo.setPixelColor(43, yellow);}
            else{neo.setPixelColor(43, off);}
            if(t2_ > 0,40){neo.setPixelColor(42, yellow);}
            else{neo.setPixelColor(42, off);}
            if(t2_ > 0,36){neo.setPixelColor(41, yellow);}
            else{neo.setPixelColor(41, off);}
            if(t2_ > 0,32){neo.setPixelColor(40, yellow);}
            else{neo.setPixelColor(40, off);}
            if(t2_ > 0,28){neo.setPixelColor(39, red);}
            else{neo.setPixelColor(39, off);}
            if(t2_ > 0,24){neo.setPixelColor(38, red);}
            else{neo.setPixelColor(38, off);}
            if(t2_ > 0,20){neo.setPixelColor(37, red);}
            else{neo.setPixelColor(37, off);}
            if(t2_ > 0,16){neo.setPixelColor(36, red);}
            else{neo.setPixelColor(36, off);}
            if(t2_ > 0,12){neo.setPixelColor(35, red);}
            else{neo.setPixelColor(35, off);}
            if(t2_ > 0,07){neo.setPixelColor(34, red);}
            else{neo.setPixelColor(34, off);}
            if(t2_ > 0,04){neo.setPixelColor(33, red);}
            else{neo.setPixelColor(33, off);}
            if(t2_ >= 0,00){neo.setPixelColor(32, red);}
            else{neo.setPixelColor(32, off);}
            break;
            
        case 3:
            if(t3_ > 0,96){neo.setPixelColor(56, green);}
            else{neo.setPixelColor(56, off);}
            if(t3_ > 0,92){neo.setPixelColor(55, green);}
            else{neo.setPixelColor(55, off);}
            if(t3_ > 0,88){neo.setPixelColor(54, green);}
            else{neo.setPixelColor(54, off);}
            if(t3_ > 0,84){neo.setPixelColor(53, green);}
            else{neo.setPixelColor(53, off);}
            if(t3_ > 0,80){neo.setPixelColor(52, green);}
            else{neo.setPixelColor(52, off);}
            if(t3_ > 0,76){neo.setPixelColor(51, green);}
            else{neo.setPixelColor(51, off);}
            if(t3_ > 0,72){neo.setPixelColor(50, green);}
            else{neo.setPixelColor(50, off);}
            if(t3_ > 0,68){neo.setPixelColor(49, green);}
            else{neo.setPixelColor(49, off);}
            if(t3_ > 0,64){neo.setPixelColor(48, yellow);}
            else{neo.setPixelColor(48, off);}
            if(t3_ > 0,60){neo.setPixelColor(47, yellow);}
            else{neo.setPixelColor(47, off);}
            if(t3_ > 0,56){neo.setPixelColor(46, yellow);}
            else{neo.setPixelColor(46, off);}
            if(t3_ > 0,52){neo.setPixelColor(45, yellow);}
            else{neo.setPixelColor(45, off);}
            if(t3_ > 0,48){neo.setPixelColor(44, yellow);}
            else{neo.setPixelColor(44, off);}
            if(t3_ > 0,44){neo.setPixelColor(43, yellow);}
            else{neo.setPixelColor(43, off);}
            if(t3_ > 0,40){neo.setPixelColor(42, yellow);}
            else{neo.setPixelColor(42, off);}
            if(t3_ > 0,36){neo.setPixelColor(41, yellow);}
            else{neo.setPixelColor(41, off);}
            if(t3_ > 0,32){neo.setPixelColor(40, yellow);}
            else{neo.setPixelColor(40, off);}
            if(t3_ > 0,28){neo.setPixelColor(39, red);}
            else{neo.setPixelColor(39, off);}
            if(t3_ > 0,24){neo.setPixelColor(38, red);}
            else{neo.setPixelColor(38, off);}
            if(t3_ > 0,20){neo.setPixelColor(37, red);}
            else{neo.setPixelColor(37, off);}
            if(t3_ > 0,16){neo.setPixelColor(36, red);}
            else{neo.setPixelColor(36, off);}
            if(t3_ > 0,12){neo.setPixelColor(35, red);}
            else{neo.setPixelColor(35, off);}
            if(t3_ > 0,07){neo.setPixelColor(34, red);}
            else{neo.setPixelColor(34, off);}
            if(t3_ > 0,04){neo.setPixelColor(33, red);}
            else{neo.setPixelColor(33, off);}
            if(t3_ >= 0,00){neo.setPixelColor(32, red);}
            else{neo.setPixelColor(32, off);}
            break;
            
        case 4:
            if(t4_ > 0,96){neo.setPixelColor(56, green);}
            else{neo.setPixelColor(56, off);}
            if(t4_ > 0,92){neo.setPixelColor(55, green);}
            else{neo.setPixelColor(55, off);}
            if(t4_ > 0,88){neo.setPixelColor(54, green);}
            else{neo.setPixelColor(54, off);}
            if(t4_ > 0,84){neo.setPixelColor(53, green);}
            else{neo.setPixelColor(53, off);}
            if(t4_ > 0,80){neo.setPixelColor(52, green);}
            else{neo.setPixelColor(52, off);}
            if(t4_ > 0,76){neo.setPixelColor(51, green);}
            else{neo.setPixelColor(51, off);}
            if(t4_ > 0,72){neo.setPixelColor(50, green);}
            else{neo.setPixelColor(50, off);}
            if(t4_ > 0,68){neo.setPixelColor(49, green);}
            else{neo.setPixelColor(49, off);}
            if(t4_ > 0,64){neo.setPixelColor(48, yellow);}
            else{neo.setPixelColor(48, off);}
            if(t4_ > 0,60){neo.setPixelColor(47, yellow);}
            else{neo.setPixelColor(47, off);}
            if(t4_ > 0,56){neo.setPixelColor(46, yellow);}
            else{neo.setPixelColor(46, off);}
            if(t4_ > 0,52){neo.setPixelColor(45, yellow);}
            else{neo.setPixelColor(45, off);}
            if(t4_ > 0,48){neo.setPixelColor(44, yellow);}
            else{neo.setPixelColor(44, off);}
            if(t4_ > 0,44){neo.setPixelColor(43, yellow);}
            else{neo.setPixelColor(43, off);}
            if(t4_ > 0,40){neo.setPixelColor(42, yellow);}
            else{neo.setPixelColor(42, off);}
            if(t4_ > 0,36){neo.setPixelColor(41, yellow);}
            else{neo.setPixelColor(41, off);}
            if(t4_ > 0,32){neo.setPixelColor(40, yellow);}
            else{neo.setPixelColor(40, off);}
            if(t4_ > 0,28){neo.setPixelColor(39, red);}
            else{neo.setPixelColor(39, off);}
            if(t4_ > 0,24){neo.setPixelColor(38, red);}
            else{neo.setPixelColor(38, off);}
            if(t4_ > 0,20){neo.setPixelColor(37, red);}
            else{neo.setPixelColor(37, off);}
            if(t4_ > 0,16){neo.setPixelColor(36, red);}
            else{neo.setPixelColor(36, off);}
            if(t4_ > 0,12){neo.setPixelColor(35, red);}
            else{neo.setPixelColor(35, off);}
            if(t4_ > 0,07){neo.setPixelColor(34, red);}
            else{neo.setPixelColor(34, off);}
            if(t4_ > 0,04){neo.setPixelColor(33, red);}
            else{neo.setPixelColor(33, off);}
            if(t4_ >= 0,00){neo.setPixelColor(32, red);}
            else{neo.setPixelColor(32, off);}
            break;
            
        case 5:
            if(t5_ >= 0,96){neo.setPixelColor(56, green);}
            else{neo.setPixelColor(56, off);}
            if(t5_ >= 0,92){neo.setPixelColor(55, green);}
            else{neo.setPixelColor(55, off);}
            if(t5_ >= 0,88){neo.setPixelColor(54, green);}
            else{neo.setPixelColor(54, off);}
            if(t5_ >= 0,84){neo.setPixelColor(53, green);}
            else{neo.setPixelColor(53, off);}
            if(t5_ >= 0,80){neo.setPixelColor(52, green);}
            else{neo.setPixelColor(52, off);}
            if(t5_ >= 0,76){neo.setPixelColor(51, green);}
            else{neo.setPixelColor(51, off);}
            if(t5_ >= 0,72){neo.setPixelColor(50, green);}
            else{neo.setPixelColor(50, off);}
            if(t5_ >= 0,68){neo.setPixelColor(49, green);}
            else{neo.setPixelColor(49, off);}
            if(t5_ >= 0,64){neo.setPixelColor(48, yellow);}
            else{neo.setPixelColor(48, off);}
            if(t5_ >= 0,60){neo.setPixelColor(47, yellow);}
            else{neo.setPixelColor(47, off);}
            if(t5_ >= 0,56){neo.setPixelColor(46, yellow);}
            else{neo.setPixelColor(46, off);}
            if(t5_ >= 0,52){neo.setPixelColor(45, yellow);}
            else{neo.setPixelColor(45, off);}
            if(t5_ >= 0,48){neo.setPixelColor(44, yellow);}
            else{neo.setPixelColor(44, off);}
            if(t5_ >= 0,44){neo.setPixelColor(43, yellow);}
            else{neo.setPixelColor(43, off);}
            if(t5_ >= 0,40){neo.setPixelColor(42, yellow);}
            else{neo.setPixelColor(42, off);}
            if(t5_ >= 0,36){neo.setPixelColor(41, yellow);}
            else{neo.setPixelColor(41, off);}
            if(t5_ >= 0,32){neo.setPixelColor(40, yellow);}
            else{neo.setPixelColor(40, off);}
            if(t5_ >= 0,28){neo.setPixelColor(39, red);}
            else{neo.setPixelColor(39, off);}
            if(t5_ >= 0,24){neo.setPixelColor(38, red);}
            else{neo.setPixelColor(38, off);}
            if(t5_ >= 0,20){neo.setPixelColor(37, red);}
            else{neo.setPixelColor(37, off);}
            if(t5_ >= 0,16){neo.setPixelColor(36, red);}
            else{neo.setPixelColor(36, off);}
            if(t5_ >= 0,12){neo.setPixelColor(35, red);}
            else{neo.setPixelColor(35, off);}
            if(t5_ >= 0,07){neo.setPixelColor(34, red);}
            else{neo.setPixelColor(34, off);}
            if(t5_ >= 0,04){neo.setPixelColor(33, red);}
            else{neo.setPixelColor(33, off);}
            if(t5_ >= 0,00){neo.setPixelColor(32, red);}
            else{neo.setPixelColor(32, off);}
            break;
        
        default:
            break;
        }
    }
}

void neopixel_rotary_rotate_(int led_on_){//led 8-31
    if(led_on == 31 && led_on_ == 1){
        led_on = 8;
    }
    else if(led_on == 8 && led_on_ == -1){
        led_on = 31;
    }
    else{
        led_on += led_on_;
    }
}
void neopixel_rotary_rotate(){
    if(neopixel_active){
        for(int i=8; i<32; i++){
            neo.setPixelColor(i, off);
        }
        neo.setPixelColor(led_on, white);
    }
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
    }
}

void neopixel_leiste(int wi_fi, int wi_fi_act, int web_server, int web_server_act, unsigned long t1, unsigned long t2, unsigned long t3, unsigned long t4, unsigned long t5, unsigned long *t){//led 0-7
    float t1_ = float(t[0])/float(t1);
    float t2_ = float(t[1])/float(t2);
    float t3_ = float(t[2])/float(t3);
    float t4_ = float(t[3])/float(t4);
    float t5_ = float(t[4])/float(t5);

    if(neopixel_active){
        neo.setPixelColor(7, green);//power-led
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
                neo.setPixelColor(5, green);
            }
            else{
                neo.setPixelColor(5, red);
            }
        }
        else{
            neo.setPixelColor(5, off);
        }

        if(t5 == 0){
            neo.setPixelColor(4, off);
        }
        else if(t5_ > 0.6){
            neo.setPixelColor(4, green);
        }
        else if(t5_ > 0.3){
            neo.setPixelColor(4, yellow);
        }
        else{
            neo.setPixelColor(4, red);
        }

        if(t4 == 0){
            neo.setPixelColor(3, off);
        }
        else if(t4_ > 0.6){
            neo.setPixelColor(3, green);
        }
        else if(t4_ > 0.3){
            neo.setPixelColor(3, yellow);
        }
        else{
            neo.setPixelColor(3, red);
        }

        if(t3 == 0){
            neo.setPixelColor(2, off);
        }
        else if(t3_ > 0.6){
            neo.setPixelColor(2, green);
        }
        else if(t3_ > 0.3){
            neo.setPixelColor(2, yellow);
        }
        else{
            neo.setPixelColor(2, red);
        }

        if(t2 == 0){
            neo.setPixelColor(1, off);
        }
        else if(t2_ > 0.6){
            neo.setPixelColor(1, green);
        }
        else if(t2_ > 0.3){
            neo.setPixelColor(1, yellow);
        }
        else{
            neo.setPixelColor(1, red);
        }

        if(t1 == 0){
            neo.setPixelColor(0, off);
        }
        else if(t1_ > 0.6){
            neo.setPixelColor(0, green);
        }
        else if(t1_ > 0.3){
            neo.setPixelColor(0, yellow);
        }
        else{
            neo.setPixelColor(0, red);
        }
    }
}