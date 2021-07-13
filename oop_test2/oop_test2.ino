#include "my_servo.h"
#include "sonar_sensor.h";


//my_servo servo1(9);
sonar_sensor sensor(10,9);
void setup() {
  // put your setup code here, to run once:
  //Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.get_duration();
  //Serial.print(servo1.get_sweep_count());
  exit(0);

}
