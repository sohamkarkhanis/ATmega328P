//This program interfaces the KY-040, a simple rotary encoder with an Arduino 

int clk = 6;
int dt = 7;
int count;

unsigned char aPin;
unsigned char bPin;
unsigned char prev;

void setup() {
Serial.begin(9600);


}

void loop() {
  aPin= digitalRead(clk);
    if(aPin != prev){                 //when states are changed, (when knob is rotated)
      bPin= digitalRead(dt);
        if(aPin != bPin){
          count++;                    //count increases when knob is turned clock-wise
        }    
        else{
          count--;                    //count decreases when knob is turned anticlock-wise
        }
        Serial.print("Steps: ");
        Serial.println("count");
    }
  prev=aPin;
}
