#define BL1 248
#define BL2 278
#define BL3 294
#define BL4 330
#define BL5 371
#define BL6 416
#define BL7 467

#define B1 495
#define B2 556
#define B3 624
#define B4 661
#define B5 742
#define B6 833
#define B7 935

#define BH1 990
#define BH2 1112
#define BH3 1178
#define BH4 1322
#define BH5 1484
#define BH6 1665
#define BH7 1869

#define NTC1 262
#define NTC2 294
#define NTC3 330
#define NTC4 350
#define NTC5 393
#define NTC6 441
#define NTC7 495

#define NTCL1 131
#define NTCL2 147
#define NTCL3 165
#define NTCL4 175
#define NTCL5 196
#define NTCL6 221
#define NTCL7 248

#define NTCH1 525
#define NTCH2 589
#define NTCH3 661
#define NTCH4 700
#define NTCH5 786
#define NTCH6 882
#define NTCH7 990

#define NTD0 -1
#define NTD1 294
#define NTD2 330
#define NTD3 350
#define NTD4 393
#define NTD5 441
#define NTD6 495
#define NTD7 556

#define NTDL1 147
#define NTDL2 165
#define NTDL3 175
#define NTDL4 196
#define NTDL5 221
#define NTDL6 248
#define NTDL7 278

#define NTDH1 589
#define NTDH2 661
#define NTDH3 700
#define NTDH4 786
#define NTDH5 882
#define NTDH6 990
#define NTDH7 1112

#define NTE1 330
#define NTE2 350
#define NTE3 393
#define NTE4 441
#define NTE5 495
#define NTE6 556
#define NTE7 624

#define NTEL1 165
#define NTEL2 175
#define NTEL3 196
#define NTEL4 221
#define NTEL5 248
#define NTEL6 278
#define NTEL7 312

#define NTEH1 661
#define NTEH2 700
#define NTEH3 786
#define NTEH4 882
#define NTEH5 990
#define NTEH6 1112
#define NTEH7 1248


int speakerPin= 8;
int buzzer=8;//Defining the digital port 8 to control the buzzer
int i = 0;
/*YeZi C*/

int tune[]=                 //List the frequencies according to the simple spectrum
{
NTC3, NTC5, NTC5, NTC3, NTC6, NTC6, NTC7, NTC6, NTC6, NTC6, NTC5, NTCH1, NTCH1, NTCH1, NTCH1, NTC6,
 NTCH1, NTC6, NTC5, 

NTC3, NTC5, NTC5, NTC5, NTC3, NTC6, NTC6, NTC7, NTC6, NTC6, NTC6, NTC5, NTCH1, NTCH1, NTCH1,
 NTCH1, NTC6, NTC6, NTCH1,NTCH2, 

NTCH5, NTCH5, NTCH5, NTCH5,NTCH5, NTCH3, NTCH2, NTCH1, NTCH1, NTC6, NTCH1, NTC6, NTCH1, NTCH2,
  NTCH2, NTCH2, NTCH2,NTCH2, NTCH1, NTCH3, NTCH2, NTCH2, 

NTCH3, NTCH3, NTCH3, NTCH3, NTCH2, NTCH2, NTCH1, NTCH1, NTCH1, NTCH2, NTCH1, NTC6, NTC5, NTC5, 
 NTC5, NTC5, NTC6, NTC5,NTCH2, NTCH3,NTCH1,

 
};
float durt[]=                   //List the tempo according to the simple spectrum
{
0.5, 0.5, 1.5, 0.5
, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 2,
 
0.5, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 0.5, 1, 0.5, 0.5, 
0.5, 0.5, 0.5, 0.5, 2,
0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 1, 0.5, 0.5, 0.5, 1, 0.25,
  0.5, 0.5, 0.5, 0.5, 1, 0.25, 2, 

0.5, 1, 0.5, 0.5, 0.5, 1, 0.5, 1, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 1, 
 0.5, 0.5, 0.5, 0.5, 0.5, 2,
};

void PlayTest()
{
 int length = sizeof(tune)/sizeof(tune[0]);   //Calculate length
 for(int x=0; x < length;x++)
  {
    tone(speakerPin,tune[x]);
    delay(500*durt[x]);   //This is used to adjust the time delay according to the beat,500 this index can be adjusted by yourself. In this music, I find that 500 is more suitable.。
    noTone(speakerPin);
  }
  
}
void setup() 
{ 
pinMode(buzzer,OUTPUT); //Defining the buzzer port for the output port 
} 
void loop() 
{ 
         PlayTest();
}

