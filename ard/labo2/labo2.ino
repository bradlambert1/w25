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
    return potValue;
  }
 
}
void button(int potValue) {
  int pot = map(potValue, 0, 1023, 0, 20);
  int pot100 = map(potValue, 0, 1023, 0, 100);
  const int DA_AVANT_DERNIER = 0;
  if(estClic(currentTime)){
    if (DA_AVANT_DERNIER % 2 == 0) {
     Serial.print('[');
      for (int i = 0; i < 20; i++) {
        if (pot >= i + 1) {
          Serial.print('#');
        } else {
          Serial.print('.');
        }
      }
      Serial.print("]  ");
      Serial.print(pot100);
      Serial.println("%");
      leds(potValue);  
    } else { 
      Serial.print(pot100);
      Serial.print("%  [");
      for (int i = 0; i < 20; i++) {
        if (pot >= i + 1) {
          Serial.print('@');
        } else {
          Serial.print('.');
        }
      }
      Serial.println(']');
    }
  }
}

void leds(int potValue) {
  //Responsive but assumes decrementing and sequential pin numbers, as well as a number of leds dividable by 4 
  int pot100 = map(potValue, 0, 1023, 0, 100);
  const int lowestPinNumber = 8;
  const int highestPinNumber = 11;
  const int pinDiff = highestPinNumber - lowestPinNumber + 1;
  int bulbsPerBracket = pinDiff / 4;
  int pin = highestPinNumber;
  
  for (int j = lowestPinNumber; j <= highestPinNumber; j++) {
    analogWrite(j, 0);
  }
  
  if (pot100 < 25) {
    pin = pin - (pinDiff * 0);
    for (int i = 0; i < bulbsPerBracket; i++) {
      analogWrite(pin, 255);
      pin ++;
    }
  } else if (pot100 < 50) {
  pin = pin - (pinDiff * (1*(1.0/4.0)));
  for (int i = 0; i < bulbsPerBracket + 1; i++) {
    analogWrite(pin, 255);
    pin++;
  }
  } else if (pot100 < 75) {
  pin = pin - (pinDiff * (2*(1.0/4.0)));
  for (int i = 0; i < bulbsPerBracket + 2; i++) {
    analogWrite(pin, 255);
    pin++;
  }
  } else if (pot100 <= 100) {
  pin = pin - (pinDiff * (3*(1.0/4.0)));
  for (int i = 0; i < bulbsPerBracket + 3; i++) {
    analogWrite(pin, 255);
    pin++;
  }
  } else {
    Serial.print("Error");
  }
  
}

void loop() {
  currentTime = millis();
  int pot = potentium();
  button(pot);
  leds(pot);  
}
