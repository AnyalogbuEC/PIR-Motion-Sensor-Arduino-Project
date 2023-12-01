// PIR Motion Sensor Arduino Project
//
// Written by Anyalogbu,E. C. on November, 2023 for more info visit g.dev/Anyalogbu_EC.
// This is a program for detecting and alerting when motion is detected.
// Basically put, its a intruder alert system.
// This program utilize the following components for it functionalities:
//    1. Ofcourse, the Ardunio board (UNO, Nano) and its corresponding usb cord.
//    2. The PIR motion sensor.
//    3. LED for visual indication.
//    4. Buzzer for audio indication / alert.
//    5. Jumper wires for estalishing connections.
//
//Other components can be included to modify the functions program.
//
//


// Definition of the PIR sensor pin, Buzzer pin and LED pin goes here.
int pirSensorPin = 2; // Connect the PIR sensor to digital pin 2.
int buzzerPin = 3; // Connect the Buzzer to digital pin 3.
int ledPin = 13;      // Built-in LED on most Arduino boards, which is same as the digital pin 13.

void setup() {
// This section of the code runs once (only when the starts).

  // Initializing the PIR sensor as an input
  pinMode(pirSensorPin, INPUT);

  // Initializing the Buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);

  // Initializing the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Serial communication for debugging (optional)
  Serial.begin(9600);
}

void loop() {
// This section of the code runs till the program is terminated (either by swithching off the power supply).

  // Reading the PIR sensor's output
  int motionDetected = digitalRead(pirSensorPin);

  // Checking for motion and taking actions ...
  if (motionDetected == HIGH) {
    // Motion detected
    digitalWrite(ledPin, HIGH); // Turn on the LED
    digitalWrite(buzzerPin, HIGH); // Turn on the Buzzer
    Serial.println("Motion detected!"); // Print "Motion detected!" to the serial monitor
    // You can add additional actions here, like sending a notification
  } else {
    // No motion detected
    digitalWrite(ledPin, LOW); // Turn off the LED
    digitalWrite(buzzerPin, LOW); // Turn off the Buzzer
    Serial.println("No motion detected."); // Print "No motion detected." to the serial monitor
  }

  delay(1000); // You can adjust the delay as needed to control the sensitivity
}