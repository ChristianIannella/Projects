/*
  RX

  Rx for RF Nano board based on nRF24 Nordic
  
  This example work wel with RF Nano board or Arduino boards with external nRF24.

  29/11/2020
  Iannella Christian 

  This example code is in the public domain.

*/



#include <nRF24L01.h>
#include <RF24_config.h>
#include <RF24.h>
#include <SPI.h>

RF24 radio(10, 9); //Pin CE e CSN 
const byte indirizzo[5] = {00001};//define radio address

void setup() {
  Serial.begin(115200);

  while (!Serial) { 
  }
  Serial.println(F("Starting"));
  radio.begin();  //Radio initialization
  radio.setPALevel(RF24_PA_MAX);//Set redio power to higher level
  /*
       There are four different power levels: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH e RF24_PA_MAX
        -18dBm, -12dBm,-6dBM, e 0dBm
  */
  radio.openReadingPipe(1, indirizzo);//Open a reading channel
  radio.startListening();//Let radio start listening
  Serial.println(F("Listening!"));
}

void loop() {
  if (radio.available()) { //If some data available
    int buff = 0;
    radio.read(&buff, sizeof(buff));//Read data and store it in a buffe
    Serial.println(buff);//Stamp to serial monitor
  }
}
