/*
  Servo control
  (This file is named "Blink" due to the Arduino software restrictions)

  If the switch is toggled on, the servo motor rotate in a way during a short time, then the other way during the same amount of time.
  If not, the program switch to a standby mode, waiting for the switch to be toggled on.
  
  The switch signal goes from pin 2 to GND, passing through a switch

  This code is based on the article below:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial

  Blink a led without delay:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay

  Controlling a servo motor:
  https://www.carnetdumaker.net/articles/controler-un-servomoteur-avec-une-carte-arduino-genuino/
*/

// LIBRARIES
#include <Servo.h>

// VARIABLES
// Setting the switch's pin where the switch is linked and it's state
const int switchPin = 2;
int switchState;

// This variable will store last time the LED was updated
unsigned long previousMillis = 0;

// Set the blink interval (in ms)
const long interval = 1000;

// Declaring the servo motor and the working angles
Servo servoMotor;
const int servoAngleStart = 0;
const int servoAngleEnd = 180;

// SETUP
void setup() {
  // Initializing the serial communication
  Serial.begin(9600);
  
  // Initializing digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialializing the switch (on pin 2) as an input
  pinMode(switchPin, INPUT_PULLUP);

  // Initializing the Servo library
  servoMotor.attach(9);
}


// START
void loop() {
  // Resetting the servo motor
  //Serial.println("Initializing");
  //servoMotor.write(servoAngleStart);
  
  // Reading the state of the switch
  switchState = digitalRead(switchPin);
  
  // Displaying the result (for DEBUG)
  //Serial.println(switchState);
  
  // The "INPUT_PULLUP" parameter in setup() reverts the switch's logic
  // So if the switch is toggled off, switchState is HIGH (equals 1)
  
  if (switchState == 1) {
    // As we are in standby mode here, do nothing (or whatever you want)
    Serial.println("In standby mode, doing nothing");

  } else {
    // As we are in runnin mode here, do whatever you want)
    
    // Catch the time since the loop is running
    unsigned long currentMillis = millis();

    // If the diferrence between the current time and the last time the LED blinked 
    // is superior than the interval, is it time to blink the led
    if (currentMillis - previousMillis >= interval) {
      // We save the last time you blinked the LED
      previousMillis = currentMillis;

      // if the LED is off turn it on and vice-versa:
      if (digitalRead(LED_BUILTIN) == LOW) {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("LED IS ON");
        servoMotor.write(servoAngleEnd);
      } else {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("LED IS OFF");
        servoMotor.write(servoAngleStart);
      } 
    }
  }
}
