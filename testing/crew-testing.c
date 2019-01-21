#include "../base.h"
#include "../autonomous/crew.h"
#include "../usercontrol/standard.h"

task main() {
	if (virtual) {
		runAutonomous();
	} else {
		runUsercontrol();
	}
}
