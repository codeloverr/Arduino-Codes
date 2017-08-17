#include <SoftwareSerial.h>


SoftwareSerial BTserial(11, 10); // RX | TX
#define echoPin 48
#define trigPin 49




int max_range = 400;
int min_range = 0;
int duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  BTserial.begin(9600);

}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.print("front:");
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // calculate distance in cm
  delay(500);
  Serial.println(distance);
  BTserial.print("Front : "  );
  BTserial.println(distance);
  

  delay(500);


}
