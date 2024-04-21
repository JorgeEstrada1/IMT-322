#define echoPin 13
#define trigPin 12
#define BOTON 11
int Baudrate = 9600;
int estado = HIGH;
volatile bool btnflag=false;
volatile unsigned long lasttime=0;
typedef enum{
  ENCENDER,
  MEDIR,
}lectura;
lectura FSM = ENCENDER;
long duracion, distancia;
void setup()
{
Serial.begin(Baudrate);
pinMode(BOTON, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
digitalWrite(trigPin, LOW);
}
void loop(){
        switch (FSM){
          case ENCENDER:
          if(btnflag){
    		if(digitalRead(BOTON)==0){
      			if(millis()-lasttime>=3000){
          		FSM = MEDIR;
                }
             }
          }
          break;
          case MEDIR:
          for(int i=0; i<=120; i++) {
            digitalWrite(trigPin, HIGH);
    	  	delayMicroseconds(10);
    	  	digitalWrite(trigPin, LOW);
          	duracion = pulseIn(echoPin, HIGH);
          	FSM = ENCENDER;
            Serial.print("El sensor esta midiendo a: ");
        	  Serial.println(distancia);
        	  btnflag=false;
   			}
          break;
        
      }
    
  }