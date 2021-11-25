#include <Wire.h> 
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);  


#define R A1
#define MQ A0


void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(R, INPUT);
  pinMode(MQ, INPUT); 
  dht.begin();    
}


int t;
void loop() {
  int r=analogRead(R);      
  int mq=analogRead(MQ);
  r=map(r,0,1023,100,0);
  mq=map(mq,0,1023,0,100);  
  t = (int)dht.readTemperature();
  Serial.print("T ");
  Serial.print(t);  
  Serial.print(" R ");
  Serial.print(r);
  Serial.print(" M ");
  Serial.print(mq);  
  Serial.println();
  delay(1000);    
}
