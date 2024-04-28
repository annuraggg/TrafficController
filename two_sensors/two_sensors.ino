int signal1[] = { 21, 03, 04 };
int signal2[] = { 15, 33, 25 };
int signal3[] = { 05, 18, 19 };
int signal4[] = { 17, 32, 16 }; 

int triggerpin1 = 13;
int echopin1 = 12;

int triggerpin2 = 27;
int echopin2 = 14;

int redDelay = 5000;
int yellowDelay = 2000;

long duration;       // Time for ultrasonic signal to return
int S1, S2;  // Distance measurements from each sensor

int t = 5;  // Threshold distance to check for traffic presence

void setup() {
  Serial.begin(115200);

  // Initialize traffic signal LEDs as outputs
  for (int i = 0; i < 3; i++) {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
  }

  // Initialize ultrasonic sensor pins
  pinMode(triggerpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(triggerpin2, OUTPUT);
  pinMode(echopin2, INPUT);
}

void loop() {
  // Measure distance from each ultrasonic sensor
  S1 = readDistance(triggerpin1, echopin1);
  S2 = readDistance(triggerpin2, echopin2);

  // Print sensor readings to Serial Monitor
  Serial.print("Sensor 1: ");
  Serial.print(S1);
  Serial.print(" cm, Sensor 2: ");
  Serial.print(S2);
  Serial.println(" cm");

  // Check and update the status of each traffic signal
  if (S1 < t) {
    signal1Function();
  } else if (S2 < t) {
    signal2Function();
  }

  // Wait a bit before next loop iteration
  delay(1000);
}


int readDistance(int triggerPin, int echoPin) {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // Convert to cm
}

// Define functions for handling each signal
void signal1Function() {
  controlSignal(signal1);
}
void signal2Function() {
  controlSignal(signal2);
}

// Controls the signal light changes
void controlSignal(int signalPins[]) {
  lowAll();                           // Reset all signals to red before changing the current one
  digitalWrite(signalPins[0], HIGH);  // Turn on red LED
  delay(redDelay);

  digitalWrite(signalPins[0], LOW);   // Turn off red LED
  digitalWrite(signalPins[2], HIGH);  // Turn on green LED
  delay(redDelay);

  digitalWrite(signalPins[2], LOW);   // Turn off green LED
  digitalWrite(signalPins[1], HIGH);  // Turn on yellow LED
  delay(yellowDelay);

  digitalWrite(signalPins[1], LOW);  // Turn off yellow LED
}

// Set all signals to red
void lowAll() {
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal1[1], HIGH);
  digitalWrite(signal1[2], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal2[1], HIGH);
  digitalWrite(signal2[2], HIGH);
}
