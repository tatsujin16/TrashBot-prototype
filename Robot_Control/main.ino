void order1(const std_msgs::Int16 &message){
  const int dustbox = message.data;
  if (dustbox == 0){
    CLOSE();
    nh.spinOnce();
    Timer(500);
  }
  else if (dustbox == 1){
    OPEN();
    nh.spinOnce();
    Timer(500);
  }
  else if (dustbox == 2){
    STRAIGHT(); 
    STOP();
    nh.spinOnce();  
    Timer(500); 
  }
  else if (dustbox == 3){
    BACK();
    STOP();
    nh.spinOnce();
    Timer(500);
  }
  else if (dustbox == 4){
    RIGHT();
    STOP();
    nh.spinOnce();
    Timer(500);
  }
  else if (dustbox == 5){
    LEFT();
    STOP();
    nh.spinOnce();
    Timer(500);
  }
  else if (dustbox == 6){
    STRAIGHT();
    STOP();
    nh.spinOnce();
    Timer(500);
    OPEN();
    Timer(500);
  }
  else if (dustbox == 7){
    CLOSE();
    Timer(500);
    nh.spinOnce();
    BACK();
    STOP();
    nh.spinOnce();
    Timer(500);
  }
  //タイマーモード
  else if (dustbox == 8){
    STRAIGHT();
    STOP();
    nh.spinOnce();
    Timer(500);
    OPEN();
    Timer(500);
    nh.spinOnce();
    Timer(2000);
    nh.spinOnce();
    CLOSE();
    Timer(500);
    nh.spinOnce();
    BACK();
    STOP();
    nh.spinOnce();
    Timer(500);
  }
  //センサーモード
  else if (dustbox == 9){
    STRAIGHT();
    STOP();
    OPEN();
    Timer(500);
    nh.spinOnce();
    PRESS();
    Timer(500);
    nh.spinOnce();
    BACK();
    STOP();
    nh.spinOnce();
    Timer(500);
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
