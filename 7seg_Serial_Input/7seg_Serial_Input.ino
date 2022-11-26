//This code takes input from the user in the serial monitor and then displays the respective input on a 7 segment COMMON ANODE display

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

int data;
int dt = 1000;

void setup() {

  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter no: ");
  Serial.setTimeout(100);
}
void loop() {

  if (Serial.available() > 0) {
    data = Serial.parseInt();
    Serial.println("Enter no: ");
  }

//------------------------------------------------here I have coded in the simplest way possible using multiple if-else statements, feel free to switch it out with switch-case or even make functions to make the program more modular
  if (data == 0) {
    digitalWrite(leda, LOW);  // I am using a common anode 7 segment, if you're using a common cathode display, swap the "high" and "low" values. Also, note the wiring differences between a common cathode display and a common anode.
    digitalWrite(ledb, LOW);  // in CA, the current is sunk into the uC, while in CC, the current is sourced from the uC for the LEDs
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, LOW);
    digitalWrite(lede, LOW);
    digitalWrite(ledf, LOW);
    digitalWrite(ledg, HIGH);
   

  }

  else if (data == 1) {
    digitalWrite(leda, HIGH);
    digitalWrite(ledb, LOW);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, HIGH);
    digitalWrite(lede, HIGH);
    digitalWrite(ledf, HIGH);
    digitalWrite(ledg, HIGH);

    //1

  }

  else if (data == 2) {
    digitalWrite(leda, LOW);
    digitalWrite(ledb, LOW);
    digitalWrite(ledc, HIGH);
    digitalWrite(ledd, LOW);
    digitalWrite(lede, LOW);
    digitalWrite(ledf, HIGH);
    digitalWrite(ledg, LOW);
    delay(dt);

   
    //2

  }

  else if (data == 3) {
    digitalWrite(leda, LOW);
    digitalWrite(ledb, LOW);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, LOW);
    digitalWrite(lede, HIGH);
    digitalWrite(ledf, HIGH);
    digitalWrite(ledg, LOW);
  
    //3

  }

  else if (data == 4) {
    digitalWrite(leda, HIGH);
    digitalWrite(ledb, LOW);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, HIGH);
    digitalWrite(lede, HIGH);
    digitalWrite(ledf, LOW);
    digitalWrite(ledg, LOW);
  
    //4

  }

  else if (data == 5) {
    digitalWrite(leda, LOW);
    digitalWrite(ledb, HIGH);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, LOW);
    digitalWrite(lede, HIGH);
    digitalWrite(ledf, LOW);
    digitalWrite(ledg, LOW);


  }

  else if (data == 6) {
    digitalWrite(leda, HIGH);
    digitalWrite(ledb, HIGH);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, LOW);
    digitalWrite(lede, LOW);
    digitalWrite(ledf, LOW);
    digitalWrite(ledg, LOW);
   
    //6
  }
  else if (data == 7) {
    digitalWrite(leda, LOW);
    digitalWrite(ledb, LOW);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, HIGH);
    digitalWrite(lede, HIGH);
    digitalWrite(ledf, HIGH);
    digitalWrite(ledg, HIGH);
    
    //7
  }



  else if (data == 8) {
    digitalWrite(leda, LOW);
    digitalWrite(ledb, LOW);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, LOW);
    digitalWrite(lede, LOW);
    digitalWrite(ledf, LOW);
    digitalWrite(ledg, LOW);
   
    //8
  }

  else if (data == 9) {
    digitalWrite(leda, LOW);
    digitalWrite(ledb, LOW);
    digitalWrite(ledc, LOW);
    digitalWrite(ledd, LOW);
    digitalWrite(lede, HIGH);
    digitalWrite(ledf, LOW);
    digitalWrite(ledg, LOW);
   
    //9
  }

  /*else if(data==NULL){
    digitalWrite(leda, HIGH);
    digitalWrite(ledb, HIGH);
    digitalWrite(ledc, HIGH);
    digitalWrite(ledd, HIGH);
    digitalWrite(lede, HIGH);
    digitalWrite(ledf, HIGH);
    digitalWrite(ledg, LOW);
    }*/

}
