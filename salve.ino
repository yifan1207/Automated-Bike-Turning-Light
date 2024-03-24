#include <Adafruit_NeoPixel.h> 
#include <Wire.h>
 
#define PIN1 6s
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(512, PIN1, NEO_GRB + NEO_KHZ800);

#define COLOR strip1.Color(5, 5, 0)
void second_part();
void first_part();
void Third_part();
void Fourth_part();
void forword();
void First_down();
void Second_down();
void First_up();
void Second_up();

void Front(){
    strip1.setBrightness(0);strip1.show();
    strip1.setBrightness(255);strip1.show();
    Third_part();
    Fourth_part();
    strip1.show();
  }
void Left(){
  strip1.setBrightness(0);strip1.show();
  strip1.setBrightness(255);strip1.show();
  Third_part();
  Second_down();
  strip1.show();
  }
void Right(){
  strip1.setBrightness(0);strip1.show();
  strip1.setBrightness(255);strip1.show();  
  First_down();
  Fourth_part();
  strip1.show();
  }

void setup() {
  Wire.begin(1);    //ID号
  Wire.onReceive(receiveEvent);
  
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'  

}

void loop() {

}
void receiveEvent()
{
    char cmd =(char)Wire.read();
    if(cmd=='0') {Front();}
    if(cmd=='1') {Left();}
    if(cmd=='2') {Right();}    
  }
  
