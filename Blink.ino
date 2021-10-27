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
  
  // Displaying the result (for DEBUG)
  //Serial.println(buttonState);
  
  // The "INPUT_PULLUP" parameter reverts the button's logic
  // So if button pressed, buttonState is LOW
  if (buttonState == LOW) {
    // Exiting the program
    Serial.println("The button has been pressed, exiting...");
    delay(1000);
    exit(0);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    Serial.println("LED IS ON...");
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    Serial.println("LED IS OFF...");
    delay(1000);                       // wait for a second
  }
}
