//============================Yahboom========================================
//  Intelligent car bluetooth remote control experiment
//=============================================================================

#define run_car     '1'
#define back_car    '2'
#define left_car    '3'
#define right_car   '4'
#define stop_car    '0'
#define left_turn   0x06
#define right_turn  0x07
/*Car running status enumeration*/
enum{
  enSTOP = 0,
  enRUN,
  enBACK,
  enLEFT,
  enRIGHT
}enCarState;
//==============================
//
//Speed control
#define level1  0x08
#define level2  0x09
#define level3  0x0A
#define level4  0x0B
#define level5  0x0C
#define level6  0x0D
#define level7  0x0E
#define level8  0x0F
//==============================
//==============================
int Left_motor_back = 9;      //Left motor back(IN1)
int Left_motor_go = 5;        //Left motor forward(IN2)
int Right_motor_go = 6;       //Right motor forward(IN3)
int Right_motor_back = 10;    //Right motor back(IN4)
int buzzer = 8;//Buzzer connects to wiringPi port 10 of Arduino UNO 

int control = 150;
int incomingByte = 0;         
String inputString = "";         //This array is used to store received content
boolean newLineReceived = false; 
boolean startBit  = false;  
int g_carstate = enSTOP;      //1run 2back 3left 4right 0stop

/*ultrasonic*/
int Echo = A5;  // Define the EchoPin connect to port A5 of Arduino UNO
int Trig =A4;  //  Define the TrigPin connect to port A4 of Arduino UNO
int Distance = 0;
String returntemp = ""; 

/*servo*/
int servopin = 2;  

/*lighting*/
int Led = 13;
/*OutFire*/
int Fire = 12;

int speakerPin= 11;

/*All tones*/
#define BL1 248
#define BL2 278
#define BL3 294
#define BL4 330
#define BL5 371
#define BL6 416
#define BL7 467

#define B1 495
#define B2 556
#define B3 624
#define B4 661
#define B5 742
#define B6 833
#define B7 935

#define BH1 990
#define BH2 1112
#define BH3 1178
#define BH4 1322
#define BH5 1484
#define BH6 1665
#define BH7 1869

#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495

#define NTCL1 131
#define NTCL2 147
#define NTCL3 165
#define NTCL4 175
#define NTCL5 196
#define NTCL6 221
#define NTCL7 248

#define NTCH1 525
#define NTCH2 589
#define NTCH3 661
#define NTCH4 700
#define NTCH5 786
#define NTCH6 882
#define NTCH7 990

#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 1112

#define NTE1 330
#define NTE2 350
#define NTE3 393
#define NTE4 441
#define NTE5 495
#define NTE6 556
#define NTE7 624

#define NTEL1 165
#define NTEL2 175
#define NTEL3 196
#define NTEL4 221
#define NTEL5 248
#define NTEL6 278
#define NTEL7 312

#define NTEH1 661
#define NTEH2 700
#define NTEH3 786
#define NTEH4 882
#define NTEH5 990
#define NTEH6 1112
#define NTEH7 1248

//List all the beats
/*Two TigersC*/
/*int tune[]=                 //The frequencies are listed according to the spectrum
{
 NTC1,NTC2,NTC3,NTC1,
 NTC1,NTC2,NTC3,NTC1,
 NTC3,NTC4,NTC5,
 NTC3,NTC4,NTC5,
 NTC5,NTC6,NTC5,NTC4,NTC3,NTC1,
 NTC5,NTC6,NTC5,NTC4,NTC3,NTC1,
 NTC2,NTCL5,NTC1,
 NTC2,NTCL5,NTC1
};
float durt[]=                   //The beats are listed according to the spectrum
{
  1,1,1,1,
  1,1,1,1,
  1,1,2,
  1,1,2,
  0.75,0.25,0.75,0.25,1,1,
  0.75,0.25,0.75,0.25,1,1,
  1,1,2,
  1,1,2
};*/

//Little Apple
int tune[]=                 //The frequencies are listed according to the spectrum
{
  B3, B1, B2, BL6,
  B3,B2,B1,B2,BL6,
  B3,B1,B2,B2,
  B5,B3,BL7,B1,B1,BL7,
  BL6,BL7,B1,B2,BL5,
  B6,B5,B3,B3,B2,
  B1,B2,B3,B2,B3,B2,B3,B5,
  B5,B5,B5,B5,B5,B5,
//  B3,B1,B2,BL6,
//  B3,B2,B1,B2,BL6,
//  B3,B1,B2,B2,B2,
//  B5,B3,BL7,B1,B1,BL7,
//  BL6,BL7,B1,B2,BL5,
//  B6,B5,B3,B3,B2,
//  B1,B2,B3,B2,BL5,
//  BL6,BL6,B1,BL6,B1
  
};
float durt[]=                   //The beats are listed according to the spectrum
{
  1,1,1,1,
  0.5,0.5,0.5,0.5,2,
  1,1,1,1,
  0.5,0.5,1,1,0.5,0.5,
  
  1,0.5,0.5,1,1,
  0.5,0.5,1,1.5,0.5,
  1,0.5,0.5,0.5,0.5,0.5,0.25,0.25,
  1,0.5,0.5,0.5,0.5,1,
  
//  1,1,1,1,
//  0.5,0.5,0.5,0.5,2,
//  1,1,1,0.5,0.5,
//  0.5,0.5,1,1,0.5,0.5,
//  
//  1,0.5,0.5,1,1,
//  0.5,0.5,1,1.5,0.5,
//  1,0.5,0.5,1,1,
//  1,0.5,0.5,1,1,1
};

