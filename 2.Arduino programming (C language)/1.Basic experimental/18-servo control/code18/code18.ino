//UART send 1~9==>20~180 degree
int servopin=2;//Set the servopin to the digital port 9
int myangle;//Define angle variables
int pulsewidth;//Define pulse width variable
int val;
void servopulse(int servopin,int myangle)/*Define a pulse function that is used to simulate a PWM value*/
{
  pulsewidth=(myangle*11)+500;//Turn the angle to 500-2480 of the pulse width
  digitalWrite(servopin,HIGH);//Servopin port is high level
  delayMicroseconds(pulsewidth);//The number of microseconds of the delayed pulse width
  digitalWrite(servopin,LOW);//Servopin port is low level
  delay(20-pulsewidth/1000);//Remainder time in time delay
}
void setup()
{
  pinMode(servopin,OUTPUT);//Set the servo interface to the output interface
  Serial.begin(9600);//Set the baud rate to 9600
  Serial.println("servo=o_seral_simple ready" ) ;
}
void loop()
{
	val=Serial.read();//Read the data received from the serial port
	if(val>'0'&&val<='400')//Determine whether the value of the received data is in conformity with the range
	{
		val=val-'0';//Convert ASCII code into numeric value，eg:'9'-'0'=0x39-0x30=9
		//val=val*(180/9);//Convert numbers to angles，eg:9*（180/9）=180
		Serial.print("moving servo to ");
		Serial.print(val,DEC);
		Serial.println();
		for(int i=0;i<=50;i++) //Produce PWM number, equivalent delay to ensure that it can turn to the response angle
		{
			servopulse(servopin,val);//Analog generation of PWM
		}
	}
}
