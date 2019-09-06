//============================yahboom===========================
//  Intelligent car run experiment
//===============================================================

int Left_motor_back=9;      //IN1
int Left_motor_go=5;        //IN2

int Right_motor_go=6;       // IN3
int Right_motor_back=10;    //IN4

void setup()
{
  //Initialize the motor drive IO for output mode
  pinMode(Left_motor_go,OUTPUT); // PIN 5 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 6 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 10 (PWM)
}
void run(int time)     
{
  digitalWrite(Right_motor_go,HIGH);  
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,200);//PWM ratio 0~255 speed control, 
                                 //the difference of left and right wheel slightly increase or decrease
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200);//PWM ratio 0~255 speed control, 
                                 //the difference of left and right wheel slightly increase or decrease
  analogWrite(Left_motor_back,0);
  delay(time * 100);   //execution time, can be adjusted 
}

void loop()
{
  delay(500);
  run(10); 	
}


