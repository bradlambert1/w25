///////// Distance
#include <HCSR04.h>
#define TRIGGER_PIN 9
#define ECHO_PIN 10

HCSR04 hc(TRIGGER_PIN, ECHO_PIN);

///////// LCD
#include <LiquidCrystal.h>

const int rs = 36, en = 34, d4 = 32, d5 = 30, d6 = 28, d7 = 26;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

///////// State Machine
enum State {STARTUP, WORKING};
State state = STARTUP;

///////// Accel stepper
#include <AccelStepper.h>

// Définir le type de moteur, les broches IN1-IN3-IN2-IN4
#define MOTOR_INTERFACE_TYPE 4

#define IN_1 31
#define IN_2 33
#define IN_3 35
#define IN_4 37

// Crée une instance
// Attention : L’ordre des broches (IN1, IN3, IN2, IN4) est spécifique au 28BYJ-48.
AccelStepper myStepper(MOTOR_INTERFACE_TYPE, IN_1, IN_3, IN_2, IN_4);

////////// Global vars
unsigned long currentTime = 0;

void setup() {
  /////// put your setup code here, to run once:
  // Serial.begin(9600);
  Serial.begin(115200);
  
  /////// Distance
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  /////// LCD
  lcd.begin(16, 2);
  
  /////// Accel Stepper default configs
  // Définir la vitesse maximale, le facteur d'accélération,
  // la vitesse initiale et la position cible
  myStepper.setMaxSpeed(500);  // Vitesse max en pas/seconde
  myStepper.setAcceleration(100); // Accélération en pas/seconde²
	myStepper.setSpeed(200); // Vitesse constante en pas/seconde
	myStepper.moveTo(2038); // Position cible
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
  Serial.print("test");

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

void motorTarget(int deg) {
  float targetAngle = map(deg, 0, 180, 0, 170);
  float targetStep = map (targetAngle, 0, 170, 0, 2038);
  
  myStepper.moveTo(targetStep);
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
    motorTarget(deg);

    if (currentTime - lastPrintTime >= printRate) {
      printDistance(distance, deg);
      lastMeasureTime = currentTime;
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:  
  currentTime = millis();
  Serial.print("test");
  switch (state) {
    case STARTUP:
      stateStartup();
      break;
    case WORKING:
      stateWorking();
      break;
  }
  // Faire tourner le moteur d'un pas
  // Il faut appeler cette fonction dans le loop sinon le moteur ne tourne pas
	myStepper.run();
}
