#include <LiquidCrystal.h>
#include <Wire.h>
#include "RTClib.h"


RTC_DS1307 RTC;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Wire.begin();
  RTC.begin();
  lcd.begin(16, 2);
  if (! RTC.isrunning()){ 
      Serial.println("rtc in NOT running!");
      RTC.adjust(DateTime(F(__DATE__),F(__TIME__)));
  }
}

void loop() {
  DateTime now = RTC.now();
  Serial.print(now.year(),DEC);
  Serial.print("/");
  Serial.print(now.month(),DEC);
  Serial.print("/");
  Serial.print(now.day(),DEC);
  Serial.print(now.hour(),DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);
  Serial.println();
  
  // l'heure sur la premiêre ligne du LCD
  lcd.setCursor(0, 0);
  lcd.print("TIME: ");
  lcd.print(now.hour(),DEC);
  lcd.print(":");
  lcd.print(now.minute(), DEC);
  lcd.print(":");
  lcd.print(now.second(), DEC);
  
  // la date sur la deuxième ligne du LCD
  lcd.setCursor(0, 1);
  lcd.print("DATE: "); 
  lcd.print(now.year(),DEC);
  lcd.print("/");
  lcd.print(now.month(),DEC);
  lcd.print("/");
  lcd.print(now.day(),DEC); 
  delay(1000);
}  
