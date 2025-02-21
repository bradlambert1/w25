unsigned long currentTime = 0;
const int broche = A1;
const int PIN_BUTTON = 2;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_BUTTON, INPUT_PULLUP);

}
 
int estClic(unsigned long ct) {
  static unsigned long lastTime = 0;
  static int lastState = HIGH;
  const int rate = 50;
  int clic = 0;

  if (ct - lastTime < rate) {
    return clic; // Trop rapide
  }

  lastTime = ct;

  int state = digitalRead(PIN_BUTTON);

  if (state == LOW) {
    if (lastState == HIGH) {
      clic = 1;
    }
  }

  lastState = state;

  return clic;
}

int potentium() {
  const int interval = 1000;
  static unsigned long previousTime = currentTime;
  int pot = 0;
  if(currentTime - previousTime >= interval){
    previousTime = currentTime;
    int potValue = analogRead(broche);
    pot = map(potValue, 0, 1023, 0, 20);
    return pot;
  }
 
}
void button(int pot) {
  if(estClic(currentTime)){
    if (pot % 2 == 0) {
     Serial.print('[');
      for (int i = 0; i < 20; i++) {
        if (pot >= i) {
          Serial.print('#');
        } else {
          Serial.print('.');
        }
      }
      Serial.println(']');
      Serial.print("  ");
      Serial.print((pot*100)/20);
      Serial.print("%");
    } 
    } else {
      Serial.print((pot*100)/20);
      Serial.print("%  ");
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


void loop() {
  currentTime = millis();
  int pot = potentium();
  button(pot);  
  //Exécuter d'autres choses
}

// static int previousState = HIGH; 
//   static int state = HIGH;
//   const int interval = 10;
//   static unsigned long previousTime = currentTime;
//   static unsigned int currentState = digitalRead(broche_button);
//   static unsigned long lastChange = 0;
//   if (currentState != previousState) {
//     lastChange = millis();
//   }
//   if(millis() - lastChange >= interval && currentState != state){
//     previousState = currentState;
//     previousTime = currentTime;
//     if (analogRead(2) == 1) {
    //  Serial.print('[');
    //   for (int i = 0; i < 20; i++) {
    //     if (pot >= i) {
    //       Serial.print('#');
    //     } else {
    //       Serial.print('.');
    //     }
    //   }
    //   Serial.println(']');
//     }
//   }
