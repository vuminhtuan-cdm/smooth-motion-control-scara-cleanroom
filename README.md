# Smooth Motion Control for SCARA Robots in Clean Rooms

## Project Overview
This research project focuses on developing smooth motion control algorithms for SCARA robots operating in semiconductor cleanroom environments.

## Research Objectives
- Develop smooth motion control strategies
- Implement trapezoidal velocity profiles
- Implement S-curve trajectory planning
- Evaluate motion performance
- Improve wafer handling precision

## Current Progress
- [X] Basic motor control
- [X] PWM speed control     
- [X] Trapezoidal profile
- [X] S-curve profile
- [X] Motion performance evaluation
- [ ] SCARA integration
- [ ] Wafer handling validation

## Experimental Results & Demos

### 1. Standard PWM Control (Without Profile)
> *Observation: Motor vibrates and shakes at startup due to sudden acceleration.*
  [https://github.com/user-attachments/assets/664ecdd9-f9eb-41cd-8849-d0fbb2d9c368]




## Hardware Platform
- Arduino
- Motor Driver
- Motor System
  
## Software
- MATLAB
- Arduino IDE
  
## Contributors
- Minh Tuan

## Challenges & Solutions (Rắc rối & Cách giải quyết)

### 1. Motor Startup Failure at Low PWM Duty Cycle
   **Problem:** 
    During the initial testing phase, when attempting to step the motor speed through `0% -> 25% -> 50% -> 75% -> 100%`, the motor failed to rotate at the `25%` threshold. This halted the entire initial motion sequence.
   **Root Cause:** 
    A 25% PWM duty cycle was too low to generate enough voltage and electromagnetic torque to overcome the system's initial static friction (holding torque/friction).
*   **Solution:** 
    Calibrated the minimum threshold required to initiate motion. Adjusted the speed test intervals to `31% -> 51% -> 75% -> 100%`. The updated 31% starting PWM provided sufficient power to break static friction, allowing the motor to start smoothly and execute the profile successfully.
