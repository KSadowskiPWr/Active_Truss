#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <MPU6050.h>
#include <Keypad.h>
#define calibration_factor 1112.75
#include <FastLED.h>
#include <SPI.h>
#include <Wire.h>
const int MPU_addr=0x68;
#include "HX711.h"
#define DOUT  A3
#define CLK  A2
#define TFT_CS         53
#define TFTsclk SCK    52    
#define TFTmosi MOSI   51    
#define TFT_DC         49          
#define TFT_RST        48
#define LED_PIN        10
const byte ROWS = 4; 
const byte COLS = 3;
char hexaKeys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}};
byte rowPins[ROWS] = {35, 33, 31, 29}; 
byte colPins[COLS] = {27, 25, 23}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

#define NUM_LEDS    509

#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];
bool prety[89], sily[240];
int podpory[120];
float wsppreta[89];
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
#include <Fonts/FreeSerif18pt7b.h>
float ab=0, m, m1, m2, m3, m4, m5, m6, m7;
String textForSMS;
HX711 scale0;
HX711 scale1;
HX711 scale2;
HX711 scale3;
HX711 scale4;
HX711 scale5;
HX711 scale6;
HX711 scale7;
char customKey = customKeypad.getKey();
void setup() {
Serial.begin(115200); 
tft.initR(INITR_BLACKTAB);
tft.fillScreen(ST7735_BLACK);
tft.setTextWrap(false);
tft.setRotation(1);
tft.setTextSize(0);
tft.setCursor(0, 0);
scale0.begin(A1, A0);
scale1.begin(A3, A2);
scale2.begin(A5, A4);
scale3.begin(A7, A6);
scale4.begin(A9, A8);
scale5.begin(A11, A10);
scale6.begin(A13, A12);
scale7.begin(A15, A14);
scale0.set_scale(1031.714);
scale1.set_scale(194.608);
scale2.set_scale(1074.3211);
scale3.set_scale(calibration_factor);
scale4.set_scale(calibration_factor);
scale5.set_scale(calibration_factor);
scale6.set_scale(calibration_factor);
scale7.set_scale(calibration_factor); 
scale0.tare();
scale1.tare();
scale2.tare();
scale3.tare();
scale4.tare();
scale5.tare();
scale6.tare();
scale7.tare(); 
m=m+256;
 FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
menu();}

void menu(){
  int abc=0, q=0;
tft.setTextColor(ST7735_MAGENTA);
tft.setTextSize(2);
tft.setCursor(10, 10);  
tft.print("BIEDUINO");
tft.drawLine(10, 30, 150, 30, ST7735_CYAN);
tft.setTextColor(ST7735_WHITE);
tft.setTextSize(1);
tft.setCursor(10, 32);  
tft.print("1.Obsluga kratownic");
tft.setCursor(10, 42);
tft.print("2.Rysowanie kratownic");
tft.setCursor(10, 52);
tft.print("3.Test belek");
tft.setCursor(10, 62);
tft.print("4.Test zyroskopow");
while (abc<1){String textForSMS;
textForSMS = textForSMS + "men" + ",";
Serial.println(textForSMS); 
textForSMS = "";
char customKey = customKeypad.getKey();
customKeypad.getKey();
if(customKey=='1'){
tft.setTextColor(ST7735_YELLOW);
tft.setTextSize(1);
tft.setCursor(10, 32);  
tft.print("1.Obsluga kratownic");
tft.setCursor(0, 0); 
delay(500);
tft.setTextColor(ST7735_WHITE);
tft.fillRect(0, 0, 160, 128,ST7735_BLACK );
programobslugi();}
  if(customKey=='2'){
tft.setTextColor(ST7735_YELLOW);
tft.setTextSize(1);
tft.setCursor(10, 42);  
tft.print("2.Rysowanie kratownic"); 
tft.setCursor(0, 0);
delay(500);
tft.setTextColor(ST7735_WHITE);
tft.fillRect(0, 0, 160, 128,ST7735_BLACK );
program1();}
if(customKey=='3'){
tft.setTextColor(ST7735_YELLOW);
tft.setTextSize(1);
tft.setCursor(10, 52);  
tft.print("3.Test belek"); 
tft.setCursor(0, 0);
delay(500);
tft.setTextColor(ST7735_WHITE);
tft.fillRect(0, 0, 160, 128,ST7735_BLACK );
testbelek();}
if(customKey=='4'){
tft.setTextColor(ST7735_YELLOW);
tft.setTextSize(1);
tft.setCursor(10, 62);  
tft.print("4.Test zyroskopow");
tft.setCursor(0, 0); 
delay(500);
tft.setTextColor(ST7735_WHITE);
tft.fillRect(0, 0, 160, 128,ST7735_BLACK );
testzyroskopow();}}}

void testzyroskopow(){
pinMode(22, OUTPUT);
pinMode(24, OUTPUT);
pinMode(26, OUTPUT);
pinMode(28, OUTPUT);
pinMode(30, OUTPUT);
pinMode(32, OUTPUT);
pinMode(34, OUTPUT);
pinMode(36, OUTPUT);
  int AcX,AcY,AcZ,AcX2,AcY2,AcZ2,AcX3,AcY3,AcZ3,AcX4,AcY4,AcZ4,AcX5,AcY5,AcZ5,AcX6,AcY6,AcZ6,AcX7,AcY7,AcZ7,AcX8,AcY8,AcZ8; 
  int ax, ay, kat1, ax2, ay2, ax3, ay3, ax4, ay4, ax5, ay5, ax6, ay6, ax7, ay7, ax8, ay8, kat2, kat3, kat4, kat5, kat6, kat7, kat8;
  MPU6050 mpu;
digitalWrite(22,LOW);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
digitalWrite(22,HIGH);
digitalWrite(24,LOW);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,LOW);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,LOW);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,LOW);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,LOW);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,LOW);
digitalWrite(36,HIGH);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,LOW);
mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G);
while (ax<10000000){ 
digitalWrite(22,LOW);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
delay(20);
tft.drawLine(80, 40, 80+ ax*20/kat1, 40+ ay*20/kat1, ST7735_BLACK);
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
AcX=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
AcY=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
ax=AcX/1000;
ay=AcY/1000;
kat1=sqrt(ax*ax+ay*ay);
tft.drawLine(80, 40, 80+ ax*20/kat1, 40+ ay*20/kat1, ST7735_GREEN);
digitalWrite(22,HIGH);
digitalWrite(24,LOW);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
delay(20);
tft.drawLine(120, 80, 120+ ax2*20/kat2, 80+ ay2*20/kat2, ST7735_BLACK);
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
  AcX2=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY2=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ2=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
ax2=AcX2/1000;
ay2=AcY2/1000;
kat2=sqrt(ax2*ax2+ay2*ay2);
tft.drawLine(120, 80, 120+ ax2*20/kat2, 80+ ay2*20/kat2, ST7735_GREEN);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,LOW);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
delay(20);
tft.drawLine(80, 40, 80+ ax3*20/kat3, 40+ ay3*20/kat3, ST7735_BLACK);
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
AcX3=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
AcY3=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ3=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
ax3=AcX3/1000;
ay3=AcY3/1000;
kat3=sqrt(ax3*ax3+ay3*ay3);
tft.drawLine(120, 80, 120+ ax3*20/kat3, 80+ ay3*20/kat3, ST7735_GREEN);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,LOW);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
delay(20);
tft.drawLine(80, 40, 80+ ax4*20/kat4, 40+ ay4*20/kat4, ST7735_BLACK);
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
AcX4=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
AcY4=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ4=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
ax4=AcX4/1000;
ay4=AcY4/1000;
kat4=sqrt(ax4*ax4+ay4*ay4);
tft.drawLine(120, 80, 120+ ax4*20/kat4, 80+ ay4*20/kat4, ST7735_GREEN);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,LOW);
digitalWrite(32,HIGH);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
delay(20);
tft.drawLine(80, 40, 80+ ax5*20/kat5, 40+ ay5*20/kat5, ST7735_BLACK);
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
AcX5=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
AcY5=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ5=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
ax5=AcX5/1000;
ay5=AcY5/1000;
kat5=sqrt(ax5*ax5+ay5*ay5);
tft.drawLine(120, 80, 120+ ax5*20/kat5, 80+ ay5*20/kat5, ST7735_GREEN);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,LOW);
digitalWrite(34,HIGH);
digitalWrite(36,HIGH);
delay(20);
tft.drawLine(80, 40, 80+ ax6*20/kat6, 40+ ay6*20/kat6, ST7735_BLACK);
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
AcX6=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
AcY6=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ6=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
ax6=AcX6/1000;
ay6=AcY6/1000;
kat6=sqrt(ax6*ax6+ay6*ay6);
tft.drawLine(120, 80, 120+ ax6*20/kat6, 80+ ay6*20/kat6, ST7735_GREEN);
digitalWrite(22,HIGH);
digitalWrite(24,HIGH);
digitalWrite(26,HIGH);
digitalWrite(28,HIGH);  
digitalWrite(30,HIGH);
digitalWrite(32,HIGH);
digitalWrite(34,LOW);
digitalWrite(36,HIGH);
delay(20);
tft.drawLine(80, 40, 80+ ax7*20/kat7, 40+ ay7*20/kat7, ST7735_BLACK);
Wire.begin();
Wire.beginTransmission(MPU_addr);
Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true);  // request a total of 14 registers
AcX7=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
AcY7=Wire.read()<<8|Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
AcZ7=Wire.read()<<8|Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
ax7=AcX7/1000;
ay7=AcY7/1000;
kat7=sqrt(ax7*ax7+ay7*ay7);
tft.drawLine(120, 80, 120+ ax7*20/kat7, 80+ ay7*20/kat7, ST7735_GREEN);
delay(20);
  textForSMS = textForSMS + "zyr" + "," + AcX + "," + AcY + "," + AcZ + "," + AcX2 + "," + AcY2 + "," + AcZ2 + "," + AcX3 + "," + AcY3 + "," + AcZ3 + "," + AcX4 + "," + AcY4 + "," + AcZ4 + "," + AcX5 + "," + AcY5 + "," + AcZ5 + "," + AcX6 + "," + AcY6 + "," + AcZ6 + ",";
