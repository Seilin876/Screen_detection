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

    switch (val) {
      case 'w':
        // move mouse up
        Mouse.move(0, -40);
        break;
      case 's':
        // move mouse down
        Mouse.move(0, 40);
        break;
      case 'a':
        // move mouse left
        Mouse.move(-40, 0);
        break;
      case 'd':
        // move mouse right
        Mouse.move(40, 0);
        break;
      case 'q':
        // perform mouse left click
        Mouse.click(MOUSE_LEFT);
        break;
      case 'e':
        // perform mouse left click
        Mouse.click(MOUSE_RIGHT);
        break;
      case 'r':
      for(int i=0;i<20;i++){Mouse.move(-100, -100);}
        break;
    }
  }

  // use the pushbuttons to control the keyboard:
  if (digitalRead(five) == HIGH) {
    delay(1200000);//300000
    delay(10000);
    for(int i=0;i<20;i++)Mouse.move(-100, -100);//原點
    delay(500);
    Mouse.move(95, 100);//接受
    Mouse.move(95, 100);
    Mouse.move(95, 80);
    Mouse.move(70, 0);
    Mouse.click(MOUSE_LEFT);
    
    for(int i=0;i<20;i++)Mouse.move(-100, -100);//原點
    delay(20000);//200
    Mouse.move(95, 30);//進入選角畫面
    Mouse.move(95, 30);
    Mouse.move(95, 30);
    Mouse.move(40, 23);
    Mouse.click(MOUSE_LEFT);
    
    for(int i=0;i<20;i++)Mouse.move(-100, -100);//原點
    delay(500);
    Mouse.move(95, 60);
    Mouse.move(95, 60);
    Mouse.move(95, 60);
    Mouse.move(40, 0);
    Mouse.click(MOUSE_LEFT);
    
    for(int i=0;i<20;i++)Mouse.move(-100, -100);//原點
    delay(500);
    Mouse.move(95, 100);//鎖角
    Mouse.move(95, 100);
    Mouse.move(95, 100);
    Mouse.move(70, 0);
    Mouse.click(MOUSE_LEFT);
    
    for(int i=0;i<20;i++)Mouse.move(-100, -100);//原點
    delay(90000);
    Mouse.move(95, 100);//開始，切畫面並置中
    Mouse.move(95, 100);
    Mouse.move(95, 100);
    Mouse.move(70, 0);
    Mouse.click(MOUSE_LEFT);
    delay(500);
    Keyboard.write('b');
        
    for(int i=0;i<20;i++)Mouse.move(-100, -100);//原點
    delay(500);
    Mouse.move(100, 30);//往中路的點
    Mouse.move(100, 25);
    Mouse.move(100, 0);
    Mouse.move(100, 0);
    Mouse.move(90, 0);
    delay(20000);
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
  }

}
