

// functions to control the DRA818 V modle 

// Pin mapping is needed for the following pins
// PPT
// Low power 
// Rx
// Tx 
// wake A6(D20)

#define radio_wake 20
#define radio_ppt 17
#define radio_pwr 21


void init_radio(){
  
  // 
  pinMode(radio_wake,OUTPUT);
  digitalWrite(radio_wake,LOW); //sleep the radio at init

  // PPT  0: TX
  //      1: RX
  // board : (A3 missing pin)
  // set this pin to RX
  pinMode(radio_ppt,OUTPUT);
  digitalWrite(radio_ppt,HIGH);

  pinMode(radio_pwr,OUTPUT);
  


}

void radio_TX(){
  digitalWrite(radio_ppt,LOW);
}

void radio_RX(){
  digitalWrite(radio_ppt,HIGH);
}

void radio_on(){
  digitalWrite(radio_wake,HIGH); 
}

void radio_off(){
  digitalWrite(radio_wake,LOW); 
}

void radio_high_pw(){
  pinMode(radio_pwr,INPUT);
}

void radio_low_pw(){
    pinMode(radio_pwr,OUTPUT);
    digitalWrite(radio_pwr,LOW);
}
