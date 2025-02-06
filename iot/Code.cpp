#include <SoftwareSerial.h> // Include the software serial library

#define DTMF_RX_PIN 2       // Define the pin connected to DTMF decoder module Rx
#define MOTOR_PIN_1 3       // Define the pins connected to the motor drivers
#define MOTOR_PIN_2 4       // Adjust pins according to your hardware setup

SoftwareSerial dtmfSerial(DTMF_RX_PIN, -1); // RX, TX

void setup() {
  Serial.begin(9600);     // Initialize serial communication for debugging
  dtmfSerial.begin(9600); // Initialize software serial for DTMF communication
  pinMode(MOTOR_PIN_1, OUTPUT); // Set motor control pins as output
  pinMode(MOTOR_PIN_2, OUTPUT);
}

void loop() {
  if (dtmfSerial.available() > 0) { // Check if there is incoming DTMF data
    char dtmfData = dtmfSerial.read(); // Read the DTMF data
    Serial.print("Received DTMF tone: ");
    Serial.println(dtmfData);
    
    // Perform actions based on received DTMF tone
    switch (dtmfData) {
      case '1':
        // Example: Rotate motor clockwise
        digitalWrite(MOTOR_PIN_1, HIGH);
        digitalWrite(MOTOR_PIN_2, LOW);
        break;
      case '2':
        // Example: Rotate motor counterclockwise
        digitalWrite(MOTOR_PIN_1, LOW);
        digitalWrite(MOTOR_PIN_2, HIGH);
        break;
      // Add more cases for additional DTMF tones and corresponding actions
    }
  }
}
