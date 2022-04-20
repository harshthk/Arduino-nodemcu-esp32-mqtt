#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE); 
const int led = 5;
void setup(void)
{ 
  pinMode(led,OUTPUT);
  dht.begin();
  Serial.begin(9600);
  Serial.println("Humidity and temperature\n\n");
  delay(700);

}
void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();         
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t); 
    Serial.println("C  ");
  delay(800);
  if (t < 27)

{ 
  digitalWrite(led,HIGH);

}

else  
{

 digitalWrite(led,LOW);

}
  
}
