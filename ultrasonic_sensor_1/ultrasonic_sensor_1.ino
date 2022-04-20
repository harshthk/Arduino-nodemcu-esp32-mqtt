#define trigPin 9 // Trigger Pin of Ultrasonic Sensor
#define echoPin 8 // Echo Pin of Ultrasonic Sensor
#define ledPin 13
void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(ledPin, OUTPUT);
}

void loop() 
{ long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration*0.0343)/2 ;

if (distance < 10)

{ 
  digitalWrite(ledPin,HIGH);

}

else {

digitalWrite(ledPin,LOW);

}

Serial.print(distance);

Serial.println(" cm");

delay(500);

}
