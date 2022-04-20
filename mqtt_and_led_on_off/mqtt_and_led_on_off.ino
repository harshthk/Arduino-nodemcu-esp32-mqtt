
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define LED D2
// Update these with values suitable for your network.

const char* ssid = "iBall-Baton";
const char* password = "gj1ns9622";
const char* mqtt_server = "iot.eclipse.org";
String data="";

WiFiClient espClient;
PubSubClient client(espClient);
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    data=data+(char)payload[i];
  }
  Serial.println(data);

  if( data=="LedOn")
  {
     digitalWrite(LED, HIGH);
     data="";
  }
  if(data=="LedOff")
  {
       digitalWrite(LED,LOW);
       data="";

  }
  }



void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
   
     
      client.subscribe("ledtesting");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(115200);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

 
    client.publish("testing", "hey from harsh");
  }
