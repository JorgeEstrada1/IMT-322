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
typedef enum{
  v1=500,
  v2=1000,
  v3=1500
}velocidad;
velocidad velocidades=v1;

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
  delay(velocidades);
  digitalWrite(LED,0);
  delay(velocidades);

  if(boton1){
    
    if(digitalRead(CONTAR)==0){
      if(millis()-lasttime>=3000){
        cont=0;
        Serial.println("Contador Reiniciado");
        boton1=false;
      }
    }
  }
  if(boton2){
    
    if(digitalRead(REDUCIR)==0){
      if(millis()-lasttime>=3000){
        switch (velocidades){
          case v1:
          velocidades=v2;
          break;
          case v2:
          velocidades=v3;
          break;
          case v3:
          velocidades=v1;
          break;
        }
        Serial.print("Velocidad: ");
        Serial.println(velocidades);
        boton2=false;
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
      boton2=true;
      lasttime=millis();
      Serial.println(cont);
    }  
  }
}