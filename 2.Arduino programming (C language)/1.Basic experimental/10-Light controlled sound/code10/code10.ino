int buzzer=6;//Set the digital IO foot to control the buzzer
int i = 0;
void setup() 
{ 
pinMode(buzzer,OUTPUT);//Set the digital IO foot mode, OUTPUT for output
} 
void loop() 
{ 
    for(i=0;i<80;i++)//Output a frequency of sound
    { 
      digitalWrite(buzzer,HIGH);//sound
      delay(1); 
      digitalWrite(buzzer,LOW);//no sound
      delay(1);
    } 
    for(i=0;i<100;i++)//Output ano frequency of sound 
    { 
      digitalWrite(buzzer,HIGH);//sound
      delay(2); 
      digitalWrite(buzzer,LOW);//no sound
      delay(2);
    } 
}

