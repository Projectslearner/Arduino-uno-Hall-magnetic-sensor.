/*
    Project name : Arduino Uno Hall Magnetic Sensor
    Modified Date: 29-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-hall-magnetic-sensor
*/

// Define the pin connected to the Hall effect sensor
const int hallSensorPin = 2;

void setup() {
  // Initialize the Hall sensor pin as input
  pinMode(hallSensorPin, INPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the state of the Hall effect sensor
  int sensorState = digitalRead(hallSensorPin);

  // Check if the sensor is triggered by a magnetic field
  if (sensorState == LOW) {
    // Magnetic field detected
    Serial.println("Magnetic field detected!");
  } else {
    // No magnetic field detected
    Serial.println("No magnetic field.");
  }

  delay(500);  // Delay for 500 milliseconds
}
