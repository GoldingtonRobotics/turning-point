void runUsercontrol() {
	while (true) {
		if (autoSignal()) runAutonomous();
		tankLeft(vexRT[Ch3]);
		tankRight(vexRT[Ch2]);
		buttons(Btn5U, Btn5D, port5);
		buttons(Btn6U, Btn6D, port6);
		buttons(Btn7U, Btn7D, port7);
		buttons(Btn8U, Btn8D, port8);
	}
}
