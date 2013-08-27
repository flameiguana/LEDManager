#include <LEDManager.h>

LEDManager pinNine(9);
LEDManager pinTen(10);

void setup() {
	//pattern, maximum brightness (PWM value), cycle time
	pinNine.setMode(LEDManager::FADE, 150, 2000);;
	pinTen.setMode(LEDManager::BLINK, 255, 400);
}

void loop(){
	unsigned long currentTime = millis();
	pinNine.update(currentTime);
	pinTen.update(currentTime);
}
