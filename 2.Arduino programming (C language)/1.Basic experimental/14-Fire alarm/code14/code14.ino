int flame=A5;//declare analog port A5
 int Beep=8;//declare digital port 8
 int val=0;//defien variable
void setup() 
{
	pinMode(Beep,OUTPUT);//digital port output mode
	pinMode(flame,INPUT);//analog port input mode
	Serial.begin(9600);//baud rate 9600 
	val=analogRead(flame);//read a analog port voltage
}
 
void loop() 
{  
	Serial.println(analogRead(flame));//serial port send Analog voltage value 
	if((analogRead(flame)-val)>=600)//determine whether the analog voltage is more than 600
		digitalWrite(Beep,HIGH); 
        else
                digitalWrite(Beep,LOW);
 }
