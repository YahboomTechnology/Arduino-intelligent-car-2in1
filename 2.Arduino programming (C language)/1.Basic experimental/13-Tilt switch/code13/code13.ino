int switchpin = 5;
int ledpin = 8;
int val = 0;
void setup() 
{ 
pinMode(ledpin,OUTPUT);
Serial.begin(9600);//set the serial baud rate is 9600
} 
void loop() 
{ 
        val = analogRead(switchpin);
	if(val>512)//analog voltage value 512 is just 2.5V
		digitalWrite(ledpin,HIGH);//More than 2.5V, pull up
	else//Less or equal 
		digitalWrite(ledpin,LOW);//pull low
        Serial.println(val);
}
