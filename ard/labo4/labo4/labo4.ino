#include <LiquidCrystal.h>
const int rs = 36, en = 34, d4 = 32, d5 = 30, d6 = 28, d7 = 26;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.port(9600)
}

void printDistance(string da, int dist, int deg) {
  Serial.print("etd:");
  Serial.print(da);
  Serial.print(",dist:");
  Serial.print(dist);
  Serial.print(",deg:");
  Serial.println(deg);
}

StartupPrint() {
  lcd.SetCursor(0, 0);
  lcd.print("2471005");
  lcd.SetCursor(0,1);
  lcd.print("Labo 4B");
  delay(2000);
}

void stateStartup() {
  static bool firstRun = true;
  if (firstRun) {
    StartupPrint();
    firstRun = false;
  }
}



void loop() {
  // put your main code here, to run repeatedly:  
  stateStartup();



}
