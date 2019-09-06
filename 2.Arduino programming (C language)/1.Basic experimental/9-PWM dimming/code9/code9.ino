int potpin=0;//Define the analog interface 0
int ledpin=11;//Define the digital interface 11 (PWM output)
int val=0;//Temporary storage of variable values from sensors
void setup()
{
  pinMode(ledpin,OUTPUT);//Define the digital interface 11 for output
  Serial.begin(9600);//Set the baud rate to 9600
//Note: the analog interface is automatically set to input
}
void loop()
{
  val=analogRead(potpin);// Read the analog value of the sensor and assign the value to the val
  Serial.println(val);//display val 
  analogWrite(ledpin,val/4);// Open the LED and set the brightness (PWM output maximum 255)
  delay(10);
}

