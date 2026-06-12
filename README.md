# Smart Traffic Simulation

An adaptive, density-based traffic light simulation built with C++ and the [raylib](https://www.raylib.com/) library. This project simulates an intelligent intersection that adjusts green-light timing based on real-time vehicle demand.

## 🚀 Features
*   **Adaptive Green Timing:** Traffic lights dynamically adjust their duration based on the number of vehicles in each lane.
*   **Ambulance Priority:** Emergency vehicles automatically trigger a green light and "push" traffic ahead of them to clear the path.
*   **Smooth Physics:** Vehicles feature realistic acceleration and smooth braking logic.
*   **Interactive HUD:** Real-time density bars and timers show the simulation's "logic" in action.
*   **Manual Spawning:** Click on lanes to spawn cars or ambulances and test the system's response.

## 🛠 Project Structure
*   `include/`: Header files (`.h`) defining the system architecture and constants.
*   `src/`: Implementation files (`.cpp`) containing the simulation logic, rendering, and input handling.
  * `constants.h`: Geometry configurations and base timing thresholds.
  * `traffic.cpp` / `traffic.h`: Adaptive timing metrics and state transitions.
  * `vehicle.cpp` / `vehicle.h`: Spawning safety and gap-based physics.
  * `render.cpp` / `render.h`: Drawing pipelines and HUD rendering.
  * `main.cpp`: Window initialization and core loop.
## 🔨 Build Instructions

### Prerequisites
*   C++ Compiler (e.g., `g++`)
*   [raylib](https://www.raylib.com/) installed on your system.

### Compilation
From the project root directory, run:
```bash
g++ src/*.cpp -o simulation -Iinclude -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
```

### Running
```bash
./simulation
```
