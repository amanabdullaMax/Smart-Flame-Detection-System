#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int flameSensorPin = 2; 
const int greenLedPin = 4;    
const int redLedPin = 7;      
const int buzzerPin = 8;      

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.init();                      
  lcd.backlight();
  
  Serial.begin(9600);
  
  lcd.setCursor(0, 0);
  lcd.print("Flame Detector");
  lcd.setCursor(0, 1);
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  int flameState = digitalRead(flameSensorPin); 
  
    
    
  lcd.setCursor(0, 0);
  
  if (flameState == HIGH) { 
    // Actions when flame is detected Danger
    digitalWrite(redLedPin, HIGH);   
    digitalWrite(greenLedPin, LOW);  
    digitalWrite(buzzerPin, HIGH);   
    
    lcd.print("WARNING: FIRE!  ");
    lcd.setCursor(0, 1);
    lcd.print("Buzzer Active   ");
  } else {
    // Actions when no flame is nearby Safe
    digitalWrite(redLedPin, LOW);    
    digitalWrite(greenLedPin, HIGH); 
    digitalWrite(buzzerPin, LOW);    
    
    lcd.print("Status: Safe    ");
    lcd.setCursor(0, 1);
    lcd.print("No Flame Nearby ");
  }
  
  delay(200);
}
        