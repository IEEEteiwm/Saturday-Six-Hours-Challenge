#include <LiquidCrystal.h>              //Library for the lcd screen
#include "cactus_io_HIH6130.h"          //Library for the temperature sensor
byte address = 0x27;                    //Sets the save address for the temperature variable
HIH6130 hih6130(address);               //Uses the sensor library to set the temperature variable with right value 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  //Finds the appropriate lcd pins

void setup() {
  lcd.begin(16, 2);     //Setup for the lcd screen
  pinMode(7,OUTPUT);    //Setup for the lcd screen
  digitalWrite(7,HIGH); //Setup for the lcd screen
}

void loop() {
lcd.setCursor(0,0);               //Sets the cursor location for the lcd at 0,0 (0 colum,0 line))
lcd.print("The temperature");     //Prints the "The temperature" on screen
lcd.setCursor(0,1);               //Sets the cursor location for the lcd at 0,1 (0 colum,1 line))       
lcd.print("is : ");               //Prints the "is : " on screen
hih6130.readSensor();             //Reads the realtime temperature and sets the variable
lcd.print(hih6130.temperature_C); //Prints the value of the temperature variable
lcd.print(" C");                  //Prints the " C" on screen
delay(1000);                      //Resets the loop 
}

