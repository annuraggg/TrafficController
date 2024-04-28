#include <NewPing.h>

#define ECHO_PIN_1 12
#define TRIGGER_PIN_1 13

#define ECHO_PIN_2 14
#define TRIGGER_PIN_2 27

#define ECHO_PIN_3 34
#define TRIGGER_PIN_3 23

#define ECHO_PIN_4 2
#define TRIGGER_PIN_4 22

int signal1[] = { 21, 03, 04 };
int signal2[] = { 05, 18, 19 };
int signal3[] = { 17, 32, 16 };
int signal4[] = { 15, 33, 25 };

#define MAX_DISTANCE 200

int yellowDetail = 3000;
int greenDetail = 4000;

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

  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();
  unsigned int distance3 = sonar3.ping_cm();
  unsigned int distance4 = sonar4.ping_cm();

  for (int i = 0; i < 3; i++) {

    digitalWrite(signal4[i], HIGH);
  }

  Serial.print("Reads: ");
  Serial.print(distance1);
  Serial.print(", ");
  Serial.print(distance2);
  Serial.print(", ");
  Serial.print(distance3);
  Serial.print(", ");
  Serial.println(distance4);  // Print distance4 and move to the next line
  delay(50);
}

void turnGreen(int signalNo) {
  if (signalNo == "1") {
    digitalWrite(signal1[0], 'LOW');
    digitalWrite(signal1[1], 'HIGH');
    delay(yellowDelay);
    digitalWrite(signal1[1], 'LOW');
    digitalWrite(signal1[2], 'HIGH');
    delay(greenDelay);
    return;
  }

  if (signalNo == "2") {
    digitalWrite(signal2[0], 'LOW');
    digitalWrite(signal2[1], 'HIGH');
    delay(yellowDelay);
    digitalWrite(signal2[1], 'LOW');
    digitalWrite(signal2[2], 'HIGH');
    delay(greenDelay);
    return;
  }

  if (signalNo == "3") {
    digitalWrite(signal3[0], 'LOW');
    digitalWrite(signal3[1], 'HIGH');
    delay(yellowDelay);
    digitalWrite(signal3[1], 'LOW');
    digitalWrite(signal3[2], 'HIGH');
    delay(greenDelay);
    return;
  }

  if (signalNo == "4") {
    digitalWrite(signal4[0], 'LOW');
    digitalWrite(signal4[1], 'HIGH');
    delay(yellowDelay);
    digitalWrite(signal4[1], 'LOW');
    digitalWrite(signal4[2], 'HIGH');
    delay(greenDelay);
    return;
  }
}
