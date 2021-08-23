//#include <WiFiClient.h>
//#include <WiFiServer.h>
//#include <WiFiUdp.h>
//#include<ArduinoOTA.h>
#include <WiFi.h>
#include<Wire.h>
#include<SPI.h>
WiFiClient client1;
WiFiServer server1(80);
byte n=1;
byte front=4,right=5,back=6,left=7;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  //  wifi related stetup are here
  WiFi.begin("sahay","12345678");
 
 while(WiFi.status()!=WL_CONNECTED)
    {
   Serial.print("..");
   delay(200);
 }
  
  Serial.println("Wifi is connected");
  Serial.println(WiFi.localIP());
  server1.begin();
  Wire.begin();
 
  DDRC=0x00;
  DDRD=0xf0;
  PORTD=0x00;
  Serial.println("sahay"); 
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //  client=server1.avaliable();
 while(server1.available()/*client1==1*/)
  {
    String request=client1.readStringUntil("\n");
    Serial.println(request);
    request.trim();
  }
 
 movement();
 delay(10);
  
  
}

void tomotor(int k)
{
  //Wire.requestFrom(k,1); 
  Wire.beginTransmission(k);
  Wire.write(n);
  Wire.endTransmission();
}

void trigger()
{
  byte pre=PORTD;
  PORTD=0xf0;
  delay(10);
  front=analogRead(A0);
  left=analogRead(A1);
  right=analogRead(A2);
  back=analogRead(A3);
  PORTD=pre;
  delay(10);
}

void movement()
{
  trigger();
  delay(10);
  if(front==0)
  {n=0;}
  else if(left==0)
  {n=90;}
  else if(right==0)
  {n=270;}
  else if(back==0)
  {n=180;}
  tomotor(8);
}
