// Definición de pines para pulsadores
#define      CONT   2
#define      RESET  3
#define      BAUDRATE 9600
#define      LED     13
// Variables para el manejo de pulsadores

volatile unsigned long lasttime = 0;
volatile unsigned long debounceDelay = 2000; // Tiempo de antirrebote
volatile unsigned long lastPressTime = 0; // Tiempo de la última pulsación del botón contador

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