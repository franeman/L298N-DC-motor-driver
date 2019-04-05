/*\
 * Motor.cpp - Library for using a DC motor wiwth the L298N driver
 * Created by: Ethan Grey, 4/5/19
 */

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int PosPin, int NegPin) // Constructor without speed control
{
  // Assign pins
  _pin1 = PosPin;
  _pin2 = NegPin;
  _pwmPin = -1; // Not using speed control

  // Set pins as outputs
  pinMode(_pin1,OUTPUT);
  pinMode(_pin2,OUTPUT);
}

Motor::Motor(int PosPin, int NegPin, int pwmPin) // Constructor using speed control
{
  // Assign pins
  _pin1 = PosPin;
  _pin2 = NegPin;
  _pwmPin = pwmPin;

  // Set pins as outputs
  pinMode(_pin1,OUTPUT);
  pinMode(_pin2,OUTPUT);
  pinMode(_pwmPin, OUTPUT);
}

void Motor::DriveMotor(char motorDirection) 
/*
 * Controls motor direction, this function takes a character as an input and then determines if the motor will spin forward, back, or stop.
 * 'f' will make the motor turn forward
 * 'b' or 'r' will make the motor turn backward
 * anything else will cause the motor to stop
 */
{
  switch(motorDirection)
  {
    case 'f':
    {
      digitalWrite(_pin1,HIGH);
      digitalWrite(_pin2,LOW);
      break;
    }
    case 'b':
    case 'r':
    {
      digitalWrite(_pin1,LOW);
      digitalWrite(_pin2,HIGH);
      break;
    }
    default:
    {
      digitalWrite(_pin1,LOW);
      digitalWrite(_pin2,LOW);
    }
  }
}

void Motor::SetSpeed(int pwmSpeed)
/*
 * Controls the motor's speed, this takes an int as an input and sets that as the pwm output
 */
{
  if(_pwmPin != -1) // If the pwm pin was defined
  {
    _speedControl = pwmSpeed;
    analogWrite(_pwmPin, _speedControl);
  }
}
