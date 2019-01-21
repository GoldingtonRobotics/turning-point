#include "../base.h"
#include "../autonomous/jaguars.h"
#include "../usercontrol/standard.h"

task main() {
	if (virtual) {
		runAutonomous();
	} else {
		runUsercontrol();
	}
}
