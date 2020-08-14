#include "Keyboard.h"
#include "Mouse.h"
#include <SoftwareSerial.h>   // 引用程式庫
SoftwareSerial BT(8,9); // 接收腳, 傳送腳
// set pin numbers for the five buttons:
const int ResetBT = 2;
const int five = 3;
const int ten = 4;
const int twenty = 5;
//const int rightButton = 5;


void setup() { // initialize the buttons' inputs:
  pinMode(five, INPUT);
  pinMode(ResetBT, INPUT);
  pinMode(ten, INPUT);
  pinMode(twenty, INPUT);
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");
  BT.begin(38400);
  Mouse.begin();
  Keyboard.begin();
}

void loop() {
  // use serial input to control the mouse:  Serial.available()||
  if (BT.available()) {
    char val = BT.read();
    Serial.print(val);
    char inChar = Serial.read();
  if(val=='0'){
        Mouse.begin();
        Serial.print(val);}
      else if(val=='1'){
        Mouse.end();
        Serial.print(val);}
      else if(val=='2'){
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        Serial.print(val);} 
      else if(val=='3'){
        Serial.print(val);
        int x1=50,y1=700;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x1;i++)Mouse.move(1, 0);
        for(int i=0;i<y1;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);}
      else if(val=='4'){
        Serial.print(val);
        int x1=1730,y1=700;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x1;i++)Mouse.move(1, 0);
        for(int i=0;i<y1;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);}  
      else if(val=='5'){
        Serial.print(val);
        int x1=400,y1=400;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x1;i++)Mouse.move(1, 0);
        for(int i=0;i<y1;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);}
      else if(val=='6'){
        Serial.print(val);
        int x1=400,y1=400;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x1;i++)Mouse.move(1, 0);
        for(int i=0;i<y1;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);}
      else if(val=='7'){
        Serial.print(val);
        int x1=400,y1=400;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x1;i++)Mouse.move(1, 0);
        for(int i=0;i<y1;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);}
  }
}
