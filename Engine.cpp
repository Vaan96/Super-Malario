

/*Game Main Engine Class*/

#include "SDL.h"
#include <stdlib.h>
#include <iostream>
#include <thread>  




using namespace std;


class Engine {

	
public:	

	//Getters and Setters
	void setIsRunning(bool set) {
		isRunning = set;
	}


	bool getIsRunning() {
		return isRunning;
	}

	Engine() {
		isRunning = true;

	}

	void initEngine() {

		

		//init vars
		//init window

		// Pointers to our window and surface
		SDL_Surface* winSurface = NULL;
		SDL_Window* window = NULL;

		// Initialize SDL. SDL_Init will return -1 if it fails.
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			//cout << "Error initializing SDL: " << SDL_GetError() << endl;
			system("pause");
			// End the program
			//return;
		}

		// Create our window
		window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

		// Make sure creating the window succeeded
		if (!window) {
			//cout << "Error creating window: " << SDL_GetError() << endl;
			system("pause");
			// End the program
			//return;
		}

		// Get the surface from the window
		winSurface = SDL_GetWindowSurface(window);

		// Make sure getting the surface succeeded
		if (!winSurface) {
			//cout << "Error getting surface: " << SDL_GetError() << endl;
			system("pause");
			// End the program
			//return;
		}

		// Fill the window with a white rectangle
		SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 0, 0, 0));

		// Update the window display
		SDL_UpdateWindowSurface(window);

		// Wait -  Delay
		//SDL_Delay(2000);

		//cicle while loop



		/*   
		
		int counter = 0;
		double test, test2;
		while (timer.elapsedSeconds() < 10.0)
		{
			counter++;
			test = std::cos(counter / M_PI);
			test2 = std::sin(counter / M_PI);
		}
		timer.stop();

		std::cout << counter << std::endl;
		std::cout << "Seconds: " << timer.elapsedSeconds() << std::endl;
		std::cout << "Milliseconds: " << timer.elapsedMilliseconds() << std::endl;
	}*/

		//Timer timer;

		int tick = SDL_GetTicks();
		unsigned int lastTime = 0;
		int frame = 0;

		int r = 1; 

		bool white = false;
		

		while (isRunning) {
			//std::this_thread::sleep_for(std::chrono::microseconds(10));

			//tick = SDL_GetTicks();
			//std::cout << "ticks:  " << currentTime << std::endl;
			//measurement = (measurement * smoothing) + (tick * (1.0 - smoothing));

			// frame / (tick / 60.0f);

			while (frame < 240) {
				frame++;
				std::cout << "loading...  " << frame << std::endl;
			}

			float fps = frame / 60;

			float avgFPS = frame / fps;

			
		
			if (r > 0 && r != 255 && white == false) {
				SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, r, r, r));
				SDL_UpdateWindowSurface(window);
				r++;

				if (r == 255)
					white = true;
			}

			if (r != 1 && r <= 255 && white == true) {
				SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, r, r, r));
				SDL_UpdateWindowSurface(window);
				r--;

				if (r == 1)
					white = false;
			}

			//std::cout << "FPS:  " << fps << std::endl;
			std::cout << "avgFPS:  " << avgFPS << std::endl;
			/*if (currentTime > lastTime + 2000) {
				std::cout << "Milliseconds:  " << lastTime << std::endl;
				lastTime = currentTime;
			}*/
			
			++frame;
			
			/*for (int k = 0; k < 255; k++) {

				int r = k, g = k, b = k;
				
				SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, r, g, b));
				SDL_UpdateWindowSurface(window);
			}

			for (int k = 255; k > 0; k--) {

				int r = k, g = k, b = k;
				//std::this_thread::sleep_for(std::chrono::milliseconds(25));

				SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, r, g, b));
				SDL_UpdateWindowSurface(window);
			}
			*/
			

		}

		// Destroy the window. This will also destroy the surface
		SDL_DestroyWindow(window);

		// Quit SDL
		SDL_Quit();
	}

private:
		bool isRunning;


};


