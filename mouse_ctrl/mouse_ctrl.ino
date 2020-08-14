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
  if (Serial.available()) {
    //char val = BT.read();
    //Serial.print(val);
    char val = Serial.read();

    switch (val) {
      case 'q':
        // move mouse up
        Mouse.begin();
        Serial.print(val);
        break;
      case 'w':
        // move mouse down
        Mouse.end();
        Serial.print(val);
        break;
      case 'e':
        // move mouse left
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        Serial.print(val);
        break;
      case 'r':
        // move mouse right
        Serial.print(val);
        int x1=100,y1=200;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x1;i++)Mouse.move(1, 0);
        for(int i=0;i<y1;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        break;
      case 't':
        // perform mouse left click
        Serial.print(val);
        int x2=200,y2=400;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x2;i++)Mouse.move(1, 0);
        for(int i=0;i<y2;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        break;
      case 'y':
        // perform mouse left click
        Serial.print(val);
        int x3=400,y3=400;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x3;i++)Mouse.move(1, 0);
        for(int i=0;i<y3;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        break;
       case 'u':
        // perform mouse left click
        Serial.print(val);
        int x4=800,y4=400;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x4;i++)Mouse.move(1, 0);
        for(int i=0;i<y4;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        break;
      case 'i':
      int x5=1600,y5=400;
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        for(int i=0;i<x5;i++)Mouse.move(1, 0);
        for(int i=0;i<y5;i++)Mouse.move(0, 1);
        Mouse.click();
        delay(5000);
        for(int i=0;i<20;i++)Mouse.move(-100, -100);
        break;
    }
  }

  // use the pushbuttons to control the keyboard:
  /*if (digitalRead(five) == HIGH) {
    delay(3000);//300000
    for(int i=0;i<20;i++)Mouse.move(-100, -100);//原點ㄏ  
    delay(1000);
    
    Mouse.move(95, 30);
    Mouse.move(95, 30);
    Mouse.move(95, 30);
    Mouse.move(66, 27);
    while(1){
    Keyboard.write('a');
    delay(7000);}
  }

  if (digitalRead(ten) == HIGH) {
    delay(600000);

    while(1){
    Keyboard.write('a');
    delay(7000);}
  }

  if (digitalRead(twenty) == HIGH) {
    delay(1200000);
    while(1){
    Keyboard.write('a');
    delay(7000);}
  }
  
  if (digitalRead(ResetBT) == HIGH) {
    for(int i=0;i<20;i++)Mouse.move(-100, -100);
  }*/

}
