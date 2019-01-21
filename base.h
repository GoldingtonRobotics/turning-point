
void offAfter(int milliseconds) {
	wait1Msec(milliseconds);
	motor[port1] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
	motor[port6] = 0;
	motor[port7] = 0;
	motor[port8] = 0;
	motor[port9] = 0;
	motor[port10] = 0;
}

bool virtual = SensorValue[in1] > 1000;

void tankLeft(int power) {
	if (virtual) {
		motor[port3] = power;
		motor[port4] = power;
	} else {
		motor[port1] = power;
		motor[port2] = power;
	}
}

void tankRight(int power) {
	if (virtual) {
		motor[port1] = power * -1;
		motor[port2] = power * -1;
	} else {
		motor[port9] = power;
		motor[port10] = power;
	}
}

void goForwards(int milliseconds) {
	tankLeft(127);
	tankRight(127);
	offAfter(milliseconds);
}

void goBackwards(int milliseconds) {
	tankLeft(-127);
	tankRight(-127);
	offAfter(milliseconds);
}

void turnLeft(int milliseconds) {
	tankLeft(-127);
	tankRight(127);
	offAfter(milliseconds);
}

void turnRight(int milliseconds) {
	tankLeft(127);
	tankRight(-127);
	offAfter(milliseconds);
}

bool autoSignal() {
	return vexRT[Btn5U] + vexRT[Btn5D] + vexRT[Btn6U] + vexRT[Btn6D] == 4;
}

void buttons(int up, int down, int port)
{
	if      (vexRT[up])   motor[port] =  64;
	else if (vexRT[down]) motor[port] = -64;
	else                  motor[port] =   0;
}
