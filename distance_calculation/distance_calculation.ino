#include <LiquidCrystal.h>
#include <SoftwareSerial.h>


SoftwareSerial BTserial(10, 11); // TX | RX
//
#define echo_pin_front 53
#define trig_pin_front 52


int max_range = 400;
int min_range = 0;
int duration;
int distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo_pin_front, INPUT);
  pinMode(trig_pin_front, OUTPUT);

  
  BTserial.begin(9600);

}

void loop() {
  
  ////for front side/////
  Serial.print("front:");
  
  digitalWrite(trig_pin_front, LOW);
  delayMicroseconds(100);
  
  digitalWrite(trig_pin_front, HIGH);
  delayMicroseconds(100);
  
  digitalWrite(echo_pin_front, HIGH);

  duration = pulseIn(echo_pin_front, HIGH);
  distance = (duration / 2) / 29.1; // calculate distance in cm

  Serial.println(distance);
  BTserial.print("Front : "  );
  BTserial.print(distance);
  delay(1000);


}
