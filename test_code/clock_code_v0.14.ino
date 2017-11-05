// Code for nixie clock using DS3231 Precision RTC

#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

uint8_t wholeSecond;
uint8_t wholeMinute;
uint8_t wholeHour;

uint8_t secondsDigits;
uint8_t secondsTens;

uint8_t minutesDigits;
uint8_t minutesTens;

uint8_t hoursDigits;
uint8_t hoursTens;

int switchValue;
byte switchPin = 52;
bool toggle = false;

void setup () {

  // DST/BST switch
  pinMode(switchPin, INPUT_PULLUP);
  
  // K155ID1 pins

  // Pins will need to change when mounted to the PCB
  
  // Seconds Digits
  pinMode(5, OUTPUT);// D
  pinMode(4, OUTPUT);// C
  pinMode(3, OUTPUT);// B
  pinMode(2, OUTPUT);// A

  // Seconds Tens
  pinMode(9, OUTPUT);// D
  pinMode(8, OUTPUT);// C
  pinMode(7, OUTPUT);// B
  pinMode(6, OUTPUT);// A

  // Minutes Digits
  pinMode(13, OUTPUT);// D
  pinMode(12, OUTPUT);// C
  pinMode(11, OUTPUT);// B
  pinMode(10, OUTPUT);// A
  // Minutes Tens
  pinMode(37, OUTPUT);// D
  pinMode(35, OUTPUT);// C
  pinMode(33, OUTPUT);// B
  pinMode(31, OUTPUT);// A
  // Hours Digits
  pinMode(45, OUTPUT);// D
  pinMode(43, OUTPUT);// C
  pinMode(41, OUTPUT);// B
  pinMode(39, OUTPUT);// A
  // Hours Digits
  pinMode(53, OUTPUT);// D
  pinMode(51, OUTPUT);// C
  pinMode(49, OUTPUT);// B
  pinMode(47, OUTPUT);// A

  Serial.begin(9600); // note baud rate change from DS1307
  delay(3000); // wait for console opening
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  // DS3231 when initializing or on external power
  if (rtc.lostPower()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
     rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop () {
    DateTime now = rtc.now();
    // Check if DST has been set:
    // NOTE- CURRENTLY SET TO SUMMER AS DEFAULT
    switchValue = digitalRead(switchPin);
    if(switchValue == LOW){
      if(!toggle){
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour()-1, now.minute(), now.second()));
        toggle = !toggle;
      }
    }
    else{
      if(toggle){
        rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour()+1, now.minute(), now.second()));
        toggle = !toggle;
      }
    }
  
    now = rtc.now();
    
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    wholeSecond = now.second();
    wholeMinute = now.minute();
    wholeHour = now.hour();
    secondsDigits = wholeSecond % 10;
    secondsTens = (wholeSecond / 10);
    minutesDigits = wholeMinute % 10;
    minutesTens = wholeMinute / 10;
    hoursDigits = wholeHour % 10;
    hoursTens = wholeHour / 10;

    writeNixie(secondsDigits, 5, 4, 3, 2);
    writeNixie(secondsTens, 9, 8, 7, 6);
    writeNixie(minutesDigits, 13, 12, 11, 10);
    writeNixie(minutesTens, 37, 35, 33, 31);
    writeNixie(hoursDigits, 45, 43, 41, 39); 
    writeNixie(hoursTens, 53, 51, 49, 47);
    Serial.println();

    delay(1000);
}

void writeNixie(uint8_t value, uint8_t dPin, uint8_t cPin, uint8_t bPin, uint8_t aPin){

 byte binValue = (unsigned byte)value;

 Serial.print("Incoming value: ");
 Serial.println(value);
 
 digitalWrite(dPin, ((binValue >> 3)));  //D
 digitalWrite(cPin, ((binValue >> 2) & 0x1));  //C
 digitalWrite(bPin, ((binValue >> 1) & 0x1));  //B
 digitalWrite(aPin, (binValue & 0x1)); //A


 
}