Serial.println(textForSMS); 
textForSMS = "";
}}

void testbelek(){int abc=0; 
 tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
tft.setCursor(140, 1);  
tft.print("B1");
tft.setCursor(100, 1);  
tft.print("B2");
tft.setCursor(60, 1);  
tft.print("B3");
while (abc<1){
      
char customKey = customKeypad.getKey();
customKeypad.getKey();
if(customKey=='#'){testbelek2();}
if(customKey=='*'){
tft.fillRect(0, 0, 160, 128,ST7735_BLACK );
menu();}
if(customKey=='0'){scale0.tare();
scale1.tare();
scale2.tare();}  
m=scale0.get_units();
m1=scale1.get_units();
m2=scale2.get_units();
if(100>m and m>0){
tft.setCursor(125, 115);
tft.print("+");  
tft.print(m);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 60, 5, m/2,ST7735_GREEN );
tft.fillRect(140, 60+m/2, 5, 50-m/2,ST7735_RED );
tft.fillRect(140, 10, 5, 50,ST7735_RED );} 
if(-100<m and m<0){
tft.setCursor(125, 115);  
tft.print(m);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 60, 5, 50,ST7735_RED );
tft.fillRect(140, 10, 5, 50+m/2,ST7735_RED );
tft.fillRect(140, 60+m/2, 5, -m/2,ST7735_GREEN );}
if(100<m){
tft.setCursor(125, 115);
tft.print("+");  
tft.print(m);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 60, 5, 50,ST7735_MAGENTA );} 
if(-100>m){
tft.setCursor(125, 115);  
tft.print(m);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 10, 5, 50,ST7735_MAGENTA );}

