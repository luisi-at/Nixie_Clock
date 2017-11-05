// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
//#include <Time.h>
#include <Wire.h>
#include "RTClib.h"
//#include <DS1307RTC.h>

int clockPin = 0;

byte second;
byte minute;
byte hour;
byte day;
byte date;
byte month;
byte year;

int secondIntOne;
int secondIntTwo;
int minuteIntOne;
int minuteIntTwo;
int hourIntOne;
int hourIntTwo;

byte secondOne; //left
byte secondTwo; //right
byte minuteOne; //left
byte minuteTwo; //right
byte hourOne; //left
byte hourTwo; //right




RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {

  // set output pins

  //K155ID1 pins

  // Seconds 2
  pinMode(5, OUTPUT);// D
  pinMode(4, OUTPUT);// C
  pinMode(3, OUTPUT);// B
  pinMode(2, OUTPUT);// A

  // Seconds 1
  pinMode(9, OUTPUT);// D
  pinMode(8, OUTPUT);// C
  pinMode(7, OUTPUT);// B
  pinMode(6, OUTPUT);// A

  // Minutes 2
/*  pinMode(5, OUTPUT);// D
  pinMode(4, OUTPUT);// C
  pinMode(3, OUTPUT);// B
  pinMode(2, OUTPUT);// A

  // Minutes 1
  pinMode(5, OUTPUT);// D
  pinMode(4, OUTPUT);// C
  pinMode(3, OUTPUT);// B
  pinMode(2, OUTPUT);// A

  // Hours 2
  pinMode(5, OUTPUT);// D
  pinMode(4, OUTPUT);// C
  pinMode(3, OUTPUT);// B
  pinMode(2, OUTPUT);// A

  // Hours 1
  pinMode(5, OUTPUT);// D
  pinMode(4, OUTPUT);// C
  pinMode(3, OUTPUT);// B
  pinMode(2, OUTPUT);// A
*/
  pinMode(clockPin, INPUT);
  pinMode(clockPin, LOW);
  Wire.begin();
  
  while (!Serial); // for Leonardo/Micro/Zero
  
  // For Arduino Uno
  /*
  pinMode(A3, OUTPUT); //A3
  pinMode(A2, OUTPUT); //A2
  digitalWrite(A3, HIGH); //A3
  digitalWrite(A2, LOW); //A2
  */
  Serial.begin(57600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  // updates the RTC clock time when compiled to the board
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    //rtc.set(now());
    

  }
}

void loop () {
    DateTime now = rtc.now();
    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    while(digitalRead(clockPin)){
      Wire.beginTransmission(0x68);

      Wire.write(0);

      Wire.endTransmission();

      Wire.requestFrom(0x68, 7);

      second = Wire.read();
      minute = Wire.read();
      hour = Wire.read();

      // time is split into two hex digits
      // have to extract the bits as such
      // remember it is the binary value that is sent to the K155ID1 decoder
      secondOne = (second & 0xFF) >> 4;
      secondTwo = second & 0x0F;
      writeNixie(secondTwo, 5, 4, 3, 2);
      writeNixie(secondOne, 9, 8, 7, 6);

      minuteOne = minute >> 4;
      minuteTwo = minute & 0xF;
     
      hourOne = hour >> 4;
      hourTwo = hour & 0xF;

      secondIntOne = int(secondOne);
      secondIntTwo = int(secondTwo);
      minuteIntOne = int(minuteOne);
      minuteIntTwo = int(minuteTwo);
      hourIntOne = int(hourOne);
      hourIntTwo = int(hourTwo);
      

      Serial.print(hour, HEX);
      Serial.print(":");
      Serial.print(minute, HEX);
      Serial.print(":");
      Serial.print(second, HEX);
      Serial.println("");
      Serial.print(second, BIN);
      Serial.println("");

      Serial.print(hourIntOne, DEC);
      Serial.print(hourIntTwo, DEC);
      Serial.print(":");
      Serial.print(minuteIntOne, DEC);
      Serial.print(minuteIntTwo, DEC);      
      Serial.print(":");
      Serial.print(secondOne, DEC);
      Serial.print(secondIntTwo, DEC);
      Serial.println("");
      Serial.print((secondIntOne >> 3), BIN);
      Serial.print((secondIntOne >> 2) & 0x01, BIN);
      Serial.print((secondIntOne >> 1) & 0x01, BIN);
      Serial.print((secondIntOne & 0x1), BIN);
      //Serial.println("");
      //Serial.print((secondIntTwo >> 3), BIN);
      //Serial.print((secondIntTwo >> 2) & 0x01, BIN);
      //Serial.print((secondIntTwo >> 1) & 0x01, BIN);
      //Serial.print((secondIntTwo & 0x1), BIN);

      Serial.println();
      //will need to figure a way to prevent the nixies firing at every pulse
      //maybe this delay is the way forward?
      delay(1000);

    
    }
}

void writeNixie(byte value, uint8_t dPin, uint8_t cPin, uint8_t bPin, uint8_t aPin){
 Serial.print("Pin out bits: ");
 digitalWrite(dPin, ((value >> 3)));  //D
 digitalWrite(cPin, ((value >> 2) & 0x1));  //C
 digitalWrite(bPin, ((value >> 1) & 0x1));  //B
 digitalWrite(aPin, (value & 0x1)); //A
 Serial.println(value, BIN);
 Serial.print((value >> 3), BIN);
 Serial.print(((value >> 2) & 0x1), BIN);
 Serial.print(((value >> 1) & 0x1), BIN);
 Serial.print((value & 0x1), BIN);
 Serial.println();
}

