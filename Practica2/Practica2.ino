#define LED 13
#define PULSADOR 3
#define ARDUINO 9600
#define TIEMPO 200
int contar =0;

void setup() {
pinMode(LED, OUTPUT);
pinMode(PULSADOR, INPUT_PULLUP);
Serial.begin(ARDUINO);
attachInterrupt(digitalPinToInterrupt(PULSADOR), contador, RISING);
}

void loop() {
digitalWrite(LED, HIGH);
delay(TIEMPO);
digitalWrite(LED, LOW);
delay(TIEMPO);
Serial.println(contar);
delay(TIEMPO);
}

void contador(){
  contar++;

}


