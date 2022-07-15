#define BLINKER_WIFI
#include <Blinker.h>

char auth[] = "";
char ssid[] = "";
char pswd[] = "";

BlinkerButton Button1("btn-1");
BlinkerButton Button2("btn-2");
BlinkerButton Button3("btn-3");
BlinkerButton Button5("btn-lock");
BlinkerText Text1("tex-1");

String t;
int lock_status = 0;

void status_text(){
//  文本显示
    Text1.print(t);
    Blinker.delay(5000);
    t = "";
    Text1.print(t);
}

void led_twinkle(){
//  指示灯闪烁
    digitalWrite(LED_BUILTIN, LOW);
    Blinker.delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
}

void heartbeat(){
    if(lock_status == 0){
      Button5.text("已关锁");
      Button5.print("off");
    }else{
      Button5.text("已开锁");
      Button5.print("on"); 
    }
}

void lock_btn_callback(const String & state){
//  防误触锁
    led_twinkle();
    if(lock_status == 0){
      lock_status = 1;
      Button5.text("已开锁");
      Button5.print("on");
      Blinker.delay(30000);
      Button5.text("已关锁");
      Button5.print("off");
      lock_status = 0;
    }else{
      t = "锁开了不用再按了";
      status_text();
    }
}

void button1_callback(const String & state){
//  按钮1，上行
    if(lock_status == 1){
        digitalWrite(14, HIGH);
        Blinker.delay(500);
        digitalWrite(14, LOW);
        Blinker.delay(500);
        digitalWrite(5, HIGH);
        Blinker.delay(500);
        digitalWrite(5, LOW);
        led_twinkle();
        t = "1 Pressed";
        status_text();
    }else{
        t = "先开防误触锁";
        status_text();
    }
}

void button2_callback(const String & state){
//  按钮2，下行
    if(lock_status == 1){
        digitalWrite(14, HIGH);
        Blinker.delay(500);
        digitalWrite(14, LOW);
        Blinker.delay(500);
        digitalWrite(4, HIGH);
        Blinker.delay(500);
        digitalWrite(4, LOW);
        led_twinkle();
        t = "2 Pressed";
        status_text();
    }else{
        t = "先开防误触锁";
        status_text();
    }
}

void button3_callback(const String & state){
//  按钮3，暂停
    if(lock_status == 1){
        digitalWrite(14, HIGH);
        Blinker.delay(500);
        digitalWrite(14, LOW);
        led_twinkle();
        t = "3 Pressed";
        status_text();
    }else{
        t = "先开防误触锁";
        status_text();
    }
}

void setup() {
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
//  5=D1,4=D2,14=D5
    pinMode(5, OUTPUT);
    digitalWrite(5, LOW);
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);
    pinMode(14, OUTPUT);
    digitalWrite(14, LOW);
    pinMode(LED_BUILTIN, OUTPUT);
    
    digitalWrite(LED_BUILTIN, LOW);
    Blinker.delay(2000);
    digitalWrite(LED_BUILTIN, HIGH);
    
    Blinker.begin(auth, ssid, pswd);

    Button1.attach(button1_callback);
    Button2.attach(button2_callback);
    Button3.attach(button3_callback);
    Button5.attach(lock_btn_callback);
    Blinker.attachHeartbeat(heartbeat);

}

void loop() {
    Blinker.run();
}
