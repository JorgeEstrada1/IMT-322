String msg1 = "Ingrese a que piso desea ir: '1', '2' o '3' ";
String msg2 = "Te encuentras en el piso: ";
int Baudrate = 9600;
int s = 0;
typedef enum{
  t,
  a,
  b,
  c
}lectura;
lectura FSM = t;
void setup()
{
Serial.begin(Baudrate);
}
void loop(){
  Serial.println(msg1);
  while (Serial.available() == 0){
  }
  int mynumber = Serial.parseInt();
  if (mynumber == 1){
    FSM = a;
  }
  if (mynumber == 2){
    FSM = b;
  }
  if (mynumber == 3){
    FSM = c;
  }
        switch (FSM){
          case a:
          while (s<=9){
              	s+=1;
                Serial.println(s);         		
          }
          if (s=9){
                  Serial.print(msg2);
          		  Serial.println(mynumber);
            	} 
          break;
          case b:
          while (s<=9){
              	s+=1;
                Serial.println(s);         		
          }
          if (s=9){
                  Serial.print(msg2);
          		  Serial.println(mynumber);
            	}
          break;
          case c:
          while (s<=9){
              	s+=1;
                Serial.println(s);         		
          }
          if (s=9){
                  Serial.print(msg2);
          		  Serial.println(mynumber);
            	}
          break;
      }
    
  }