void setup()
{
  //Initialize the motor drive IO as the output mode
  pinMode(Left_motor_go, OUTPUT); 
  pinMode(Left_motor_back, OUTPUT); 
  pinMode(Right_motor_go, OUTPUT); 
  pinMode(Right_motor_back, OUTPUT); 
  pinMode(buzzer,OUTPUT);
  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT);  
  
  Serial.begin(9600);	
 
  pinMode(servopin,OUTPUT);      
  pinMode(Led, OUTPUT);   
  pinMode(Fire, OUTPUT);  
  pinMode(speakerPin, OUTPUT); 
   
  //digitalWrite(buzzer,HIGH);   
 // digitalWrite(Led,HIGH);    
 // digitalWrite(Fire,HIGH);   

  
}

void Distance_test()   
{
  digitalWrite(Trig, LOW);   // Input a low level of 2 us to the Trig pin
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  //Input a high level of at least 10 US to the Trig pin
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);    
  float Fdistance = pulseIn(Echo, HIGH);  // Read high level time (unit:microseconds)
  Fdistance= Fdistance/58;       //Y meter=（X second * 344）/2
  // X second =（ 2*Y meter）/344 ==》X second=0.0058 * Y meter ==》centimeter = microsecond / 58
  //Serial.print("Distance:");      //Output distance (unit:centimeters)
  //Serial.println(Fdistance);        
  Distance = Fdistance;
}  

void run()     // advance
{
   digitalWrite(Right_motor_back,LOW);        
   digitalWrite(Left_motor_back,LOW);
   digitalWrite(Right_motor_go,HIGH);  //Right motor advance
   digitalWrite(Left_motor_go,HIGH);  //Left motor advance
  
  analogWrite(Right_motor_go,control);
  analogWrite(Left_motor_go,control-25); //Speed control range 0~255
  //delay(time * 100);   //The execution time can be adjusted
}

void brake()         //brake
{
  digitalWrite(Left_motor_back, LOW);
  digitalWrite(Left_motor_go, LOW);
  digitalWrite(Right_motor_go, LOW);
  digitalWrite(Right_motor_back, LOW);
  //delay(time * 100);//The execution time can be adjusted
}

void left()         //turn left(left wheel stop，right wheel advance)
{
  digitalWrite(Right_motor_go, HIGH);	//Right motor advance
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_go, 200);    //Speed control range 0~255
   
  digitalWrite(Left_motor_go, LOW);    //Left motor stop
  digitalWrite(Left_motor_back, LOW);
}

void spin_left()         //turn left in place(left wheel back，right wheel advance)
{
  digitalWrite(Right_motor_go, HIGH);	//Right motor advance
  digitalWrite(Right_motor_back, LOW);
  analogWrite(Right_motor_go,control);  //Speed control range 0~255

  digitalWrite(Left_motor_go, LOW);     //Left motor back
  digitalWrite(Left_motor_back, HIGH);
  analogWrite(Left_motor_back,control); //Speed control range 0~255
  //delay(time * 100);	
}

void right()        //turn right(left wheel advance，right wheel stop)
{
  digitalWrite(Right_motor_go, LOW);   //Right motor stop
  digitalWrite(Right_motor_back, LOW);

  digitalWrite(Left_motor_go, HIGH);   //Left motor advance
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_go,200);      //Speed control range 0~255
}

void spin_right()        //turn right in place(left wheel advance，right wheel back)
{
  digitalWrite(Right_motor_go, LOW);     //Right motor back
  digitalWrite(Right_motor_back, HIGH);
  analogWrite(Right_motor_back,control); //Speed control range 0~255
  
  digitalWrite(Left_motor_go, HIGH);     //Left motor advance
  digitalWrite(Left_motor_back, LOW);
  analogWrite(Left_motor_go,control);   //Speed control range 0~255
}

