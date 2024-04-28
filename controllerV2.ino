#include <NewPing.h>

#define ECHO_PIN_1 12
#define TRIGGER_PIN_1 13

#define ECHO_PIN_2 14
#define TRIGGER_PIN_2 27

#define ECHO_PIN_3 34
#define TRIGGER_PIN_3 23

#define ECHO_PIN_4 2
#define TRIGGER_PIN_4 22

#define signal1 [] = {21, 04, 0}; // is actually 03 for green
#define signal2 [] = {05, 18, 19};
#define signal3 [] = {16, 32, 17};
#define signal4 [] = {15, 33, 25};

int signals[] = {signal1, signal2, signal3, signal4};

int yellowDelay = 3000;
int greenDelay = 4000;

int threshold = 4;

#define MAX_DISTANCE 200
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

    if (S1 > threshold)
    {
        turnGreen(0);
    }
    else if (S2 > threshold)
    {
        turnGreen(1);
    }
    else if (S3 > threshold)
    {
        turnGreen(2);
    }
    else if (S4 > threshold)
    {
        turnGreen(3);
    }
}

void turnGreen(int number)
{
    for (int i = 0; i < 4; i++)
    {
        if (i == number)
        {
            digitalWrite(signals[i][0], HIGH);
            digitalWrite(signals[i][1], LOW);
            digitalWrite(signals[i][2], LOW);
        }
        else
        {
            digitalWrite(signals[i][0], LOW);
            digitalWrite(signals[i][1], HIGH);
            digitalWrite(signals[i][2], LOW);
        }
    }
}