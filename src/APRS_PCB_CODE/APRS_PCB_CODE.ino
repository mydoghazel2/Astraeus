

#include <stdio.h>
#include <SoftwareSerial.h>
#include "DRA818.h" // uncomment the following line in DRA818.h (#define DRA818_DEBUG)
#include <ArduinoQAPRS.h>

#include <LibAPRS_Tracker.h>

#define ADC_REFERENCE REF_5V
#define OPEN_SQUELCH false

/* Used Pins */
#define PD      16  // to the DRA818 PD pin
#define RX      14   // arduino serial RX pin to the DRA818 TX pin
#define TX      15   // arduino serial TX pin to the DRA818 RX pin

SoftwareSerial *dra_serial; // Serial connection to DRA818
DRA818 *dra;                // the DRA object once instanciated
float freq;                 // the next frequency to scan
String packetBuffer;

SoftwareSerial radioSerial(RX, TX);



void setup(){
  Serial.begin(9600); // for logging
  radioSerial.begin(9600);


  APRS_init();
  char myCALL[] = "KC3RXZ";
  char Lat[] = "2134.00N";
  char Lon[] = "01234.00E";

  APRS_setCallsign(myCALL, 9);
  APRS_setLat(Lat);
  APRS_setLon(Lon);
  

  Serial.println("Booting ...");

  Serial.print("initializing I/O ... ");  
  dra_serial = new SoftwareSerial(RX, TX); // Instantiate the Software Serial Object.
  pinMode(PD, OUTPUT);                     // Power control of the DRA818
  digitalWrite(PD,HIGH);                    // start at low power
  Serial.println("done");

  Serial.print("initializing DRA818 ... ");
  
  dra = DRA818::configure(dra_serial, DRA818_VHF, 145.550, 145.550, 4, 8, 0, 0, DRA818_12K5, true, true, true, &Serial);
  if (!dra) {
    Serial.println("\nError while configuring DRA818");
  }

  freq = 144.39;

  Serial.println("done");

  Serial.println("Starting ... ");
  
  
}

void loop(){
  
 
  char buf[9];

  if (!dra) return; // do nothing if DRA configuration failed

  dtostrf(freq, 8, 4, buf);  // convert frequency to string with right precision
  Serial.print(String("Scanning frequency ") +  String(buf) + String(" kHz ..."));
  /* scan the frequency */
  //if (dra->scan(freq)) Serial.print("Found");
  Serial.println("dummy");
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  delay(500);

   char comment []= "TAMSAT hymTR APRS Tracker Test";
  APRS_sendLoc(comment, strlen(comment),'!');
  while(bitRead(PORTB,5)); //Wait for transmission to be completed
  //delay(10000);
  
  //freq += 0.0125; //12.5kHz step
  //if (freq > 144.390) freq = 144.390; // when DRA818_VHF_MAX (174.0) is reached, start over at DRA818_VHF_MIN (134.0)
  delay(2000);
}
