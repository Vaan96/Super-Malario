#include "Malario.h"


	//Get the var to know is Malario is alive
	bool Malario::getAlive() {
		return isAlive;
	}

	//Sets Malario alive or not
	void Malario::setAlive(bool set) {
		isAlive = set;
	}

	//Get how many lives Malario has
	int Malario::getCurrLives() {
		return currLives;
	}

	//Set the number of lives 
	void Malario::setCurrLives(int set) {
		currLives = set;
	}
	
	//sets Malario current state
	void Malario::setCurrState(int state) {
		currState = state;
	}

	//Gets current state
	int Malario::getCurrState() {
		return currState;
	}

	//Set if Malario is already drawn on screen
	void Malario::setDrawn(bool set) {
		isDrawn = set;
	}

	//Gets the flag if Malario is drawn
	bool Malario::getDrawn() {
		return isDrawn;
	}

	//Sets the flag to running
	void Malario::setMalarioRunning(bool set) {
		isMalarioRunning = set;
	}
	
	//Gets the flag if is running
	bool Malario::getMalarioRunning() {
		return isMalarioRunning;
	}
	
	Malario::Malario() {

		//default configuration
		isAlive = true;
		currLives = 3;
		currState = 1;
		isMalarioRunning = false;

		isDrawn = false;

	}

	Malario::~Malario() {

	}

