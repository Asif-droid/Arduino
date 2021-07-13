#include<Servo.h>
#include<Arduino.h>
class my_servo{
  private:
  int degree;
  byte pin;
  int sweep_count;
  int s_delay=15;
  Servo servo;
  public:
  my_servo(byte pin){
    this->pin=pin;
    degree=0;
    sweep_count=0;
    init();
    
  }
  void init(){
    servo.attach(pin);
    set_to_degree(0);
  }
  void set_to_degree(int deg){
    degree=deg;
    servo.write(deg);
  }
  void move_to(int deg){
    if(deg>degree){
      for(int i=degree;i<deg;i++){
        servo.write(i);
        delay(s_delay);
      }
      sweep_count+=1;
      
    }
    else if(deg<degree){
      for(int i=degree;i>deg;i--){
        servo.write(i);
        delay(s_delay);
      }
      sweep_count+=1;
    }
    
  }
  void move_to(int deg,int g_delay){
    if(deg>degree){
      for(int i=degree;i<deg;i++){
        servo.write(i);
        delay(g_delay);
      }
      sweep_count+=1;
      
    }
    else if(deg<degree){
      for(int i=degree;i>deg;i--){
        servo.write(i);
        delay(g_delay);
      }
      sweep_count+=1;
    }
    
  }
  void sweep_between(int from,int to){
    set_to_degree(from);
    move_to(to);
    set_to_degree(to);
    move_to(from);
  }
  void sweep_between(int from,int to,int g_delay){
    set_to_degree(from);
    move_to(to,g_delay);
    set_to_degree(to);
    move_to(from,g_delay);
  }
  int get_degree(){
    return degree;
  }
  int get_sweep_count(){
    return sweep_count;
  }
  
};
