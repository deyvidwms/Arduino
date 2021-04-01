  int carR = 2;
  int carY = 3;
  int carG = 4;
  int pR = 5;
  int pG = 6;
  int button = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  pinMode(carR, OUTPUT);
  pinMode(carY, OUTPUT);
  pinMode(carG, OUTPUT);
  pinMode(pR, OUTPUT);
  pinMode(pG, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(carR, 1);
  digitalWrite(carG, 0);
  digitalWrite(carY, 1);
  digitalWrite(pR, 0);
  digitalWrite(pG, 1);

  if(!digitalRead(button)){
    delay(2000);
    digitalWrite(carR, 1);
    digitalWrite(carG, 1);
    digitalWrite(carY, 0);
    delay(2000);
    digitalWrite(carR, 0);
    digitalWrite(carG, 1);
    digitalWrite(carY, 1);
    digitalWrite(pR, 1);
    digitalWrite(pG, 0);
    delay(3000);
    tone(8, 3000);
    delay(1000);
    
  }
}
