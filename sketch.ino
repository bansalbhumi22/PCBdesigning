#include <Servo.h>
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 7;
int segE = 8;
int segF = 10;
int segG = 11;

int d2 = 12;  // Hundreds
int d3 = 13;  // Tens
int d4 = A0;  // Ones

#define PIR_IN  A3   
#define PIR_OUT A4   
int lastIn = LOW;
int lastOut = LOW;

Servo gate1, gate2, gate3, gate4;
int OPEN_POS = 90;
int CLOSE_POS = 0;
int count = 25;
byte digits[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};
void setup() {
  int segPins[] = {segA, segB, segC, segD, segE, segF, segG};
  for (int i=0;i<7;i++) pinMode(segPins[i], OUTPUT);

  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);

  pinMode(PIR_IN, INPUT);
  pinMode(PIR_OUT, INPUT);
  gate1.attach(5);
  gate2.attach(6);
  gate3.attach(9);
  gate4.attach(A2);
  updateGates();
}

void loop() {
int readingIn = digitalRead(PIR_IN);

if (lastIn == LOW && readingIn == HIGH) {
    count++;
    if (count > 999) count = 999;
    updateGates();
}
if (readingIn == LOW) lastIn = LOW;
else lastIn = HIGH;
int readingOut = digitalRead(PIR_OUT);

if (lastOut == LOW && readingOut == HIGH) {
    count--;
    if (count < 0) count = 0;
    updateGates();
}

if (readingOut == LOW) lastOut = LOW;
else lastOut = HIGH;
  shownumber(count);
}
void disableAllDigits() {
  digitalWrite(d2, HIGH);
  digitalWrite(d3, HIGH);
  digitalWrite(d4, HIGH);
}

void lightDigit(int digitPin, int number) {
  disableAllDigits();
  
  int segPins[] = {segA, segB, segC, segD, segE, segF, segG};
  for (int i = 0; i < 7; i++)
    digitalWrite(segPins[i], digits[number][i]);

  digitalWrite(digitPin, LOW);
  delay(2);
  digitalWrite(digitPin, HIGH);
}

void shownumber(int num) {
  int hundreds = num / 100;
  int tens     = (num / 10) % 10;
  int ones     = num % 10;

  lightDigit(d2, hundreds);
  lightDigit(d3, tens);
  lightDigit(d4, ones);
}
void updateGates() {
  if (count <= 50) {
    gate1.write(OPEN_POS);
    gate2.write(OPEN_POS);
    gate3.write(OPEN_POS);
    gate4.write(OPEN_POS);
  }
  else if (count <= 60) {
    gate1.write(CLOSE_POS);
    gate2.write(OPEN_POS);
    gate3.write(OPEN_POS);
    gate4.write(OPEN_POS);
  }
  else if (count <= 70) {
    gate1.write(CLOSE_POS);
    gate2.write(CLOSE_POS);
    gate3.write(OPEN_POS);
    gate4.write(OPEN_POS);
  }
  else if (count <= 80) {
    gate1.write(CLOSE_POS);
    gate2.write(CLOSE_POS);
    gate3.write(CLOSE_POS);
    gate4.write(OPEN_POS);
  }
  else {
    gate1.write(CLOSE_POS);
    gate2.write(CLOSE_POS);
    gate3.write(CLOSE_POS);
    gate4.write(CLOSE_POS);
  }
}
