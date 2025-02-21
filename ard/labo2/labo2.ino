unsigned long currentTime = 0;
 
void setup() {
  Serial.begin(115200);
}
 
void loop() {
  const int interval = 1000;
  static unsigned long previousTime = 0;

  currentTime = millis();

  //potentiometre
  if(currentTime - previousTime >= interval){
      previousTime = currentTime;

      analogRead(A0)
  }
  
  //Exécuter d'autres choses
}