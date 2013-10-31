Arduino-Serial-Port-Communication-R-C
=====================================
Arduino and Processing Code Repository

Description:
The Processing code runs on a computer in order to wirelessly control an
Arduino Mega ADK with an attached Adafruit motor shield by using a pair
of XBees. My current set up for my "Arduino Car" consists of four 3V
motors, four Tamiya 12:1 gearboxes, and a servo for steering. The
Processing code records pressed keys (on the keyboard) and writes the
keys' characters to the serial port. The Arduino code then uses the
received characters to change the motor speed and servo position. W =
forward, S = reverse, A = steer left, D = steer right, C = increase
speed, X = decrease speed.
