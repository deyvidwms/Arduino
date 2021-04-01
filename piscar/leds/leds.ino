int LEDs[]={3,5,6,11};
void setup() {
  // put your setup code here, to run once:
  for  (int i=0;i<4;i++){
    pinMode(LEDs[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for  (int i=0;i<4;i++){
    digitalWrite(LEDs[i], HIGH);
    delay(150);
  }
  
   for  (int i=3;i > -1;i--){
     digitalWrite(LEDs[i], LOW);
     delay(150);
   }
  
}
