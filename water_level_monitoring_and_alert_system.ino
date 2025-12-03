#include <LiquidCrystal.h>
// LCD pins (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
#define trigPin 10
#define echoPin 2
#define buzzer 8
int tankHeight = 30;  // Tank height in cm
void setup()
{
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd.print("Water Level Sys"); 
  delay(1500);
  lcd.clear();
}
void loop()
{
  long duration;
  int distance;

  // Create trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time
  duration = pulseIn(echoPin, HIGH);

  // Convert time → distance (cm)
  distance = duration * 0.0343 / 2;

  // Calculate water level
  int waterLevel = tankHeight - distance;
  if (waterLevel < 0) waterLevel = 0;
  if (waterLevel > tankHeight) waterLevel = tankHeight;

  int percent = (waterLevel * 100) / tankHeight;

  // -------- LCD Display --------
  lcd.setCursor(0, 0);
  lcd.print("Dist:");
  lcd.print(distance);
  lcd.print("cm   ");

  lcd.setCursor(0, 1);
  lcd.print("Water:");
  lcd.print(percent);
  lcd.print("%    ");

  // Buzzer alert when tank is almost full (90%)
  if (percent >= 90) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}
