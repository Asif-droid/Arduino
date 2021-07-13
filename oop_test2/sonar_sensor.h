#include<Arduino.h>
class sonar_sensor{
  private:
  byte trig_pin;
  byte echo_pin;
  long distance,duration;
  public:
  sonar_sensor(byte trig_pin,byte echo_pin){    ///both trig and echo pin haas to be PWM pins
    this->trig_pin=trig_pin;
    this->echo_pin=echo_pin;
    distance=duration=-1;
    init();
  }
  void init(){
    pinMode(trig_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
  }
  void set_duration(){
    digitalWrite(trig_pin,LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin,LOW);

    duration=pulseIn(echo_pin,HIGH);
    
  }
  long get_duration(){
    return duration;
  }
  long get_distance_cm(){
    distance=duration*.034/2;
    return distance;
  }
  long get_distance_inch(){
    distance=duration*.034/2;
    return distance*0.393701;
  }
  
  
};
