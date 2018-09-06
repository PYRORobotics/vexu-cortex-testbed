// PID Controllers go here.

#include "main.h"
#include "math.h"

double kp = 0.1;

int getSetPoint()
{
  return 0; // FIX ME
}

int PID(int lastSetPoint, int setPoint, double kp)
{
  //kp;
  double ki;
  double kd;

  return setPoint;
}

void drivetrainSet(int speed)
{
  motorSet(1, -speed);
  motorSet(10, speed);
}

void BRJoystick(int joystick, int joyChannel)
{
  //int setPoint;

  int joyValue = joystickGetAnalog(joystick, joyChannel);
  int speed;

  if(joyValue > 10)
  {
    speed = 0.95 * joyValue;
  }
  else if(joyValue < -50)
  {
    speed = -1 * exp(0.0623 * (joyValue - 50));
  }
  else if(joyValue < 0)
  {
    //kp = kp + kp * (-joyValue / 50);
    speed = 0;
  }
  else // 0 - 10 deadzone
  {
    speed = 0;
  }
  //return setPoint;
}
