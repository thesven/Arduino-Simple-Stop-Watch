#include <LiquidCrystal.h>


const int BUTTON = 6;
const String INITIAL_MESSAGE = "Press to Start";
const String TIMING_MESSAGE = "Timing in Secs.";

int buttonVal = 0;
int buttonOldVal = 0;
int buttonState = 0;

long startTime = 0;
long endTime = 0;
boolean showTimer = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  
  lcd.begin(16, 2);
  lcd.print(INITIAL_MESSAGE);
  
  pinMode(BUTTON, INPUT);
  
}

void loop(){
 
 buttonVal = digitalRead(BUTTON);
 
 if(buttonVal == HIGH && buttonOldVal == LOW){
   buttonState = 1 - buttonState;
   
   if(buttonState == 1){
     startTimer();
   } else {
     endTimer(); 
   }
   
 }
 
 if(showTimer == true){
   printTime();
 }
 
 buttonOldVal = buttonVal;
  
}

void startTimer(){
 
 showTimer = true;
 startTime = millis();
 lcd.clear();
 lcd.print(TIMING_MESSAGE);
  
}

void endTimer(){
  
 showTimer = false;
 lcd.clear();
 lcd.print(INITIAL_MESSAGE);
 lcd.setCursor(0, 1);
 lcd.print(endTime / 1000);
 
}

void printTime(){
  
  long timeVal = endTime = millis() - startTime;
  
  lcd.setCursor(0, 1);
  lcd.print(timeVal / 1000);
  
}
