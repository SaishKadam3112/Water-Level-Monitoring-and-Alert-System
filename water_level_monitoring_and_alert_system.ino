#include <LiquidCrystal.h>
// LCD pins (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define trigPin 9
#define echoPin 10
#define buzzer 11
int tankHeight = 30;  // Tank height in cm
void setup() {
  lcd.begin(16, 2);
