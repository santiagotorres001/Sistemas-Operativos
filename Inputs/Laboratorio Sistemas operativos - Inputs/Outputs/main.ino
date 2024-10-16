
#include <LiquidCrystal.h>
#define LED 13
#define MOTOR 10
#define tempVal	0

int seconds = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd_1.begin(13, 1); // Set up the number of columns and rows on the LCD.
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  
  
}

void alert(){
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);

}

void loop()
{
   float temp = 0;
  int sensorVal=analogRead(A0);
  
  
  //Se usa esta formula para un TMP36
  temp = ( sensorVal * (500.0 / 1023.0) - 50.0 )
    ;
  lcd_1.print("Tempe: ");
  lcd_1.print(temp);
  lcd_1.print("\xB0");
  lcd_1.println("C");
  
  if(temp <= 10.0){
     digitalWrite(MOTOR, LOW);  
     alert();
  }
  
  else if(temp >= 11.0 && temp <=25.0) {
     digitalWrite(MOTOR, LOW);  
     digitalWrite(LED, LOW);  

  }
  
  if(temp >= 26.0){
     digitalWrite(LED, HIGH);  
	 digitalWrite(MOTOR, HIGH);  
  }
 
  lcd_1.setCursor(0, 1);
  
}