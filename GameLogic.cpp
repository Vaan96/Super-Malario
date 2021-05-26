#include "GameLogic.h"

	//Set the boolean game loop var
	void GameLogic::setIsRunning(bool set) {
		running = set;
	}

	//Get the state of the var 
	bool GameLogic::getIsRunning() {
		return running;
	}

	//Sets the current game state
	void GameLogic::setGameState(int currGameState) {
		gameState = currGameState;
	}

	//gets the current game state
	int GameLogic::getGameState() {
		return gameState;
	}


	void GameLogic::gameLoop() {

		while (running) {



		}
	}

	GameLogic::GameLogic() {

		//init all necessary classes and vars
		ge = new GraphicsEngine();
		malario = new Malario();
	
		//gameState = 1;

		//after its done, start the main loop
		running = true;
	}

	GameLogic::~GameLogic() {

	}



