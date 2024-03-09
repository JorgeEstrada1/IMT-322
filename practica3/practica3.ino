// Definición de pines para pulsadores
#define      CONT   2
#define      RESET  3
#define      BAUDRATE 9600
#define      LED     13
// Variables para el manejo de pulsadores

volatile unsigned long lasttime = 0;
volatile unsigned long debounceDelay = 2000; // Tiempo de antirrebote

// Contador
volatile int contador = 0;
volatile int contador2 = 0;

void setup() {
  // Configurar pines de entrada para pulsadores
  pinMode(CONT, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  // Configurar interrupciones para pulsadores
  attachInterrupt(digitalPinToInterrupt(CONT), Contador, RISING);
  attachInterrupt(digitalPinToInterrupt(RESET), reset, RISING);

  // Iniciar comunicación serial 
  Serial.begin(BAUDRATE);
  }

void loop() {
  // Verificar si el pulsador 1 fue presionado
  if (contador2 == 1){
      digitalWrite(LED,HIGH);
      delay(500);
      digitalWrite(LED,LOW);
      delay(500);
  }
  if (contador2 == 2){
      digitalWrite(LED,HIGH);
      delay(1000);
      digitalWrite(LED,LOW);
      delay(1000);
  }
  if (contador2 == 3){
      digitalWrite(LED,HIGH);
      delay(1500);
      digitalWrite(LED,LOW);
      delay(1500);
  }
}

// Función de interrupción para el pulsador 1
void Contador() {

  if (millis() - lasttime > debounceDelay) {
    contador++;
    lasttime = millis();
    Serial.println(contador);
  }
}

// Función de interrupción para el pulsador 2
void reset() {
  if (millis() - lasttime > debounceDelay) {
    contador=0;
    contador2++;
    lasttime = millis();
    Serial.println("Contador reiniciado");
    Serial.println(contador2);
  if (contador2 >= 3){
      contador2 = 0;
    
  }
}
}
