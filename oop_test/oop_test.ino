
#include "led.h"

class co_ordinate{
  int x;
  int y;
  int z;
  public:
  co_ordinate(int x,int y,int z){
    this->x=x;
    this->y=y;
    this->z=z;
  }
  co_ordinate(){
    this->x=0;
    this->y=0;
    this->z=0;
  }
  int get_x(){
    return x;
  }
  int get_z(){
    return z;
  }
  int get_y(){
    return y;
  }
  void set_x(int x){
    this->x=x;
  }
  void set_y(int y){
    this->y=y;
  }
  void set_z(int z){
    this->z=z;
  }
  
};



Led led1(13);
void setup() {
  
  // put your setup code here, to run once:

}

void loop() {
  led1.on();
  delay(500);
  led1.off();
  delay(500);
  if(led1.get_led_count()>5){
    exit(0);
  }
  // put your main code here, to run repeatedly:

}
