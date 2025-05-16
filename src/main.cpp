#include <Arduino.h>
#include <Servo.h>

const int motor_pin = 3;

#define MAX_ANGLE 180
#define MIN_ANGLE 0
#define MAX_MS 2500
#define MIN_MS 500

// #define STATIC_INPUT
#define DYNAMIC_INPUT

Servo servo_1; // Create a servo object
String userInput = ""; // String to store user input that is part of the String class

void setup() {
  // put your setup code here, to run once:
  servo_1.attach(motor_pin);
  Serial.begin(9600);

  #ifdef STATIC_INPUT
  Serial.print("Enter the desired angle: ");
  #endif

  #ifdef DYNAMIC_INPUT
  Serial.println("\nPress 'a' to decrease angle, 'd' to increase angle:");
  #endif
}

#ifdef STATIC_INPUT

void loop() {
  // Check if any data is available
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();  // Read each character

    // Echo the character back to the Serial Monitor
    Serial.print(receivedChar);         // Print it as you type

    // Check for newline (Enter key)
    if (receivedChar == '\n') {
      int angle = userInput.toInt(); // Convert the input to an integer

      // Ensure the angle is within the valid range
      angle = constrain(angle, MIN_ANGLE, MAX_ANGLE);

      // Map the angle to microseconds
      float ms_amount = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_MS, MAX_MS);
      servo_1.writeMicroseconds(ms_amount);

      // Clear the input string for the next entry
      userInput = "";
      Serial.print("\nEnter the next desired angle: ");

    } else {
      // Add character to input string if it's not the newline
      userInput += receivedChar;
    }
  }
}

#endif

#ifdef DYNAMIC_INPUT

int angle = 0;
int step_size = 1;

void loop() {
  // Check if any data is available
  while (Serial.available() > 0) {
    char receivedChar = Serial.read();  // Read each character

    // Adjust angle based on received character
    if (receivedChar == 'd' && angle < MAX_ANGLE) {
      angle += step_size;
    } else if (receivedChar == 'a' && angle > MIN_ANGLE) {
      angle -= step_size;
    }

    // Map the angle to microseconds
    float ms_amount = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_MS, MAX_MS);
    servo_1.writeMicroseconds(ms_amount);
    
    // Print the current angle
    Serial.print("Current angle: ");
    Serial.println(angle);
  }
}

#endif