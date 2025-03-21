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



void loop() {
  // put your main code here, to run repeatedly:

}
