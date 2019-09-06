int BASE = 2 ;  //The I/O foot of the first LED
int NUM = 6;   //The total number of LED
int i=0;
void setup()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     pinMode(i, OUTPUT);   //Set the digital I/O foot for output
   }
}

void loop()
{
   for (i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, LOW);    //Set the number I/O foot to be "low",  the order is extinguished.
     delay(200);     
   }
   for (i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, HIGH);    //Set the number I/O foot to be "high",  the order is lighted.
     delay(200);       
   }  
}

