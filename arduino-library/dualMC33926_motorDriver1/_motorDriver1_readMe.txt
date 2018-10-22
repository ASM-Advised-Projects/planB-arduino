This is the Arduin library for motor driver Dual MC33926 that only supports ONE driver connecting to the Arduino.

# Basic Application Connection

In a typical application, five I/O lines are used to connect the motor driver to a microcontroller: the two input lines, IN1 and IN2, for
direction control, one of the disable lines, D1 or D2, for PWM speed control, the status flag, SF, for monitoring motor driver errors, and
the current sense output, FB, for monitoring motor current draw (connected to an analog-to-digital converter input). The control lines can
be reduced to two pins if PWM signals are applied directly to the two input pins with both disable pins held inactive. A two-pin interface
can also be achieved using one of the disable lines for PWM speed control and the INV input for direction control with IN1 and IN2 held at
different values (i.e. one set HIGH and the other set LOW). In each of these cases, the other unused lines must be set to enable proper
operation. For example, if D2 is used for the PWM input (as is typically the case), D1 must be held low to prevent it from disabling the
motor driver. The circuit board provides convenient jumper points for overriding the motor driver defaults without having to connect extra 
wires to the module.

The current sense and status flag connections are optional, though monitoring of the status flag can allow detection of latched fault 
conditions. The status flag is an open-drain output, so multiple units can have their status flag pins wired together for applications 
where I/O pins are scarce and determining which motor driver is experiencing a fault condition is not necessary.

Note that the default state of the enable pin, EN, is LOW, which holds the chip in a low-current sleep mode. You will need to hold this 
pin high (either with an external connection or via the default-overriding jumper next to the pin) to allow the chip to run.

# testing...
## Pin Conenction
  * IN1 : D2
  * IN2 : D3
  * D1 : D7
  * D2 : D9
  * SF : no connection
  * FB : no connection
  * EN : to Arduino 5V pin
  

