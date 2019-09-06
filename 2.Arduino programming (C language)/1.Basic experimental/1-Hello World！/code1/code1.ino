int val;      //Define variable val
int ledpin=13;//Define the digital interface13
void setup()
{
  Serial.begin(9600);//Set the baud rate to 9600, which is consistent with the software setup. 
                     //When access to a particular device, such as Bluetooth,
                    // we are also consistent with the baud rate of other devices。
  pinMode(ledpin,OUTPUT);//Set the number 13 port as the output interface,
                        // Arduino we use on the I/O port to do such a definition.
}
void loop()
{
  val=Serial.read();
  //Read the instructions or characters sent to Arduino by the personal computer and assign the instruction or character to the val
  if(val=='R')//Determine whether the received instruction or character is "R"。
  {//If the "R" character is received
    digitalWrite(ledpin,HIGH);  //Light the number 13 LED.   
    delay(500);
    digitalWrite(ledpin,LOW);  //Extinguish the number 13 port LED  
    delay(500);
    Serial.println("Hello World!");//display“Hello World！”
  }
}

