#include <Arduino.h>
#include <LiquidCrystal.h>

using namespace std;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //used default pin layout as in the example code.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String name = "";

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("LCD START");
  delay(1000);
  lcd.clear();
  Serial.begin(115200);
}

void loop() {
  lcd.print("Your Name? ");
  lcd.setCursor(0,0);
 if (Serial.available()) {
    // wait a bit for the entire message to arrive
    lcd.clear(); //clear for new message
    lcd.print("Reading Input...");
    delay(2000);
    // read all the available characters
    while (Serial.available() > 0 && name.length() < 16) {
      char c = Serial.read(); 
      if (c == '\n') break;
      name += c; //add each individual char to name
    }
    lcd.clear();
    lcd.print("Name is: ");
    lcd.setCursor(0,1);
    lcd.print(name);
    name = ""; //clear the name after each print
    delay(2000);
    lcd.clear();
}
}