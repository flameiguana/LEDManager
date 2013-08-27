#ifndef LEDManager_H
#define LEDManager_H

#include "Arduino.h"

class LEDManager{
public: 
	enum LEDMode {FADE_IN, FADE_OUT, FADE, SOLID, BLINK};
	LEDManager(){}
	LEDManager(int pin);
	void setMode(LEDMode mode, int maxBrightness, unsigned long cycleTime = 1000);
	void update(unsigned long currentTime);
	
	LEDMode getMode() {return mode;}
	int getBrightness() {return maxBrightness;}
private:
	int pin, maxBrightness;
	unsigned long startTime, cycleTime, previousTime; 
	bool startedCycle, timeToStep;
	LEDMode mode;
};

#endif