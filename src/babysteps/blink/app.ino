#define LED GPIO_NUM_2
 
void setup() {
  pinMode(LED,OUTPUT);
}
 
void loop() {
  digitalWrite(LED,!digitalRead(LED));
  delay(100);
  // delayMicroseconds(17);
}
