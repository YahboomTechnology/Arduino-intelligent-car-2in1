int redled =10; //Define number 10 interface
int yellowled =7; //Define number 7 interface
int greenled =4; //Define number 4 interface
void setup()
{
  pinMode(redled, OUTPUT);//Define the red light interface for the output interface
  pinMode(yellowled, OUTPUT); //Define the yellow light interface for the output interface
  pinMode(greenled, OUTPUT); //Define the green light interface for the output interface
}
void loop()
{
  digitalWrite(redled, HIGH);//Light the red light
  delay(1000);
  digitalWrite(redled, LOW); //Extinguish the red light
  digitalWrite(yellowled, HIGH);//Light the yellow light
  delay(200);
  digitalWrite(yellowled, LOW);//Extinguish the yellow light
  digitalWrite(greenled, HIGH);//Light the green light
  delay(1000);
  digitalWrite(greenled, LOW);//Extinguish the green light
}

