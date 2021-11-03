/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly while the button is not pressed.
  The signal goes from pin 2 to GND, passing through a button

  This code is based on the article below:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial

  Blink a led without delay
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
*/

// VARIABLES
// Setting the button's pin and its default value
const int buttonPin = 2;
int buttonState = 0;

// Set the standby mode by default
boolean standbyMode = false;

// // will store last time LED was updated
unsigned long previousMillis = 0;

// Set the blink interval
const long interval = 1000;

void standbyModeSwitcher() {
  standbyMode = !standbyMode;
}

// SETUP
void setup() {
  // Initializing the serial communication
  Serial.begin(9600);
  
  // Initializing digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialializing the button (on pin 2) as an input
  pinMode(buttonPin, INPUT_PULLUP);

  // Trigger the function standbyModeSwitcher when the button is pressed
  // https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt(digitalPinToInterrupt(buttonPin), standbyModeSwitcher, CHANGE);
}


// START
void loop() {
  // Reading the state of the button's value
  buttonState = digitalRead(buttonPin);
  
  // Displaying the result (for DEBUG)
  //Serial.println(buttonState);
  
  // The "INPUT_PULLUP" parameter reverts the button's logic
  // So if button pressed, buttonState is LOW
  
  if (standbyMode == true) {
    // Put a job to do here
    // As we are in standby mode, do nothing
    Serial.println("Standby mode has been enabled, stop doing the job");

  } else {

    // Catch the time since the loop is running
    unsigned long currentMillis = millis();

    // If the diferrence between the current time and the last time we blinked the led 
    // is superior than the interval, is it time to blink the led
    if (currentMillis - previousMillis >= interval) {
      // We save the last time you blinked the LED
      previousMillis = currentMillis;

      // if the LED is off turn it on and vice-versa:
      if (digitalRead(LED_BUILTIN) == LOW) {
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.println("LED IS ON");
      } else {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("LED IS OFF");
      } 
    }
  }
}
