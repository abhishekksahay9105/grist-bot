#include<Wire.h>
byte n=1;
int front=4,right=5,back=6,left=7;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  pinMode(3,INPUT);
  pinMode(2,OUTPUT);
  DDRC=0x00;
  DDRD=0xf0;
  PORTD=0xf0;
  
}

void loop() 
{
  // put your main code here, to run repeatedly:
  while(analogRead(A0)==0)
  {
    n=1;
    toslave();
    trigger(front);
  }
  trigger(right);
 
   if(analogRead(A1==0)
  {
    n=2;
    toslave();
    delay(250);
  }
  else
  {
    trigger(left);
    if(analogRead(A3==0)
  {
    n=2;
    toslave(4);
    delay(250);
  }
  else
  {
    trigger(back);
    while(analogRead(A2==0)
    {
      search();
    }
    
  }
  }
  
  
  
  
}

void toslave()
{
  //Wire.requestFrom(8,1); 
 
  Wire.beginTransmission(8);
  Wire.write(n);
  Wire.endTransmission();
}
void trigger(int n)
{
  byte pre=PORTD;
  PORTD|=(1<<n);
  delay(1);
  PORTD=pre;
  delay(1);
}
