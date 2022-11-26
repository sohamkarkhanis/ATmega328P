//This code interfaces the Hitachi HD44780 LCD without using the LiquidCrystal library, in a 4-bit mode, a must try to throughly understand the working of the LCD
//Check the LCD program titled "lcd mod str" to see how to use a pointer and array to directly print a string insteaed of one character at a time!


#define RS 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2


void lcdwrite(int select, char data){
  digitalWrite(RS, select);                     //Change RS for command/data
  digitalWrite(D4, (data & 0b00010000) >> 4);
  digitalWrite(D5, (data & 0b00100000) >> 5);
  digitalWrite(D6, (data & 0b01000000) >> 6);
  digitalWrite(D7, (data & 0b10000000) >> 7);
  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(D4, (data & 0b00000001) >> 0);
  digitalWrite(D5, (data & 0b00000010) >> 1);
  digitalWrite(D6, (data & 0b00000100) >> 2);
  digitalWrite(D7, (data & 0b00001000) >> 3);
  digitalWrite(E, HIGH);
  digitalWrite(E, LOW);
}

void lcd_data(char dat){       
  lcdwrite(1, dat);             //yes, you can simply call the lcdwrite function instead.
}


void lcd_ini(){  
  //lcdwrite(0, 0x33);
  //delay(15);
  lcdwrite(0, 0x32);//4 bit initialisation
  delay(15);
  lcdwrite(0, 0x28);//2line 5*7 matrix in 4-bit
  delay(15);
  lcdwrite(0, 0x01);//clr display
  delay(15);
  lcdwrite(0, 0x0C);//remove cursor display
  delay(15);
  lcdwrite(0, 0x06);//increment cursor (right)
  delay(15);
  lcdwrite(0, 0x80);
  delay(15);

}



void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  

  lcd_ini();
  lcd_data('H');
  lcd_data('e');
  lcd_data('l');
  lcd_data('l');
  lcd_data('o');

}

void loop() {}