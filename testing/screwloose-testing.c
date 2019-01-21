#include "../base.h"
#include "../autonomous/screwloose.h"
#include "../usercontrol/standard.h"

task main() {
	if (virtual) {
		runAutonomous();
	} else {
		runUsercontrol();
	}
}
