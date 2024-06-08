/*
    Project name : Hall Effect Sensor with LED Indicator
    Modified Date: 08-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-hall-magnetic-sensor
*/

#define hallSensorPin 2
#define ledPin 13
#define debounceDelay 50 // Set debounce delay time in milliseconds

int previousState = HIGH; // Previous state of the sensor
unsigned long lastDebounceTime = 0; // Last time the input pin was toggled

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(hallSensorPin, INPUT_PULLUP); // Enable internal pull-up resistor for Hall Effect Sensor
  Serial.begin(9600); // Initialize Serial communication
}

void loop() {
  int currentState = digitalRead(hallSensorPin);

  // Check if the state of the sensor has changed
  if (currentState != previousState) {
    lastDebounceTime = millis(); // Reset the debounce timer
  }

  // Check if enough time has passed to consider it a valid change
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // If the state has changed, update the LED accordingly
    if (currentState == LOW) {
      digitalWrite(ledPin, HIGH); // Turn on LED
      Serial.println("Magnetic Field Detected!"); // Print to Serial Monitor
    } else {
      digitalWrite(ledPin, LOW); // Turn off LED
      Serial.println("No Magnetic Field Detected"); // Print to Serial Monitor
    }
  }

  // Update previous state for the next iteration
  previousState = currentState;
}
