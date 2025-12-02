#include <LiquidCrystal.h>
// LCD pins (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define trigPin 9
#define echoPin 10
#define buzzer 11
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
void loop() {
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
