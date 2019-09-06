//============================Yahboom===========================
//  Intelligent car run comprehensive experiment
//===============================================================
int Left_motor_back=9;        //(IN1)
int Left_motor_go=5;          //(IN2)

int Right_motor_go=6;         // (IN3)
int Right_motor_back=10;      // (IN4)

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
  analogWrite(Left_motor_go,200); //PWM ratio 0~255 speed control, 
                                 //the difference of left and right wheel slightly increase or decrease
  analogWrite(Left_motor_back,0);
  delay(time * 100);   //execution time, can be adjusted 
}

void brake(int time)         
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  delay(time * 100);   //execution time, can be adjusted 
}

void left(int time)         //turn left (The left wheel stop, the right wheel run)
{
  digitalWrite(Right_motor_go,HIGH);	// Right motor go
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);   //PWM ratio 0~255 speed control 
  digitalWrite(Left_motor_go,LOW);   //left motor stop
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);//PWM ratio 0~255 speed control 
  delay(time * 100);	//execution time, can be adjusted   
}

void spin_left(int time)         //Turn left in place(The left wheel back, the right wheel run)
{
  digitalWrite(Right_motor_go,HIGH); // Right motor go
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);   //PWM ratio 0~255 speed control 
  digitalWrite(Left_motor_go,LOW);   //left motor back
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,200);  //PWM ratio 0~255 speed control 
  delay(time * 100);	//execution time, can be adjusted  
}

void right(int time)        //turn right(The right wheel stop, the left wheel run)
{
  digitalWrite(Right_motor_go,LOW);   //right motor stop
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);   //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH);  //left motor go
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);   //PWM ratio 0~255 speed control
  delay(time * 100);	//execution time, can be adjusted   
}

void spin_right(int time)        //turn right in place(The right wheel back, the left wheel run)
{
  digitalWrite(Right_motor_go,LOW);   //right motor back
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,200); //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH);  //left motor go
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);    //PWM ratio 0~255 speed control
  delay(time * 100);	  //execution time, can be adjusted  
}

void back(int time)          //car back
{
  digitalWrite(Right_motor_go,LOW);  //right motor back
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,150); //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);   //left motor back
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,150);  //PWM ratio 0~255 speed control
  delay(time * 100);     //execution time, can be adjusted  
}

void loop()
{
  delay(2000); //Start up after delay 2s
  back(10); //back 1s
  brake(5);//stop 0.5s
  run(10);//run 1s
  brake(5);//stop 0.5s
  left(10);//turn left 1s
  right(10);//turn right 1s
  spin_right(20); //turn left in place 2s
  spin_left(20);//turn right in place 2s
  brake(5);//stop
}


