#include <DS1307RTC.h>

#include <Time.h>

#include <Wire.h>
void setup() {
pinMode(10,OUTPUT);
}

void loop() {
    tmElements_t tm;

    if (RTC.read(tm)){
      if(tm.Hour==15){
        digitalWrite(10,HIGH);}
      
      
      }

    
}
