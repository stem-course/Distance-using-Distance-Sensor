/*
Code by: www.munphurid.com
M.Hashir

This is a code that uses an Ultrasonic sensor to measure distance
And displays it on Serial Monitor

Hardware:
-Arduino
-Ultrasonic sensor module HC SR04
-4 wires

Connections:

Connect GND of module to GND of Arduino
Connect VCC of module to 5V of Arduino
Connect Trigger of module to pin 11 of Arduino
Connect Echo of module to pin 10 of Arduino

Connect VSS of Lcdpin to GND of Arduino
Connect VDD of Lcdpin to 5V of Arduino
Connect Vo/ VEE(potentiometer) of Lcdpin to GND of Arduino
Connect RS of Lcdpin to pin12 of Arduino
Connect RW of Lcdpin to GND of Arduino
Connect E of Lcdpin to pin11 of Arduino
D0 TO D3 NOT USED
Connect D4 of Lcdpin to PIN5 of Arduino
Connect D5 of Lcdpin to PIN4 of Arduino
Connect D6 of Lcdpin to PIN3 of Arduino
Connect D7 of Lcdpin to PIN2 of Arduino
Connect LED+/A of Lcdpin to 5V of Arduino
Connect LED-/K of Lcdpin to GND of Arduino

*/

int trigger = 11;              //Trigger of module is connected to pin 11 of Arduino
int echo=10;                   //Echo of module is connected to pin 10 of Arduino
int duration;                  //Will be used later on
float distance;                //Will be used later on

void setup() {
  Serial.begin (9600);         //Do not edit this line
  pinMode(trigger, OUTPUT);    //Do not edit this line
  pinMode(echo, INPUT);        //Do not edit this line
/*  pinMode(12, OUTPUT);
  pinMode(9,OUTPUT);
      digitalWrite(12,1);  
      digitalWrite(9, LOW);  
*/
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
delay(1000);
}
