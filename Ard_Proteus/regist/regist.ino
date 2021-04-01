//Pin connected to ST_CP of 74HC595
int latchPin = 4;
//Pin connected to SH_CP of 74HC595
int clockPin = 5;
//Pin connected to DS of 74HC595
int dataPin = 3;
//Ligado ao pino 2 do L293D
int Entrada1 = 6;   
//Ligado ao pino 7 do L293D
int Entrada2 = 7;   

int incomingByte = -1;
int data = 0;
bool menu = 1;

void s595(int data);

void setup() {
  //set pins to output because they are addressed in the main loop
  
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(Entrada1, OUTPUT);  
  pinMode(Entrada2, OUTPUT); 
  Serial.begin(9600);
}


void loop() {
  
  if (menu) {
  Serial.println("Menu:");
  Serial.println("0 - Lampadas");
  Serial.println("1 - Caragem");
  Serial.println("2 - Portoes");
  menu = 0;
  }
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();
  
    switch (incomingByte) {
      case 0:
        Serial.println("lampada 0 a 15: ");
        while (Serial.available() == 0 && menu == 0) {
        // read the incoming byte:
          if (Serial.available() > 0){
            incomingByte = Serial.parseInt();
            bitWrite(data, incomingByte, !bitRead(data,incomingByte));  
            s595(data);
            delay(100);
            menu = -1;
          }
        }
        break;
      case 1:
        inicia_motor();
        menu =-1;
        break;
    }
  }
  
  
}


/////////////////////////////////////////////

void s595(int data){
  //coloca e mantém o pino latch em low enquanto ocorre a transmissão
  digitalWrite(latchPin, LOW);
  
  //transmite o valor de j, a começar pelo bit menos significativo
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  shiftOut(dataPin, clockPin, LSBFIRST, (data >> 8));
  
  
  //retorna o pino latch para high para sinalizar ao chip
  //que esse não precisa mais esperar por informação
  digitalWrite(latchPin, HIGH);
}

void inicia_motor()
{
  //Define a velocidade de rotacao  
  //int velocidade = 500;  
  //analogWrite(PinoVelocidade, velocidade);   

  //Aciona o motor  
  digitalWrite(Entrada1, LOW);  
  digitalWrite(Entrada2, HIGH);  
  delay(3000);  

  //Chama a rotina de parada do motor  
  para_motor();  

  //Aciona o motor no sentido inverso  
  digitalWrite(Entrada1, HIGH);  
  digitalWrite(Entrada2, LOW);  
  delay(3000); 
  para_motor();
}

void para_motor()  
{  
  digitalWrite(Entrada1, LOW);  
  digitalWrite(Entrada2, LOW);  
  delay(3000);  
}

