/*
Code by:
M.Hashir

This is a code that uses an Ultrasonic sensor to measure distance
And displays it on Serial Monitor and LCD

Hardware:
- Arduino
- Ultrasonic sensor module HC SR04
- 4 wires
- 16x2 LCD

Connections:

Ultrasonic sensor and Arduino
•	Connect GND of module to GND of Arduino
•	Connect VCC of module to 5V of Arduino
•	Connect Trigger of module to pin 9 of Arduino
•	Connect Echo of module to pin 10 of Arduino

LCD and Arduino
•	Connect pin 1 of LCD to GND of Arduino board.
•	Connect pin 2 of LCD to 5V of Arduino board.
•	Connect pin 3 of LCD to centre leg of pot. Connect one of the remaining legs of pot (potentiometer) to GND of Arduino and the third leg of pot to 5V of Arduino board.
•	Connect pin 4 of LCD to pin 12 of Arduino board.
•	Connect pin 5 of LCD to GND of Arduino board.
•	Connect pin 6 of LCD to pin 11 of Arduino board.
•	Connect pin 11 of LCD to pin 5 of Arduino board.
•	Connect pin 12 of LCD to pin 4 of Arduino board.
•	Connect pin 13 of LCD to pin 3 of Arduino board.
•	Connect pin 14 of LCD to pin 2 of Arduino board.
•	Connect pin 15 of LCD to pin 5V of Arduino board.
•	Connect pin 16 of LCD to pin GND of Arduino.

*/

#include <LiquidCrystal.h>          //library file added

int RS = 12;                        //connect RS of LCD to this pin
int E = 11;                         //connect E of LCD to this pin
int D4 = 5;                        //connect D4 of LCD to this pin
int D5 = 4;                        //connect D5 of LCD to this pin
int D6 = 3;                        //connect D6 of LCD to this pin
int D7 = 2;                        //connect D7 of LCD to this pin

int trigger = 9;              //Trigger of module is connected to pin 11 of Arduino
int echo=10;                   //Echo of module is connected to pin 10 of Arduino
int duration;                  //Will be used later on
float distance;                //Will be used later on

LiquidCrystal lcd(RS,E,D4,D5,D6,D7);

void setup() {

  lcd.begin(16,2);
  Serial.begin (9600);         //Do not edit this line
  pinMode(trigger, OUTPUT);    //Do not edit this line
  pinMode(echo, INPUT);        //Do not edit this line

}

void loop() {
      digitalWrite(trigger, LOW);  
      delayMicroseconds(2); 
      digitalWrite(trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger, LOW);
      duration = pulseIn(echo, HIGH);
      distance = (duration / 2) / 29.1;
      digitalWrite(trigger, LOW);  

      Serial.print("Distance= ");
      Serial.print(distance);
      Serial.println(" cm");
      lcd.setCursor(0,0);
      lcd.print("Distance=");
      lcd.print(distance);
      lcd.print(" cm");
delay(1000);
}
