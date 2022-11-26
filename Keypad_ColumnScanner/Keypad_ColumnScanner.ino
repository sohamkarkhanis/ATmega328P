//This is my attempt at interfacing a 4x4 matrix keypad with an Arduino without using the user defined Keypad.h library
//It requires 8 pins from the keypad to be directly connected to the Arduino, 
//I have also designed a circuit using a voltage divider concept with which the matrix keypad can be connected to the Arduino using just 1 pin!

#define r1 13
#define r2 12
#define r3 11
#define r4 10

#define c1 9
#define c2 8
#define c3 7
#define c4 6

int keyp;
char actualKey;

void setup() {
  // put your setup code here, to run once:
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(r4,OUTPUT);

  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP);
  pinMode(c4,INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  keypadScanner();
  //Serial.print(actualKey);
  //delay(5000);
}






void keypadScanner(){
//------------------------------------------------------   
  digitalWrite(r1, LOW);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  
  if(digitalRead(c1)==LOW){
    keyp=1;
    actualKey='1';
    delay(400);
    Serial.print(actualKey);
  }
if(digitalRead(c2)==LOW){
    keyp=2;
    actualKey='2';
    delay(400); 
  	Serial.print(actualKey);
  }
  if(digitalRead(c3)==LOW){
    keyp=3;
    actualKey='3';
    delay(400); 
    Serial.print(actualKey);
  }
  if(digitalRead(c4)==LOW){
    keyp=4;
    actualKey='A';
    delay(400);
    Serial.print(actualKey);
  }  
//--------------------------------------------------------
  digitalWrite(r1, HIGH);
  digitalWrite(r2, LOW);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  
  if(digitalRead(c1)==LOW){
    keyp=5;
    actualKey='4';
    delay(400); 
    Serial.print(actualKey);
  }
if(digitalRead(c2)==LOW){
    keyp=6;
    actualKey='5';
    delay(400);
  Serial.print(actualKey);
  }
  if(digitalRead(c3)==LOW){
    keyp=7;
    actualKey='6';
    delay(400); 
    Serial.print(actualKey);
  }
  if(digitalRead(c4)==LOW){
    keyp=8;
    actualKey='B';
    delay(400); 
    Serial.print(actualKey);
  }  
//--------------------------------------------------------
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, LOW);
  digitalWrite(r4, HIGH);
  
  if(digitalRead(c1)==LOW){
    keyp=9;
    actualKey='7';
    delay(400);
    Serial.print(actualKey);
  }
if(digitalRead(c2)==LOW){
    keyp=10;
    actualKey='8';
    delay(400);
  	Serial.print(actualKey);
  }
  if(digitalRead(c3)==LOW){
    keyp=11;
    actualKey='9';
    delay(400);
    Serial.print(actualKey);
  }
  if(digitalRead(c4)==LOW){
    keyp=12;
    actualKey='C';
    delay(400);
    Serial.print(actualKey);
  }  
//--------------------------------------------------------
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, LOW);
  
  if(digitalRead(c1)==LOW){
    keyp=13;
    actualKey='*';
    delay(400);
    Serial.print(actualKey);
  }
if(digitalRead(c2)==LOW){
    keyp=14;
    actualKey='0';
    delay(400);
  	Serial.print(actualKey);
  }
  if(digitalRead(c3)==LOW){
    keyp=15;
    actualKey='#';
    delay(400);
    Serial.print(actualKey);
  }
  if(digitalRead(c4)==LOW){
    keyp=16;
    actualKey='D';
    delay(400);
    Serial.print(actualKey);
  }  
//--------------------------------------------------------
}




