// this doesn't work

#define STEP GPIO_NUM_33
#define DIR  GPIO_NUM_32

int i;
 
void setup() {
  pinMode(STEP,OUTPUT);
  pinMode(DIR, OUTPUT);
  delay(100);
  digitalWrite(DIR,LOW);
  digitalWrite(STEP,LOW);
}
 
void loop() {
  for (i = 0; i < 5000;i++) {
    digitalWrite(STEP,HIGH);
    delayMicroseconds(10);
    digitalWrite(STEP,LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}
