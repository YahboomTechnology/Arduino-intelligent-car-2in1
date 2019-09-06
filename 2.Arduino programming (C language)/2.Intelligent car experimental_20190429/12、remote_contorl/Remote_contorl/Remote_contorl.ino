//============================yahboom========================================
//  Intelligent car IRemote contorl

//In the experiment, the received infrared signal is used as the signal for the distribution remote control, 
//and the signal value can be printed out with other infrared signals control.

//The speed of the motor can not be adjusted in this experiment. 
//The adjustment of the PWM value will affect the signal reception of the infrared
//=============================================================================
#include <IRremote.h>
int RECV_PIN = A4;//declare port 
IRrecv irrecv(RECV_PIN);
decode_results results;//declare structure
int on = 0;//Marker bit
unsigned long last = millis();

long run_car = 0x00FF18E7;   //key 2
long back_car = 0x00FF4AB5;  //key 8
long left_car = 0x00FF10EF;  //key 4
long right_car = 0x00FF5AA5; //key 6
long stop_car = 0x00FF38C7;  //key 5
long left_turn = 0x00ff30CF; //key 1
long right_turn = 0x00FF7A85;//key 3
//==============================
int Left_motor_back=9;     //(IN1)
int Left_motor_go=5;       //(IN2)
int Right_motor_go=6;      //(IN3)
int Right_motor_back=10;   //(IN4)

void setup()
{
  //Initialize the motor drive IO for output mode
  pinMode(Left_motor_go,OUTPUT); // PIN 5 (PWM)
  pinMode(Left_motor_back,OUTPUT); // PIN 9 (PWM)
  pinMode(Right_motor_go,OUTPUT);// PIN 6 (PWM) 
  pinMode(Right_motor_back,OUTPUT);// PIN 10 (PWM)
  pinMode(13, OUTPUT);  //Define the key interface for the input interface
  Serial.begin(9600);	//baud rate 9600
  irrecv.enableIRIn();  // Start the receiver
}
void run()     
{
  digitalWrite(Right_motor_go,HIGH);  //right motor go
  digitalWrite(Right_motor_back,LOW);     
  //analogWrite(Right_motor_go,200);//PWM ratio 0~255 speed control, 
                                 //the difference of left and right wheel slightly increase or decrease
  //analogWrite(Right_motor_back,0);
  digitalWrite(Left_motor_go,HIGH);   // left motor go
  digitalWrite(Left_motor_back,LOW);
  //analogWrite(Left_motor_go,200);//PWM ratio 0~255 speed control, 
                                   //the difference of left and right wheel slightly increase or decrease
  //analogWrite(Left_motor_back,0);
  //delay(time * 100);   //execution time, can be adjusted   
}

void brake()         
{
  digitalWrite(Right_motor_go,LOW);
  digitalWrite(Right_motor_back,LOW);
  digitalWrite(Left_motor_go,LOW);
  digitalWrite(Left_motor_back,LOW);
  //delay(time * 100);//execution time, can be adjusted  
}

void left()         //turn left(left wheel stop,right wheel go)
{
  digitalWrite(Right_motor_go,HIGH);	//right motor go
  digitalWrite(Right_motor_back,LOW);
  //analogWrite(Right_motor_go,200); 
  //analogWrite(Right_motor_back,0); //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);   
  digitalWrite(Left_motor_back,LOW);
  //analogWrite(Left_motor_go,0); 
  //analogWrite(Left_motor_back,0);//PWM ratio 0~255 speed control
  //delay(time * 100);	//execution time, can be adjusted   
}

void spin_left()         //left rotation(left wheel back，right wheel go)
{
  digitalWrite(Right_motor_go,HIGH);	//right motor go
  digitalWrite(Right_motor_back,LOW);
  //analogWrite(Right_motor_go,200); 
  //analogWrite(Right_motor_back,0); //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);   //left motor back
  digitalWrite(Left_motor_back,HIGH);
  //analogWrite(Left_motor_go,0); 
  //analogWrite(Left_motor_back,200);//PWM ratio 0~255 speed control
  //delay(time * 100);	//execution time, can be adjusted 
}

