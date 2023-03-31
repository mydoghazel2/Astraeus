#include <SoftwareSerial.h>

#define RX_radio 14
#define TX_radio 15
//#include <LibAPRS.h>
SoftwareSerial mySerial(RX_radio, TX_radio); // RX, TX

#define led 13
String a;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
  
  Serial.begin(9600);
  Serial.println("WVU Rocketry - GPS APRS tracker");

  init_radio();
  radio_on();
  radio_RX();
  radio_low_pw();


  mySerial.begin(9600);
  mySerial.print("\r\n");

  mySerial.print("AT+DMOCONNECT\r\n");
  a = mySerial.readStringUntil('\n'); 
  mySerial.print("AT+DMOCONNECT\r\n");
  a = mySerial.readStringUntil('\n'); 

  Serial.print(">>");
  Serial.println(a);

  mySerial.print("AT+DMOSETGROUP=1,144.3900,144.3900,0000,5,0000\r\n");
  radio_TX();
}

void loop() {

  if (mySerial.available()>0){
     //a = mySerial.readString('\n');
     Serial.print(">");
     //Serial.print(a);
  }

 // radio_TX();
 // delay(2000);
 // radio_RX();
 // delay(2000);

  // blank line to separate data from the two ports:

      // wait for a second
}
