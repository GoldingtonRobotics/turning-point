#include "../base.h"
#include "../autonomous/because.h"
#include "../usercontrol/standard.h"

task main() {
	if (virtual) {
		runAutonomous();
	} else {
		runUsercontrol();
	}
}
