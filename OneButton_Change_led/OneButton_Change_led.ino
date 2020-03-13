/*
 * Project: Using One Button change LEDs
 * Author: John Valdez
 * Date: 3-4-2020
 */

#include <OneButton.h>

OneButton button1 (23,false);

int buttonState = LOW;
int flash = LOW;
int flashState;
int ledG = 14;
int ledY = 4;
int ledB = 5;

void setup() {
  // put your setup code here, to run once:

  pinMode (ledG,OUTPUT);
  pinMode (ledY,OUTPUT);
  pinMode (ledB,OUTPUT);

// Setup Serial Monitor

    Serial.begin(9600);
    while (!Serial);
    Serial.println ("Ready to Start");

  // Link oneButton library to function click1, doubleclick1.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.setClickTicks(250);
  button1.setPressTicks(2000);

  if (Serial) Serial.println("Starting OneButton...");

}

void loop() {
  // put your main code here, to run repeatedly:
 button1.tick();

    if(buttonState == LOW) {
      digitalWrite(ledG,LOW);}
      
    else
    
    { if (flash == LOW) {
        digitalWrite(ledG,HIGH);}
        
       else
       {
         
        digitalWrite (ledY,HIGH);
        delay(50);
        digitalWrite (ledY,LOW);
        delay(50);
        }
        
    }
    }


 // loop



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
  Serial.println(flash);}
 // doubleclick1
