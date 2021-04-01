int LEDs[]={3,5,6,11};
int pwmLeds [] = {0, 64, 128, 255};

void setup() {
  // put your setup code here, to run once:
  for  (int i=0;i<4;i++){
    pinMode(LEDs[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++){
    analogWrite(LEDs [i],pwmLeds[i]);
    delay(150);
  }
  int aux = pwmLeds[0];
  for (int i = 0; i < 3; i++){
    pwmLeds[i] = pwmLeds[i +1];
  }
  pwmLeds[3] = aux;
}
