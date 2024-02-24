#define LED 13
#define LED2 12
#define LED3 11
#define PULSADOR 7
#define ARDUINO 9600
#define TIEMPO 200
uint8_t val=0;
uint8_t apagar=0;
uint8_t prender=0;

void setup() {
pinMode(LED, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(PULSADOR, INPUT_PULLUP);
Serial.begin(ARDUINO);
}

void loop() {
  val=digitalRead(PULSADOR);
  Serial.println(val);
  if(val && apagar == 0)
    {
      prender = 1- prender;
      delay (300);
    }
    apagar = val;
  if (prender){
    digitalWrite(LED, LOW);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
    delay(TIEMPO);
    digitalWrite(LED, LOW);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED3,LOW);
    delay(TIEMPO);
    digitalWrite(LED, HIGH);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,LOW);
    delay(TIEMPO);
  }
  else{
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
}


