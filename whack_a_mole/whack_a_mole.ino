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

int joyXPin = 7;
int joyYPin = 8;

int xState;
int yState;
int buttonPressed;          

int rNum;           // Random number global
int wins = 0;       // Number of successful times "whacking" the mole

const int easy = 1000;    // Predetermined wait intervals
const int medium = 500;
const int hard = 325;
const int stupid = 250;

int difficulty = 0;

int ledPins[] = {A0,A1,A2,A3}; // A0 = up, A1 = right, A2 = down, A3 = left         

uint32_t timeLastTurnedOn = 0;      // Timer to keep track of when a currently on LED was turned on
bool ledStates[] = {false, false, false, false}; // An array to keep track of which LED was on

void setup() {
  // Setting input pins
  Serial.begin(9600);
  pinMode(joyXPin, INPUT);   
  pinMode(joyYPin, INPUT);

  // Setting output pins
  pinMode(A0, OUTPUT); // Up LED
  pinMode(A1, OUTPUT); // Right LED
  pinMode(A2, OUTPUT); // Down LED
  pinMode(A3, OUTPUT); // Left LED
  pinMode(9, OUTPUT);  // Buzzer pin
}

void loop() {
  if(difficulty == 0) {
    setDifficultyLCD();
    while(difficulty == 0) {
      setDifficulty();
    }
    lcd.clear();
  }
  
  if(millis() < timeLastTurnedOn) { // Checking for timer overflow
    timeLastTurnedOn = 0;
    return;
  }

  lcd.setCursor(0, 0);
  lcd.print("CURRENT SCORE:");
  lcd.setCursor(0, 2);
  lcd.print(wins);

  xState = analogRead(joyXPin);
  yState = analogRead(joyYPin);

  buttonPressed = -1;
  if(yState < 500) {
    buttonPressed = 0;
  } else if (xState > 550) {
    buttonPressed = 1;
  } else if (yState > 550) {
    buttonPressed = 2;
  } else if (xState < 500) {
    buttonPressed = 3;
  }
  
  if(numOn() == -1) {                   // If no LEDs, turn one on
    rNum = random(0, 3);
    digitalWrite(ledPins[rNum], HIGH);
    ledStates[rNum] = true;
    timeLastTurnedOn = millis();
  } else {      
    // If an LED is on, see if enough time has elapsed
    if(millis() - timeLastTurnedOn > difficulty) {
      digitalWrite(ledPins[rNum], LOW);
      ledStates[rNum] = false;
      Serial.println("Fail");
      Serial.println(rNum);
      analogWrite(9, 128);
      delay(100);
      analogWrite(9, 0);
    } else {  
      // If the button was pressed, increment the score
      if (buttonPressed == rNum) {
        wins++;
        Serial.println("Win!!!");
      }
    }
  }
} 

int numOn() { // Custom function to determine which LED was on
  int i;
  for(i = 0; i < 4; i++) {
    if(ledStates[i]) {
      return i;
    }
  }
  return -1;
}

void setDifficultyLCD() {
  lcd.setCursor(0, 0);
  lcd.print("SELECT");
  lcd.setCursor(0, 1);
  lcd.print("DIFFICULTY");
  lcd.setCursor(0, 2);
  lcd.print("Up: Easy");
  lcd.setCursor(0, 3);
  lcd.print("Right: Medium");
  lcd.setCursor(0, 4);
  lcd.print("Down: Hard");
  lcd.setCursor(0, 5);
  lcd.print("Left: Stupid");
}

void setDifficulty() {
  xState = analogRead(joyXPin);
  yState = analogRead(joyYPin);

  if(yState < 500) {
    difficulty = easy;
  } else if(xState > 550) {
    difficulty = medium;
  } else if (yState > 550) {
    difficulty  = hard;
  } else if (xState < 500) {
    difficulty = stupid;
  }
}
