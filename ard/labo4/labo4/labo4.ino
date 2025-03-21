// Distance
#include <HCSR04.h>
#define TRIGGER_PIN 9
#define ECHO_PIN 10

HCSR04 hc(TRIGGER_PIN, ECHO_PIN);

// LCD
#include <LiquidCrystal.h>

const int rs = 36, en = 34, d4 = 32, d5 = 30, d6 = 28, d7 = 26;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// State Machine
enum State {STARTUP, WORKING};
State state = STARTUP;

// Global vars
unsigned long currentTime = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Distance
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // LCD
  lcd.begin(16, 2);
}

void printDistance(int dist, int deg) {
  Serial.print("etd:");
  Serial.print("2471005");
  Serial.print(",dist:");
  Serial.print(dist);
  Serial.print(",deg:");
  Serial.println(deg);
}


void stateStartup() {
  
  lcd.clear();
  lcd.print("2471005");
  lcd.setCursor(0,1);
  lcd.print("Labo 4B");
  delay(2000);
  
  lcd.clear();

  state = WORKING;
}

float measureDistance() {
  float distance = hc.dist();

  return distance;
}

void lcdDisplay(float distance, int deg) {
  
  lcd.clear();
  lcd.print("Dist  : ");
  lcd.print(distance);
  lcd.setCursor(0, 1);
  if (distance < 30) {
    lcd.print("Obj  : Trop pret");
  } else if (distance >= 30 && distance <=60) {
    lcd.print("Obj  : ");
    lcd.print(deg);
    lcd.print(" deg");
  } else {
    lcd.print("Obj  : Trop loin");
  }
  
}

void stateWorking() {
  static unsigned long lastMeasureTime = 0;
  static unsigned long lastPrintTime = 0;
  const int MeasureRate = 50;
  const int printRate = 100;
  int deg = 0;
  float distance = 0;


  if (currentTime - lastMeasureTime >= MeasureRate) {
    distance = measureDistance();
    lastMeasureTime = currentTime;
  
    if (distance >= 30 && distance <= 60) {
      deg = map(distance, 30, 60, 0, 180);
    }
    
    lcdDisplay(distance, deg);

    if (currentTime - lastPrintTime >= printRate) {
      printDistance(distance, deg);
      lastMeasureTime = currentTime;
    }
  }
  

}


void loop() {
  // put your main code here, to run repeatedly:  
  currentTime = millis();

  switch (state) {
    case STARTUP:
      stateStartup();
      break;
    case WORKING:
      stateWorking();
      break;
  }
}
