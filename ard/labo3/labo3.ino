unsigned long currentTime = 0;
const int photometer = A0;
const int PIN_BUTTON = 2;
const int PIN_joyX = 0;
const int PIN_joyY = 0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void name() {
  //this should last 3 seconds,
}
void printLuminosity(bool isOn) {
  //LCD : Affiche la luminosité (ex. en %) et « Phares: ON/OFF ».
}
void photores() {
  float currentLuminosity = analogRead(photometer);
  static unsigned long underTimer = 0;
  static unsigned long overTimer = 0;

  if (currentLuminosity < 0.5) {
    underTimer += currentTime - lastTime;
  } else {
    underTimer = 0;
  }
  if (currentLuminosity > 0.5) {
    overTimer += currentTime - lastTime;
  } else {
    overTimer = 0;
  }


  if (underTimer >= 5000) {
    // turn on LEDS and print
    printLuminosity(1);
  }
  if (overTimer >= 5000) {
    //turn off LEDS and print

    printLuminosity(0);
  }


  static unsigned long lastTime = currentTime;
  static float lastLuminority = currentLuminosity;
}

void joystick() {
   // read analog X and Y analog values
  xValue = analogRead(PIN_joyX);
  yValue = analogRead(PIN_joyY);

  
}

void loop() {
  if (currentTime == 0) ? name();
  currentTime = millis();
  photores();
  joystick();
}
