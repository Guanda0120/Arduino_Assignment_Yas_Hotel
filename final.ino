
#include <DS1307RTC.h>

#include <Time.h>

#include <Wire.h> 

int photoresistancePin=0;
int redPin1=11;
int greenPin1=10;
int bluePin1=9;
int redPin2=6;
int greenPin2=5;
int bluePin2=3;
int val=0;
int i=0;
int p=10;
void setup()
{
   Serial.begin(9600);
   pinMode(redPin1,OUTPUT);
   pinMode(greenPin1,OUTPUT);
   pinMode(bluePin1,OUTPUT);
   pinMode(redPin2,OUTPUT);
   pinMode(greenPin2,OUTPUT);
   pinMode(bluePin2,OUTPUT);

void loop()

{
    val=analogRead(photoresistancePin);
    tmElements_t tm;
    Serial.println(val);
    if (RTC.read(tm)){
           if(tm.Hour>17 and val>=100){
              setColor1(255-i,0,i);
              setColor2(i,0,255-i);
              delay(p);
              i=i+2;}
            else{
              setColor(0,0,0);}}
}

void setColor1(int red,int green,int blue){
  analogWrite(redPin1, 255-red);
  analogWrite(greenPin1, 255-green);
  analogWrite(bluePin1, 255-blue);}
void setColor2(int red,int green,int blue){
  analogWrite(redPin2, 255-red);
  analogWrite(greenPin2, 255-green);
  analogWrite(bluePin2, 255-blue);}
