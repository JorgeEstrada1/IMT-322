#define     CONTAR      2
#define     REDUCIR     3
#define     LED         13
#define     BAUDRATE    9600
volatile uint16_t cont =0;
volatile unsigned long lasttime=0;
volatile unsigned long debounceDelay=300;
volatile bool boton1=false;
volatile bool boton2=false;
void contador();
void reducir();

void setup() {
  Serial.begin(BAUDRATE);
  pinMode(CONTAR,INPUT_PULLUP);
  pinMode(REDUCIR,INPUT_PULLUP);
  pinMode(LED,OUTPUT);

  attachInterrupt(digitalPinToInterrupt(CONTAR),contador,FALLING);
  attachInterrupt(digitalPinToInterrupt(REDUCIR),reducir,FALLING);
  
}

void loop() {
  digitalWrite(LED,1);
  delay(500);
  digitalWrite(LED,0);
  delay(500);

  if(boton1){
    
    if(digitalRead(CONTAR)==0){
      if(millis()-lasttime>=3000){
        cont=0;
        Serial.println("Contador Reiniciado");
        boton1=false;
      }
    }
  }
  

}

void contador(){
  
  if(millis()-lasttime>debounceDelay){
    if(digitalRead(CONTAR)==0){
      cont++;
      boton1=true;
      lasttime=millis();
      Serial.println(cont);
    }
    
  }
}
void reducir(){
  if(millis()-lasttime>debounceDelay){
    if(digitalRead(REDUCIR)==0){
      cont--;
      lasttime=millis();
      Serial.println(cont);
    }  
  }
}