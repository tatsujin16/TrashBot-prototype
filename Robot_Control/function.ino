#include <Servo.h>
#include<MsTimer2.h>
#include<Arduino.h>
#include<ros.h>
#include<geometry_msgs/Twist.h>
#include<std_msgs/Int16.h>
ros::NodeHandle nh;

Servo servo1;
int ang1 = 0;
int count_time=0;
//left_motor
int enA = 7;
int in1 = 9;
int in2 = 8;
//right_motor
int enB = 5;
int in3 = 3;
int in4 = 2;
int ang_open = 110;
int ang_close = 5;
volatile boolean tim1msF = false;
int val;
int x = 900;

void timer1mS(){
  tim1msF = true;
}
int Timer(int n){
  MsTimer2::set(1, timer1mS);
  MsTimer2::start();
  while(count_time <= n){
    if(tim1msF){
      count_time = count_time + 1;
      tim1msF = false;
    }
  }
  MsTimer2::stop();
  tim1msF = false;
  count_time = 0;
  return 0;
}

void OPEN(){
  for(ang1 = ang_close; ang1 <= ang_open; ang1 +=1){
        servo1.write(ang1);
        Timer(20);
    }
}

void CLOSE(){
  for(ang1 = ang_open; ang1 >= ang_close+30; ang1 -= 1){
        servo1.write(ang1);
        Timer(20);
    }
  servo1.write(ang_close); //パタッと閉める
}

void STOP(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3,LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void STRAIGHT(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 130);
  digitalWrite(in3,HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
  Timer(2500);
}

void BACK(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  analogWrite(enA, 130);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
  Timer(2500);
}

void RIGHT(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
  Timer(700);
}

void LEFT(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
  Timer(700);
}

void PRESS(){
  while(1){
    nh.spinOnce();
    val = analogRead(A1);
    Timer(5);
    if(val < x){
      CLOSE();
      x = val - 5;
      break;
    }
  } 
}

void Adjust(){
  nh.spinOnce();
  Timer(500);
}