void right()        //turn right (right wheel stop,left wheel go)
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,LOW);
  //analogWrite(Right_motor_go,0); 
  //analogWrite(Right_motor_back,0);//PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH); //left motor go
  digitalWrite(Left_motor_back,LOW);
  //analogWrite(Left_motor_go,200); 
  //analogWrite(Left_motor_back,0);//PWM ratio 0~255 speed control
  //delay(time * 100);	//execution time, can be adjusted   
}

void spin_right()        //right rotation(right wheel back,left wheel go)
{
  digitalWrite(Right_motor_go,LOW);   
  digitalWrite(Right_motor_back,HIGH);  //right motor back
  //analogWrite(Right_motor_go,0); 
  //analogWrite(Right_motor_back,200);  //PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,HIGH);     //left motor go
  digitalWrite(Left_motor_back,LOW);
  //analogWrite(Left_motor_go,200); 
  //analogWrite(Left_motor_back,0);    //PWM ratio 0~255 speed control
  //delay(time * 100);	//execution time, can be adjusted   
}

void back()          
{
  digitalWrite(Right_motor_go,LOW);   //right motor back
  digitalWrite(Right_motor_back,HIGH);
  //analogWrite(Right_motor_go,0);
  //analogWrite(Right_motor_back,150);//PWM ratio 0~255 speed control
  digitalWrite(Left_motor_go,LOW);    //left motor back
  digitalWrite(Left_motor_back,HIGH);
  //analogWrite(Left_motor_go,0);
  //analogWrite(Left_motor_back,150);//PWM ratio 0~255 speed control
  //delay(time * 100);     //execution time, can be adjusted 
}

void dump(decode_results *results)
{
  int count = results->rawlen;
  if (results->decode_type == UNKNOWN) 
  {
    //Serial.println("Could not decode message");
    brake();
  } 
//Serial port printing, debugging can be opened, 
//the actual operation will affect the speed of reaction, it is recommended to shield
/*
  else 
  {

    if (results->decode_type == NEC) 
    {
      Serial.print("Decoded NEC: ");
    } 
    else if (results->decode_type == SONY) 
    {
      Serial.print("Decoded SONY: ");
    } 
    else if (results->decode_type == RC5) 
    {
      Serial.print("Decoded RC5: ");
    } 
    else if (results->decode_type == RC6) 
    {
      Serial.print("Decoded RC6: ");
    }
    Serial.print(results->value, HEX);
    Serial.print(" (");
    Serial.print(results->bits, DEC);
    Serial.println(" bits)");
    
  }
  Serial.print("Raw (");
  Serial.print(count, DEC);
  Serial.print("): ");

  for (int i = 0; i < count; i++) 
  {
    if ((i % 2) == 1) 
    {
      Serial.print(results->rawbuf[i]*USECPERTICK, DEC);
    } 
    else  
    {
      Serial.print(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
    Serial.print(" ");
  }
  Serial.println("");
*/
}

void loop()
{
  if (irrecv.decode(&results)) //Call library function: decode
  {
    // If it's been at least 1/4 second since the last
    // IR received, toggle the relay
    if (millis() - last > 250) //Determine the received signal
    {
      on = !on;
      digitalWrite(13, on ? HIGH : LOW);
      //The signal is received on the board, led_twinkle

      dump(&results);//Decoded infrared signal
    }
    if (results.value == run_car )//key 2
      run();
    if (results.value == back_car )//key 8
      back();
    if (results.value == left_car )//key 4
      left();//turn left
    if (results.value == right_car )//key 6
      right();//turn right
    if (results.value == stop_car )//key 5
      brake();
    if (results.value == left_turn )//key 1
      spin_left();//left retation
    if (results.value == right_turn )//key 3
      spin_right();//right retation 
    last = millis();      
    irrecv.resume(); // Receive the next value
  }
}



