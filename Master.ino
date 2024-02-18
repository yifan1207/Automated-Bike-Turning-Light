#include <Adafruit_NeoPixel.h> 
#include <Wire.h>
#include <SoftwareSerial.h>

#define PINss

const int MUSIC1 = 3;//
const int MUSIC2 = 4;//
const int MUSIC3 = 5;//

//const int MODECHANGE = 5;//

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(512, PIN1, NEO_GRB + NEO_KHZ800);
SoftwareSerial BT(8,9);   //8  rx,9  tx
//SoftwareSerial BT2(10,11);   //8  rx,9  tx
#define COLOR strip1.Color(5, 5, 0) 


char cmd,lastcmd;

void Music_Control(uint8_t state);
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
    forword();
  }
void Left(){
  strip1.setBrightness(0);strip1.show();
  strip1.setBrightness(255);strip1.show();
  first_part();
  Second_up();
  }
void Right(){
  strip1.setBrightness(0);strip1.show();
  strip1.setBrightness(255);strip1.show();  
  First_up(); 
  second_part();
  }

void setup() {
  
  BT.begin(38400);
  Wire.begin();

  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'  

  pinMode(MUSIC1,OUTPUT);
  pinMode(MUSIC2,OUTPUT);
  pinMode(MUSIC3,OUTPUT);
  digitalWrite(MUSIC1,HIGH);
  digitalWrite(MUSIC2,HIGH);
  digitalWrite(MUSIC3,HIGH);
//  pinMode(MODECHANGE,OUTPUT);
}

void loop() {
  if(BT.available()>0)
  {
    cmd=BT.read();
    if(cmd!=lastcmd){
        if(cmd=='0') {cmdTx(cmd);Front();Music_Control(0);}
        if(cmd=='1') {cmdTx(cmd);Left();Music_Control(1);}
        if(cmd=='2') {cmdTx(cmd);Right();Music_Control(2);}
        lastcmd=cmd;
       }  
    }
delay(10);
}

void cmdTx(char cmd){
  Wire.beginTransmission(1);
  Wire.write(cmd);
  Wire.endTransmission(); 
  }
