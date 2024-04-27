#include "funciones.h"
#define BOTON 10
#define BAUDRATE 9600
String msg1 = "Bienvenido";
String msg2 = "Ingrese el dinero";
String msg3 = "Seleccione una de las bebidas disponibles";
String msg4 = "1) Bebida 1 Precio 2$";
String msg5 = "2) Bebida 2 Precio 5$";
String msg6 = "3) Bebida 3 Precio 7$";
int monto;
int cambio;
int mynumber;
int estado;
typedef enum{
  ESPERA,
  BEBIDA1,
  BEBIDA2,
  BEBIDA3
}EXPENDEDORA;
EXPENDEDORA FSM = ESPERA;


void setup () {
  Serial.begin(BAUDRATE);
  Serial.println(msg1);
  Serial.println(msg2);
  pinMode(BOTON, INPUT);
}
void loop(){
while (Serial.available() == 0){
  }
monto = Serial.parseInt();
Serial.print("Tienes "); 
Serial.print(monto);
Serial.println("$ de saldo.");
if(monto>1){
  Serial.println(msg3);
  Serial.println(msg4);
  Serial.println(msg5);
  Serial.println(msg6);
  while (Serial.available() == 0){
    }
  mynumber = Serial.parseInt();
  if (mynumber == 1){
    FSM = BEBIDA1;
  }
  if (mynumber == 2){
    FSM = BEBIDA2;
  }
  if (mynumber == 3){
    FSM = BEBIDA3;
  }
  switch (FSM){
          case BEBIDA1:
          cambio = monto - 2;
          Serial.println("Elegiste la bebida 1 ");
          Serial.print("Tu cambio es de: ");
          Serial.println(cambio);
          mostrarBarraDeCarga(2000);
          Serial.print("Presiona el boton para retirar el vaso");
          while(BOTON==LOW){

          }
          estado=digitalRead(BOTON);
            if(estado==HIGH){
              Serial.println("Bebida retirada");
            }

          break;
          case BEBIDA2:
          cambio = monto - 5;
          Serial.println("Elegiste la bebida 2 ");
          Serial.print("Tu cambio es de: ");
          Serial.println(cambio);
          mostrarBarraDeCarga(5000);
          Serial.println("Presiona el boton para retirar el vaso");
          while(BOTON==LOW){

          }
          estado=digitalRead(BOTON);
            if(estado==HIGH){
              Serial.println("Bebida retirada");
            }

          break;
          case BEBIDA3:
          cambio = monto - 7;
          Serial.println("Elegiste la bebida 3 ");
          Serial.print("Tu cambio es de: ");
          Serial.println(cambio);
          mostrarBarraDeCarga(7000);
          Serial.print("Presiona el boton para retirar el vaso");
          while(BOTON==LOW){

          }
          estado=digitalRead(BOTON);
            if(estado==HIGH){
              Serial.println("Bebida retirada");
            }
          break;
          }

      }
 


}