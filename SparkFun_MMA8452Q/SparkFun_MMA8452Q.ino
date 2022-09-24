#include <Wire.h>                 
#include "SparkFun_MMA8452Q.h"   
MMA8452Q accel;                 

void setup() {
  Serial.begin(9600);
  Wire.begin();
   if (accel.begin() == false) {
    while (1);
  }
}

void loop() {
  delay(100);
  
  if (accel.available()) {   
   float  valx = (accel.getCalculatedX()+1.024)*100;
   float  valy = (accel.getCalculatedY()+1.024)*100;
   int  valxx = map(valx, 0,204.8, 0, 255);
   int  valyy = map(valy, 0,204.8, 0, 255);
    Serial.print("X = ");
    Serial.println(valxx);
    Serial.print("Y = ");
    Serial.println(valyy);
  }
}
