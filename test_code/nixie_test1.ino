void setup() {
  // put your setup code here, to run once:


  // set output pins
  pinMode(5, OUTPUT);// D
  pinMode(4, OUTPUT);// C
  pinMode(3, OUTPUT);// B
  pinMode(2, OUTPUT);// A


}

void loop() {
  // put your main code here, to run repeatedly:

  // cycle through
 //0 
 digitalWrite(5, LOW);  //D
 digitalWrite(4, LOW);  //C
 digitalWrite(3, LOW);  //B
 digitalWrite(2, LOW);  //A
 delay(1000);

//1
 digitalWrite(5, LOW);  //D
 digitalWrite(4, LOW);  //C
 digitalWrite(3, LOW);  //B
 digitalWrite(2, HIGH); //A
 delay(1000);
 //2
 digitalWrite(5, LOW);  //D
 digitalWrite(4, LOW);  //C
 digitalWrite(3, HIGH); //B
 digitalWrite(2, LOW);  //A
 delay(1000);
 //3
 digitalWrite(5, LOW);  //D
 digitalWrite(4, LOW);  //C
 digitalWrite(3, HIGH); //B
 digitalWrite(2, HIGH); //A
 delay(1000);
 //4
 digitalWrite(5, LOW);  //D
 digitalWrite(4, HIGH); //C
 digitalWrite(3, LOW);  //B
 digitalWrite(2, LOW);  //A
 delay(1000);
 //5
 digitalWrite(5, LOW);  //D
 digitalWrite(4, HIGH); //C
 digitalWrite(3, LOW);  //B
 digitalWrite(2, HIGH); //A
 delay(1000);
 //6
 digitalWrite(5, LOW);  //D
 digitalWrite(4, HIGH); //C
 digitalWrite(3, HIGH); //B
 digitalWrite(2, LOW);  //A
 delay(1000);
 //7
 digitalWrite(5, LOW);  //D
 digitalWrite(4, HIGH); //C
 digitalWrite(3, HIGH); //B
 digitalWrite(2, HIGH); //A
 delay(1000);
 //8
 digitalWrite(5, HIGH); //D
 digitalWrite(4, LOW);  //C
 digitalWrite(3, LOW);  //B
 digitalWrite(2, LOW);  //A
 delay(1000);
 //9
 digitalWrite(5, HIGH); //D
 digitalWrite(4, LOW);  //C
 digitalWrite(3, LOW); //B
 digitalWrite(2, HIGH);  //A
 delay(1000);


}
