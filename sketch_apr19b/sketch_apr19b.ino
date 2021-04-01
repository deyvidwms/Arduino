void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(7)) digitalWrite(13,0);    
  else digitalWrite(13,1);


}

