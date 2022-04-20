#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#define DHTTYPE DHT11
#define dht_dpin 4
DHT dht(dht_dpin, DHTTYPE); 
// Replace with your network credentials
const char* ssid = "iBall-Baton";
const char* password = "<gj1ns9622>";

ESP8266WebServer server(80);   //instantiate server at port 80 (http port)
String page = "";
float t;
float h;
void setup()
{

  pinMode(D2, INPUT);
  
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password); //begin WiFi connection
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", [](){
    page = "<h1>Sensor to Node MCU Web Server</h1><h3>Data:</h3> <h4>"+String(t)+String(h)+"</h4>";
    server.send(200, "text/html", page);
  });
  
  server.begin();
  Serial.println("Web server started!");
}
 
void loop(void){
    float h = dht.readHumidity();
   float t = dht.readTemperature();
  server.handleClient();
}
