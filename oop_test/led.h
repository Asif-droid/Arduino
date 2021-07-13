#include <Arduino.h>
class Led{
  private:
  byte pin;
  int led_count;
  public:
  Led(byte pin){
    this->pin=pin;
    this->led_count=0;
    init();
  }
  void init(){
    pinMode(pin,OUTPUT);
    off();
  }
  void on(){
    digitalWrite(pin,HIGH);
    led_count+=1;
  }
  void off(){
    digitalWrite(pin,LOW);
  }
  int get_led_count(){
    return led_count;
  }
};
