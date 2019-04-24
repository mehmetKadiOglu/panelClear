#include "MotorHareket.h"
#include <SoftwareSerial.h>
SoftwareSerial BTserial(3, 5);
Hareket *hareket;
void setup() {
  hareket = new Hareket();
  BTserial.begin(9600);  
  Serial.begin(9600);
}
void loop() {
  
  if (BTserial.available()){

    char a = BTserial.read();
    if( a == 'q'){
         hareket->hareketBaslat();
         BTserial.write("bitti");
     }
  }
}
