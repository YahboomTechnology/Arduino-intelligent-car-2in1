#include <LiquidCrystal.h> //Declare 1602 liquid crystal libraries
//Declare the Arduino digital port connected by the pin of the 1602 LCD, 8 or 4 line data modes, choose one of them.
LiquidCrystal lcd(12,11,10,9,8,7,6,5,4,3,2);   //8 data port mode connection statement
//LiquidCrystal lcd(12,11,10,5,4,3,2); //4 data port mode connection statement
int i;
void setup()
{
  lcd.begin(16,2);      //Initialization of 1602 liquid crystal working mode
                       //Define the 1602 LCD display range of 2 lines and 16 columns
  while(1)
  {
    lcd.home();        //Move the cursor back to the upper left corner, which is the beginning of the output  
    lcd.print("Hello World"); 
    lcd.setCursor(0,1);   //Position the cursor in first lines, zeroth columns
    lcd.print("Welcome to BST-Arduino");    
    delay(500);
    for(i=0;i<3;i++)
    {
      lcd.noDisplay();
      delay(500);
      lcd.display();
      delay(500);
    }
    for(i=0;i<24;i++)
    {
      lcd.scrollDisplayLeft();
      delay(500);
    }
    lcd.clear();
    lcd.setCursor(0,0);        //Move the cursor back to the upper left corner, which is the beginning of the output  
    lcd.print("Hi,"); 
    lcd.setCursor(0,1);   //Position the cursor in first lines, zeroth columns
    lcd.print("Arduino is fun");       
    delay(2000);
  }
}
void loop()
{}//Initialization has completed display, main loop no action
