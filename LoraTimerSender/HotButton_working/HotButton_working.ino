#include <HotButton.h>

// Define the GPIO pins for buttons
const int button1Pin = 5;
const int button2Pin = 6;
const int button3Pin = 7;
const int commonPin = 4;

// Create HotButton objects
HotButton button1(button1Pin);
HotButton button2(button2Pin);
HotButton button3(button3Pin);

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Set common pin as output and set to LOW (ground)
  pinMode(commonPin, OUTPUT);
  digitalWrite(commonPin, HIGH);

}

void loop() {
  // Update button states
  button1.update();
  button2.update();
  button3.update();

  // Check if button1 is pressed
  if (button1.pressed()) {
    Serial.println("Button 1 pressed");
  }

  // Check if button2 is pressed
  if (button2.pressed()) {
    Serial.println("Button 2 pressed");
  }

  // Check if button3 is pressed
  if (button3.pressed()) {
    Serial.println("Button 3 pressed");
  }

  // Small delay to allow for debouncing
  delay(50);
}