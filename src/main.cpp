#include <Arduino.h>
#include <Servo.h>

#define MAX_ANGLE 180
#define MIN_ANGLE 0
#define MAX_MS 2500
#define MIN_MS 500

const int FR_pin = 3;
const int FL_pin = 5;
const int BR_pin = 6;
const int BL_pin = 9;

// #define STATIC_INPUT
// #define DYNAMIC_INPUT

Servo servo_0; // Create a servo object
Servo servo_1; // Create a second servo object
Servo servo_2; // Create a third servo object
Servo servo_3; // Create a fourth servo object
// String userInput = ""; // String to store user input that is part of the String class

void setup() {
  // put your setup code here, to run once:
  servo_0.attach(FR_pin);
  servo_1.attach(FL_pin);
  servo_2.attach(BR_pin);
  servo_3.attach(BL_pin);

  // Hardcoded angle for now
  int angle = 90;

  // Map the angle to microseconds
  float us_amount = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_MS, MAX_MS);
  servo_0.writeMicroseconds(us_amount);
  servo_1.writeMicroseconds(us_amount);
  servo_2.writeMicroseconds(us_amount);
  servo_3.writeMicroseconds(us_amount);

  // Serial.begin(9600);

  // #ifdef STATIC_INPUT
  // Serial.print("Enter the desired angle: ");
  // #endif

  // #ifdef DYNAMIC_INPUT
  // Serial.println("\nPress 'a' to decrease angle, 'd' to increase angle:");
  // #endif
}

void loop() {
  int angle = 0 ;
  float us_amount = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_MS, MAX_MS);
  servo_2.writeMicroseconds(us_amount);
  delay(50);
  angle += 1;
  if (angle > MAX_ANGLE) {
    angle = MIN_ANGLE;
  }

  // put your main code here, to run repeatedly:
  // Serial.println("Hello world");
}

// #ifdef STATIC_INPUT

// void loop() {
//   // Check if any data is available
//   while (Serial.available() > 0) {
//     char receivedChar = Serial.read();  // Read each character

//     // Echo the character back to the Serial Monitor
//     Serial.print(receivedChar);         // Print it as you type

//     // Check for newline (Enter key)
//     if (receivedChar == '\n') {
//       int angle = userInput.toInt(); // Convert the input to an integer

//       // Ensure the angle is within the valid range
//       angle = constrain(angle, MIN_ANGLE, MAX_ANGLE);

//       // Map the angle to microseconds
//       float ms_amount = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_MS, MAX_MS);
//       servo_1.writeMicroseconds(ms_amount);

//       // Clear the input string for the next entry
//       userInput = "";
//       Serial.print("\nEnter the next desired angle: ");

//     } else {
//       // Add character to input string if it's not the newline
//       userInput += receivedChar;
//     }
//   }
// }

// #endif

// #ifdef DYNAMIC_INPUT

// int angle = 0;
// int step_size = 1;

// void loop() {
//   // Check if any data is available
//   while (Serial.available() > 0) {
//     char receivedChar = Serial.read();  // Read each character

//     // Adjust angle based on received character
//     if (receivedChar == 'd' && angle < MAX_ANGLE) {
//       angle += step_size;
//     } else if (receivedChar == 'a' && angle > MIN_ANGLE) {
//       angle -= step_size;
//     }

//     // Map the angle to microseconds
//     float ms_amount = map(angle, MIN_ANGLE, MAX_ANGLE, MIN_MS, MAX_MS);
//     servo_1.writeMicroseconds(ms_amount);
    
//     // Print the current angle
//     Serial.print("Current angle: ");
//     Serial.println(angle);
//   }
// }

// #endif