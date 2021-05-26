#include "SDL.h"
#include "SDL_image.h"
#include <stdlib.h>
#include <iostream>
#include <thread>  
#include "resource.h"
#include "GraphicsEngine.cpp"
#include "Malario.cpp"


class GameLogic {

	//Enumeration for game states
	enum gameStateList {
		MAIN_SCREEN = 1,
		IN_GAME = 2,
		GAME_OVER = 3,
		PAUSE = 4
	};


public:

	GraphicsEngine* ge;
	Malario* malario;


	//Set the boolean game loop var
	void setIsRunning(bool set) {
		running = set;
	}

	//Get the state of the var 
	bool getIsRunning() {
		return running;
	}

	//Sets the current game state
	void setGameState(int currGameState) {
		gameState = currGameState;
	}

	//gets the current game state
	int getGameState() {
		return gameState;
	}

	GameLogic() {

		//init all necessary classes and vars
		ge = new GraphicsEngine();
		malario = new Malario();

		gameState = 1;

		//after its done, start the main loop
		running = true;
		gameLoop();
		
	}


	//Main Game Loop
	void gameLoop() {

		int frame = 0;

		
		//ge->renderTexture(img1, srcrect1, dstrect1);

		SDL_Rect srcrect1 = { 0, 0, 1280, 750 };
		SDL_Rect dstrect1 = { 0, 0, 1280, 750 };
		SDL_Surface* img1 = IMG_Load("assets/img/bg.png");


		ge->renderTexture(img1, srcrect1, dstrect1);

		

		int i = 0;
		int h = 0;

		SDL_Event input;

		while (running) {

			SDL_RenderClear(ge->getMainRenderer());

			

			/*while (SDL_PollEvent(&input) > 0)
			{
				if (input.type == SDL_QUIT) running = false;
			}*/


			int totalFrames = 8;
			int delayPerFrame = 100;

			int frame = (SDL_GetTicks() / delayPerFrame) % totalFrames;





			//mario
			SDL_Rect srcrect = { 28, 0, 18, 17 };
			SDL_Rect dstrect = { i, h, 50, 50 };
			SDL_Surface* img = IMG_Load("assets/spritesheet/mario.png");

			

			ge->renderTexture(img, srcrect, dstrect);


			std::cout << "avgFPS:  " << frame << std::endl;

			


			i++;
			h++;

		}

	}

private:

	int gameState;
	bool running;


};