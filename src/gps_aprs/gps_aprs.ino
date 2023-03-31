#include <SoftwareSerial.h>

//#include <LibAPRS.h>

#define led 13

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  
  Serial.begin(9600);
  Serial.println("WVU Rocketry - GPS APRS tracker");

}

void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
