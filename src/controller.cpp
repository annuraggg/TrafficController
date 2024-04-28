#include <NewPing.h>

#define ECHO_PIN_1 12
#define TRIGGER_PIN_1 13

#define ECHO_PIN_2 14
#define TRIGGER_PIN_2 27

#define ECHO_PIN_3 34
#define TRIGGER_PIN_3 23

#define ECHO_PIN_4 2
#define TRIGGER_PIN_4 22

int signal1[] = {21, 04, 0}; // GREEN IS 03
int signal2[] = {05, 18, 19};
int signal3[] = {16, 32, 17};
int signal4[] = {15, 33, 25};

int signals[][3] = {
    {21, 04, 0},  // signal1
    {5, 18, 19},  // signal2
    {16, 32, 17}, // signal3
    {15, 33, 25}  // signal4
};

int yellowDelay = 500;
int greenDelay = 500;

int threshold = 4;

boolean booting = true;
int bootDelay = 30;

#define MAX_DISTANCE 400
NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
NewPing sonar4(TRIGGER_PIN_4, ECHO_PIN_4, MAX_DISTANCE);

void setup()
{
    Serial.begin(9600);

    for (int i = 0; i < 3; i++)
    {
        pinMode(signal1[i], OUTPUT);
        pinMode(signal2[i], OUTPUT);
        pinMode(signal3[i], OUTPUT);
        pinMode(signal4[i], OUTPUT);
    }
}

void loop()
{
    unsigned int S1 = sonar1.ping_cm();
    unsigned int S2 = sonar2.ping_cm();
    unsigned int S3 = sonar3.ping_cm();
    unsigned int S4 = sonar4.ping_cm();

    if (booting)
    {
        bootAnimation();
    }

    if (S1 < threshold)
    {
        turnGreen(2);
    }
    else if (S2 < threshold)
    {
        turnGreen(3);
    }
    else if (S3 < threshold)
    {
        turnGreen(0);
    }
    else if (S4 < threshold)
    {
        turnGreen(1);
    }
    else
    {
        setRed();
    }

    delay(50);
}

void turnGreen(int number)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == number)
        {
            delay(greenDelay);
            digitalWrite(signals[i][0], LOW);
            digitalWrite(signals[i][1], LOW);
            digitalWrite(signals[i][2], HIGH);
        }
        else
        {
            digitalWrite(signals[i][0], HIGH);
            digitalWrite(signals[i][1], LOW);
            digitalWrite(signals[i][2], LOW);
        }
    }
}

void setRed()
{
    for (int i = 0; i < 4; i++)
    {
        if (digitalRead(signals[i][2]) == HIGH)
        {
            delay(greenDelay);
            digitalWrite(signals[i][2], LOW);
            digitalWrite(signals[i][1], HIGH);
            delay(yellowDelay);
            digitalWrite(signals[i][1], LOW);
            digitalWrite(signals[i][0], HIGH);
        }
        else
        {
            digitalWrite(signals[i][0], HIGH);
            digitalWrite(signals[i][1], LOW);
            digitalWrite(signals[i][2], LOW);
        }
    }
}


void bootAnimation()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            digitalWrite(signal1[j], HIGH);
            delay(bootDelay);
            digitalWrite(signal2[j], HIGH);
            delay(bootDelay);
            digitalWrite(signal3[j], HIGH);
            delay(bootDelay);
            digitalWrite(signal4[j], HIGH);
            delay(bootDelay);

            digitalWrite(signal1[j], LOW);
            digitalWrite(signal2[j], LOW);
            digitalWrite(signal3[j], LOW);
            digitalWrite(signal4[j], LOW);
            delay(50);
        }
    }

    booting = false;
}