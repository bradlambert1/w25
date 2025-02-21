unsigned long currentTime = 0;
const int broche = A1;
const int broche_button = 2;

void setup() {
  Serial.begin(115200);
  pinMode(broche_button, INPUT_PULLUP);

}
 
void potentium(int& pot) {
  const int interval = 1000;
  static unsigned long previousTime = currentTime;
  if(currentTime - previousTime >= interval){
    previousTime = currentTime;
    int potValue = analogRead(broche);
    pot = map(potValue, 0, 1023, 0, 20);
  }
}
void button(int pot) {
  static int etatPrecedent = HIGH; 
  static int state = HIGH;
  const int interval = 25;
  static unsigned long previousTime = currentTime;
  static unsigned int currentState = digitalRead(broche_button);
  if (currentState != previousState) {
    previousTime = currentTime;
  }
  static unsigned int previousState = currentTime
  if(currentTime - previousTime >= interval && currentState != state){
    state = currentState;
    previousTime = currentTime;
    if (analogRead(2) == 1) {
     Serial.print('[');
      for (int i = 0; i < 20; i++) {
        if (pot >= i) {
          Serial.print('#');
        } else {
          Serial.print('.');
        }
      }
      Serial.println(']');
    }
  }
}
void loop() {
  currentTime = millis();
  int pot = 0;

  potentium(pot);
  button(pot);  
  //Exécuter d'autres choses
}