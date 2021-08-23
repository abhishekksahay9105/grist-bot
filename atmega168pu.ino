//function created
//requestEvent()  
//recieveEvent()  
//forward() 
//backward()
//right()
//left()

#include<Wire.h>
byte x=0x00;
int n=0;
void setup() 
{
   Serial.begin(9600);
   DDRB=0xff;
   PORTB=0x00;
   Wire.begin(8);
   Wire.onRequest(requestEvent);
   Wire.onReceive(recieveEvent);                 
   pinMode(3,OUTPUT);  
}

void loop() 
{
   // step one revolution in the other direction:
   Serial.print(n);
   while(n==0){forward();digitalWrite(3,HIGH);}
   if(n==180){right();delay(10);stopped();digitalWrite(3,LOW);}
   if(n==90){right();Serial.print(n);delay(5);stopped();}
   if(n==270){left(); delay(5);stopped();}   
}

void requestEvent()
{
 Serial.print("sahay");
}

void recieveEvent()
{
   n=Wire.read();
}

void forward()
{
    PORTB=0x81;delay(10);
    PORTB=0x42;delay(10);
    PORTB=0x24;delay(10);
    PORTB=0x18;delay(10);
}


void backward()
{
   PORTB=0x18;delay(10);
   PORTB=0x24;delay(10);
   PORTB=0x42;delay(10);
   PORTB=0x81;delay(10);
}

void stopped()
{
  PORTB=0x00;delay(5);
}

void right()
{
  PORTB=0x11;delay(10);
  PORTB=0x22;delay(10);
  PORTB=0x44;delay(10);
  PORTB=0x88;delay(10);
}

void left()
{
  PORTB=0x88;delay(10);
  PORTB=0x44;delay(10);
  PORTB=0x22;delay(10);
  PORTB=0x11;delay(10);
}
