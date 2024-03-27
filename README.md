# Dust Density Measurement with Pump Control

This Arduino project measures dust density using a dust sensor module and controls a pump using a relay based on the measured dust density. The system employs an analog dust sensor to detect dust particles in the air and activates a pump to mitigate dust accumulation when the density exceeds a certain threshold.

## Components Used
- Arduino board (e.g., Arduino Uno)
- Dust sensor module
- Relay module
- Pump
- LEDs and resistors (for indication, optional)

## Installation and Setup
1. Connect the dust sensor module to the Arduino board.
2. Connect the relay module to control the pump.
3. Upload the provided Arduino sketch to the Arduino board.

## Code Overview
- **Measure Dust Density:** The code reads analog values from the dust sensor module and converts them to dust density using a predefined formula.
- **Pump Control:** If the calculated dust density exceeds a specified threshold, the relay is activated to turn on the pump. Otherwise, the relay is deactivated, turning off the pump.
- **Serial Output:** Real-time data including raw sensor readings, voltage values, and dust density are printed via serial communication for monitoring purposes.

## Adjustments
- **Threshold Setting:** You can adjust the dust density threshold value (`0.5` in the provided code) to match your specific application requirements.
- **Sampling Parameters:** Fine-tune sampling time, delta time, and sleep time variables for optimal performance based on environmental conditions.

## Usage
1. Power up the Arduino board and ensure proper connections.
2. Open the serial monitor to observe real-time data.
3. As dust density changes, monitor the pump activation/deactivation based on the set threshold.
