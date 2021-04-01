//var
int opcaoMP;

//var aux



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.flush();
}

void loop() {
  
  Serial.println("##========================##");
  Serial.println("||          MENU          ||");
  Serial.println("##========================##");
  Serial.println("|| 1 - Controle de Leds   ||");
  Serial.println("|| 2 - Controle do Portão ||");
  Serial.println("|| 3 - Abrt. de Fechadura ||");
  Serial.println("|| 4 - Acendimento Led    ||");
  Serial.println("##========================##");
  
  opcaoMP = Serial.read();
  switch (opcaoMP){
    case 0:
      func_um();
      break;
    case 1:

      break;
    case 2:

      break;
    case 3:
      
      break;
  }
  
  
}

void func_um(){
  int opLed;
  if (Serial.available()>0){
      opLed = Serial.read();
      
      if(opLed == '1'){
        Serial.println("Entrou 1");
      }
      
  }
  
}  


