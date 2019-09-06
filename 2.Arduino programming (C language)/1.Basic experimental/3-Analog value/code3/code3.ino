int potpin=0;   //Specify the analog port A0
int ledpin=13;  //Specify LED port 13
int val=0;      //define temporary variables
void setup()
{
  pinMode(ledpin,OUTPUT);//Set port 13 for output mode
  Serial.begin(9600);//Set the serial port baud rate to 9600
}
void loop()
{
  digitalWrite(ledpin,HIGH);//Pull up port 13, LED light
  delay(50);
  digitalWrite(ledpin,LOW);//Pull down port 13,LED close
  delay(50);
  val=analogRead(potpin);//Read the voltage value of the A0 port and assign it to val
  Serial.println(val);//Sending Val value by serial port
}
