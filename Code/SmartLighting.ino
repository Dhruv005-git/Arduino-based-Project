#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

// -----------------------------
// Pin assignments for each room
// -----------------------------
const int LIVING_ROOM_PIN = 5;
const int BEDROOM_PIN     = 6;
const int DINING_ROOM_PIN = 7;

// -----------------------------
// Bluetooth setup
// -----------------------------
SoftwareSerial Bluetooth(0, 1);  // RX, TX
char receivedData;               // Holds incoming Bluetooth data

// -----------------------------
// Function to send confirmation messages
// -----------------------------
void sendData(String message) {
  Bluetooth.println(message);
}

// -----------------------------
// Setup function
// -----------------------------
void setup() {
  // Initialize Bluetooth communication
  Bluetooth.begin(9600);

  // Configure pins as outputs
  pinMode(LIVING_ROOM_PIN, OUTPUT);
  pinMode(BEDROOM_PIN, OUTPUT);
  pinMode(DINING_ROOM_PIN, OUTPUT);
}

// -----------------------------
// Main loop
// -----------------------------
void loop() {
  // Check if Bluetooth data is available
  if (Bluetooth.available()) {
    receivedData = Bluetooth.read();  // Read incoming data

    // -----------------------------
    // Individual room controls
    // -----------------------------
    if (receivedData == '4') { 
      digitalWrite(LIVING_ROOM_PIN, HIGH); 
      sendData("Living Room Light ON");
    }
    if (receivedData == '1') { 
      digitalWrite(LIVING_ROOM_PIN, LOW); 
      sendData("Living Room Light OFF");
    }

    if (receivedData == '5') { 
      digitalWrite(BEDROOM_PIN, HIGH); 
      sendData("Bedroom Light ON");
    }
    if (receivedData == '2') { 
      digitalWrite(BEDROOM_PIN, LOW); 
      sendData("Bedroom Light OFF");
    }

    if (receivedData == '6') { 
      digitalWrite(DINING_ROOM_PIN, HIGH); 
      sendData("Dining Room Light ON");
    }
    if (receivedData == '3') { 
      digitalWrite(DINING_ROOM_PIN, LOW); 
      sendData("Dining Room Light OFF");
    }

    // -----------------------------
    // Global controls
    // -----------------------------
    if (receivedData == '9') {  // Turn on all lights
      digitalWrite(LIVING_ROOM_PIN, HIGH);
      digitalWrite(BEDROOM_PIN, HIGH);
      digitalWrite(DINING_ROOM_PIN, HIGH);
      sendData("ALL LIGHTS ON");
    }
    if (receivedData == '0') {  // Turn off all lights
      digitalWrite(LIVING_ROOM_PIN, LOW);
      digitalWrite(BEDROOM_PIN, LOW);
      digitalWrite(DINING_ROOM_PIN, LOW);
      sendData("ALL LIGHTS OFF");
    }
  }
}