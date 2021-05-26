#pragma once


class Malario
{
public:

	enum currState {
		SMALL = 1,
		BIG = 2,
		FIRE = 3
	};

	Malario();
	~Malario();

	bool getAlive();
	void setAlive(bool set);
	int getCurrLives();
	void setCurrLives(int set);
	void setCurrState(int state);
	int getCurrState();
	void setDrawn(bool set);
	bool getDrawn();
	void setMalarioRunning(bool set);
	bool getMalarioRunning();



private:

	bool isAlive;
	int currLives;
	int currState;
	bool isDrawn;
	bool isMalarioRunning;

};