if(100>m1 and m1>0){
tft.setCursor(80, 115);
tft.print("+");  
tft.print(m1);
tft.fillRect(115, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(100, 60, 5, m1/2,ST7735_GREEN );
tft.fillRect(100, 60+m1/2, 5, 50-m1/2,ST7735_RED );
tft.fillRect(100, 10, 5, 50,ST7735_RED );

} 
if(-100<m1 and m1<0){
tft.setCursor(80, 115);  
tft.print(m1);
tft.fillRect(115, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(100, 60, 5, 50,ST7735_RED );
tft.fillRect(100, 10, 5, 50+m1/2,ST7735_RED );
tft.fillRect(100, 60+m1/2, 5, -m1/2,ST7735_GREEN );
tft.fillRect(95, 10, 5, 100,ST7735_BLACK);
tft.fillRect(105, 10, 5, 100,ST7735_BLACK);}
if(100<m1){
tft.setCursor(80, 115);
tft.print("+");  
tft.print(m1);
tft.fillRect(115, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(100, 60, 5, 50,ST7735_MAGENTA );} 
if(-100>m1){
tft.setCursor(80, 115);  
tft.print(m1);
tft.fillRect(115, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(100, 10, 5, 50,ST7735_MAGENTA );}

if(100>m2 and m2>0){
tft.setCursor(40, 115);
tft.print("+");  
tft.print(m2);
tft.fillRect(75, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(60, 60, 5, m2/2,ST7735_GREEN );
tft.fillRect(60, 60+m2/2, 5, 50-m2/2,ST7735_RED );
tft.fillRect(60, 10, 5, 50,ST7735_RED );

} 
if(-100<m2 and m2<0){
tft.setCursor(40, 115);  
tft.print(m2);
tft.fillRect(75, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(60, 60, 5, 50,ST7735_RED );
tft.fillRect(60, 10, 5, 50+m2/2,ST7735_RED );
tft.fillRect(60, 60+m2/2, 5, -m2/2,ST7735_GREEN );
}
if(100<m2){
tft.setCursor(40, 115);
tft.print("+");  
tft.print(m2);
tft.fillRect(75, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(60, 60, 5, 50,ST7735_MAGENTA );} 
if(-100>m2){
tft.setCursor(40, 115);  
tft.print(m2);
tft.fillRect(75, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(60, 10, 5, 50,ST7735_MAGENTA );}}}



void testbelek2(){
  String textForSMS1; int abc=0; 
 tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
tft.setCursor(140, 1);  
tft.print("B5");
tft.setCursor(100, 1);  
tft.print("B6");
tft.setCursor(60, 1);  
tft.print("B7");
while (abc<1){
      
char customKey = customKeypad.getKey();
customKeypad.getKey();
if(customKey=='#'){testbelek();}
if(customKey=='*'){
tft.fillRect(0, 0, 160, 128,ST7735_BLACK );
menu();}
if(customKey=='0'){scale4.tare();

scale6.tare();}  
m4=scale4.get_units();

m6=scale6.get_units();
if(100>m4 and m4>0){
tft.setCursor(125, 115);
tft.print("+");  
tft.print(m4);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 60, 5, m4/2,ST7735_GREEN );
tft.fillRect(140, 60+m4/2, 5, 50-m4/2,ST7735_RED );
tft.fillRect(140, 10, 5, 50,ST7735_RED );} 
if(-100<m4 and m4<0){
tft.setCursor(125, 115);  
tft.print(m4);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 60, 5, 50,ST7735_RED );
tft.fillRect(140, 10, 5, 50+m4/2,ST7735_RED );
tft.fillRect(140, 60+m4/2, 5, -m4/2,ST7735_GREEN );}
if(100<m4){
tft.setCursor(125, 115);
tft.print("+");  
tft.print(m4);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 60, 5, 50,ST7735_MAGENTA );} 
if(-100>m4){
tft.setCursor(125, 115);  
tft.print(m4);
tft.fillRect(155, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(140, 10, 5, 50,ST7735_MAGENTA );}

if(100>m5 and m5>0){
tft.setCursor(80, 115);
tft.print("+");  
tft.print(m5);
tft.fillRect(115, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(100, 60, 5, m5/2,ST7735_GREEN );
tft.fillRect(100, 60+m5/2, 5, 50-m5/2,ST7735_RED );
tft.fillRect(100, 10, 5, 50,ST7735_RED );

} 
if(-100<m5 and m5<0){
tft.setCursor(80, 115);  
tft.print(m5);
tft.fillRect(115, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(100, 60, 5, 50,ST7735_RED );
tft.fillRect(100, 10, 5, 50+m5/2,ST7735_RED );
tft.fillRect(100, 60+m5/2, 5, -m5/2,ST7735_GREEN );
tft.fillRect(95, 10, 5, 100,ST7735_BLACK);
tft.fillRect(105, 10, 5, 100,ST7735_BLACK);}
if(100<m5){
tft.setCursor(80, 115);
tft.print("+");  
tft.print(m5);
tft.fillRect(115, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(100, 60, 5, 50,ST7735_MAGENTA );} 
if(-100>m5){
tft.setCursor(80, 115);  
tft.print(m5);
tft.fillRect(115, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(100, 10, 5, 50,ST7735_MAGENTA );}

if(100>m6 and m6>0){
tft.setCursor(40, 115);
tft.print("+");  
tft.print(m6);
tft.fillRect(75, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(60, 60, 5, m6/2,ST7735_GREEN );
tft.fillRect(60, 60+m6/2, 5, 50-m6/2,ST7735_RED );
tft.fillRect(60, 10, 5, 50,ST7735_RED );

} 
if(-100<m6 and m6<0){
tft.setCursor(40, 115);  
tft.print(m6);
tft.fillRect(75, 114, 5, 9,ST7735_BLACK );  
tft.fillRect(60, 60, 5, 50,ST7735_RED );
tft.fillRect(60, 10, 5, 50+m6/2,ST7735_RED );
tft.fillRect(60, 60+m6/2, 5, -m6/2,ST7735_GREEN );
}
if(100<m6){
tft.setCursor(40, 115);
tft.print("+");  
tft.print(m6);
tft.fillRect(75, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(60, 60, 5, 50,ST7735_MAGENTA );} 
if(-100>m6){
tft.setCursor(40, 115);  
tft.print(m6);
tft.fillRect(75, 114, 6, 9,ST7735_BLACK );  
tft.fillRect(60, 10, 5, 50,ST7735_MAGENTA );}

textForSMS1 = textForSMS1 + "bel"+ "," + m4 + "," + m5 + ","+ m6 + ",";
Serial.println(textForSMS1); 
textForSMS1 = "";}}

void program1() {
tft.setTextWrap(false);  
int r=30, x=30, s=24, y=24, t=30, u=24, w=0, m=30, n=24, o=0, p=0;
for(int i=0; i<89; i++){ab=0;
tft.print("pret ");
tft.println(i+1);
while (ab<1){
char customKey = customKeypad.getKey();
  if(customKey=='1')
  {prety[i]=1; 
  tft.print("pret ");
  tft.print(i+1);
  tft.println(" wystepuje");
  delay(500);ab++;
  tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
  tft.setCursor(0, 0);
  if(x<125){
    tft.drawLine(x, y, x+20, y, ST7735_CYAN);x=x+20;}
    if(x>125 and y<85) {
      y=y+20;
      x=30;} if(y>85){p++;}
     if(y>85 and p>6) {if (r<131) {tft.drawLine(r, s, r, s+20, ST7735_CYAN);r=r+20;} 
  }if (r>131 and s<83) {s=s+20; r=30;}if(s>83){w++;}if(s>83 and w>7) {if (t<125) {tft.drawLine(t, u, t+20, u+20, ST7735_CYAN);t=t+20;} 
  }if (t>125 and u<83) {u=u+20; t=30;}if(u>83){o++;}if(u>83 and o>6) {if (m<125) {tft.drawLine(m+20, n, m, n+20, ST7735_CYAN);m=m+20;} 
  }if (m>125 and n<83) {n=n+20; m=30;}}
  if(customKey=='0')
  {prety[i]=0; 
  tft.print("brak preta ");
  tft.println(i+1);
  delay(500);ab++;
  tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
  tft.setCursor(0, 0);
  if(x<125){
    x=x+20;}
    if(x>125 and y<85) {
      y=y+20;
      x=30;} if(y>85){p++;}
     if(y>85 and p>6) {if (r<131) {r=r+20;} 
  }if (r>131 and s<83) {s=s+20; r=30;}if(s>83){w++;}if(s>83 and w>7) {if (t<125) {t=t+20;} 
  }if (t>125 and u<83) {u=u+20; t=30;}if(u>83){o++;}if(u>83 and o>6) {if (m<125) {m=m+20;} 
  }if (m>125 and n<83) {n=n+20; m=30;}}}}program2();}
void program2(){int g=24, f=30, p=0;
tft.setCursor(0, 0);
tft.print("zbieranie sil z kratownicy");
delay(1000);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK ); 

int kl=0;
for (int b=0; b<30;) {
tft.setCursor(0, 0);
tft.print(" sila na wezle ");
tft.println(b+1);
kl=b*8;

p=0;
while (p<1){char customKey = customKeypad.getKey();
if (customKey=='7'){
tft.print("wystepuje sila na wezle ");
tft.print(b+1);
tft.print("    ");
tft.print("indeks #");
tft.print(kl); 
delay(500); 
tft.drawLine(f-20, g+20, f, g, ST7735_GREEN);
tft.drawLine(f-5, g+2, f, g, ST7735_GREEN);
tft.drawLine(f-2, g+5, f, g, ST7735_GREEN);
f=f+20;
sily[kl]=1;
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
p++;
}
if (customKey=='4'){kl=kl+1;
  tft.print("wystepuje sila na wezle ");
tft.print(b+1);
tft.print("    ");
tft.print("indeks #");
tft.print(kl); 
delay(500); 
tft.drawLine(f-20, g, f, g, ST7735_GREEN);
tft.drawLine(f-5, g-3, f, g, ST7735_GREEN);
tft.drawLine(f-5, g+3, f, g, ST7735_GREEN);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
sily[kl]=1;
p++;}
if (customKey=='1'){kl=kl+2;
  tft.print("wystepuje sila na wezle ");
tft.print(b+1);
tft.print("    ");
tft.print("indeks #");
tft.print(kl); 
delay(500); 
tft.drawLine(f-20, g-20, f, g, ST7735_GREEN);
tft.drawLine(f-2, g-5, f, g, ST7735_GREEN);
tft.drawLine(f-5, g-2, f, g, ST7735_GREEN);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
sily[kl]=1;
p++;}
if (customKey=='2'){kl=kl+3;
  tft.print("wystepuje sila na wezle ");
tft.print(b+1);
tft.print("    ");
tft.print("indeks #");
tft.print(kl); 
delay(500); 
tft.drawLine(f, g-20, f, g, ST7735_GREEN);
tft.drawLine(f-3, g-5, f, g, ST7735_GREEN);
tft.drawLine(f+3, g-5, f, g, ST7735_GREEN);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
sily[kl]=1;
p++;}
if (customKey=='3'){kl=kl+4;
  tft.print("wystepuje sila na wezle ");
tft.print(b+1);
tft.print("    ");
tft.print("indeks #");
tft.print(kl); 
delay(500); 
tft.drawLine(f+20, g-20, f, g, ST7735_GREEN);
tft.drawLine(f+2, g-5, f, g, ST7735_GREEN);
tft.drawLine(f+5, g-2, f, g, ST7735_GREEN);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
sily[kl]=1;
p++;}
if (customKey=='6'){kl=kl+5;
  tft.print("wystepuje sila na wezle ");
tft.print(b+1);
tft.print("    ");
tft.print("indeks #");
tft.print(kl); 
delay(500); 
tft.drawLine(f+20, g, f, g, ST7735_GREEN);
tft.drawLine(f+5, g-2, f, g, ST7735_GREEN);
tft.drawLine(f+5, g+2, f, g, ST7735_GREEN);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
sily[kl]=1;
p++;}
if (customKey=='9'){kl=kl+6;
  tft.print("wystepuje sila na wezle ");
tft.print(b+1); 
tft.print("    ");
tft.print("indeks #");
tft.print(kl);
delay(500); 
tft.drawLine(f+20, g+20, f, g, ST7735_GREEN);
tft.drawLine(f+5, g+2, f, g, ST7735_GREEN);
tft.drawLine(f+2, g+5, f, g, ST7735_GREEN);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
sily[kl]=1;
p++;}
if (customKey=='8'){kl=kl+7;
  tft.print("wystepuje sila na wezle ");
tft.print(b+1);
tft.print("    ");
tft.print("indeks #");
tft.print(kl); 
delay(500); 
tft.drawLine(f, g+20, f, g, ST7735_GREEN);
tft.drawLine(f-3, g+5, f, g, ST7735_GREEN);
tft.drawLine(f+3, g+5, f, g, ST7735_GREEN);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
sily[kl]=1;
p++;}
if (customKey=='5'){
  tft.print("brak sily w wezle ");
tft.print(b+1); 
delay(500);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
f=f+20;
p++;}
if(f>135){f=30; g=g+20;}

  }b++;} program5();}
  void program3(){int i=0;
    tft.setCursor(8, 0);
tft.print("wpisywanie wspolczynnikow pretow");
delay(1500);
tft.fillRoundRect(0, 0, 160, 16, 5,ST7735_BLACK );
for(int z=0; z<89; z++){
if (prety[z]==1){  

if( i<89){wsppreta[z]=0;
tft.setCursor(8, 8);
tft.print(" wspolczynnik preta "); 
tft.print(z+1);
tft.setCursor(8, 16);
tft.print(wsppreta[z]);  
int h=0;
while(h<1){ char customKey = customKeypad.getKey();
if(customKey=='1'){wsppreta[z]=wsppreta[z]+1;
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
tft.setCursor(8, 16);
tft.print(wsppreta[z]);
delay(200);
}
if(customKey=='2'){wsppreta[z]=wsppreta[z]-1;
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
tft.setCursor(8, 16);
tft.print(wsppreta[z]);
delay(200);
  }
  if(customKey=='3'){wsppreta[z]=wsppreta[z]+0.1;
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
tft.setCursor(8, 16);
tft.print(wsppreta[z]);
delay(200);
}
if(customKey=='4'){wsppreta[z]=wsppreta[z]-0.1;
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
tft.setCursor(8, 16);
tft.print(wsppreta[z]);
delay(200);
}
  if(customKey=='5'){wsppreta[z]=wsppreta[z]+0.01;
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
tft.setCursor(8, 16);
tft.print(wsppreta[z]);
delay(200);
}
if(customKey=='6'){wsppreta[z]=wsppreta[z]-0.01;
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
tft.setCursor(8, 16);
tft.print(wsppreta[z]);
delay(200);
}
if(customKey=='0'){
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
tft.fillRoundRect(120, 8, 24, 8, 5,ST7735_BLACK );
tft.setCursor(64, 16);
tft.print("zapisano pret");
delay(500);
tft.fillRoundRect(0, 16, 160, 8, 5,ST7735_BLACK );
h=h+1;
}}i++;}}
if (prety[z]==0){}}
tft.setCursor(8, 0);
tft.setTextSize(1);
tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
tft.println("zakonczono kalibracje!");
delay(2000);
tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
program4();}

void program5() {int qwe=0,qwt=0, ef=30, fg=24, alb=0;
tft.setCursor(0, 0);
tft.println("rysowanie podpor"); 
delay(1000);
  for(int xyz=0; xyz<30; xyz++){
  alb=xyz*4; 
  qwe=0;

tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK ); 
tft.setCursor(0, 0);
tft.print("czy na wezle ");
tft.println(xyz+1);
tft.print("znajduje sie podpora?"); 
while(qwe<1){char customKey = customKeypad.getKey();
if(customKey=='1'){
tft.setCursor(0, 0);
tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
tft.print("na wezle ");
tft.print(xyz+1);
tft.println(" jest podpora");
delay(500);
tft.setCursor(0, 0);
tft.print("wybierz ulozenie podpory");
delay(500); 
qwt=0;
while (qwt<1){char customKey = customKeypad.getKey();
 if(customKey=='8'){
  tft.setCursor(0, 0); 
  tft.print("wybrano ulozenie 1       ");
  delay(500);
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  tft.setCursor(0, 0);
  tft.print("prosze wybrac rodzaj");
  delay(500);
  while (qwt<1){char customKey = customKeypad.getKey();
  if(customKey=='1'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa npr");
  tft.drawLine(ef-5, fg+5, ef, fg, ST7735_GREEN);
  tft.drawLine(ef, fg, ef+5, fg+5, ST7735_GREEN);
  tft.drawLine(ef-5, fg+5, ef+5, fg+5, ST7735_GREEN);
  podpory[alb]=1;
  delay(500);
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='2'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa pr");
  tft.drawLine(ef-5, fg+5, ef, fg, ST7735_GREEN);
  tft.drawLine(ef, fg, ef+5, fg+5, ST7735_GREEN);
  tft.drawLine(ef-5, fg+5, ef+5, fg+5, ST7735_GREEN);
  tft.drawLine(ef-6, fg+7, ef+6, fg+7, ST7735_GREEN);
  delay(500);
  alb=alb+1;
  podpory[alb]=2;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='3'){
  tft.setCursor(0, 8);
  tft.print("usztywnienie");
  tft.drawLine(ef-4, fg, ef+5, fg+5, ST7735_GREEN);
  tft.drawLine(ef-2, fg, ef+4, fg+4, ST7735_GREEN);
  tft.drawLine(ef+1, fg, ef-1, fg+4, ST7735_GREEN);
  tft.drawLine(ef+4, fg, ef+1, fg+4, ST7735_GREEN);
  delay(500);
  alb=alb+1;
  podpory[alb]=3;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='4'){
  tft.setCursor(0, 8);
  tft.print("lyzwa");
  tft.drawLine(ef-4, fg, ef+4, fg, ST7735_GREEN);
  tft.drawLine(ef-4, fg+2, ef+4, fg+2, ST7735_GREEN);
  tft.drawLine(ef+1, fg+2, ef-1, fg+6, ST7735_GREEN);
  tft.drawLine(ef-2, fg+2, ef-4, fg+6, ST7735_GREEN);
  tft.drawLine(ef+4, fg+2, ef+1, fg+6, ST7735_GREEN);
  delay(500);
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  alb=alb+1;
  podpory[alb]=4;
  qwe++;
  qwt++;}}}
  if(customKey=='4'){
  tft.setCursor(0, 0); 
  tft.print("wybrano ulozenie 2       ");
  delay(500);
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  tft.setCursor(0, 0);
  tft.print("prosze wybrac rodzaj");
  delay(500);
  while (qwt<1){char customKey = customKeypad.getKey();
  if(customKey=='1'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa npr");
  tft.drawLine(ef-5, fg-5, ef, fg, ST7735_GREEN);
  tft.drawLine(ef-5, fg-5, ef-5, fg+5, ST7735_GREEN);
  tft.drawLine(ef-5, fg+5, ef, fg, ST7735_GREEN);
  delay(500);
  alb=alb+2;
  podpory[alb]=1;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='2'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa pr");
  tft.drawLine(ef-5, fg-5, ef, fg, ST7735_GREEN);
  tft.drawLine(ef-5, fg-5, ef-5, fg+5, ST7735_GREEN);
  tft.drawLine(ef-5, fg+5, ef, fg, ST7735_GREEN);
  tft.drawLine(ef-7, fg-7, ef+7, fg-7, ST7735_GREEN);
  delay(500);
  alb=alb+2;
  podpory[alb]=2;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='3'){
  tft.setCursor(0, 8);
  tft.print("usztywnienie");
  tft.drawLine(ef, fg-4, ef, fg+4, ST7735_GREEN);
  tft.drawLine(ef, fg-2, ef-4, fg-4, ST7735_GREEN);
  tft.drawLine(ef, fg+1, ef-4, fg-1, ST7735_GREEN);
  tft.drawLine(ef, fg+4, ef-4, fg+2, ST7735_GREEN);
  delay(500);
  alb=alb+2;
  podpory[alb]=3;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='4'){
  tft.setCursor(0, 8);
  tft.print("lyzwa");
  delay(500);
  alb=alb+2;
  podpory[alb]=4;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}}}
  if(customKey=='2'){
  tft.setCursor(0, 0); 
  tft.print("wybrano ulozenie 3       ");
  delay(500);
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  tft.setCursor(0, 0);
  tft.print("prosze wybrac rodzaj");
  delay(500);
  while (qwt<1){char customKey = customKeypad.getKey();
  if(customKey=='1'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa npr");
  delay(500);
  alb=alb+3;
  podpory[alb]=1;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='2'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa pr");
  delay(500);
  alb=alb+3;
  podpory[alb]=2;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='3'){
  tft.setCursor(0, 8);
  tft.print("usztywnienie");
  delay(500);
  alb=alb+3;
  podpory[alb]=3;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='4'){
  tft.setCursor(0, 8);
  tft.print("lyzwa");
  alb=alb+3;
  podpory[alb]=4;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}}}
  if(customKey=='6'){
  tft.setCursor(0, 0); 
  tft.print("wybrano ulozenie 4      ");
  delay(500);
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  tft.setCursor(0, 0);
  tft.print("prosze wybrac rodzaj");
  delay(500);
  while (qwt<1){char customKey = customKeypad.getKey();
  if(customKey=='1'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa npr");
  delay(500);
  alb=alb+4;
  podpory[alb]=1;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='2'){
  tft.setCursor(0, 8);
  tft.print("podpora przegubowa pr");
  delay(500);
  alb=alb+4;
  podpory[alb]=2;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='3'){
  tft.setCursor(0, 8);
  tft.print("usztywnienie");
  delay(500);
  alb=alb+4;
  podpory[alb]=3;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}
  if(customKey=='4'){
  tft.setCursor(0, 8);
  tft.print("lyzwa");
  delay(500);
  alb=alb+4;
  podpory[alb]=4;
  tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
  qwe++;
  qwt++;}}}}}

if(customKey=='5'){
tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
tft.setCursor(0, 0);
tft.print("na wezle ");
tft.print(xyz+1);
tft.print(" nie ma podpory");
delay(500);
tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
qwe++;
qwt++;} 

if(ef>135){ef=30; fg=fg+20;}
}ef=ef+20;}
  
program3();}















void program4(){
tft.setCursor(0, 0);
tft.println("dzialanie belki");
delay(2000);
tft.fillRoundRect(0, 0, 160, 20, 5,ST7735_BLACK );
while (ab<100000){
char customKey = customKeypad.getKey();
customKeypad.getKey();
if(customKey=='1'){tft.fillRoundRect(0, 0, 160, 128, 5,ST7735_BLACK ); menu();}  
m=scale0.get_units();
m=m*9.98/1000;

int qwe=0;
for(int qw=0; qw<89;qw++){
if(prety[qw]==1){
if(m*wsppreta[qw]>=0){tft.setTextColor(ST7735_GREEN, ST7735_BLACK);}
if(m*wsppreta[qw]<0){tft.setTextColor(ST7735_RED, ST7735_BLACK);}  
tft.setCursor(0,qwe*8);
tft.print("B");
tft.print(qw);
tft.print(":");
tft.setCursor(131,qwe*8);
tft.setTextSize(0);
if(m*wsppreta[qw]>=0){tft.setTextColor(ST7735_GREEN, ST7735_BLACK);
tft.print(" ");
tft.setCursor(137,qwe*8);}
if(m*wsppreta[qw]<0){tft.setTextColor(ST7735_RED, ST7735_BLACK);}
tft.print(m*wsppreta[qw]);qwe++;}
if(prety[qw]==0){}

}
}}




void programobslugi(){ 



tft.setRotation(1);

tft.fillScreen(ST7735_BLACK);
tft.setTextWrap(true);
tft.setCursor(10, 0);
tft.setTextColor(ST7735_WHITE);
tft.setTextSize(2);
tft.println("prezentacje");
tft.setCursor(10, 30);
tft.setTextColor(ST7735_WHITE);
tft.println("kratownic");
tft.setFont();
delay(1000);
tft.fillScreen(ST7735_BLACK);
menu1();}
void menu1(){String textForSMS;
textForSMS = textForSMS + "men" + ",";
Serial.println(textForSMS); 
textForSMS = "";
float  m;
float g;
int o=0;
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_WHITE);
tft.println("1.program");
tft.setCursor(10, 60);
tft.println("2.program");
while (o<10) {char customKey = customKeypad.getKey();
  customKeypad.getKey();
if(customKey=='*'){tft.fillScreen(ST7735_BLACK); menu();}  
if(customKey=='1'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_YELLOW);
tft.println("1.program");  
delay(1500);
kratownica1();}
if(customKey=='2'){
tft.setTextSize(1);
tft.setCursor(10, 60);
tft.setTextColor(ST7735_YELLOW);
tft.println("2.program");
delay(1500);
kratownica2();}
if(customKey=='3'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
tft.println("wybrano numer 3");  
delay(1500);}
if(customKey=='4'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
tft.println("wybrano numer 4");
delay(1500);}
if(customKey=='5'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
tft.println("wybrano numer 5");
delay(1500);}
if(customKey=='6'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
tft.println("wybrano numer 6");
delay(1500);}
if(customKey=='7'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
tft.println("wybrano numer 7");
delay(1500);}
if(customKey=='8'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
tft.println("wybrano numer 8");
delay(1500);}
if(customKey=='9'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
tft.println("wybrano numer 9");
delay(1500);}
if(customKey=='0'){
tft.setTextSize(1);
tft.setCursor(10, 50);
tft.setTextColor(ST7735_RED);
menu();}
}}
void kratownica1() {float  m;
float g;
int o=0;
char customKey = customKeypad.getKey();
customKeypad.getKey();
if(customKey=='*'){tft.fillScreen(ST7735_BLACK); delay(500); menu();}
  tft.fillScreen(ST7735_BLACK);
  tft.drawLine(80, 100, 80, 50, ST7735_WHITE);
  tft.drawLine(80, 50, 80, 20, ST7735_GREEN);
  tft.drawLine(80, 50, 70, 40, ST7735_GREEN);
  tft.drawLine(80, 50, 90, 40, ST7735_GREEN);
  tft.drawLine(30, 100, 35, 105, ST7735_MAGENTA);
  tft.drawLine(25, 105, 35, 105, ST7735_MAGENTA);
  tft.drawLine(25, 105, 30, 100, ST7735_MAGENTA);
  tft.drawLine(130, 100, 135, 105, ST7735_MAGENTA);
  tft.drawLine(125, 105, 135, 105, ST7735_MAGENTA);
  tft.drawLine(125, 105, 130, 100, ST7735_MAGENTA);
  tft.drawLine(123, 108, 137, 108, ST7735_MAGENTA);
  while(o<10) {char customKey = customKeypad.getKey();
customKeypad.getKey();
if(customKey=='*'){tft.fillScreen(ST7735_BLACK); delay(500); menu();}
  m=scale0.get_units();
  if(m>0 and m<256)
  {g=9.98*m/1000;
  tft.drawLine(30, 100, 130, 100, ST7735_BLUE);
  tft.drawLine(30, 100, 80, 50, ST7735_RED);
  tft.drawLine(130, 100, 80, 50, ST7735_RED);
  tft.setTextColor(ST7735_GREEN, ST7735_BLACK);
  tft.setCursor(30,30);
  tft.println(g);
  tft.setCursor(55,30);
  tft.println("N");
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setTextSize(0);
  tft.setCursor(5,75);
  tft.println(g/2*1.41);
  tft.setCursor(30,75);
  tft.println("N");
  tft.setCursor(120,75);
  tft.println(g/2*1.41);
  tft.setCursor(145,75);
  tft.println("N");
  tft.setTextColor(ST7735_MAGENTA, ST7735_BLACK);
  tft.setCursor(15,115);
  tft.println(g/2);
  tft.setCursor(40,115);
  tft.println("N");
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(65,105);
  tft.println(g/2);
  tft.setCursor(90,105);
  tft.println("N");
  tft.setTextColor(ST7735_MAGENTA, ST7735_BLACK);
  tft.setCursor(115,115);
  tft.println(g/2);
  tft.setCursor(140,115);
  tft.println("N");
  leds[0] = CRGB(m, 0, 0);
  leds[1] = CRGB(m, 0, 0);
  leds[2] = CRGB(m, 0, 0);
  leds[3] = CRGB(m, 0, 0);
  leds[4] = CRGB(m, 0, 0);
  leds[5] = CRGB(0, m, 0);
  leds[6] = CRGB(0, m, 0);
  leds[7] = CRGB(0, m, 0);
  leds[8] = CRGB(0, m/10, 0);
  leds[9] = CRGB(0, m/10, 0);
  leds[10] = CRGB(0, m/10, 0);
  FastLED.show();
  delay (50);
  leds[0] = CRGB(0, 0, 0);
  leds[1] = CRGB(0, 0, 0);
  leds[2] = CRGB(0, 0, 0);
  leds[3] = CRGB(0, 0, 0);
  leds[4] = CRGB(0, 0, 0);
  leds[5] = CRGB(0, 0, 0);
  leds[6] = CRGB(0, 0, 0);
  leds[7] = CRGB(0, 0, 0);
  leds[8] = CRGB(0, 0, 0);
  leds[9] = CRGB(0, 0, 0);
  leds[10] = CRGB(0, 0, 0);
  if(customKey=='*'){tft.fillScreen(ST7735_BLACK); delay(500); menu();}}
  if(m<0 and m>-256)
  {m=-m;
  g=9.98*m/1000;
     tft.drawLine(30, 100, 130, 100, ST7735_RED);
   tft.drawLine(30, 100, 80, 50, ST7735_BLUE);
   tft.drawLine(130, 100, 80, 50, ST7735_BLUE);
   tft.drawLine(80, 100, 80, 50, ST7735_WHITE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.drawLine(80, 50, 80, 20, ST7735_GREEN);
  tft.setTextSize(0);
  tft.setCursor(5,75);
  tft.println(g/2*1.41);
  tft.setCursor(30,75);
  tft.println("N");
  tft.setCursor(120,75);
  tft.println(g/2*1.41);
  tft.setCursor(145,75);
  tft.println("N");
   tft.setTextColor(ST7735_GREEN, ST7735_BLACK);
  tft.setCursor(30,30);
  tft.println(g);
  tft.setCursor(55,30);
  tft.println("N");
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(65,105);
  tft.println(g/2);
  tft.setCursor(90,105);
  tft.println("N");
  tft.setTextColor(ST7735_MAGENTA, ST7735_BLACK);
  tft.setCursor(115,115);
  tft.println(g/2);
  tft.setCursor(140,115);
  tft.println("N");
  tft.setCursor(15,115);
  tft.println(g/2);
  tft.setCursor(40,115);
  tft.println("N");
  leds[0] = CRGB(0, m, 0);
  leds[1] = CRGB(0, m, 0);
  leds[2] = CRGB(0, m, 0);
  leds[3] = CRGB(0, m, 0);
  leds[4] = CRGB(0, m, 0);
  leds[5] = CRGB(m, 0, 0);
  leds[6] = CRGB(m, 0, 0);
  leds[7] = CRGB(m, 0, 0);
  leds[8] = CRGB(m/10, 0, 0);
  leds[9] = CRGB(m/10, 0, 0);
  leds[10] = CRGB(m/10, 0, 0);
  FastLED.show();
  delay (50);
  leds[0] = CRGB(0, 0, 0);
  leds[1] = CRGB(0, 0, 0);
  leds[2] = CRGB(0, 0, 0);
  leds[3] = CRGB(0, 0, 0);
  leds[4] = CRGB(0, 0, 0);
  leds[5] = CRGB(0, 0, 0);
  leds[6] = CRGB(0, 0, 0);
  leds[7] = CRGB(0, 0, 0);
  leds[8] = CRGB(0, 0, 0);
  leds[9] = CRGB(0, 0, 0);
  leds[10] = CRGB(0, 0, 0);
  if(customKey=='*'){tft.fillScreen(ST7735_BLACK); delay(500); menu();}}
  if (m>256)
  { if(customKey=='*'){tft.fillScreen(ST7735_BLACK); delay(500); menu();}
  g=9.98*m/1000;
  tft.drawLine(30, 100, 130, 100, ST7735_BLUE);
  tft.drawLine(30, 100, 80, 50, ST7735_RED);
  tft.drawLine(130, 100, 80, 50, ST7735_RED);
  tft.setTextColor(ST7735_GREEN, ST7735_BLACK);
  tft.setCursor(30,30);
  tft.println(g);
  tft.setCursor(55,30);
  tft.println("N");
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setTextSize(0);
  tft.setCursor(5,75);
  tft.println(g/2*1.41);
  tft.setCursor(30,75);
  tft.println("N");
  tft.setCursor(120,75);
  tft.println(g/2*1.41);
  tft.setCursor(145,75);
  tft.println("N");
  tft.setTextColor(ST7735_MAGENTA, ST7735_BLACK);
  tft.setCursor(15,115);
  tft.println(g/2);
  tft.setCursor(40,115);
  tft.println("N");
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(65,105);
  tft.println(g/2);
  tft.setCursor(90,105);
  tft.println("N");
  tft.setTextColor(ST7735_MAGENTA, ST7735_BLACK);
  tft.setCursor(115,115);
  tft.println(g/2);
  tft.setCursor(140,115);
  tft.println("N");
  leds[0] = CRGB(0, 0, 255);
  leds[1] = CRGB(0, 0, 255);
  leds[2] = CRGB(0, 0, 255);
  leds[3] = CRGB(0, 0, 255);
  leds[4] = CRGB(0, 0, 255);
  leds[5] = CRGB(0, 0, 255);
  leds[6] = CRGB(0, 0, 255);
  leds[7] = CRGB(0, 0, 255);
  leds[8] = CRGB(0, 0, 255);
  leds[9] = CRGB(0, 0, 255);
  leds[10] = CRGB(0, 0, 255);
  FastLED.show();
 }
    if (m<-256)
  {if(customKey=='*'){tft.fillScreen(ST7735_BLACK); delay(500); menu();}
  m=-m;
  g=9.98*m/1000;
   tft.drawLine(30, 100, 130, 100, ST7735_RED);
   tft.drawLine(30, 100, 80, 50, ST7735_BLUE);
   tft.drawLine(130, 100, 80, 50, ST7735_BLUE);
   tft.drawLine(80, 100, 80, 50, ST7735_WHITE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.drawLine(80, 50, 80, 20, ST7735_GREEN);
  tft.setTextSize(0);
  tft.setCursor(5,75);
  tft.println(g/2*1.41);
  tft.setCursor(30,75);
  tft.println("N");
  tft.setCursor(120,75);
  tft.println(g/2*1.41);
  tft.setCursor(145,75);
  tft.println("N");
   tft.setTextColor(ST7735_GREEN, ST7735_BLACK);
  tft.setCursor(30,30);
  tft.println(g);
  tft.setCursor(55,30);
  tft.println("N");
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(65,105);
  tft.println(g/2);
  tft.setCursor(90,105);
  tft.println("N");
  tft.setTextColor(ST7735_MAGENTA, ST7735_BLACK);
  tft.setCursor(115,115);
  tft.println(g/2);
  tft.setCursor(140,115);
  tft.println("N");
  tft.setCursor(15,115);
  tft.println(g/2);
  tft.setCursor(40,115);
  tft.println("N");
  leds[0] = CRGB(0, 0, 255);
  leds[1] = CRGB(0, 0, 255);
  leds[2] = CRGB(0, 0, 255);
  leds[3] = CRGB(0, 0, 255);
  leds[4] = CRGB(0, 0, 255);
  leds[5] = CRGB(0, 0, 255);
  leds[6] = CRGB(0, 0, 255);
  leds[7] = CRGB(0, 0, 255);
  leds[8] = CRGB(0, 0, 255);
  leds[9] = CRGB(0, 0, 255);
  leds[10] = CRGB(0, 0, 255);
  FastLED.show();
  delay (50);
  leds[0] = CRGB(0, 0, 0);
  leds[1] = CRGB(0, 0, 0);
  leds[2] = CRGB(0, 0, 0);
  leds[3] = CRGB(0, 0, 0);
  leds[4] = CRGB(0, 0, 0);
  leds[5] = CRGB(0, 0, 0);
  leds[6] = CRGB(0, 0, 0);
  leds[7] = CRGB(0, 0, 0);
  leds[8] = CRGB(0, 0, 0);
  leds[9] = CRGB(0, 0, 0);
  leds[10] = CRGB(0, 0, 0);}

}
}
void kratownica2(){int poda=0, podb=0, a=0, pa=0, pb=0, pc=0, pd=0, pe=0, pf=0, pg=0, ph=0, pi=0, pj=0, pk=0, pl=0, pm=0, pn=0, po=0, pp=0, pr=0;
int  m, x1=0, x2=0, x3=0, x4=0, x5=0, x6=0, x7=0, x8=0, mnoznikklawiatury, czerwonywys, niebieskiwys, tryb;
int bezwladnosc;
float g;
float mnoznik;
mnoznik=0.2;
mnoznikklawiatury=1;
czerwonywys=1;
niebieskiwys=1;
int o=0, b, c;
int belkit[7];
bezwladnosc =2;
for(int a=0; a<1; a++){
tft.fillScreen(ST7735_BLACK);  
tft.setTextColor(ST7735_RED, ST7735_BLACK);
tft.setCursor(10,10);  
tft.print("Jaki tryb pracy wybrać? ");
b=0;
FastLED.setBrightness(60);
scale0.tare();
scale1.tare();
scale2.tare();
scale3.tare();
scale4.tare();
scale5.tare();
scale6.tare();
scale7.tare();
while(b<1){
char customKey = customKeypad.getKey();
customKeypad.getKey();
if(customKey=='0'){
belkit[0]=1;
belkit[1]=1;
belkit[2]=1;
belkit[3]=1;
belkit[4]=1;
belkit[5]=1;
belkit[6]=1;
belkit[7]=1;
tryb=1;
tft.setCursor(10,20);
tft.print("wybrano tryb pełnych danych");
delay(2000);
b=1;}
if(customKey=='1'){
belkit[0]=1;
belkit[1]=1;
belkit[2]=0;
belkit[3]=0;
belkit[4]=0;
belkit[5]=0;
belkit[6]=0;
belkit[7]=0;
tryb=2;
tft.setCursor(10,20);
tft.print("Wybrano tryb sił 1,2 ");
delay(1000);
b=1;}
if(customKey=='2'){
belkit[3]=1;
belkit[4]=1;
belkit[5]=1;
tryb=3;
tft.setCursor(10,20);
tft.print("Wybrano tryb sił 4,5,6 ");
delay(1000);
b=1;}
if(customKey=='3'){
belkit[6]=1;
belkit[7]=1;
tryb=4;
tft.setCursor(10,20);
tft.print("Wybrano tryb sił 7,8 ");
delay(1000);
b=1;}
if(customKey=='4'){
belkit[0]=1;
belkit[1]=1;
belkit[2]=1;
belkit[3]=0;
belkit[4]=0;
belkit[5]=0;
belkit[6]=1;
belkit[7]=1;
tryb=5;
tft.setCursor(10,20);
tft.print("Wybrano tryb sił 1,2,3,7,8 ");
delay(1000);
b=1;}
if(customKey=='5'){
belkit[0]=0;
belkit[1]=0;
belkit[2]=0;
belkit[3]=1;
belkit[4]=1;
belkit[5]=1;
belkit[6]=1;
belkit[7]=1;
tryb=6;
tft.setCursor(10,20);
tft.print("Wybrano tryb sił 4,5,6,7,8 ");
delay(1000);
b=1;}
if(customKey=='6'){
belkit[0]=1;
belkit[1]=1;
belkit[2]=1;
belkit[3]=1;
belkit[4]=1;
belkit[5]=1;
belkit[6]=0;
belkit[7]=0;
tryb=7;
tft.setCursor(10,20);
tft.print("Wybrano tryb sił 1,2,3,4,5,6 ");
delay(1000);
b=1;}
if(customKey=='7'){
belkit[0]=1;
belkit[1]=0;
belkit[2]=0;
belkit[3]=0;
belkit[4]=0;
belkit[5]=0;
belkit[6]=0;
belkit[7]=0;
tryb=8;
tft.setCursor(10,20);
tft.print("Wybrano tryb siły 1 ");
delay(1000);
b=1;}}
b=0;
tft.fillScreen(ST7735_BLACK);}

  tft.fillScreen(ST7735_BLACK);
  tft.drawLine(10, 40, 10, 75, ST7735_WHITE);
  tft.drawLine(10, 40, 45, 40, ST7735_WHITE);
  tft.drawLine(80, 40, 80, 75, ST7735_WHITE);
  tft.drawLine(150, 40, 150, 75, ST7735_WHITE);
  tft.drawLine(115, 40, 150, 40, ST7735_WHITE);
 FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
  while(o<10) {delay(200);
char customKey = customKeypad.getKey();
customKeypad.getKey();
 
if(customKey=='*'){tft.fillScreen(ST7735_BLACK);
delay(500); menu1();}
if(customKey=='1'){
mnoznikklawiatury=mnoznikklawiatury+1;}
if(customKey=='2'){
czerwonywys=czerwonywys+1;}
if(customKey=='3'){
niebieskiwys=niebieskiwys+1;}
if(mnoznikklawiatury==4){
mnoznikklawiatury=1;}
if(czerwonywys==6){
czerwonywys=1;}
if(niebieskiwys==6){
niebieskiwys=1;}
if(belkit[0]==1){
x1=scale0.get_units();}
if(belkit[0]==0){
x1=0;}
if(belkit[1]==1){
x2=scale1.get_units();}
if(belkit[1]==0){
x2=0;}
if(belkit[2]==1){
x3=scale2.get_units();}
if(belkit[2]==0){
x3=0;}
if(belkit[3]==1){
x4=scale3.get_units();}
if(belkit[3]==0){
x4=0;}
if(belkit[4]==1){
x5=scale4.get_units();}
if(belkit[4]==0){
x5=0;}
if(belkit[5]==1){
x6=scale5.get_units();}
if(belkit[5]==0){
x6=0;}
if(belkit[6]==1){
x7=scale6.get_units();}
if(belkit[6]==0){
x7=0;}
if(belkit[7]==1){
x8=scale7.get_units();}
if(belkit[7]==0){
x8=0;}

poda=0.75*x1+0.5*x2+0.25*x3+0.75*x4+0.5*x5+0.75*x6-0.25*x7+0.25*x8;
podb=0.25*x1+0.5*x2+0.75*x3+0.25*x4+0.5*x5+0.25*x6+0.25*x7-0.25*x8;
pa=0.75*x1+0.5*x2+0.25*x3+0.75*x4+0.5*x5+0.25*x6-0.75*x7+0.75*x8;
pb=0;
pc=-1.060*x1-0.707*x2-0.3536*x3-1.0607*x4-0.707*x5-0.3536*x6-0.3536*x7+0.3536*x8;
pd=x7;
pe=-0.25*x1+0.5*x2+0.25*x3+0.75*x4+0.5*x5+0.25*x6+0.25*x7-0.25*x8;
pf=0.353*x1-0.707*x2-0.3536*x3+0.3536*x4-0.707*x5-0.3536*x6-0.3536*x7+0.3536*x8;
pg=-0.75*x1-0.5*x2-0.25*x3-0.75*x4-0.5*x5-0.25*x6+0.75*x7+0.25*x8;
ph=x5;
pi=-0.353*x1-0.707*x2+0.3536*x3-0.3536*x4-0.707*x5+0.3536*x6+0.3536*x7-0.3536*x8;
pj=-0.25*x1-0.5*x2-0.75*x3-0.25*x4-0.5*x5-0.75*x6+0.25*x7+0.75*x8;
pk=0.25*x1+0.5*x2-0.25*x3+0.25*x4+0.5*x5+0.75*x6-0.25*x7+0.25*x8;
pl=0.5*x1+x2+0.5*x3+0.5*x4+x5+0.5*x6-0.5*x7+0.5*x8;
pm=x8;
pn=-0.353*x1-0.707*x2-1.0607*x3-0.3536*x4-0.707*x5-1.0607*x6+0.3536*x7-0.3536*x8;
po=0.25*x1+0.5*x2+0.75*x3+0.25*x4+0.5*x5+0.75*x6-0.25*x7+0.25*x8;
pp=0;
pr=0.5*x1+x2+0.5*x3+0.5*x4+x5+0.5*x6-0.5*x7+0.5*x8;
if(customKey=='9'){
scale0.tare();
scale1.tare();
scale2.tare();
scale3.tare();
scale4.tare();
scale5.tare();
scale6.tare();
scale7.tare(); 
}

textForSMS = textForSMS + "kra" + "," + pb + "," + pd + ","+ pg + "," + pr + "," + pa + "," + pc + "," + pe + "," + pf + ","+ ph + "," + pl + "," + po + "," + pn + ","+ pk + "," + pi + ","+ pj + "," + pm + "," + pp + "," + tryb + "," + x1 + "," + x2 + "," + x3 + "," + x4 + "," + x5 + "," + x6 + "," + x7 + "," + x8 + ","+ poda + "," + podb + ",";
Serial.println(textForSMS); 
textForSMS = ""; 
mnoznik=mnoznik*mnoznikklawiatury;
pa=mnoznik*pa;
pb=mnoznik*pb;
pc=mnoznik*pc;
pd=mnoznik*pd;
pe=mnoznik*pe;
pf=mnoznik*pf;
pg=mnoznik*pg;
ph=mnoznik*ph;
pi=mnoznik*pi;
pj=mnoznik*pj;
pk=mnoznik*pk;
pl=mnoznik*pl;
pm=mnoznik*pm;
pn=mnoznik*pn;
po=mnoznik*po;
pp=mnoznik*pp;
pr=mnoznik*pr;
/*if (pa>0){
pa=pa/20;
pa=pa*pa;}
if(pa<0){
pa=pa/20;
pa=-pa*pa;}
if (pb>0){
pb=pb/20;
pb=pb*pb;}
if(pb<0){
pb=pb/20;
pb=-pb*pb;}
if (pc>0){
pc=pc/20;
pc=pc*pc;}
if(pc<0){
pc=pc/20;
pc=-pc*pc;}
if (pd>0){
pd=pd/20;
pd=pd*pd;}
if(pd<0){
pd=pd/20;
pd=-pd*pd;}
if (pe>0){
pe=pe/20;
pe=pe*pe;}
if(pe<0){
pe=pe/20;
pe=-pe*pe;}
if (pf>0){
pf=pf/20;
pf=pf*pf;}
if(pf<0){
pf=pf/20;
pf=-pf*pf;}
if (pg>0){
pg=pg/20;
pg=pg*pg;}
if(pg<0){
pg=pg/20;
pg=-pg*pg;}
if (ph>0){
ph=ph/20;
ph=ph*ph;}
if(ph<0){
ph=ph/20;
ph=-ph*ph;}
if (ph>0){
ph=ph/20;
ph=ph*ph;}
if(pi<0){
pi=pi/20;
pi=-pi*pi;}
if (pi>0){
pi=pi/20;
pi=pi*pi;}
if (pj>0){
pj=pj/20;
pj=pj*pj;}
if(pj<0){
pj=pj/20;
pj=-pj*pj;}
if (pk>0){
pk=pk/20;
pk=pk*pk;}
if(pk<0){
pk=pk/20;
pk=-pk*pk;}
if (pl>0){
pl=pl/20;
pl=pl*pl;}
if(pl<0){
pl=pl/20;
pl=-pl*pl;}
if (pm>0){
pm=pm/20;
pm=pm*pm;}
if(pm<0){
pm=pm/20;
pm=-pm*pm;}
if (pn>0){
pn=pn/20;
pn=pn*pn;}
if(pn<0){
pn=pn/20;
pn=-pn*pn;}
if (po>0){
po=po/20;
po=po*po;}
if(po<0){
po=po/20;
po=-po*po;}
if (pp>0){
pp=pp/10;
pp=pp*pp;}
if(pp<0){
pp=pp/20;
pp=-pp*pp;}
if (pr>0){
pr=pr/20;
pr=pr*pr;}
if(pr<0){
pr=pr/20;
pr=-pr*pr;}*/
if(pb<256 and pb>bezwladnosc){
  for(int i=0; i<27; i++){
  leds[i]=CRGB(0,0,pb);
 }}
if(pb>-256 and pb<-bezwladnosc){
  for(int i=0; i<27; i++){
  leds[i]=CRGB(-pb,0,0);
 }} 
 if(pb<bezwladnosc and pb>-bezwladnosc){
  for(int i=0; i<27; i++){
  leds[i]=CRGB(0,0,0);
 }} 
if(pd<256 and pd>bezwladnosc){
  for(int i=27; i<54; i++){
  leds[i]=CRGB(0,0,pd);}
  tft.drawLine(10, 40, 45, 40, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(15,80);
  tft.print(pa);
  tft.setCursor(40,80);
  tft.println("N");
  }
 if(pd>-256 and pd<-bezwladnosc){
  for(int i=27; i<54; i++){
  leds[i]=CRGB(-pd,0,0);}
  tft.drawLine(10, 40, 45, 40, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(15,80);
  tft.print(-pa);
  tft.setCursor(40,80);
  tft.println("N");
 }
 if(pd<bezwladnosc and pd>-bezwladnosc){
  for(int i=27; i<54; i++){
  leds[i]=CRGB(0,0,0);
  }}
 if(pg<256 and pg>bezwladnosc){
  for(int i=54; i<80; i++){
  leds[i]=CRGB(0,0,pg); 
  }
  tft.drawLine(80, 40, 45, 40, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(50,80);
  tft.print(pr);
  tft.setCursor(75,80);
  tft.println("N");
 }
if(pg>-256 and pg<-bezwladnosc){
  for(int i=54; i<80; i++){
  leds[i]=CRGB(-pg,0,0);
  }
  tft.drawLine(80, 40, 45, 40, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(50,80);
  tft.print(-pr);
  tft.setCursor(75,80);
  tft.println("N");
 }
 if(pg<bezwladnosc and pg>-bezwladnosc){
  for(int i=54; i<80; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pr<256 and pr>bezwladnosc){
  for(int i=80; i<107; i++){
  leds[i]=CRGB(0,0,pr);}
  tft.drawLine(80, 40, 80, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(50,100);
  tft.print(pg);
  tft.setCursor(75,100);
  tft.println("N");
 }
if(pr>-256 and pr<-bezwladnosc){
  for(int i=80; i<107; i++){
  leds[i]=CRGB(-pr,0,0);}
  tft.drawLine(45, 75, 80, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(50,100);
  tft.print(-pg);
  tft.setCursor(75,100);
  tft.println("N");
 }
 if(pr<bezwladnosc and pr>-bezwladnosc){
  for(int i=80; i<107; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pa<256 and pa>bezwladnosc){
  for(int i=107; i<134; i++){
  leds[i]=CRGB(0,0,pa);} 
  tft.drawLine(45, 75, 10, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(15,100);
  tft.print(pd);
  tft.setCursor(50,100);
  tft.println("N");}
if(pa>-256 and pa<-bezwladnosc){
  for(int i=107; i<134; i++){
  leds[i]=CRGB(-pa,0,0);}
  tft.drawLine(45, 75, 10, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(15,100);
  tft.print(-pd);
  tft.setCursor(50,100);
  tft.println("N");} 
  if(pa<bezwladnosc and pa>-bezwladnosc){
  for(int i=107; i<134; i++){
  leds[i]=CRGB(0,0,0);}} 
 if(pc<256 and pc>bezwladnosc){
  for(int i=134; i<174; i++){
     
  leds[i]=CRGB(0,0,pc);}
  tft.drawLine(45, 40, 10, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(15,90);
  tft.print(pc);
  tft.setCursor(40,90);
  tft.println("N");}
if(pc>-256 and pc<-bezwladnosc){
  for(int i=134; i<174; i++){
  leds[i]=CRGB(-pc,0,0);}
  tft.drawLine(45, 40, 10, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(15,90);
  tft.print(-pc);
  tft.setCursor(40,90);
  tft.println("N");}
  if(pc<bezwladnosc and pc>-bezwladnosc){
  for(int i=134; i<174; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pe<256 and pe>bezwladnosc){
  for(int i=174; i<201; i++){
  leds[i]=CRGB(0,0,pe);}
  tft.drawLine(45, 40, 45, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(30,110);
  tft.print(pe);
  tft.setCursor(55,110);
  tft.println("N");}
if(pe>-256 and pe<-bezwladnosc){
  for(int i=174; i<201; i++){
  leds[i]=CRGB(-pe,0,0);}
  tft.drawLine(45, 40, 45, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(30,110);
  tft.print(-pe);
  tft.setCursor(55,110);
  tft.println("N");}
  if(pe<bezwladnosc and pe>-bezwladnosc){
  for(int i=174; i<201; i++){
  leds[i]=CRGB(0,0,0);}}  
 if(pf<256 and pf>bezwladnosc){
  for(int i=201; i<241; i++){
  leds[i]=CRGB(0,0,pf);}
  tft.drawLine(80, 40, 45, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(50,90);
  tft.print(pf);
  tft.setCursor(75,90);
  tft.println("N");}
if(pf>-256 and pf<-bezwladnosc){
  for(int i=201; i<241; i++){
  leds[i]=CRGB(-pf,0,0);}
  tft.drawLine(80, 40, 45, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(50,90);
  tft.print(-pf);
  tft.setCursor(75,90);
  tft.println("N");} 
  if(pf<bezwladnosc and pf>-bezwladnosc){
  for(int i=201; i<241; i++){
  leds[i]=CRGB(0,0,0);}}
 if(ph<256 and ph>bezwladnosc){
  for(int i=241; i<268; i++){
  leds[i]=CRGB(0,0,ph);}
  tft.drawLine(80, 40, 80, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(65,110);
  tft.print(ph);
  tft.setCursor(90,110);
  tft.println("N");}
if(ph>-256 and ph<-bezwladnosc){
  for(int i=241; i<268; i++){
  leds[i]=CRGB(-ph,0,0);}
  tft.drawLine(80, 40, 80, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(65,110);
  tft.print(-ph);
  tft.setCursor(90,110);
  tft.println("N");}
  if(ph<bezwladnosc and ph<-bezwladnosc){
  for(int i=241; i<268; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pl<256 and pl>bezwladnosc){
  for(int i=268; i<295; i++){
  leds[i]=CRGB(0,0,pl);}
  tft.drawLine(115, 75, 80, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(85,100);
  tft.print(pj);
  tft.setCursor(110,100);
  tft.println("N");}
if(pl>-256 and pl<-bezwladnosc){
  for(int i=268; i<295; i++){
  leds[i]=CRGB(-pl,0,0);}
  tft.drawLine(115, 75, 80, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(85,100);
  tft.print(-pj);
  tft.setCursor(110,100);
  tft.println("N");} 
  if(pl<bezwladnosc and pl>-bezwladnosc){
  for(int i=268; i<295; i++){
  leds[i]=CRGB(0,0,0);}}
 if(po<256 and po>bezwladnosc){
  for(int i=295; i<322; i++){
  leds[i]=CRGB(0,0,po);}
  tft.drawLine(115, 75, 150, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(120,100);
  tft.print(pm);
  tft.setCursor(145,100);
  tft.println("N");}
if(po>-256 and po<-bezwladnosc){
  for(int i=295; i<322; i++){
  leds[i]=CRGB(-po,0,0);}
  tft.drawLine(115, 75, 150, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(120,100);
  tft.print(-pm);
  tft.setCursor(145,100);
  tft.println("N");} 
  if(pl<bezwladnosc and pl>-bezwladnosc){
  for(int i=295; i<322; i++){
  leds[i]=CRGB(0,0,0);}} 
 if(pp<256 and pp>bezwladnosc){
  for(int i=322; i<347; i++){
  leds[i]=CRGB(0,0,pp);}
  tft.drawLine(115, 40, 150, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(120,90);
  tft.print(pn);
  tft.setCursor(145,90);
  tft.println("N");}
if(pp>-256 and pp<-bezwladnosc){
  for(int i=322; i<347; i++){
  leds[i]=CRGB(-pp,0,0);}
  tft.drawLine(115, 40, 150, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(120,90);
  tft.print(-pn);
  tft.setCursor(145,90);
  tft.println("N");} 
  if(pp<bezwladnosc and pp>-bezwladnosc){
  for(int i=322; i<347; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pm<256 and pm>bezwladnosc){
  for(int i=347; i<372; i++){
  leds[i]=CRGB(0,0,pm);}
  tft.drawLine(115, 40, 115, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(100,110);
  tft.print(pk);
  tft.setCursor(125,110);
  tft.println("N");}
if(pm>-256 and pm<-bezwladnosc){
  for(int i=347; i<372; i++){
  leds[i]=CRGB(-pm,0,0);}
  tft.drawLine(115, 40, 115, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(100,110);
  tft.print(-pk);
  tft.setCursor(125,110);
  tft.println("N");}
  if(pm<bezwladnosc and pm>-bezwladnosc){
  for(int i=347; i<372; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pj<256 and pj>bezwladnosc){
  for(int i=372; i<397; i++){
  leds[i]=CRGB(0,0,pj);}
  tft.drawLine(80, 40, 115, 75, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(85,90);
  tft.print(pi);
  tft.setCursor(110,90);
  tft.println("N");}
if(pj>-256 and pj<-bezwladnosc){
  for(int i=372; i<397; i++){
  leds[i]=CRGB(-pj,0,0);}
  tft.drawLine(80, 40, 115, 75, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(85,90);
  tft.print(-pi);
  tft.setCursor(110,90);
  tft.println("N");}
  if(pj<bezwladnosc and pj>-bezwladnosc){
  for(int i=372; i<397; i++){
  leds[i]=CRGB(0,0,0);}}  
 if(pi<256 and pi>bezwladnosc){
  for(int i=397; i<437; i++){
  leds[i]=CRGB(0,0,pi);}
  tft.drawLine(80, 40, 115, 40, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(85,80);
  tft.print(pl);
  tft.setCursor(110,80);
  tft.println("N");}
if(pi>-256 and pi<-bezwladnosc){
  for(int i=397; i<437; i++){
  leds[i]=CRGB(-pi,0,0);}
  tft.drawLine(80, 40, 115, 40, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(85,80);
  tft.print(-pl);
  tft.setCursor(110,80);
  tft.println("N");} 
   if(pi<bezwladnosc and pi>-bezwladnosc){
  for(int i=397; i<437; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pk<256 and pk>bezwladnosc){
  for(int i=437; i<464; i++){
  leds[i]=CRGB(0,0,pk);}
  tft.drawLine(150, 40, 115, 40, ST7735_RED);
  tft.setTextColor(ST7735_RED, ST7735_BLACK);
  tft.setCursor(120,80);
  tft.print(po);
  tft.setCursor(145,80);
  tft.println("N");}
if(pk>-256 and pk<-bezwladnosc){
  for(int i=437; i<464; i++){
  leds[i]=CRGB(-pk,0,0);}
  tft.drawLine(150, 40, 115, 40, ST7735_BLUE);
  tft.setTextColor(ST7735_BLUE, ST7735_BLACK);
  tft.setCursor(120,80);
  tft.print(-po);
  tft.setCursor(145,80);
  tft.println("N");}
  if(pk<bezwladnosc and pk>-bezwladnosc){
  for(int i=437; i<464; i++){
  leds[i]=CRGB(0,0,0);}}
 if(pn<256 and pn>bezwladnosc){
  for(int i=464; i<505; i++){
  leds[i]=CRGB(0,0,pn);}}
if(pn>-256 and pn<-bezwladnosc){
  for(int i=464; i<505; i++){
  leds[i]=CRGB(-pn,0,0);}} 
  if(pn<bezwladnosc and pn>-bezwladnosc){
  for(int i=464; i<505; i++){
  leds[i]=CRGB(0,0,0);}} 

FastLED.show();}}
void loop() {}
