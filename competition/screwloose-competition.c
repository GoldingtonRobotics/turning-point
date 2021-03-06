#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
#include "../base.h"
#include "../autonomous/screwloose.h"
#include "../usercontrol/standard.h"

void pre_auton() { bStopTasksBetweenModes = true; }

task autonomous() { runAutonomous(); }

task usercontrol() { runUserControl(); }
