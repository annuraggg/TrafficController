int signal1[] = { 21, 03, 04 };
int signal2[] = { 15, 33, 25 };
int signal3[] = { 05, 18, 19 };
int signal4[] = { 17, 32, 16 };

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
  }
}

void loop() {
  /*digitalWrite(signal1[0], HIGH);
  delay(500);
  digitalWrite(signal2[0], HIGH);
  delay(500);
  digitalWrite(signal3[0], HIGH);
  delay(500);
  digitalWrite(signal4[0], HIGH);
  delay(500);

  digitalWrite(signal1[0], LOW);
  delay(500);
  digitalWrite(signal2[0], LOW);
  delay(500);
  digitalWrite(signal3[0], LOW);
  delay(500);
  digitalWrite(signal4[0], LOW);
  delay(500);

  digitalWrite(signal1[1], HIGH);
  delay(500);
  digitalWrite(signal2[1], HIGH);
  delay(500);
  digitalWrite(signal3[1], HIGH);
  delay(500);
  digitalWrite(signal4[1], HIGH);
  delay(500);

  digitalWrite(signal1[1], LOW);
  delay(500);
  digitalWrite(signal2[1], LOW);
  delay(500);
  digitalWrite(signal3[1], LOW);
  delay(500);
  digitalWrite(signal4[1], LOW);
  delay(500);

  digitalWrite(signal1[2], HIGH);
  delay(500);
  digitalWrite(signal2[2], HIGH);
  delay(500);
  digitalWrite(signal3[2], HIGH);
  delay(500);
  digitalWrite(signal4[2], HIGH);
  delay(500);

  digitalWrite(signal1[2], LOW);
  delay(500);
  digitalWrite(signal2[2], LOW);
  delay(500);
  digitalWrite(signal3[2], LOW);
  delay(500);
  digitalWrite(signal4[2], LOW);
  delay(500);
  */

  /*  digitalWrite(signal4[0], HIGH);
  delay(500);
  digitalWrite(signal4[1], HIGH);
  delay(500);
  digitalWrite(signal4[2], HIGH);
  delay(500);

  digitalWrite(signal4[0], LOW);
  delay(500);
  digitalWrite(signal4[1], LOW);
  delay(500);
  digitalWrite(signal4[2], LOW);
  delay(500);*/

  for (int i = 0; i < 3; i++) {
    digitalWrite(signal1[i], HIGH);
    digitalWrite(signal2[i], HIGH);
    digitalWrite(signal3[i], HIGH);
    digitalWrite(signal4[i], HIGH);
  }
}
