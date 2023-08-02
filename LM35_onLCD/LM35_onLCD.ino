// This is a program to interface the LM35 Temperature Sensor with an Arduino Uno and displaying the temperature measurements on an 16x2 character LCD using the LiquidCrystal library in parallel mode
// refer to my code on the lcd if you want to see how to interface it without the LiquidCrystal library

#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 6, 7, 8, 9, 10);        // These are the interface pins in the order of "RS, E, D4, D5, D6, D7"
const int sensor = A1;
float vOut;
float tempC;
float tempK;
float tempR;
float tempF;

void setup() {
    lcd.begin(16, 2);
    Serial.begin(9600);
    pinMode(sensor, INPUT);
    delay(200);
}

void loop() {

    vOut = analogRead(sensor);

    vOut = (vOut * 500) / 1023;        // adjusts the resolution with the Arduino's ADC.
    // basically, step size = Vcc/[(2^n) -1)] ; since we connect LM35 to +5V, Vcc=5 and since arduino has a 10 bit ADC, (2^n)=(2^10)=1024

    tempC = vOut;                             // LM35 changes it's output voltage by 10mV every 1°C change in temperature. Refer to the datasheet for additional info
    tempF = 32 + (vOut * (9 / 5));            // in Farenhite
    tempK = 273.16 + vOut;                    // in Kelvin
    tempR = 491.67 + (vOut * (9 / 5));        // in Rankine

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("C=");
    lcd.setCursor(2, 0);
    lcd.print(tempC);

    lcd.setCursor(9, 0);
    lcd.print("F=");
    lcd.setCursor(11, 0);
    lcd.print(tempF);

    lcd.setCursor(0, 1);
    lcd.print("R=");
    lcd.setCursor(2, 1);
    lcd.print(tempR);

    lcd.setCursor(9, 1);
    lcd.print("K=");
    lcd.setCursor(11, 1);
    lcd.print(tempK);
    delay(250);
}
