unsigned long currentTime = 0;
const int broche = A1;
const int PIN_BUTTON = 2;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void name() {
  //this should last 3 seconds,
}
void photores() {
  
}

void loop() {
  currentTime = millis();
  name();
  photores();
}
