unsigned long currentTime = 0;
const int broche = A1;
const int broche_button = 2;

void setup() {
  Serial.begin(115200);
}
 
void potentium() {
  const int interval = 1000;
  static unsigned long previousTime = currentTime;
  if(currentTime - previousTime >= interval){
    previousTime = currentTime;
    int potValue = analogRead(broche);
    int mappedValue = map(potValue, 0, 1023, 0, 20);
    Serial.println(mappedValue);
  }
}
void button() {
  
}
void loop() {
  currentTime = millis();

  potentium();
  button();  
  //Exécuter d'autres choses
}