#include "LEDManager.h"


LEDManager::LEDManager(int pin):pin(pin){
	pinMode(pin, OUTPUT);
}

void LEDManager::setMode(LEDMode mode, int maxBrightness, unsigned long cycleTime){
	analogWrite(pin, 0);
	startedCycle = false;
	this->cycleTime = cycleTime;
	this->mode = mode;
	this->maxBrightness = maxBrightness;
}

void LEDManager::update(unsigned long currentTime){
	if(!startedCycle){
		startedCycle = true;
		startTime = currentTime;
	}

	unsigned long  timeElapsed = currentTime - startTime;

	if(timeElapsed >= cycleTime){
		startedCycle = false;
	}

	float currentBrightness;
	switch(mode)
	{
		case SOLID:
			analogWrite(pin, maxBrightness);
			break;
		//Blink mode spends half its time on, and half off.
		case BLINK:
			if(timeElapsed <= (cycleTime/2))
				analogWrite(pin, maxBrightness);
			else
				analogWrite(pin, 0);
			break;
		case FADE_IN:
			//brightness is determined by a linear function of time
			currentBrightness = maxBrightness * (float(timeElapsed)/float(cycleTime));
			// Serial.println(currentBrightness);
			analogWrite(pin, int(currentBrightness));
			break;
		case FADE:
			//could use functions for this
			if(timeElapsed <= (cycleTime/2)){
				currentBrightness = maxBrightness * (float(timeElapsed)/float(cycleTime));
			}
			else
			{
				currentBrightness = maxBrightness * (1.0 - (float(timeElapsed)/float(cycleTime)));
			}
			analogWrite(pin, int(currentBrightness));
			break;
	}

	previousTime = currentTime;
}
