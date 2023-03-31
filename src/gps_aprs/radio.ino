

// functions to control the DRA818 V modle 

// Pin mapping is needed for the following pins
// PPT
// Low power 
// Rx
// Tx 
// wake A6(D20)

#define radio_wake 20


void init_radio(){
  
  pinMode(radio_wake,OUTPUT);
  digitalWrite(radio_wake,LOW); //sleep the radio at init
}

void radio_on(){
  digitalWrite(radio_wake,LOW); 
}