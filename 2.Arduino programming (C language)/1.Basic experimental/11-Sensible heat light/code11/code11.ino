int potpin=0;//Setting the analog port A0
int ledpin=11;//Set the digital port 11, which is later used as the PWM output
int val=0;//Declare variable val
void setup()
{
	pinMode(ledpin,OUTPUT);//Set the number 11 as the output mode
	Serial.begin(9600);//Set the baud rate to be 9600
}
void loop()
{
	val=analogRead(potpin);//Read the analog voltage value of A0 and assign it to val
	val = 245- val/2;
        if(val < 0)
          val = 0;
	Serial.println(val);
	analogWrite(ledpin,val);// PWM output driver LED
	delay(100);
}
