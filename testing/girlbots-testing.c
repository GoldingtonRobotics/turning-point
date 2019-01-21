#include "../base.h"
#include "../autonomous/girlbots.h"
#include "../usercontrol/standard.h"

task main() {
	if (virtual) {
		runAutonomous();
	} else {
		runUsercontrol();
	}
}
