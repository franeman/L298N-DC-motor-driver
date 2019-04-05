/*\
 * Motor.h - Library for using a DC motor wiwth the L298N driver
 * Created by: Ethan Grey, 4/5/19
 */

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  private:
    int _pin1;
    int _pin2;
    int _speedControl;
    int _pwmPin;
    
  public:
    Motor(int PosPin, int NegPin);
    Motor::Motor(int PosPin, int NegPin, int pwmPin);
    void DriveMotor(char motorDirection);
    void SetSpeed(int pwmSpeed);
};

#endif
