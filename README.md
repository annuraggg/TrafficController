# TrafficController

TrafficController is an embedded systems project designed to automate and optimize traffic signal control using sensors and microcontrollers (such as Arduino). It leverages ultrasonic sensors to detect vehicle presence and dynamically changes traffic lights at an intersection, aiming to reduce waiting time by adapting to real-time traffic conditions.

---

## Features

- **Sensor-Based Traffic Detection**: Uses ultrasonic sensors at each lane to measure the distance to the nearest vehicle, detecting traffic presence.
- **Dynamic Signal Control**: Changes traffic signals (red, yellow, green) based on detected traffic at each lane, minimizing idle green time and ensuring signals respond to actual vehicular flow.
- **Multiple Signal Support**: Supports up to four traffic signals/lights (typical four-way intersection).
- **Boot Animation**: On startup, a boot animation sequence lights up all signals for initialization.
- **Real-Time Feedback**: Outputs sensor readings and signal status via serial for monitoring/debugging.

---

## How It Works

1. **Sensors Setup**: Each approach to the intersection has an ultrasonic sensor (using the NewPing library) to measure vehicle distance.
2. **Signal Initialization**: All traffic signal pins are set as output during setup.
3. **Main Loop**:
    - Continuously polls each sensor for distance readings.
    - If a vehicle is detected within a set threshold on a lane, the corresponding signal turns green (with transition through yellow).
    - If no vehicles are detected (distance above threshold), the signal remains or turns red.
    - Flags ensure only one direction can be green at a time.
    - Serial output allows monitoring of sensor values and signal state.
4. **Customizable Delays**: Green and yellow durations can be configured for each signal.

---

## Hardware Connections

- **Ultrasonic Sensors**: Wired to microcontroller pins defined in the code (e.g., TRIGGER_PIN_1/ECHO_PIN_1 for lane 1).
- **Signal Lights**: Three pins per signal (red, yellow, green LEDs or relays).

---

## Code Structure

- `trafficcontroller.ino`: Main logic for sensor readings, signal control, and animation.
- `controllerV2.ino` and `src/controller.cpp`: Alternative controller logic and modularized code.
- `libraries/NewPing`: Library for accurate ultrasonic distance measurement.

---

## Getting Started

1. **Clone the repository** and open the main code file (e.g., `trafficcontroller.ino`) in the Arduino IDE.
2. **Wire up sensors and signals** as per pin definitions in the code.
3. **Upload the code** to your microcontroller.
4. **Power on** and observe boot animation, then live traffic signal control.

---

## Customization

- Adjust the `threshold` value to set sensitivity for vehicle detection.
- Modify `greenDelay` and `yellowDelay` for timing adjustments.
- Expand or modify the code for more lanes or improved logic.


---

## Author

- [@annuraggg](https://github.com/annuraggg)

---

TrafficController provides a smart, sensor-driven approach to intersection management, potentially reducing congestion and improving traffic flow in urban environments.
