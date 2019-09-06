const int row1 = 2; // Arduino Pin2 connect lattice line number 9
const int row2 = 3; // Arduino Pin3 connect lattice line number 14
const int row3 = 4; // Arduino Pin4 connect lattice line number 8
const int row4 = 5; // Arduino Pin5 connect lattice line number 12
const int row5 = 17; // Arduino Pin17 (A3) connect lattice line number 1
const int row6 = 16; // Arduino Pin16 (A2) connect lattice line number 7 
const int row7 = 15; //Arduino Pin15 (A1) connect lattice line number 2
const int row8 = 14; // Arduino Pin14 (A0) connect lattice line number 5
//the pin to control COl 
const int col1 = 6; //Arduino Pin6 connect lattice column number 13
const int col2 = 7; //Arduino Pin7 connect lattice column number 3
const int col3 = 8; //Arduino Pin8 connect lattice column number 4
const int col4 = 9; // Arduino Pin9 connect lattice column number 10
const int col5 = 10; //Arduino Pin10 connect lattice column number 6 
const int col6 = 11; //Arduino Pin11 connect lattice column number 11 
const int col7 = 12; //Arduino Pin12 connect lattice column number 15
const int col8 = 13; //Arduino Pin13 connect lattice column number 16
void setup()
{ 
	int i = 0 ; 
	for(i=2;i<18;i++) 
	{ 
		pinMode(i, OUTPUT); //Set to output (including the analog port, also set as a digital output)
	} 

	for(i=2;i<18;i++) { 
		digitalWrite(i, LOW); //Pull low
	} 

} 
void loop()
{ 
	int i; 
	//the row # 1 and col # 1 of the LEDs turn on 
	digitalWrite(row1, HIGH); 
	digitalWrite(row2, LOW); 
	digitalWrite(row3, LOW); 
	digitalWrite(row4, LOW); 
	digitalWrite(row5, LOW); 
	digitalWrite(row6, LOW); 
	digitalWrite(row7, LOW); 
	digitalWrite(row8, LOW); 
	digitalWrite(col1, LOW); 
	digitalWrite(col2, HIGH); 
	digitalWrite(col3, HIGH); 
	digitalWrite(col4, HIGH); 
	digitalWrite(col5, HIGH); 
	digitalWrite(col6, HIGH); 
	digitalWrite(col7, HIGH); 
	digitalWrite(col8, HIGH); 
	delay(1000); 
	//turn off all 
	for(i=2;i<18;i++) { 
		digitalWrite(i, LOW); 
	} 
	delay(1000); 
} 
