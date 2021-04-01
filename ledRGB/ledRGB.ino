#define red 49
#define green 50
#define blue 51
int pinRed = 11;
int pinGreen = 9;
int pinBlue = 10;
int cor;

void setup(){
  Serial.begin(9600);
  Serial.flush();
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinBlue, OUTPUT);
}

void loop(){
  if (Serial.available()>0){
    cor = Serial.read();
    digitalWrite(pinRed, LOW);
    digitalWrite(pinGreen, LOW);
    digitalWrite(pinBlue, LOW);
    if (cor == '1'){
      Serial.println("Red ON");
      digitalWrite(pinRed, HIGH);
    }else if(cor == green){
      Serial.println("Green ON"); 
      digitalWrite(pinGreen, HIGH);
    }else if(cor == blue){
      Serial.println("Blue ON");
      digitalWrite(pinBlue, HIGH);
    }else if(cor == 4){
      Serial.println("ALL ON");
      digitalWrite(pinRed, HIGH);
      digitalWrite(pinGreen, HIGH);
      digitalWrite(pinBlue, HIGH);
    }else{
      Serial.println("Valor Inválido!");
      Serial.println("Red - 1 | Green - 2 | Blue - 3 | 4 - ALL");
    }
    
    //Serial.flush();
    //delay(100);    
  }
  
}
