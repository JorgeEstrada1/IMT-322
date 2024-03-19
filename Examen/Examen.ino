#define     SUB     27
#define     BAJ      14
#define     BAUDRATE    115200
/*declaracion de variables*/
volatile uint16_t cont =5;
volatile unsigned long lasttime=0;
volatile unsigned long debounceDelay=100;
volatile bool btnflag=false;
volatile bool btnflag2=false;
int i=0;
/*declaracion de funciones*/
void sig();
void ant();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  pinMode(SUB,INPUT_PULLUP);
  pinMode(BAJ,INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(SUB),sig,FALLING);
  attachInterrupt(digitalPinToInterrupt(BAJ),ant,FALLING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis()<30000){
    Serial.print("Siguiente Cancion: ");
    Serial.println(i++);
    if (i>31){
      i=0;
    }
    delay(1000);
  }

  if(btnflag){
    
    if(digitalRead(SUB)==0){
      if(millis()-lasttime>=3000){
        cont=0;
        Serial.println("Siguiente Cancion");
        btnflag=false;
      }
    }
  }
  if(btnflag2){
    
    if(digitalRead(BAJ)==0){
      if(millis()-lasttime>=3000){
        cont=0;
        Serial.println("Anterior Cancion");
        btnflag=false;
      }
    }
  }
  

}

/*funciones de interrupcion*/
void sig(){
  if(millis()-lasttime>debounceDelay){
    if(digitalRead(SUB)==0){
      cont++;
      btnflag=true;
      lasttime=millis();
      if (cont <11 ){
        Serial.print("Volumen: ");
        Serial.println(cont);
        

      }
      
    }
    
  }
  
  
}
void ant(){
  if(millis()-lasttime>debounceDelay){
    if(digitalRead(BAJ)==0){
      cont--;
      btnflag2=true;
      lasttime=millis();
      if (cont >0 ){
        Serial.print("Volumen: ");
        Serial.println(cont);
      }

      }
    }  

}