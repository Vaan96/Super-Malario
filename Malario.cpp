#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include <iostream>
#include <thread>  
#include "resource.h"

using namespace std;

class Malario {

	enum currState {
		SMALL = 1,
		BIG = 2,
		FIRE = 3
	};


public:

	//Get the var to know is Malario is alive
	bool getAlive() {
		return isAlive;
	}

	//Sets Malario alive or not
	void setAlive(bool set) {
		isAlive = set;
	}

	//Get how many lives Malario has
	int getCurrLives() {
		return currLives;
	}

	//Set the number of lives 
	void setCurrLives(int set) {
		currLives = set;
	}
	
	//sets Malario current state
	void setCurrState(int state) {
		currState = state;
	}

	//Gets current state
	int getCurrState() {
		return currState;
	}

	//Set if Malario is already drawn on screen
	void setDrawn(bool set) {
		isDrawn = set;
	}

	//Gets the flag if Malario is drawn
	bool getDrawn() {
		return isDrawn;
	}

	//Sets the flag to running
	void setMalarioRunning(bool set) {
		isMalarioRunning = set;
	}
	
	//Gets the flag if is running
	bool getMalarioRunning() {
		return isMalarioRunning;
	}
	
	Malario() {

		//default configuration
		isAlive = true;
		currLives = 3;
		currState = 1;
		isMalarioRunning = false;

		isDrawn = false;

	}


private:
	bool isAlive;
	int currLives;
	int currState;
	bool isDrawn;
	bool isMalarioRunning;
	

};