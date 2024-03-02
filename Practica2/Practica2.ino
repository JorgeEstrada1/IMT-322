#define LED 13
#define LED2 12
#define PULSADOR 3
#define ARDUINO 9600
#define TIEMPO 200
bool estado = false;
void setup() {
pinMode(LED, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(PULSADOR, INPUT_PULLUP);
Serial.begin(ARDUINO);
attachInterrupt(digitalPinToInterrupt(PULSADOR), prender, RISING);
}

void loop() {
digitalWrite(LED, HIGH);
delay(TIEMPO);
digitalWrite(LED, LOW);
delay(TIEMPO);
}

void prender(){
  estado =! estado;
  if (estado==HIGH){
  digitalWrite(LED2, HIGH);
  }
  else{
  digitalWrite(LED2, LOW);
  }
}


