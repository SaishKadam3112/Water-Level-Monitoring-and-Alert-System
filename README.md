💧 WATER LEVEL MONITORING AND AND ALERT SYSTEM

📌 Project Overview

This project is an Arduino-based Water Level Monitoring and Alert System. It continuously monitors the water level in a tank using an ultrasonic sensor, displays the water level on a 16×2 LCD, and activates a buzzer alert when the tank is almost full.
A potentiometer is used to adjust the LCD contrast, ensuring the display is clear and readable.
This system is useful for preventing tank overflow and efficiently managing water usage.

🛠 Components Required

Arduino UNO

Ultrasonic Sensor (HC-SR04)

16×2 LCD Display

Buzzer

10kΩ Potentiometer (for LCD contrast)

Jumper Wires

Breadboard

Power Supply (USB or 5V)


🔌 Pin Connections

Component	Arduino Pin / Connection

LCD RS	              7

LCD EN	              6

LCD D4               	5

LCD D5	              4

LCD D6               	3

LCD D7              	2

LCD VSS (GND)       	GND

LCD VDD (VCC)        	5V

LCD V0 (Contrast)   	Middle pin of potentiometer

Potentiometer ends  	5V & GND

Ultrasonic Trig     	9

Ultrasonic Echo	      10

Buzzer              	11

🖼 Circuit Diagram

<img width="1280" height="890" alt="image" src="https://github.com/user-attachments/assets/44e36b16-ea75-46de-ad50-6ce7f1d3de23" />


💻 Code Explanation

Ultrasonic Sensor :-
Measures the distance from the sensor to water surface.
Formula: distance = (duration * 0.0343) / 2

Potentiometer :-
Adjusts LCD contrast for better visibility.
Connected to V0 pin of LCD.

Water Level Calculation :-
waterLevel = tankHeight - distance
Converts distance into percentage of tank capacity.

LCD Display :-
Row 1: Distance from sensor to water.
Row 2: Water level percentage.

Buzzer Alert :-
Turns ON when water level reaches 90% or more.

⚡ Features

Real-time water level monitoring

Adjustable LCD contrast using potentiometer

Percentage display of water level

Audible alert for high water level

Simple and easy-to-understand design
