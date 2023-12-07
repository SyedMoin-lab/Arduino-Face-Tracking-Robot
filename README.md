# Arduino-Face-Tracking-Robot




This repository contains the code and resources for an Arduino-based robot equipped with a Mu vision sensor for face tracking. The robot utilizes mecanum wheels and a motor driver shield to achieve omnidirectional movement while tracking faces using the vision sensor.

## Project Overview

### Parts List:
1. **Mu Vision Sensor**: Vision sensor used for face tracking capabilities.
2. **Mecanum Wheels (4x)**: 80mm specialized wheels allowing omnidirectional movement.
3. **TT Gear Motor (4x)**: Motors used to drive the mecanum wheels.
4. **Arduino Uno**: Main microcontroller board for controlling the robot.
5. **L293D Motor Driver Shield**: Motor driver shield for controlling the motors.
6. **18650 Li-ion Battery**: Power source for the robot.
7. **18650 Battery Holder**: Secures the battery in place.

### Functionality

The robot is designed to track faces using the Mu vision sensor and move accordingly with omnidirectional capabilities provided by the mecanum wheels. The Arduino Uno coupled with the L293D motor driver shield enables control over the motors for precise movement based on face tracking data.

## Repository Structure

- **/src**: Contains the source code for the robot's behavior, face tracking algorithms, and motor control.
- **/documentation**: Includes project documentation, schematics, and assembly instructions.
- **/examples**: Code examples or demonstrations showcasing specific functionalities.

## Getting Started

To replicate or further develop this robot, follow these steps:

1. **Assembly**: Build the robot chassis and attach the mecanum wheels according to the provided schematics (located in the /documentation folder).
2. **Hardware Setup**: Connect the Mu vision sensor, motors, motor driver shield, and Arduino Uno as per the wiring diagram in the documentation.
3. **Software Setup**: Upload the code from the /src folder to the Arduino Uno using the Arduino IDE or compatible development environment.

## Contributing

Contributions to this project are welcome! Feel free to fork this repository, make enhancements, and submit a pull request. Please adhere to the guidelines outlined in CONTRIBUTING.md.

## License

This project is licensed under the [MIT License](LICENSE).
