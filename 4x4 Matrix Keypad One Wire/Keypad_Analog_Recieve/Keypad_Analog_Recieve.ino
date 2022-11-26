//This is my attempt at interfacing a 4x4 matrix keypad with an Arduino without using the user defined Keypad.h library using only 1 pin of the Arduino
//It makes use of a voltage divider concept to which the 8 pins of the matrix keypad are connected to, from which only 1 pin feeds into an analog input pin on the Arduino
//DISCLAIMER: The code will not compile without adding the appropriate values after "adcVal>  && adcVal<" in each if-else statement

#define analogOut A1
int keyp;
char actualKey;
int adcVal;

void setup() {
Serial.begin(9600);  
}

void keypadRecieve(){
  
  adcVal = analogRead(analogOut); 
  
  if (adcVal>  && adcVal<)                   //i have left the values after the greater than, lesser than signs as you will have to edit them after calibrating the voltage divider setup you build
  {                                          //i have used 4.7k and 1k resistors as you can see in the screenshot attached, but since resistance values of resistors can vary (tolerance) you will have to calibrate you own values
    actualKey='1';                           // by writing a simple analog read and serial.print function and pressing each keypad key to check the respective analog voltage reading
    Serial.print("Key Pressed : ");
    Serial.println("1");
    Serial.println(actualKey); 
    keyp=1;  
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='2';
    Serial.print("Key Pressed : ");
    Serial.println("2");
    Serial.println(actualKey);
    keyp=2;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='3';
    Serial.print("Key Pressed : ");
    Serial.println("3");
    Serial.println(actualKey);
    keyp=3;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='A';
    Serial.print("Key Pressed : ");
    Serial.println("A");
    Serial.println(actualKey);
    keyp=4;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='4';
    Serial.print("Key Pressed : ");
    Serial.println("4");
    Serial.println(actualKey);
    keyp=5;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='5';
    Serial.print("Key Pressed : ");
    Serial.println("5");
    Serial.println(actualKey);
    keyp=6;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='6';
    Serial.print("Key Pressed : ");
    Serial.println("6");
    Serial.println(actualKey);
    keyp=7;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='B';
    Serial.print("Key Pressed : ");
    Serial.println("B");
    Serial.println(actualKey);
    keyp=8;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='7';
    Serial.print("Key Pressed : ");
    Serial.println("7");
    Serial.println(actualKey);
    keyp=9;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='8';
    Serial.print("Key Pressed : ");
    Serial.println("8");
    Serial.println(actualKey);
    keyp=10;
    delay(100);
  }
  else if ( adcVal> && adcVal<)
  {
    actualKey='9';
    Serial.print("Key Pressed : ");
    Serial.println("9");
    Serial.println(actualKey);
    keyp=11;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='C';
    Serial.print("Key Pressed : ");
    Serial.println("C");
    Serial.println(actualKey);
    keyp=12;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='*';
    Serial.print("Key Pressed : ");
    Serial.println("*");
    Serial.println(actualKey);
    keyp=13;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='0';
    Serial.print("Key Pressed : ");
    Serial.println("0");
    Serial.println(actualKey);
    keyp=14;
    delay(100);
  }
  else if ( adcVal>  && adcVal<)
  {
    actualKey='#';
    Serial.print("Key Pressed : ");
    Serial.println("#");
    Serial.println(actualKey);
    keyp=15;
    delay(100);
  }
  else if( adcVal>  && adcVal<)
  {
    actualKey='D';
    Serial.print("Key Pressed : ");
    Serial.println("F");
    Serial.println(actualKey);
    keyp=16;
    delay(100);
  }
  else  
}

void loop() {}
