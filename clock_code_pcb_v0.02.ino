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
byte switchPin = 2;
bool toggle = false;

void setup () {

  // DST/BST switch
  pinMode(switchPin, INPUT_PULLUP);
  
  // K155ID1 pins

  // Pins will need to change when mounted to the PCB
  
  // Hours Tens
  pinMode(22, OUTPUT);// D
  pinMode(24, OUTPUT);// C
  pinMode(26, OUTPUT);// B
  pinMode(28, OUTPUT);// A

  // Hours Digits
  pinMode(30, OUTPUT);// D
  pinMode(32, OUTPUT);// C
  pinMode(34, OUTPUT);// B
  pinMode(36, OUTPUT);// A

  // Minutes Tens
  pinMode(31, OUTPUT);// D
  pinMode(33, OUTPUT);// C
  pinMode(35, OUTPUT);// B
  pinMode(37, OUTPUT);// A
  
  // Minutes Digits
  pinMode(23, OUTPUT);// D
  pinMode(25, OUTPUT);// C
  pinMode(27, OUTPUT);// B
  pinMode(29, OUTPUT);// A
  
  // Seconds Tens
  pinMode(47, OUTPUT);// D
  pinMode(49, OUTPUT);// C
  pinMode(51, OUTPUT);// B
  pinMode(53, OUTPUT);// A
  
  // Seconds Digits
  pinMode(39, OUTPUT);// D
  pinMode(41, OUTPUT);// C
  pinMode(43, OUTPUT);// B
  pinMode(45, OUTPUT);// A

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
    secondsTens = wholeSecond / 10;
    minutesDigits = wholeMinute % 10;
    minutesTens = wholeMinute / 10;
    hoursDigits = wholeHour % 10;
    hoursTens = wholeHour / 10;

    writeNixie(secondsDigits, 47, 49, 51, 53); 
    writeNixie(secondsTens, 39, 41, 43, 45);
    writeNixie(minutesDigits, 31, 33, 35, 37);
    writeNixie(minutesTens, 23, 25, 27, 29);
    writeNixie(hoursDigits, 30, 32, 34, 36); 
    writeNixie(hoursTens, 22, 24, 26, 28);
    Serial.println();

    delay(1000);
}

void writeNixie(uint8_t value, uint8_t dPin, uint8_t cPin, uint8_t bPin, uint8_t aPin){

 byte binValue = (unsigned byte)value;
 
 Serial.print("Incoming value: ");
 Serial.println(value);
 
 digitalWrite(dPin, ((binValue >> 3)));  
 digitalWrite(cPin, ((binValue >> 2) & 0x1));  
 digitalWrite(bPin, ((binValue >> 1) & 0x1));  
 digitalWrite(aPin, (binValue & 0x1)); 


 
}
