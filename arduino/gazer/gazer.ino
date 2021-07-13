#include<Servo.h>
Servo servo1;



const int ping=7;
const int in=8;//echo
long cm,duration;
int dicission;
const int ledpin=13;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo1.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
dicission=Serial.read();
int ar[37];
if(dicission=='g'){
  int m=1000;
  int pos1,pos2,pos3;
  
  for(int deg=0;deg<=180;deg+=5){
    servo1.write(deg);
    sound:
    pinMode(ledpin,OUTPUT);
    digitalWrite(ledpin,LOW);
    pinMode(ping,OUTPUT);
    digitalWrite(ping,LOW);
    delay(20);
    digitalWrite(ping,HIGH);
    delay(50);
    digitalWrite(ping,LOW);
    pinMode(in,INPUT);
    duration=pulseIn(in,HIGH);
    cm=duration/58;
    if (cm==0){
      goto sound;
      }
    ar[deg/5]=cm;
    delay(100);
  }
  for(int i=0;i<=36;i++){
    Serial.println(ar[i]);
    Serial.println(i*10);
    Serial.println("------");
    
    if(ar[i]<=m){
      
      pos3=pos2;
      pos2=pos1;
      m=ar[i];
      pos1=i*5;
      
      
    }
  }
  Serial.println("the largest ");
  Serial.println(m);
  Serial.println(pos1);
  for(int i=180;i>=(pos1+pos2+pos3)/3;i--){
    servo1.write(i);
    
    delay(100);
  }
  Serial.println("arraived");
  digitalWrite(ledpin,HIGH);
  delay(1000);
  delay(1000);
  for(int i=(pos1+pos2+pos3)/3;i>=0;i--){
    servo1.write(i);
    delay(10);
  }
  digitalWrite(ledpin,LOW);
}
}
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
