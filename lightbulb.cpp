#include <SoftwareSerial.h>

const int relayPin = 2;  // Pin connected to the relay module
SoftwareSerial bluetooth(10, 11);  // Pins connected to the Bluetooth module (RX, TX)

void setup() {
  pinMode(relayPin, OUTPUT);     // Set relay pin as an output
  digitalWrite(relayPin, LOW);   // Initialize the relay pin as LOW
  
  Serial.begin(9600);
  bluetooth.begin(9600);         // Initialize the software serial communication for Bluetooth
}

void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();  // Read incoming Bluetooth command

    if (command == '1') {
      digitalWrite(relayPin, HIGH);   // Turn on the relay (light bulb ON)
      Serial.println("Light bulb is turned ON");
    } else if (command == '0') {
      digitalWrite(relayPin, LOW);    // Turn off the relay (light bulb OFF)
      Serial.println("Light bulb is turned OFF");
    }
  }
}
