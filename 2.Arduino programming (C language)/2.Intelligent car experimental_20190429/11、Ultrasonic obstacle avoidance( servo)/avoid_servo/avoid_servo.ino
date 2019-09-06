//============================yahboom========================================
//  Intelligent car ultrasonic obstacle avoidance(servo)

//In the program, the number part of the computer is shielded, 
//and printing will affect the speed of the car's reaction to obstacles.

//When debugging, you can open the shield content Serial.print 
//and print the measured distance.

// The PWM value and delay of the control speed are adjusted, 
//but it is still in accordance with the actual conditions 
//and the actual quantity of electricity is adjusted.
//=============================================================================
//#include <Servo.h> 
#include <LiquidCrystal.h> //Declare the function library of 1602 liquid crystals
//Declare the Arduino digital port connected by the pin of the 1602 LCD,
//8 or 4 line data modes, choose one of them.
//LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);   //8 data port mode connection statement
LiquidCrystal lcd(3,4,7,8,11,12,13); //4 data port mode connection statement

int Echo = A5;  // Echo(P2.0)
int Trig =A4;  //  Trig(P2.1)

int Front_Distance = 0;
int Left_Distance = 0;
int Right_Distance = 0;

int Left_motor_back=9;     //(IN1)
int Left_motor_go=5;       //(IN2)
int Right_motor_go=6;      //(IN3)
int Right_motor_back=10;   //(IN4)

int key=A0;//Define the key A0 interface
int beep=A1;//Define the buzzer A1 interface

int servopin=2;//Set the steering gear of the rudder to the digital port 2
int myangle;//Define angle variables
int pulsewidth;//Define of pulse width variable
int val;

void setup()
{
  Serial.begin(9600);    //Initialize the serial port
  //Initialize the motor drive IO for output mode
  pinMode(Left_motor_go,OUTPUT); // PIN 5 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 6 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 10 (PWM)
  pinMode(key,INPUT);//Define the key interface for the input interface
  pinMode(beep,OUTPUT);
  
  //Initialization of ultrasonic pins
  pinMode(Echo, INPUT);    // Define of ultrasonic input pin
  pinMode(Trig, OUTPUT);   // Define of ultrasonic output pin
  lcd.begin(16,2);      //Initialization of 1602 liquid crystal working mode
  //Define the 1602 LCD display range of 2 lines and 16 columns 
}
//=======================The basic action of car=========================
//void run(int time)    
void run()     
{
  digitalWrite(Right_motor_go,HIGH);  //right motor go
  digitalWrite(Right_motor_back,LOW);     
  analogWrite(Right_motor_go,165);//PWM ratio 0~255 speed control, 
                                 //the difference of left and right wheel slightly increase or decrease
  analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);  //left motor go
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,160);//PWM ratio 0~255 speed control, 
                                 //the difference of left and right wheel slightly increase or decrease
  analogWrite(Left_motor_back,0);
  //delay(time * 100);          //execution time, can be adjusted   
}

void brake(int time)  
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  delay(time * 100);//execution time, can be adjusted  
}

void left(int time)         //turn left(left wheel stop,right wheel go)
//void left()         //turn left(left wheel stop,right wheel go)
{
  digitalWrite(Right_motor_go,HIGH);  //right motor go
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,200); 
  analogWrite(Right_motor_back,0);    //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);  
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,0);     //PWM ratio 0~255 speed control
  delay(time * 100);	//execution time, can be adjusted   
}

void spin_left(int time)         //left rotation(left wheel back，right wheel go)
{
  digitalWrite(Right_motor_go,HIGH);	//right motor go
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,150); 
  analogWrite(Right_motor_back,0);    //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);   
  digitalWrite(Left_motor_back,HIGH);  //left motor back
  analogWrite(Left_motor_go,0); 
  analogWrite(Left_motor_back,150);   //PWM ratio 0~255 speed control
  delay(time * 100);	//execution time, can be adjusted    
}

void right(int time)
//void right()        //turn right (right wheel stop,left wheel go)
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,LOW);
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,0);//PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH);//left motor go
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,200); 
  analogWrite(Left_motor_back,0);//PWM ratio 0~255 speed control
  delay(time * 100);	//execution time, can be adjusted  
}

void spin_right(int time)        //right rotation(right wheel back,left wheel go)
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,HIGH); //right motor back
  analogWrite(Right_motor_go,0); 
  analogWrite(Right_motor_back,150);   //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH);    //left motor go
  digitalWrite(Left_motor_back,LOW);
  analogWrite(Left_motor_go,150); 
  analogWrite(Left_motor_back,0);//PWM ratio 0~255 speed control
  delay(time * 100);	//execution time, can be adjusted    
}

