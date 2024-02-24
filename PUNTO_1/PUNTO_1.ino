#define LED 5
#define LED2 6
#define LED3 7
#define TIEMPO 200
void setup() {
pinMode(LED, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  delay(TIEMPO);
  digitalWrite(LED, LOW);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
  delay(TIEMPO);
  digitalWrite(LED, LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  delay(TIEMPO);
}
