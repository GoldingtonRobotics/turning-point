#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
void pre_auton()
{
  bStopTasksBetweenModes = true;
}

void runAutonomous() {
	motor[port1] = 127;
	motor[port10] = -127;
	wait1Msec(2000);
	motor[port1] = 0;
	motor[port10] = 0;
	motor[port5] = -127;
	motor[port6] = -127;
	wait1Msec(500);
	motor[port5] = 0;
	motor[port6] = 0;
}


task autonomous()
{
	runAutonomous();
}

void buttons(int up, int down, int port)
{
	if      (vexRT[up])   motor[port] =  64;
	else if (vexRT[down]) motor[port] = -64;
	else                  motor[port] =   0;
}

task usercontrol()
{

  while (true)
  {

   		if (vexRT[Btn5U] + vexRT[Btn5D] + vexRT[Btn6U] + vexRT[Btn6D] == 4) runAutonomous();
  	// right wheel
    motor[port1] = vexRT[Ch2];
    motor[port2] = vexRT[Ch2];

    // left wheel
    motor[port9]  = vexRT[Ch3] * -1;
    motor[port10]  = vexRT[Ch3] * -1;

		buttons(Btn5U, Btn5D, port5);
		buttons(Btn6U, Btn6D, port6);
		buttons(Btn7U, Btn7D, port7);
		buttons(Btn8U, Btn8D, port8);

  }
}
