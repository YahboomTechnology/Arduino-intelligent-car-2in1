int ledpin=11;//define number 11 interface
int inpin=7;//define number 7 interface
int val;//define variable val
void setup()
{
  pinMode(ledpin,OUTPUT);//Define the light interface for the output interface
  pinMode(inpin,INPUT);//Define the key interface for the input interface
}
void loop()
{
  val=digitalRead(inpin);//Read the value of the 7 port level to the val
  if(val==LOW)//Check whether the key is pressed and the light on when the key is pressed
    digitalWrite(ledpin,LOW);
  else
    digitalWrite(ledpin,HIGH);
}

