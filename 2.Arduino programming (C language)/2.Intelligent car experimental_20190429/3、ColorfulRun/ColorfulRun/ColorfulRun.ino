//============================yahboom===========================
//  Intelligent car colorfulrun comprehensive experiment
//===============================================================

int Left_motor_back=9;       //(IN1)
int Left_motor_go=5;         //(IN2)

int Right_motor_go=6;        //(IN3)
int Right_motor_back=10;     //(IN4)

void setup()
{
  //Initialize the motor drive IO for output mode
  pinMode(Left_motor_go,OUTPUT); // PIN 5 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 6 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 10 (PWM)
}
void run(int time)    //car run
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

void brake(int time)       //car stop  
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  delay(time * 100);//execution time, can be adjusted  
}

void left(int time)         //turn left(left wheel stop，right wheel go)
{
  digitalWrite(Right_motor_go,HIGH);	// right motor go
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);     //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);     //left wheel back
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);      //PWM ratio 0~255 speed control
  delay(time * 100);	//execution time, can be adjusted  
}

void spin_left(int time)         //left rotation(left wheel back，right wheel go)
{
  digitalWrite(Right_motor_go,HIGH);	// right motor go
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);      //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);      //left wheel back
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,200);    //PWM ratio 0~255 speed control
  delay(time * 100);	        //execution time, can be adjusted  
}

void right(int time)        //turn right(right wheel stop，left wheel go)
{
  digitalWrite(Right_motor_go,LOW);    //right motor back
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);     //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH);    //left motor go
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);     //PWM ratio 0~255 speed control
  delay(time * 100);	    //execution time, can be adjusted   
}

void spin_right(int time)        // right rotation(right wheel back，left wheel go)
{
  digitalWrite(Right_motor_go,LOW);   //right motor back
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,200);  //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH);   //left motor go
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);     //PWM ratio 0~255 speed control
  delay(time * 100);	        //execution time, can be adjusted     
}

void back(int time)          //back
{
  digitalWrite(Right_motor_go,LOW);  //right wheel back
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,150); //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);   //left wheel back
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,150);  //PWM ratio 0~255 speed control
  delay(time * 100);       //execution time, can be adjusted  
}

void loop()
{    
  int i;
  delay(2000); //Start up after delay 2S
  run(10);
  back(10);   
  brake(5);

  for(i=0;i<5;i++)
  {
    run(10);   //5 steps in the discontinuous advance of the car
    brake(1);
  }

  for(i=0;i<5;i++)
  {
    back(10);  //5 steps in the discontinuous back of the car
    brake(1);
  }

  for(i=0;i<5;i++)
  {
    left(10);//Large sets of small bend left rotation continuously
    spin_left(5);
  }

  for(i=0;i<5;i++)
  {
    right(10);//Large sets of small bend right rotation continuously
    spin_right(5);
  }

  for(i=0;i<10;i++)
  {
    right(1);//turn right intermittently
    brake(1);
  }

  for(i=0;i<10;i++)
  {
    left(1);//turn left intermittently
    brake(1);
  }

  for(i=0;i<10;i++)
  {
    left(3);//Go S - shaped ways

    right(3);
  }

  for(i=0;i<10;i++)
  {
    spin_left(3);//left rotation intermittently
    brake(3);
  }

  for(i=0;i<10;i++)
  {
    spin_right(3);//right rotation intermittently
    brake(3);
  }

}





