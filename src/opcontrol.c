/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

void tankDrive()
{
	int powerL;
	int powerR;
	int intakeSpeed = 100;

	powerL = joystickGetAnalog(1, 3); // vertical axis on left joystick
	powerR = joystickGetAnalog(1, 2); // vertical axis on right joystick

	motorSet(1, - powerL * 0.9); // set left wheels
	//motorSet(3, powerL * 0.9); // set left wheels
	motorSet(10, powerR * 0.9); // set right wheels
	//motorSet(5, powerR * 0.9); // set right wheels

	if(joystickGetDigital(1, 6, JOY_UP))
	{
		motorSet(2, intakeSpeed);
	}
	else if(joystickGetDigital(1, 5, JOY_UP))
	{
		motorSet(2, -intakeSpeed);
	}
	else
	{
		motorSet(2, 0);
	}
}

void operatorControl()
{

	while (1)
	{
		tankDrive();

		delay(20);
	}
}
