#pragma once

#include "GraphicsEngine.h"
#include "Malario.h"


class GameLogic
{
public:

	//Enumeration for game states
	enum gameStateList {
		MAIN_SCREEN = 1,
		IN_GAME = 2,
		GAME_OVER = 3,
		PAUSE = 4
	};


	GameLogic();
	~GameLogic();

	void setIsRunning(bool set);
	bool getIsRunning();
	void setGameState(int currGameState);
	int getGameState();

	void gameLoop();

private:

	int gameState;
	bool running;

	GraphicsEngine* ge;
	Malario* malario;

};

