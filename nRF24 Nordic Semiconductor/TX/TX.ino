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

RF24 radio(10, 9);
const byte indirizzo[5] = {00001}; //Mustbe the same fot Tx and Rx

void setup() {
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(indirizzo);

  radio.stopListening();
}

void loop() {
  
  for (int data_to_send = 0; data_to_send < 255; data_to_send++) {
    radio.write(&val, sizeof(data_to_send));
    delay(1000);
  }


}
