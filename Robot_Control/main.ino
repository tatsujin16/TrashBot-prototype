void order1(const std_msgs::Int16 &message){
  const int dustbox = message.data;
  Timer(1000);
  if (dustbox == 1){
    OPEN();
    Adjust();
  }
  else if (dustbox == 2){
    CLOSE();
    Adjust();
  }
  else if (dustbox == 3){
    STRAIGHT(); 
    STOP();
    Adjust();
  }
  else if (dustbox == 4){
    BACK();
    STOP();
    Adjust();
  }
  else if (dustbox == 5){
    RIGHT();
    STOP();
    Adjust();
  }
  else if (dustbox == 6){
    LEFT();
    STOP();
    Adjust();
  }
  else if (dustbox == 7){
    STRAIGHT();
    STOP();
    Adjust();
    RIGHT();
    STOP();
    Adjust();
    STRAIGHT();
    STOP();
    Adjust();
    OPEN();
    Adjust();
  }
  else if (dustbox == 8){
    CLOSE();
    Adjust();
    BACK();
    STOP();
    Adjust();
    LEFT();
    STOP();
    Adjust();
    BACK();
    STOP();
    Adjust();
  }
  //タイマーモード
  else if (dustbox == 9){
    STRAIGHT();
    STOP();
    Adjust();
    OPEN();
    Timer(1500);
    Adjust();
    CLOSE();
    Adjust();
    BACK();
    STOP();
    Adjust();
  }
  //センサーモード
  else if (dustbox == 10){
    STRAIGHT();
    STOP();
    Adjust();
    OPEN();
    Adjust();
    PRESS();
    Adjust();
    BACK();
    STOP();
    Adjust();
  }
}
ros::Subscriber<std_msgs::Int16> Dustbox("/TrashBot",&order1);
void setup(){
  servo1.attach(10);
  servo1.write(ang_close);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  nh.initNode();
  nh.subscribe(Dustbox);
}
void loop(){
  nh.spinOnce();
  Timer(1);
}
