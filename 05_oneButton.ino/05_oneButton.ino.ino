/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: John Valdez
 * Date: 3-3-2020
 */

#include <OneButton.h>

// Setup OneButton on pin 23
OneButton button1 (23,false);

int buttonState = LOW;
int flash = LOW; 
int ledGreen = 4;
int ledYellow = 5;
int blink1;


// Create variables buttonState and flash


void setup() {
  
  pinMode (ledGreen,INPUT);
  pinMode (ledYellow,INPUT);

// Setup Serial Monitor

   Serial.begin(9600);
   while (!Serial);
   Serial.println ("Ready to Start");
   
  // Link oneButton library to functions click1, doubleclick1, longPressStart1
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  /*button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);*/
  button1.setClickTicks(250);
  button1.setPressTicks(2000);

  if(Serial) Serial.println("Starting OneButton...");
 
} 

void loop() {

   if(buttonState == LOW) {
    //Serial.println(buttonState);Serial.println(flash);
    digitalWrite(ledGreen,LOW);
     
  }

  else

  { //digitalWrite(ledGreen,HIGH);}

    if (flash == LOW) {
      //Serial.println(buttonState);Serial.println(flash);
      digitalWrite (ledGreen, HIGH);
     // if(flash == HIGH){
        //digitalWrite(ledGreen,HIGH);
       /* delay (300);
        digitalWrite(ledGreen,LOW);
        delay (300);*/
      
    }

    else

      { 
       digitalWrite(ledGreen,HIGH);
       delay (50);
       digitalWrite(ledGreen,LOW);
       delay (50);
       button1.tick();
      }
     
  } 
  // keep watching the push buttons:
  button1.tick();
} // loop


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time.
void click1() {
  //change and print buttonState
 // Serial.println("button 1 click.");
  buttonState = !buttonState;
  Serial.print("buttonState = ");
  Serial.println(buttonState);
  Serial.print("flash = ");
  Serial.println(flash);
    
  
  
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
// change state of flash and print
  //Serial.println("Button 1 doubleclick.");
  flash = !flash;
  Serial.print("buttonState = ");
  Serial.println(buttonState);
  Serial.print("flash = ");
  Serial.println(flash);
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 Long Press...");
// print longPress
} // longPressStart1
