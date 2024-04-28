int signal1[] = { 21, 03, 04 };
int signal2[] = { 15, 33, 25 };

int triggerpin2 = 13;
int echopin2 = 12;

int triggerpin1 = 27;
int echopin1 = 14;

int greenDelay = 2000;
int yellowDelay = 2000;
int t = 10;  // Distance threshold for triggering signals

long duration;         // Time for ultrasonic signal to return
int S1 = 20, S2 = 20;  // Distance measurements from each sensor

int currentGreen = -1;  // Keeps track of currently green signal (-1 for none)

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

  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);

  resetSignals();
}

void loop() {
  S1 = readDistance(triggerpin1, echopin1);
  S2 = readDistance(triggerpin2, echopin2);

  if (currentGreen == -1) {
    if (S1 < t || S2 < t) {
      if (S1 < t) {
        turnToGreen(1);
      } else if (S2 < t) {
        turnToGreen(2);
      }
    } else {
      // normalRotation()
      resetSignals();
    }
  }
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

void turnToGreen(int signalNo) {
  currentGreen = signalNo;
  int signal[] = { 0, 0, 0 };
  int currentValue;
  if (signalNo == 1) {
    signal[0] = signal1[0];
    signal[1] = signal1[1];
    signal[2] = signal1[2];
    currentValue = readDistance(triggerpin1, echopin1);
  } else if (signalNo == 2) {
    signal[0] = signal2[0];
    signal[1] = signal2[1];
    signal[2] = signal2[2];
    currentValue = readDistance(triggerpin2, echopin2);
  }

  digitalWrite(signal[0], LOW);
  digitalWrite(signal[1], HIGH);
  digitalWrite(signal[2], LOW);

  delay(yellowDelay);


  while (currentValue <= t) {
    // Update currentValue based on sensor readings
    currentValue = (signalNo == 1) ? readDistance(triggerpin1, echopin1) : readDistance(triggerpin2, echopin2);
    digitalWrite(signal[0], LOW);
    digitalWrite(signal[1], LOW);
    digitalWrite(signal[2], HIGH);
    delay(greenDelay);
    // Optionally add a small delay here if needed
  }

  currentGreen = -1;
  resetSignals();
}


void resetSignals() {
  for (int i = 0; i < 3; i++) {
    if (i == 0) {
      digitalWrite(signal1[i], HIGH);
      digitalWrite(signal2[i], HIGH);
      continue;
    }

    digitalWrite(signal1[i], LOW);
    digitalWrite(signal2[i], LOW);
  }
}

