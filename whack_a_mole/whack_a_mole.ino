int PushB1 = A0;    // Pushbutton pins?
int PushB2 = A1;
int PushB3 = A2;
int PushB4 = A3;
int PushB5 = A4;
int PushB6 = A5;

int PBs1;           // Read variable for pins
int PBs2;         
int PBs3;
int PBs4;
int PBs5;
int PBs6;

int Bs;             // Button state

int rNum;
int wins = 0;         
int highScore = 0;

const int easy = 1000;
const int medium = 500;
const int hard = 325;
const int stupid = 250;


int ledPins[] = {2,3,4,5,6,7};   // Why are there more than 6?
int pinCount = 8;          

int timeLastTurnedOn = 0;
bool ledStates[] = {false, false, false, false, false, false};

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

}

void loop() {

  if(millis() < timeLastTurnedOn) {
    timeLastTurnedOn = millis();
    return;
  }

  PBs1 = digitalRead(PushB1);
  PBs2 = digitalRead(PushB2);
  PBs3 = digitalRead(PushB3);
  PBs4 = digitalRead(PushB4);
  PBs5 = digitalRead(PushB5);
  PBs6 = digitalRead(PushB6);

  Bs=0;
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

  if(numOn() == -1) {
    rNum = random(0,5);
    digitalWrite(ledPins[rNum], HIGH);
    ledStates[rNum] = true;
    timeLastTurnedOn = millis();
    Serial.println(rNum);
  } else {
    if(millis() - timeLastTurnedOn > 1000) {
      digitalWrite(ledPins[rNum], LOW);
      ledStates[rNum] = false;
      Serial.println("Fail");
        for (int i=0; i<=3; i++) {   
          digitalWrite(12, HIGH);
          delay(50);
          digitalWrite(12, LOW);
          delay(50);
        }
    } else {
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

  if (wins>highScore) { 
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

int numOn() {
  int i;
  for(i = 0; i < 6; i++) {
    if(ledStates[i]) {
      return i;
    }
  }
  return -1;
}