void back(int time)          
{
  digitalWrite(Right_motor_go,LOW);  //right motor back
  digitalWrite(Right_motor_back,HIGH);
  analogWrite(Right_motor_go,0);
  analogWrite(Right_motor_back,200);//PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);  //left motor back
  digitalWrite(Left_motor_back,HIGH);
  analogWrite(Left_motor_go,0);
  analogWrite(Left_motor_back,200);//PWM ratio 0~255 speed control
  delay(time * 100);     //execution time, can be adjusted   
}
//==========================================================

void keysacn()
{
  int val;
  val=digitalRead(key);//Read the value of the port 7 level to the val
  while(!digitalRead(key))//When the key is not pressed, circulate all the time
  {
    val=digitalRead(key);//This sentence can be omitted and the circulate can run away
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
      digitalWrite(beep,LOW);          //buzzer no sound
  }
}

float Distance_test()      //Measuring the distance ahead  
{
  digitalWrite(Trig, LOW);   //Give the trigger pin low level 2us
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  //Give the trigger pin high level 10us，at least 10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    //Give the trigger pin low level Continuouly
  float Fdistance = pulseIn(Echo, HIGH);  //Reading high level time(unit：us)
  Fdistance= Fdistance/58;                //Y meter =（X second *344）/2
  //X second=（ 2*Y meter ）/344 ==》Xsecond =0.0058*Y meter ==》cm = us /58
  //Serial.print("Distance:");            //Output distance（unit：cm）
  //Serial.println(Fdistance);            //display distanc
  //Distance = Fdistance;
  return Fdistance;
}  

void Distance_display(int Distance)
{
  if((2<Distance)&(Distance<400))
  {
    lcd.home();        //Move the cursor back to the upper left corner, 
                       //which is the beginning of the output    
    lcd.print("    Distance: ");       //display
    lcd.setCursor(6,2);    //Position the cursor in second lines, sixth columns
    lcd.print(Distance);       //display distance
    lcd.print("cm");          //display
  }
  else
  {
    lcd.home();         //Move the cursor back to the upper left corner, 
                        //which is the beginning of the output  
    lcd.print("!!! Out of range");       //Display beyond distance
  }
  delay(250);
  lcd.clear();
}

void servopulse(int servopin,int myangle)
//Define a pulse function that is used to simulate a PWM value
{
  pulsewidth=(myangle*11)+500;//Turn the angle to 500-2480 of the pulse width
  digitalWrite(servopin,HIGH);//Set high level of the servopin
  delayMicroseconds(pulsewidth);//The number of microseconds of the delayed pulse width
  digitalWrite(servopin,LOW);//Set low level of the servopin
  delay(20-pulsewidth/1000);
}

void front_detection()
{
  //The number of circulate is reduced here to increase the speed of the car's reaction to obstacles.
  for(int i=0;i<=5;i++) //Produce PWM number, equivalent delay to ensure that it can turn to the response angle
  {
    servopulse(servopin,90);
  }
  Front_Distance = Distance_test();
}

void left_detection()
{
  for(int i=0;i<=15;i++)//Produce PWM number, equivalent delay to ensure that it can turn to the response angle
  {
    servopulse(servopin,175);
  }
  Left_Distance = Distance_test();
  //Serial.print("Left_Distance:");      //Output distance（unit:cm）
  //Serial.println(Left_Distance);       //display  distance
}

void right_detection()
{
  for(int i=0;i<=15;i++) //Produce PWM number, equivalent delay to ensure that it can turn to the response angle
  {
    servopulse(servopin,0);
  }
  Right_Distance = Distance_test();
  //Serial.print("Right_Distance:");      //Output distance（unit:cm）
  //Serial.println(Right_Distance);       //display  distance
}
//===========================================================
void loop()
{
 keysacn();	   
  while(1)
  {
    front_detection();//Measuring the distance ahead
    if(Front_Distance < 32)//When encounter an obstacle
    {
      back(2);
      brake(2);//Stop for distance measurement
      left_detection();//Measure the distance to the left distance obstacle
      Distance_display(Left_Distance);//LCD screen display distance
      right_detection();//Measure the distance to the right distance obstacle
      Distance_display(Right_Distance);//LCD screen display distance
      if((Left_Distance < 35 ) &&( Right_Distance < 35 ))//When there are obstacles on both sides of the side
        spin_left(0.7);//rotate and turn around
      else if(Left_Distance > Right_Distance)//The left is more open than the right.
      {      
        left(3);
        brake(1);//brake, stable direction
      }
      else//The right is more open than the left
      {
        right(3);
        brake(1);//brake, stable direction
      }
    }
    else
    {
      run(); //No obstacle, run     
    }
  } 
}











