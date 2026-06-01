// Motor A (Right)
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B (Left)
int in3 = 5;
int in4 = 4;
int enB = 3;

// Police Strobe LEDs
int redLED = 10;
int blueLED = 11;

char command;
bool strobeEnabled = false;

// Variables for Strobe Light Timing (Non-Blocking)
unsigned long previousMillis = 0;
const long interval = 150; // Blinking speed (in milliseconds)
int ledState = 0;

void setup() {
  Serial.begin(9600); // Default baud rate for HC-05
  
  // Set all pins as output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // Turn off motors initially
  Stop();
}

void loop() {
  // 1. Check for incoming Bluetooth commands
  if (Serial.available() > 0) {
    command = Serial.read();
    
    switch (command) {
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': Stop(); break;
      case 'W': strobeEnabled = true; break;  // App command to turn ON lights
      case 'w':                               // App command to turn OFF lights
        strobeEnabled = false;
        digitalWrite(redLED, LOW);
        digitalWrite(blueLED, LOW);
        break; 
    }
  }

  // 2. Handle Strobe Lights without using delay()
  if (strobeEnabled) {
    unsigned long currentMillis = millis();
    
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
      
      if (ledState == 0) {
        digitalWrite(redLED, HIGH);
        digitalWrite(blueLED, LOW);
        ledState = 1;
      } else {
        digitalWrite(redLED, LOW);
        digitalWrite(blueLED, HIGH);
        ledState = 0;
      }
    }
  }
}

// --- Motor Control Functions ---

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 255); // Speed 0-255
  analogWrite(enB, 255);
}

void backward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 255);
  analogWrite(enB, 255);
}

void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 200); // Slightly slower for turning
  analogWrite(enB, 200);
}

void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 200); // Slightly slower for turning
  analogWrite(enB, 200);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
