#include <NewPing.h>

#define ECHO_PIN_1 12
#define TRIGGER_PIN_1 13

#define ECHO_PIN_2 14
#define TRIGGER_PIN_2 27

#define ECHO_PIN_3 34
#define TRIGGER_PIN_3 23

#define ECHO_PIN_4 2
#define TRIGGER_PIN_4 22

#define MAX_DISTANCE 200
NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
NewPing sonar4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE);


void setup() {
  Serial.begin(9600);
}

void loop() {
  
  unsigned int distance1 = sonar1.ping_cm();
  unsigned int distance2 = sonar2.ping_cm();
  unsigned int distance3 = sonar3.ping_cm();
  unsigned int distance4 = sonar4.ping_cm();

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
