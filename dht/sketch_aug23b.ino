#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;
#define DHT11_PIN 7
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
 //sets cursor to second line first row
 // last name on second line
//lcd.setCursor(0,1);  // cursor to first position first line

  
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0) ;
  lcd.print("Temperature = ");
  lcd.print(DHT.temperature);
  //Serial.println(DHT.temperature);
  lcd.setCursor(0,1) ;
  lcd.print("Humidity = ");
  lcd.print(DHT.humidity);
  //Serial.println(DHT.humidity);
  delay(10000);
 
}

