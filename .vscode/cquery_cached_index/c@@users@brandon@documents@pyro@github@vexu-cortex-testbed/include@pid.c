// PID Controllers go here.

#include "main.h"

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

int BRJoystickPID(int joystick, int joyChannel)
{
  int setPoint;

  int joyValue = joystickGetAnalog(joystick, joyChannel);

  if(joyValue > 10)
  {
    setPoint = PID(getSetPoint(), 0.95 * joyValue, kp);
  }
  else if(joyValue < -50)
  {
    setPoint = PID(getSetPoint(), (int) (-1 * exp(0.0623 * (joyValue - 50))), kp);
  }
  else if(joyValue < 0)
  {
    kp = kp + kp * (-joyValue / 50);
    setPoint = PID(getSetPoint(), 0, kp);
  }
  else // 0 - 10 deadzone
  {
    setPoint = 0;
  }
  return setPoint;
}
