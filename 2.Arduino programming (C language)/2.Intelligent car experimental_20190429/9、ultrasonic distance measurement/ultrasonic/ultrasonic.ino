//============================yahboom===========================
//  Intelligent car ultrasonic distance measurement
//===============================================================
#include <LiquidCrystal.h> //Declare the function library of 1602 liquid crystals
//Declare the Arduino digital port connected by the pin of the 1602 LCD,
//8 or 4 line data modes, choose one of them.
//LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);   //8 data port mode connection statement
LiquidCrystal lcd(3,4,7,8,11,12,13); //4 data port mode connection statement

int Echo = A5;  // Echo(P2.0)
int Trig =A4;  //  Trig(P2.1)

int Distance = 0;

void setup()
{
  Serial.begin(9600);     //Initialize the serial port
  //Initialize the motor drive IO for output
  //Initialization of ultrasonic pins
  pinMode(Echo, INPUT);    // Define of ultrasonic input foot
  pinMode(Trig, OUTPUT);   // Define of ultrasonic output foot
  lcd.begin(16,2);         //Initialization of 1602 liquid crystal working mode
  //Define the 1602 LCD display range of 2 lines and 16 columns  
}


void Distance_test()            // Measuring the distance ahead
{
  digitalWrite(Trig, LOW);      // Give the trigger pin low level 2us
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);     // Give the trigger pin high level 10us，at least 10μs
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);      //Give the trigger pin low level Continuouly
  float Fdistance = pulseIn(Echo, HIGH);  //Reading high level time(unit：us)
  Fdistance= Fdistance/58;      //  Y meter =（X second *344）/2
  // X second=（ 2*Y meter ）/344 ==》Xsecond =0.0058*Y meter ==》cm = us /58
  Serial.print("Distance:");   //Output distance（unit：cm）
  Serial.println(Fdistance);   //display distance
  Distance = Fdistance;
}  

void loop()
{
  Distance_test();
  if((2<Distance)&(Distance<400))//Range of ultrasonic distance ranging from 2cm to 400cm
  {
    lcd.home();        //Move the cursor back to the upper left corner, 
                      //which is the beginning of the output   
    lcd.print("    Distance: "); //display
    lcd.setCursor(6,2);   //Position the cursor in second lines, sixth columns
    lcd.print(Distance);         //display distance
    lcd.print("cm");             //display
  }
  else
  {
    lcd.home();        //Move the cursor back to the upper left corner, 
                      //which is the beginning of the output 
    lcd.print("!!! Out of range");       //Display beyond distance
  }
  delay(250);
  lcd.clear();
}


