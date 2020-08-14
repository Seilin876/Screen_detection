#include <SoftwareSerial.h>   // 引用程式庫
#include <Keyboard.h>
#include <Mouse.h>
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(8, 9); // 接收腳, 傳送腳
char val;  // 儲存接收資料的變數
const byte LED_PIN = 12;  // 定義LED腳位

void setup() {
  // 設定HC-05藍牙模組，AT命令模式的連線速率。
  BT.begin(38400);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
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
      int x1=400,y1=400;
      for(int i=0;i<20;i++)Mouse.move(-100, -100);
      for(int i=0;i<x1;i++)Mouse.move(1, 0);
      for(int i=0;i<y1;i++)Mouse.move(0, 1);
      Mouse.click();
      delay(5000);
      for(int i=0;i<20;i++)Mouse.move(-100, -100);}
    else if(val=='4'){
      Serial.print(val);
      int x1=400,y1=400;
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
