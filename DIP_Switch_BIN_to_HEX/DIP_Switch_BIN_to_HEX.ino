//This code takes input from the user on a 4 DIP switch in binary and displays the corresponding hexadecimal value on a 7 segment COMMON ANODE display 
//Here i've made the program modular by using switch-case instead of multiple if-else statements and also making individual functions per value so the code in void setup() looks clean

int leda = 2;
int ledb = 3;
int ledc = 4;
int ledd = 5;
int lede = 6;
int ledf = 7;
int ledg = 8;

int dip1=13;
int dip2=12;
int dip3=11;
int dip4=10;

int dip1Val;
int dip2Val;
int dip3Val;
int dip4Val;

int dt=500;

void setup() {
pinMode(leda, OUTPUT);
pinMode(ledb, OUTPUT);
pinMode(ledc, OUTPUT);
pinMode(ledd, OUTPUT);
pinMode(lede, OUTPUT);
pinMode(ledf, OUTPUT);
pinMode(ledg, OUTPUT);

pinMode(dip1, INPUT_PULLUP);
pinMode(dip2, INPUT_PULLUP);
pinMode(dip3, INPUT_PULLUP);
pinMode(dip4, INPUT_PULLUP);

Serial.begin(9600);
}

void loop() {

dip1Val=digitalRead(dip1);
dip2Val=digitalRead(dip2);
dip3Val=digitalRead(dip3);
dip4Val=digitalRead(dip4);

//------------------------------------------------------
 byte data=0b00000000;
 if (dip4Val==LOW){
  data = data | 0b00000001;
 }

 if(dip3Val==LOW){
  data |= 0b00000010;
 }

 if(dip2Val==LOW){
  data |= 0b00000100;
 }

 if(dip1Val==LOW){
  data |= 0b00001000;
}
Serial.println(data);             
//------------------------------------------------------

 switch(data){
  case 0b00000000:{
     
    zero();
    break;
  }

  case 0b00000001:{
     
    one();
    break;
  }

  case 0b00000010:{
     
    two();
    break;
  }

  case 0b00000011:{
     
    three();
    break;
  }

  case 0b00000100:{
     
    four();
    break;
  }

  case 0b00000101:{
     
    five();
    break;
  }

  case 0b00000110:{
     
    six();
    break;
  }

  case 0b00000111:{
     
    seven();
    break;
  }

  case 0b00001000:{
     
    eight();
    break;
  }

  case 0b00001001:{
     
    nine();
    break;
  }

  case 0b00001010:{
     
    a();
    break;
  }

  case 0b00001011:{
     
    b();
    break;
  }

  case 0b00001100:{
     
    c();
    break;
  }

  case 0b00001101:{
     
    d();
    break;
  }

  case 0b00001110:{
     
    e();
    break;
  }

  case 0b00001111:{
     
    f();
    break;
  }

  default:{}
 }

}


void off(){
digitalWrite(leda, HIGH);
digitalWrite(ledb, HIGH);
digitalWrite(ledc, HIGH);
digitalWrite(ledd, HIGH);
digitalWrite(lede, HIGH);
digitalWrite(ledf, HIGH);
digitalWrite(ledg, HIGH);
delay(dt);
}

void zero(){
digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, HIGH);
delay(dt);

//zero
}

void one(){
digitalWrite(leda, HIGH);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, HIGH);
digitalWrite(lede, HIGH);
digitalWrite(ledf, HIGH);
digitalWrite(ledg, HIGH);
delay(dt);

//one
}

void two(){
digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, HIGH);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, HIGH);
digitalWrite(ledg, LOW);
delay(dt);

//two 
}

void three(){
digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, HIGH);
digitalWrite(ledf, HIGH);
digitalWrite(ledg, LOW);
delay(dt);

//three
}

void four(){
digitalWrite(leda, HIGH);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, HIGH);
digitalWrite(lede, HIGH);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//four
}

void five(){
 digitalWrite(leda, LOW);
digitalWrite(ledb, HIGH);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, HIGH);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//five 
}

void six(){
  digitalWrite(leda, LOW);
digitalWrite(ledb, HIGH);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//six
}

void seven(){
 digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, HIGH);
digitalWrite(lede, HIGH);
digitalWrite(ledf, HIGH);
digitalWrite(ledg, HIGH);
delay(dt);

//seven 
}

void eight(){
 digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//eight 
}

void nine(){
digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, HIGH);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//nine
}

//------------------------------------------------------HEXADECIMAL------------------------------------------------------------

void a(){
digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, HIGH);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//a
}

void b(){
digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//b
}

void c(){
digitalWrite(leda, LOW);
digitalWrite(ledb, HIGH);
digitalWrite(ledc, HIGH);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, HIGH);
delay(dt);

//C
}

void d(){
digitalWrite(leda, LOW);
digitalWrite(ledb, LOW);
digitalWrite(ledc, LOW);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, HIGH);
delay(dt);

//d
}

void e(){
digitalWrite(leda, LOW);
digitalWrite(ledb, HIGH);
digitalWrite(ledc, HIGH);
digitalWrite(ledd, LOW);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//e
}

void f(){
digitalWrite(leda, LOW);
digitalWrite(ledb, HIGH);
digitalWrite(ledc, HIGH);
digitalWrite(ledd, HIGH);
digitalWrite(lede, LOW);
digitalWrite(ledf, LOW);
digitalWrite(ledg, LOW);
delay(dt);

//f
}
