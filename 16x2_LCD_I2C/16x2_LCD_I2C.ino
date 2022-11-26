//DISCLAIMER: This code works only in a Proteus Professional simulation, or on Tinkercad. Im currently debugging why the code won't work on hardware, and will update it as and when I figure it out!
//Meanwhile, feel free to drop me a mail if you catch the bug! It will be much appreciated!
//This code interfaces the Hitachi HD44780 LCD using the i2c communication protocol, with a PCF8574 Backpack, without using the LiquidCrystal_I2C library, a must try to throughly understand the working of the LCD and the I2C protocol


#include <Wire.h>

void lcdwrite_i2c(char *data_l) //*data_l is a pointer bcz we dont know length of input string. can also simply make it [32] if working on a 16x2 lcd
{
  char data;
  int len=strlen(data_l);
    for(int i=0;i<len;i++){
      if(i==16){lcdcmdwrite_i2c(0xC0);} //wrap text
      
      data=data_l[i];
  
      unsigned int highnib;
      unsigned int lownib;
      int dtbw=15;
      Wire.beginTransmission(0x20);
    
      highnib = data & 0b11110000;                              //since the pcf8574 has only 4 output pins connected to the 4 data pins of the lcd, we use it in the 4 bit mode
      Wire.write(highnib | 0b00001101); //en high
      delay(dtbw);
      Wire.write(highnib | 0b00001001); //en low 
      delay(dtbw);
    
      lownib = (data & 0b00001111) << 4;
      delay(dtbw);
      Wire.write(lownib | 0b00001101); //en high
      delay(dtbw);
      Wire.write(lownib | 0b00001001); //en low
      delay(dtbw);
    
      Wire.endTransmission();
      }
}


void lcdcmdwrite_i2c(unsigned char data) {

  unsigned int highnib;
  unsigned int lownib;
  int dtbw=15;
  Wire.beginTransmission(0x20);
  
  highnib = data & 0b11110000;
  Wire.write(highnib | 0b00001100);//en high
  delay(dtbw);
  Wire.write(highnib | 0b00001000);//en low
  delay(dtbw);

  lownib = (data & 0b00001111) << 4;
  Wire.write(lownib | 0b00001100);//en high
  delay(dtbw);
  Wire.write(lownib | 0b00001000);//en low
  delay(dtbw);
  
  Wire.endTransmission();
}

void lcdini_i2c() {
  
  lcdcmdwrite_i2c(0x32);
  delay(15);
  lcdcmdwrite_i2c(0x28); //2line 5*7 matrix in 4-bit
  delay(15);
  lcdcmdwrite_i2c(0x01); //clr display
  delay(15);
  lcdcmdwrite_i2c(0x0C); //remove cursor display
  delay(15);
  lcdcmdwrite_i2c(0x06); //increment cursor (right)
  delay(15);
  lcdcmdwrite_i2c(0x80);
  delay(15);
  
}


void setup() {
  // put your setup code here, to run once:
  Wire.begin();

  lcdini_i2c();
  lcdwrite_i2c("Assalamuaalaikum Habibi");


}

void loop() {}
