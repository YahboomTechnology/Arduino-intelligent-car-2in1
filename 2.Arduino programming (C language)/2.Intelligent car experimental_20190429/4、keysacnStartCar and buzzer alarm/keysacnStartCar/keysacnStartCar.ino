//============================yahboom===========================
//  Intelligent car  key star and buzzer alarm experiment
//===============================================================

int Left_motor_back=9;       //(IN1)
int Left_motor_go=5;         //(IN2)

int Right_motor_go=6;        //(IN3)
int Right_motor_back=10;     //(IN4)

int key=A0;//Define the key A0 interface
int beep=A1;//Define the buzzer A1 interface

void setup()
{
  //Initialize the motor drive IO for output mode
  pinMode(Left_motor_go,OUTPUT); // PIN 5 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 6 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 10 (PWM)
  pinMode(key,INPUT);//Define the key interface for the input interface
  pinMode(beep,OUTPUT);
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

void keysacn()
{
  int val;
  val=digitalRead(key);//Read the value of the port 7 level to the val
  while(!digitalRead(key))//When the key is not pressed, circulate all the time
  {
    val=digitalRead(key);//This sentence can be omitted and the circulate can run away.
  }
  while(digitalRead(key))//When the key is pressed
  {
    delay(10);	
    val=digitalRead(key);//Read the value of the port 7 level to the val
    if(val==HIGH)  //Judge whether the key is pressed again 
    {
      digitalWrite(beep,HIGH);		//buzzer sound
      while(!digitalRead(key))	        //Judge whether the key isreleased
        digitalWrite(beep,LOW);		//buzzer no sound
    }
    else
      digitalWrite(beep,LOW);           //buzzer no sound
  }
}

void loop()
{
  keysacn();	  //Call key scan function
  back(10);       //back 1s
  brake(5);       //stop 0.5s
  run(10);        //run 1s
  brake(5);       //stop 0.5s
  left(10);       //turn left 1s
  right(10);      //turn right 1s
  spin_left(20);  //left rotation 2s
  spin_right(20); //right rotation2s
  brake(5);	  //stop
}





