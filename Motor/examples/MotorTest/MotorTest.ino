#include <Motor.h>

Motor test(8,9,3); /* DC motor with PWM control
pin 8 connected to in1
pin 9 connected to in2
pin 3 connected to ENA
*/
                    

void setup() {
  test.SetSpeed(150); // Set speed to 255
}
void loop() {
test.DriveMotor('f'); // Run motor forward
delay(2000); // Wait 2 seconds
test.DriveMotor('b'); // Run motor backward
delay(3500); // Wait 3.5 seconds
test.DriveMotor('s'); // Stop motor
delay(1000); // Wait 1 second
}
