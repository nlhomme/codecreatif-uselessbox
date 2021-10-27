/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly while the button is not pressed.
  The signal goes from pin 2 to GND, passing through a button

  This code is based on the article below:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/InputPullupSerial
*/

// VARIABLES
// Setting the button's pin and its default value
const int buttonPin = 2;
int buttonState = 0;
boolean standbyMode = false;

// SETUP
void setup() {
  // Initializing the serial communication
  Serial.begin(9600);
  
  // Initializing digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Initialializing the button (on pin 2) as an input
  pinMode(buttonPin, INPUT_PULLUP);
}


// START
void loop() {
  // Reading the state of the button's value
  buttonState = digitalRead(buttonPin);
  
  // Displaying the result (for DEBUG purpose)
  //Serial.println(buttonState);
  
  // The "INPUT_PULLUP" parameter reverts the button's logic
  // So if button pressed, buttonState is LOW
  if (buttonState == LOW) {
    // If the button's state is pressed, toggle standby mode
    standbyMode = !standbyMode;
    if (standbyMode == true) {
      Serial.println("Standby mode has been enabled, stop doing the job");
    } else {
      Serial.println("Standby mode disabled, resuming the job...");
    }
    delay(1000);
  }
  
  if (standbyMode == true) {
    // Put a job to do here
    // As we are in standby mode, do nothing
  } else {
    // Put a job to do here
    // Turn the LED on for a second, then off for a second
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("LED IS ON...");
    delay(1000);
    
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("LED IS OFF...");
    delay(1000);
  }
}
