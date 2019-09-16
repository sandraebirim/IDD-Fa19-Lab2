/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int yellow = 10;
int blue = 9;
int green = 7;
int totaltime = 30;
int button = 6;
int run = 0;
unsigned long time; 
int timeleft = 0;
int stoptime = 0;

//variable for reading the pushbutton status
int buttonState = 0;

void setup() {

//initialize all of the lights as output
  pinMode(yellow,OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);

//initialize the pushbutton pin as an input
  pinMode(button, INPUT_PULLUP);
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Plank timer: ");
  
}

void loop() {
//
  buttonState = digitalRead(button);  
  if (buttonState == LOW){ 
    if (run == 0){ 

      run = 100;
      stoptime = millis()/1000 + totaltime;
      
    }
  }
  
   
  if (run>0){
    timeleft = stoptime - millis()/1000;
    lcd.setCursor(0,1);
    lcd.print(timeleft); 
    if ((timeleft <= totaltime) and (timeleft >= 20)){
      digitalWrite(yellow, HIGH);
    } 

    if ((timeleft <= 20) and (timeleft >10)){
      digitalWrite(yellow, LOW);
      lcd.print(" ");
      
      digitalWrite(blue, HIGH);
    } 

    if (timeleft <=10) {
      lcd.print(" ");
      digitalWrite(blue,LOW);
      digitalWrite(green, HIGH);
    } else{ digitalWrite(green, LOW); }

    if (timeleft <= 0){
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("DONE!");
      digitalWrite(blue, HIGH);
      digitalWrite(yellow, HIGH);
      digitalWrite(green, HIGH);
      delay(1000);
      digitalWrite(blue, LOW);
      digitalWrite(yellow, LOW);
      digitalWrite(green, LOW);
      delay(1000);
      
    }
  }
}

