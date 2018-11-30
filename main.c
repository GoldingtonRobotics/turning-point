/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/


void runAutonomous() {
	motor[port1] = 127;
	motor[port10] = -127;
	wait1Msec(1000);
	motor[port1] = -127;
	motor[port10] = -127;
	wait1Msec(500);
	motor[port1] = 127;
	motor[port10] = -127;
	wait1Msec(1000);
	motor[port1] = 0;
	motor[port10] = 0;
}


task autonomous()
{
	runAutonomous();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop

  while (true)
  {

    if (vexRT[Btn5U] + vexRT[Btn5D] + vexRT[Btn6U] + vexRT[Btn6D] == 4) runAutonomous();

  	// right wheel
    motor[port1] = vexRT[Ch2];

    // left wheel
    motor[port10]  = vexRT[Ch3] * -1;

    // arm ...
    if(vexRT[Btn5U] == 1)
    {
      motor[port5] = 40;
    }
    else if(vexRT[Btn5D] == 1)
    {
      motor[port5] = -40;
    }
    else
    {
      motor[port5] = 0;
    }

    // claw ...
    if(vexRT[Btn6U] == 1)
    {
      motor[port6] = 40;
    }
    else if(vexRT[Btn6D] == 1)
    {
      motor[port6] = -40;
    }
    else
    {
      motor[port6] = 0;
    }
  }
}
