#include <NewPing.h>

#define ECHO_PIN_1 12
#define TRIGGER_PIN_1 13

#define ECHO_PIN_2 14
#define TRIGGER_PIN_2 27

#define ECHO_PIN_3 34
#define TRIGGER_PIN_3 23

#define ECHO_PIN_4 2
#define TRIGGER_PIN_4 22
int signal1[] = {21, 04, 19}; // GREEN IS 03
int signal2[] = {05, 18, 19};
int signal3[] = {16, 32, 17};
int signal4[] = {15, 33, 25};

int signals[][3] = {
    {21, 04, 03}, // signal1
    {5, 18, 19},  // signal2
    {16, 32, 17}, // signal3
    {15, 33, 25}  // signal4
};

#define MAX_DISTANCE 200

int s1Flag = 0;
int s2Flag = 0;
int s3Flag = 0;
int s4Flag = 0;

int yellowDelay = 3000;
int greenDelay = 4000;

int threshold = 4;
boolean isAnyGreen = false;

int bootDelay = 30;

int currentSignal = -1;
boolean bootFlag = true;

NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
NewPing sonar4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 3; i++) {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
  }
}

void loop() {
  if (bootFlag == true) {
    bootAnimation();
  }

  unsigned int S1 = sonar1.ping_cm();
  unsigned int S2 = sonar2.ping_cm();
  unsigned int S3 = sonar3.ping_cm();
  unsigned int S4 = sonar4.ping_cm();

  if (S1 <= threshold && S1 > 0) {
    turnGreen(signal3, s1Flag, 3);
    ++s1Flag;
    isAnyGreen = true;
  } else {
    setRed(signal1);
    s1Flag = 0;
  }

  if (S2 <= threshold && S2 > 0) {
    turnGreen(signal4, s2Flag, 4);
    ++s2Flag;
    isAnyGreen = true;
  } else {
    setRed(signal2);
    s2Flag = 0;
  }

  if (S3 <= threshold && S3 > 0) {
    turnGreen(signal1, s3Flag, 1);
    ++s3Flag;
    isAnyGreen = true;
  } else {
    setRed(signal3);
    s3Flag = 0;
  }

  if (S4 <= threshold && S4 > 0) {
    turnGreen(signal2, s4Flag, 2);
    ++s4Flag;
    isAnyGreen = true;
  } else {
    setRed(signal4);
    s4Flag = 0;
  }
}
void turnGreen(int signal[], int flag, int signalNo) {
  if (flag == 0) {
    isAnyGreen = false;
  }

  if (flag > 0) {
    digitalWrite(signal[0], LOW);
    digitalWrite(signal[1], LOW);
    digitalWrite(signal[2], HIGH);
    delay(greenDelay);
    return;
  }

  if (isAnyGreen) return;

  currentSignal = signalNo;
  delay(1000);
  digitalWrite(signal[0], LOW);
  digitalWrite(signal[1], HIGH);
  delay(yellowDelay);
  digitalWrite(signal[1], LOW);
  digitalWrite(signal[2], HIGH);
  delay(greenDelay);
}

void turnRedOthers(int signal1[], int signal2[], int signal3[]) {
  digitalWrite(signal1[0], HIGH);
  digitalWrite(signal2[0], HIGH);
  digitalWrite(signal3[0], HIGH);

  digitalWrite(signal1[0], LOW);
  digitalWrite(signal2[0], LOW);
  digitalWrite(signal3[0], LOW);

  digitalWrite(signal1[0], LOW);
  digitalWrite(signal2[0], LOW);
  digitalWrite(signal3[0], LOW);
}

void setRed(int signal[]) {
  digitalWrite(signal[0], HIGH);
  digitalWrite(signal[1], LOW);
  digitalWrite(signal[2], LOW);
}

void printSensors(int S1, int S2, int S3, int S4) {
  Serial.print(S1);
  Serial.print(",");
  Serial.print(S2);
  Serial.print(",");
  Serial.print(S3);
  Serial.print(",");
  Serial.print(S4);
  Serial.println("");
}

void bootAnimation() {

  for (int i = 0; i < 3; i++) {
    digitalWrite(signal1[0], HIGH);
    delay(bootDelay);
    digitalWrite(signal2[0], HIGH);
    delay(bootDelay);
    digitalWrite(signal3[0], HIGH);
    delay(bootDelay);
    digitalWrite(signal4[0], HIGH);
    delay(bootDelay);

    digitalWrite(signal1[1], HIGH);
    delay(bootDelay);
    digitalWrite(signal2[1], HIGH);
    delay(bootDelay);
    digitalWrite(signal3[1], HIGH);
    delay(bootDelay);
    digitalWrite(signal4[1], HIGH);
    delay(bootDelay);

    digitalWrite(signal1[2], HIGH);
    delay(bootDelay);
    digitalWrite(signal2[2], HIGH);
    delay(bootDelay);
    digitalWrite(signal3[2], HIGH);
    delay(bootDelay);
    digitalWrite(signal4[2], HIGH);
    delay(bootDelay);


    digitalWrite(signal1[0], LOW);
    delay(50);
    digitalWrite(signal2[0], LOW);
    delay(50);
    digitalWrite(signal3[0], LOW);
    delay(50);
    digitalWrite(signal4[0], LOW);
    delay(50);

    digitalWrite(signal1[1], LOW);
    delay(50);
    digitalWrite(signal2[1], LOW);
    delay(50);
    digitalWrite(signal3[1], LOW);
    delay(50);
    digitalWrite(signal4[1], LOW);
    delay(50);

    digitalWrite(signal1[2], LOW);
    delay(50);
    digitalWrite(signal2[2], LOW);
    delay(50);
    digitalWrite(signal3[2], LOW);
    delay(50);
    digitalWrite(signal4[2], LOW);
    delay(50);
  }

  bootFlag = false;
}
