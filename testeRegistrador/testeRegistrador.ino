int latch = 10;
int clockP = 13;
int data = 4;

int seq[14] = {1,2,4,8,16,32,64,128,64,32,16,8,4,2};


void setup()
{
  pinMode(latch, OUTPUT); //pinos de saída
  pinMode(clockP, OUTPUT);
  pinMode(data, OUTPUT);
  
 
}

void loop()
{

  for(int i = 0; i < 14;i++)
  {
  
    digitalWrite(latch, LOW);
    shiftOut(data,clockP, MSBFIRST, seq[i]);
    digitalWrite(latch,HIGH);
                 
    delay(100);
    
  }

}
