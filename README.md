# Garden Monitoring System

This Arduino project is designed to create a smart room system using various sensors and actuators. The system incorporates a temperature sensor, a light sensor, and a distance sensor to perform different functions based on the environmental conditions.

## Components Used
- Arduino Board
- Servo Motor
- Ultrasonic Distance Sensor
- Buzzer
- RGB LED
- Light Dependent Resistor (LDR)
- Temperature Sensor

## Pin Configuration
- Ultrasonic Sensor: Trigger Pin (3), Echo Pin (2)
- Buzzer: 13
- Light Sensor: A1
- Servo Motor: 5
- RGB LED: Red (11), Blue (10), Green (9)
- Temperature Sensor: A2

## Libraries Used
- Servo.h

## Setup
1. Attach the servo motor to pin 5.
2. Connect the ultrasonic sensor to trigger pin 3 and echo pin 2.
3. Connect the buzzer to pin 13.
4. Connect the light sensor to pin A1.
5. Connect the RGB LED pins as follows:
   - Red: 11
   - Blue: 10
   - Green: 9
6. Connect the temperature sensor to pin A2.

## Code Overview

### Functions
1. **`colour(int r, int g, int b)`**
   - Sets the RGB LED color based on the provided values for red, green, and blue.

2. **`tempercheck()`**
   - Reads the temperature from the sensor and sets the RGB LED color accordingly.

3. **`distcheck()`**
   - Measures the distance using the ultrasonic sensor.

4. **`servosweep()`**
   - Sweeps the servo motor back and forth.

### Loop
- Checks the light level and performs actions based on the conditions:
  - If it's bright (light level > 500), turns off the RGB LED, activates the buzzer, and blinks the red LED.
  - If an object is close (distance < 20) and it's dark (light level < 500), activates the buzzer and performs a servo sweep.
  - If it's dark (light level < 500), sets the RGB LED color based on temperature.

## How to Use
1. Upload the code to your Arduino board.
2. Connect the sensors and actuators according to the specified pin configuration.
3. Power on the system and observe the responses based on the environmental conditions.

Feel free to customize the code and hardware configuration to suit your specific needs.
