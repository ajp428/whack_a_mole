/*
 * Whack-a-mole game
 * 
 * This code implements the game whack-a-mole. It includes all of the logic
 * for initializing input and output pins on the Arduino Uno, and then 
 * turning on LEDs at predetermined intervals and scanning for button input.
 * Note that switches are physically connected active low.
 * 
 * Created April 2020
 * 
 * Authors: Daniel Andrews, Ezra Bailey-Kelly, Andrew Phares
 */
#include "Nokia_5110.h"

#define RST 6
#define CE 5
#define DC 4
#define DIN 3
#define CLK 2

Nokia_5110 lcd = Nokia_5110(RST, CE, DC, DIN, CLK);

int PushB1 = 7;    // Pushbutton pins
int PushB2 = 8;
int PushB3 = 9;
int PushB4 = 10;
int PushB5 = 11;
int PushB6 = 12;

int PBs1;           // Read variable for pins
int PBs2;         
int PBs3;
int PBs4;
int PBs5;
int PBs6;

int Bs;             // Button state

int rNum;           // Random number
int wins = 0;       // Number of successful times "whacking" the mole
int highScore = 0;  

const int easy = 1000;    // Predetermined wait intervals
const int medium = 500;
const int hard = 325;
const int stupid = 250;

int difficulty = 0;

int ledPins[] = {A0,A1,A2,A3,A4,A5};         

uint32_t timeLastTurnedOn = 0;      // Timer to keep track of when a currently on LED was turned on
bool ledStates[] = {false, false, false, false, false, false}; // An array to keep track of which LED was on

void setup() {
  Serial.begin(9600);
  pinMode(PushB1, INPUT);   // Setting input pins
  pinMode(PushB2, INPUT);
  pinMode(PushB3, INPUT);
  pinMode(PushB4, INPUT);
  pinMode(PushB5, INPUT);
  pinMode(PushB6, INPUT);

  pinMode(2, OUTPUT);       // Setting output pins
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);

  selectDifficultyLCD();
  while(difficulty == 0) {
    setDifficulty();
  }
  clearScreen();
}

void loop() {
  if(millis() < timeLastTurnedOn) { // Checking for timer overflow
    timeLastTurnedOn = 0;
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("CURRENT SCORE:");
  lcd.setCursor(0, 2);
  lcd.print(wins);

  PBs1 = digitalRead(PushB1);       // Read to see if a button has been pressed
  PBs2 = digitalRead(PushB2);
  PBs3 = digitalRead(PushB3);
  PBs4 = digitalRead(PushB4);
  PBs5 = digitalRead(PushB5);
  PBs6 = digitalRead(PushB6);

  Bs=0; // Set the button state variable to whatever button may have been pressed, default 0
  switch (PBs1) {         
    case 0:
    Bs=1;
    break;
  } 
  switch (PBs2) {
    case 0:
    Bs=2;
    break;
  }
  switch (PBs3) {
    case 0:
    Bs=3;
    break;
  }
  switch (PBs4) {
    case 0:
    Bs=4;
    break;
  }
  switch (PBs5) {
    case 0:
    Bs=5;
    break;
  }
  switch (PBs6) {
    case 0:
    Bs=6;
    break;
  }

  if(numOn() == -1) {                   // If no LEDs, turn one on
    rNum = random(0, 5);
    digitalWrite(ledPins[rNum], HIGH);
    ledStates[rNum] = true;
    timeLastTurnedOn = millis();
    Serial.println(rNum);
    Serial.println(millis());
  } else {      // If an LED is on, see if enough time has elapsed
    if(millis() - timeLastTurnedOn > difficulty) {
      digitalWrite(ledPins[rNum], LOW);
      ledStates[rNum] = false;
      Serial.println("Fail");
      Serial.println(millis());
        for (int i=0; i<=3; i++) {   
          digitalWrite(12, HIGH);
          delay(50);
          digitalWrite(12, LOW);
          delay(50);
        }
    } else {  // If the button was pressed, increment the score
      if (Bs - 1 == rNum) {
        wins++;
        Serial.println("Win!!!");
        for (int k = 0; k <= 3; k++) {
          digitalWrite(8, HIGH);
          delay(50);
          digitalWrite(8, LOW);
          delay(50);
        }
      }
    }
  }

  if (wins>highScore) { // Display the high score for Project 2
        highScore=wins;
        wins=0;
        for (int w=0; w<highScore; w++) {
          digitalWrite(8, HIGH);
          digitalWrite(12, HIGH);
          delay(200);
          digitalWrite(8, LOW);
          digitalWrite(12, LOW);
          delay(200);
        }  
  }
  //Serial.println(highScore);  
}

int numOn() { // Custom function to determine which LED was on
  int i;
  for(i = 0; i < 6; i++) {
    if(ledStates[i]) {
      return i;
    }
  }
  return -1;
}

void setDifficultyLCD() {
  lcd.setCursor(0, 0);
  lcd.print("    SELECT    ");
  lcd.setCursor(0, 1);
  lcd.print("  DIFFICULTY  ");
  lcd.setCursor(0, 2);
  lcd.print("   1: Easy    ");
  lcd.setCursor(0, 3);
  lcd.print("  2: Medium   ");
  lcd.setCursor(0, 4);
  lcd.print("   3: Hard    ");
  lcd.setCursor(0, 5);
  lcd.print("  4: Stupid   ");
}

void setDifficulty() {
  int easyDiff = digitalRead(PushB1);
  int medDiff = digitalRead(PushB2);
  int hardDiff = digitalRead(PushB3);
  int stupidDiff = digitalRead(PushB4);

  if(easyDiff == 0) {
    difficulty = easy;
  } else if(medDiff == 0) {
    difficulty = medium;
  } else if (hardDiff == 0) {
    difficulty  = hard;
  } else if (stupidDiff == 0) {
    difficulty = stupid;
  }
}

void clearScreen() {
  lcd.setCursor(0, 0);
  lcd.print("              ");
  lcd.setCursor(0, 1);
  lcd.print("              ");
  lcd.setCursor(0, 2);
  lcd.print("              ");
  lcd.setCursor(0, 3);
  lcd.print("              ");
  lcd.setCursor(0, 4);
  lcd.print("              ");
  lcd.setCursor(0, 5);
  lcd.print("              ");
}
