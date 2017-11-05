void setup() {
  // put your setup code here, to run once:
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

  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint8_t i = 0; i < 10; i++){
    //writeNixie(i, 9, 8, 7, 6);
    //writeNixie(i, 5, 4, 3, 2);
    Serial.println(i);
switch(i){
  case 0:
    digitalWrite(2, LOW); //A
    digitalWrite(3, LOW);  //B
    digitalWrite(4, LOW);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, LOW); //A
    digitalWrite(7, LOW);  //B
    digitalWrite(8, LOW);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 1:
    digitalWrite(2, HIGH); //A
    digitalWrite(3, LOW);  //B
    digitalWrite(4, LOW);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, HIGH); //A
    digitalWrite(7, LOW);  //B
    digitalWrite(8, LOW);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 2:
    digitalWrite(2, LOW); //A
    digitalWrite(3, HIGH);  //B
    digitalWrite(4, LOW);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, LOW); //A
    digitalWrite(7, HIGH);  //B
    digitalWrite(8, LOW);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 3:
    digitalWrite(2, HIGH); //A
    digitalWrite(3, HIGH);  //B
    digitalWrite(4, LOW);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, HIGH); //A
    digitalWrite(7, HIGH);  //B
    digitalWrite(8, LOW);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 4:
    digitalWrite(2, LOW); //A
    digitalWrite(3, LOW);  //B
    digitalWrite(4, HIGH);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, LOW); //A
    digitalWrite(7, LOW);  //B
    digitalWrite(8, HIGH);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 5:
    digitalWrite(2, HIGH); //A
    digitalWrite(3, LOW);  //B
    digitalWrite(4, HIGH);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, HIGH); //A
    digitalWrite(7, LOW);  //B
    digitalWrite(8, HIGH);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 6:
    digitalWrite(2, LOW); //A
    digitalWrite(3, HIGH);  //B
    digitalWrite(4, HIGH);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, LOW); //A
    digitalWrite(7, HIGH);  //B
    digitalWrite(8, HIGH);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 7:
    digitalWrite(2, HIGH); //A
    digitalWrite(3, HIGH);  //B
    digitalWrite(4, HIGH);  //C
    digitalWrite(5, LOW);  //D
    digitalWrite(6, HIGH); //A
    digitalWrite(7, HIGH);  //B
    digitalWrite(8, HIGH);  //C
    digitalWrite(9, LOW);  //D
    break;
    case 8:
    digitalWrite(2, LOW); //A
    digitalWrite(3, LOW);  //B
    digitalWrite(4, LOW);  //C
    digitalWrite(5, HIGH);  //D
    digitalWrite(6, LOW); //A
    digitalWrite(7, LOW);  //B
    digitalWrite(8, LOW);  //C
    digitalWrite(9, HIGH);  //D
    break;
    case 9:
    digitalWrite(2, HIGH); //A
    digitalWrite(3, LOW);  //B
    digitalWrite(4, LOW);  //C
    digitalWrite(5, HIGH);  //D
    digitalWrite(6, HIGH); //A
    digitalWrite(7, LOW);  //B
    digitalWrite(8, LOW);  //C
    digitalWrite(9, HIGH);  //D
    }
    
    delay(1000);
  }

}

void writeNixie(uint8_t value, uint8_t dPin, uint8_t cPin, uint8_t bPin, uint8_t aPin){

 byte binValue = (unsigned byte)value;

 Serial.print("Incoming value: ");
 Serial.print(value);
 Serial.println();

 switch(value){
  case 0:
    digitalWrite(aPin, LOW); //A
    digitalWrite(bPin, LOW);  //B
    digitalWrite(cPin, LOW);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 1:
    digitalWrite(aPin, HIGH); //A
    digitalWrite(bPin, LOW);  //B
    digitalWrite(cPin, LOW);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 2:
    digitalWrite(aPin, LOW); //A
    digitalWrite(bPin, HIGH);  //B
    digitalWrite(cPin, LOW);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 3:
    digitalWrite(aPin, HIGH); //A
    digitalWrite(bPin, HIGH);  //B
    digitalWrite(cPin, LOW);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 4:
    digitalWrite(aPin, LOW); //A
    digitalWrite(bPin, LOW);  //B
    digitalWrite(cPin, HIGH);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 5:
    digitalWrite(aPin, HIGH); //A
    digitalWrite(bPin, LOW);  //B
    digitalWrite(cPin, HIGH);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 6:
    digitalWrite(aPin, LOW); //A
    digitalWrite(bPin, HIGH);  //B
    digitalWrite(cPin, HIGH);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 7:
    digitalWrite(aPin, HIGH); //A
    digitalWrite(bPin, HIGH);  //B
    digitalWrite(cPin, HIGH);  //C
    digitalWrite(dPin, LOW);  //D
    break;
    case 8:
    digitalWrite(aPin, LOW); //A
    digitalWrite(bPin, LOW);  //B
    digitalWrite(cPin, LOW);  //C
    digitalWrite(dPin, HIGH);  //D
    break;
    case 9:
    digitalWrite(aPin, HIGH); //A
    digitalWrite(bPin, LOW);  //B
    digitalWrite(cPin, LOW);  //C
    digitalWrite(dPin, HIGH);  //D
    }
}
