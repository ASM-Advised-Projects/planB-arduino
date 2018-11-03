# asm-planB_arduino

# Summary
This file acts as the backup program for RASMv2 main control program

# Hardware
## Motor Driver
-3 Dual MC33926 Motor Driver Carrier (motor shield);
 - link: https://www.pololu.com/product/1213
 - Arduino Mega 2560 R3
  - Motor shield pins (functions and their pins requirements);
    * VIN --- this is the main 5-28V power supply connection
    * GND ---ground connection for logic and motor power supplies
    * OUT2 --- the motor output pin controlled by IN2
    * OUT1 --- the motor output pin controlled by IN1
    * IN2 --- the logic control of OUT2
    * IN1 --- the logic control of OUT1
    * D1 --- when D1 is high, OUT1 and OUT2 are set to high impedance.
    * SF --- monitor motor driver errors
   - for more information, visit: https://www.pololu.com/product/1212
  - Application connections; only five I/O that will be used on RASM: IN2, IN1, D1, SF and FB
    * IN1 --- digital pin
    * IN2 --- digital pin
    * D1 --- PWM pin
    * SF --- 
    * FB ---
    * EN --- the default state is LOW, has to set this to HIGH to allow the motor driver chip to run.

## Motor Selection
- 5 Motors; [need to add later] and 1 linear actuator

- Filtering Motor Noise
  * Using *RealTimeLTIFilter* in signal_processing.hpp (link: https://github.com/ASM-Advised-Projects/rasm-v2/blob/master/include/control/signal_processing.hpp)
  * other choices: low pass filter if necessary
  
## Encoders;
   * Encoders from: [https://www.rls.si/eng/rm22-rotary-magnetic-modular-encoder] 
   * from the technical data; RM22V only has 3 connections; 
     - V_out = Green (wire color) - connect to Arduino Digital PWM pin
     - V_dd = Red (wire color) == Voltage supply only limit to 5V with +/-5%
     - GND = Blue (wire color) == ground
     
   // the below pins information are based on the old encoder, still study if the it is still valid on the encoders that will be used on RASM as the encoders have 9 pins. 
   * Encoders pins (connected to digital pins arduino, reccommended interrupt pins 2,3,18-29);
    - encoder motor 1: pins #
    - encoder motor 2: pins #
    - encoder motor 3: pins #
    - encoder motor 4: pins # 
    - encoder motor 5: pins #
   * refs: http://playground.arduino.cc/code/interrupts
    
# Arduino Library
* DualMC33926Motor3Shield; 
 - supports 3 DualMC33926 motor shields, if needs to change any motor driver-arduino pins, change it in the .cpp file.
* rm22vEncoder ;
 - encoder library that supports RM22V encoder that RASM uses. [need to update late]
* signal_processing.hpp (link: https://github.com/ASM-Advised-Projects/rasm-v2/blob/master/include/control/signal_processing.hpp - Joe's)
 - to filter the noise if there's any  
  # Example Program
---------------
## 1. Demo.
 ### Demo 1.
 * For testing the custom motor library "DualMC33926Motor3Shield" and check if the library works as intended
 
 ### Demo 2.
 * Testing the motors and encoder reading value. 
 * library: rm22vEncoder && DualMC33926Motor3Shield

 ### Demo 3.
 * Refine encoder reading values by using filters- software and electronics(if necessary)
