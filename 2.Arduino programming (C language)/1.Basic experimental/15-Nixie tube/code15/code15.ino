int a=7;//digital IO port 7 connecte a section on nixie tube
int b=6;//digital IO port 6 connecte b section on nixie tube
int c=5;// digital IO port 5 connecte c section on nixie tube
int d=11;// digital IO port 11 connecte d section on nixie tube
int e=10;// digital IO port 10 connecte e section on nixie tube
int f=8;//digital IO port 8 connecte f section on nixie tube
int g=9;// digital IO port 9 connecte g section on nixie tube 
int dp=4;// digital IO port 9 connecte dp section on nixie tube 
void digital_1(void) //display 1
{
	unsigned char j;
	digitalWrite(c,HIGH);//Light e section
	digitalWrite(b,HIGH);//Light b section 
	for(j=7;j<=11;j++)//port 7~11a,f,g,e,d section pull low
		digitalWrite(j,LOW);
	digitalWrite(dp,LOW);// decimal point is not light
}
void digital_2(void) //display 2
{
unsigned char j;
digitalWrite(b,HIGH);
digitalWrite(a,HIGH);
for(j=9;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
digitalWrite(c,LOW);
digitalWrite(f,LOW);
}
void digital_3(void) //display 3
{
unsigned char j;
digitalWrite(g,HIGH);
digitalWrite(d,HIGH);
for(j=5;j<=7;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
digitalWrite(f,LOW);
digitalWrite(e,LOW);
}
void digital_4(void) //display 4
{
digitalWrite(c,HIGH);
digitalWrite(b,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,LOW);
digitalWrite(a,LOW);
digitalWrite(e,LOW);
digitalWrite(d,LOW);
}
void digital_5(void) //display 5
{
unsigned char j;
for(j=7;j<=9;j++)
digitalWrite(j,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(dp,LOW);
digitalWrite(b,LOW);
digitalWrite(e,LOW);
}
void digital_6(void) //dispaly 6
{
unsigned char j;
for(j=7;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(c,HIGH);
digitalWrite(dp,LOW);
digitalWrite(b,LOW);
}
void digital_7(void) //display 7
{
unsigned char j;
for(j=5;j<=7;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
for(j=8;j<=11;j++)
digitalWrite(j,LOW);
}
void digital_8(void) //display 8
{
unsigned char j;
for(j=5;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
}

void digital_9(void) //display 9
{
digitalWrite(a,HIGH);
digitalWrite(b,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(e,LOW);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,HIGH);
}
void setup()
{
	int i;
	for(i=4;i<=11;i++)
		pinMode(i,OUTPUT);//set port 4-11 is output
}
void loop()
{
  while(1)
  {
    digital_1();//display 1
    delay(1000);//display 1s
    digital_2();//display 2
    delay(1000); 
    digital_3();//display 3
    delay(1000); 
    digital_4();//display 4
    delay(1000); 
    digital_5();//display 5
    delay(1000);
    digital_6();//display 6
    delay(1000); 
    digital_7();//display 7
    delay(1000); 
    digital_8();//display 8
    delay(1000);
    digital_9();//display 9
    delay(1000);
  }
}
