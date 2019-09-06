//connect 74hc595 pin10:MR--->VCC; Pin13:OE--->GND
int latchPin = 5;//to 595 pin12
int clockPin = 4;//to 595 pin11
int dataPin = 2; //to 595 pin14
void setup ()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT); //The three feet are all output states
}
void loop()
{
  for(int a=0; a<256; a++)
  //This loop means that the a variable, +1, has been added to 256, and each cycle takes the following activity
  {
    digitalWrite(latchPin,LOW); //Add the low level on the ST_CP port to prepare the chip to receive the data
    /*dataPin：The data output pin, each of the data will be output by one by one. Pin mode needs to be set to output
      clockPin：The clock output pin, provides the clock for the output of the data, the pin mode needs to be set to output.
      bitOrder：The data displacement sequence selection, which is byte type, has two types, which are high first entry MSBFIRST and low bit first LSBFIRST.
      a：The value of the data to be output*/
    digitalWrite(latchPin,HIGH); //Restore the pin of ST_CP to high level
    delay(1000); //delay 1 seconds to make you see the effect
  }  
}