void back()          //back
{
  digitalWrite(Right_motor_back, HIGH);
  digitalWrite(Left_motor_back, HIGH);
  digitalWrite(Right_motor_go, LOW);          //Right motor back
  digitalWrite(Left_motor_go, LOW);           //Left motor back

  analogWrite(Right_motor_back,control);      //Speed control range 0~255
  analogWrite(Left_motor_back,control-15);    //Speed control range 0~255
}
void whistle()   //whistle
{
    int i;
    for(i=0;i<80;i++)//Output a frequency of sound
    { 
      digitalWrite(buzzer,HIGH);//sound
      delay(10); 
      digitalWrite(buzzer,LOW);//no sound
      delay(1);
    } 
    for(i=0;i<100;i++)//Output another frequency of sound 
    { 
      digitalWrite(buzzer,HIGH);//sound
      delay(20);
      digitalWrite(buzzer,LOW);//no sound
      delay(2);
    } 
}

/*servo control*/
void servopulse(int servopin,int myangle)/*Define a pulse function to generate PWM values in an analog manner*/
{
  int pulsewidth;    //Define pulse width variable
  pulsewidth=(myangle*11)+500;//Convert the angle to a pulse width of 500-2480
  digitalWrite(servopin,HIGH);
  delayMicroseconds(pulsewidth);
  digitalWrite(servopin,LOW);
  delay(20-pulsewidth/1000);//Delay Remaining time 
}
void front_detection()
{
  //The number of cycles is reduced, in order to increase the reaction speed of the obstacle encountered by the car
  for(int i=0;i<=5;i++) //Generate PWM, equivalent delay to ensure that it can be turned to response angle
  {
    servopulse(servopin,90);
  }
}

void left_detection()
{
  for(int i=0;i<=15;i++) //Generate PWM, equivalent delay to ensure that it can be turned to response angle
  {
    servopulse(servopin,175);
  }
}

void right_detection()
{
  for(int i=0;i<=15;i++) //Generate PWM, equivalent delay to ensure that it can be turned to response angle
  {
    servopulse(servopin,5);
  }
}

void PlayTest()
{
 int length = sizeof(tune)/sizeof(tune[0]);   //calculate length
 for(int x=0; x < length;x++)
  {
    tone(speakerPin,tune[x]);
    delay(500*durt[x]);   //This is used to adjust the delay according to the beat. The 500 can be adjusted by yourself. 
    noTone(speakerPin);
  }
  
}
    
void loop() 
{  
   
    if (newLineReceived)
    {
      switch(inputString[1])
      {
        case run_car:   g_carstate = enRUN; Serial.print("run\r\n"); break;
        case back_car:  g_carstate = enBACK;  Serial.print("back\r\n");break;
        case left_car:  g_carstate = enLEFT; Serial.print("left\r\n");break;
        case right_car: g_carstate = enRIGHT; Serial.print("right\r\n");break;
        case stop_car:  g_carstate = enSTOP; Serial.print("brake\r\n");break;
        default:g_carstate = enSTOP;break;
       }
     if(inputString[3] == '1') 
     {
        spin_left();
        delay(2000); //2 s 
        brake();
        
     }
     else if(inputString[3] == '2')  
     {
        spin_right();
        delay(2000); //2 s
        brake();
     }
     if(inputString[5] == '1')  
     {
        whistle();
        Serial.print("whistle\r\n");
     }
     if(inputString[7] == '1')  
     {
        control +=50;
        if(control > 255)
        {
          control = 255;
        }
        Serial.print("expedite\r\n");
     }
     if(inputString[9] == '1')  
     {
        control -= 50;
        if(control < 50)
        {
          control = 100;
        }
        Serial.print("reduce\r\n");
     }     
     if(inputString[11] == '1')  
     {
        left_detection();
     }
     if(inputString[13] == '1')  
     {
       right_detection();
     }
     if(inputString[15] == '1')  
     {
       PlayTest();
     }
     
     if(inputString[17] == '1')  
     {
       digitalWrite(Led, !digitalRead(Led));   
     }
     
     if(inputString[19] == '1') 
     {
        digitalWrite(Fire, !digitalRead(Fire));   
     }
   
     if(inputString[21] == '1')  
     {
       front_detection();
     }
     //return state
     Distance_test();
     returntemp = "$0,0,0,0,0,0,0,0,0,0,0,";
     returntemp.concat(Distance);
     returntemp += "cm,4.2V#";
     Serial.print(returntemp);
     
     inputString = "";   // clear the string
     newLineReceived = false;
    }
    
    switch(g_carstate)
    {
      case enSTOP: brake();break;
      case enRUN:run();break;
      case enLEFT:left();break;
      case enRIGHT:right();break;
      case enBACK:back();break;
      default:brake();break;
    }
}
  
void serialEvent()
{
  while (Serial.available()) 
  {    
    incomingByte = Serial.read();              
    if(incomingByte == '$')
    {
      startBit= true;
    }
    if(startBit == true)
    {
       inputString += (char) incomingByte;     
    }  
    if (incomingByte == '#') 
    {
       newLineReceived = true; 
       startBit = false;
    }
  }
}



