//This code interfaces the Hitachi HD44780 LCD without using the LiquidCrystal library, in a 4-bit mode, a must try to throughly understand the working of the LCD

#define RS 12
#define E 11
#define D4 5
#define D5 4
#define D6 3
#define D7 2


void lcdwrite(char *data_l) //*data_l is a pointer because we don't know the length of the input string. Can also simply make it [32] if working on a 16x2 lcd
{
  char data;
  int len=strlen(data_l);
   for(int i=0;i<len;i++){
    if(i==16){lcdcmdwrite(0xC0);} //wrap text functionality
    
    data=data_l[i];
   
    digitalWrite(RS, 1);      //Change RS for data
    digitalWrite(D4, (data & 0b00010000) >> 4);   //I have written the code using binary numbers since it is much easier for people new to coding to visualise the bit shift, replace the giant binary number with smaller hexadecimal numbers to simplify your code
    digitalWrite(D5, (data & 0b00100000) >> 5);   // for eg, replace 0b00100000 with 0x20
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
}

void lcdcmdwrite(char data)
{
    digitalWrite(RS, 0);     //Change RS for command
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

void lcd_ini()
{
  
  //lcdwrite(0, 0x33);
  //delay(15);
  lcdcmdwrite(0x32);//4 bit initialisation
  delay(15);
  lcdcmdwrite(0x28);//2line 5*7 matrix in 4-bit
  delay(15);
  lcdcmdwrite(0x01);//clr display
  delay(15);
  lcdcmdwrite(0x0C);//remove cursor display
  delay(15);
  lcdcmdwrite(0x06);//increment cursor (right)
  delay(15);
  lcdcmdwrite(0x80);
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

  lcdwrite("helo");

}

void loop() {}
