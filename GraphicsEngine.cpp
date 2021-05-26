/*Game Graphical Engine Class*/
#include "GraphicsEngine.h"

	//gets the current state of window
	SDL_Window* GraphicsEngine::getCurrentWindow() {
		return window;
	}

	//Sets the created window in the variable
	void GraphicsEngine::setCurrentWindow(SDL_Window* Mwindow) {
		window = Mwindow;
	}

	//Destroys the main window, if created
	void GraphicsEngine::destroyCurrentWindow() {

		if (getCurrentWindow() != NULL) {
			// Destroy the window. This will also destroy the surface
			SDL_DestroyWindow(getCurrentWindow());

			// Quit SDL
			SDL_Quit();
		}
		else {
			printf("Cannot destroy main window");
			system("pause");
		}
	}

	//Sets the main renderer
	void GraphicsEngine::setMainRender(SDL_Renderer* rnd) {
		mainRender = rnd;
	}

	//Gets the main renderer
	SDL_Renderer* GraphicsEngine::getMainRenderer() {
		return mainRender;
	}

	SDL_Surface* GraphicsEngine::getMainSurface() {
		return surface;
	}

	void GraphicsEngine::setMainSurface(SDL_Surface* surf) {
		surface = surf;
	}

	bool GraphicsEngine::renderTexture(SDL_Surface* img, SDL_Rect src, SDL_Rect dst) {

		SDL_Window* window = getCurrentWindow();

		IMG_Init(IMG_INIT_PNG);

		//assets/spritesheet/mario.png

		setMainSurface(img);

		SDL_Surface* image = getMainSurface();

	
		int flags = IMG_INIT_JPG | IMG_INIT_PNG;
		int initted = IMG_Init(flags);

		if (image == NULL) {
			cout << "Error image is null!\n " << endl;
			system("pause");
			return false;
		}

		Uint32 render_flags = SDL_RENDERER_PRESENTVSYNC | IMG_INIT_JPG | IMG_INIT_PNG;
		SDL_Renderer* rend = getMainRenderer();

		SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, image);

		SDL_FreeSurface(image);

		if (!tex)
		{
			printf("error creating texture: %s\n", SDL_GetError());
			//getchar(); // show error message, hit any key to quit
			SDL_DestroyRenderer(rend);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}


		//SDL_Rect srcrect = { x location, y location, width location, heigth location };
		//SDL_Rect srcrect = { 0, 16, 14, 13 }; //sprite sheet for game ove mario
		SDL_Rect srcrect = src;
		//{ 28, 0, 18, 17 }; //sprite sheet for jumping mario

		//SDL_Rect dstrect = { x screen, y screen, sprite width, sprite height };
		SDL_Rect dstrect = dst;
		//{ 102, 0, 50, 50 };

		SDL_RenderCopy(rend, tex, &srcrect, &dstrect); // draw the image to the window
		SDL_RenderPresent(rend);

		printf("texture drawn\n");
		
		return true;
		

	}

	void GraphicsEngine::updateCurrentWindow() {
		if (getMainRenderer() != NULL && getMainSurface() != NULL) {
			//update current render
			printf("Update window");
			SDL_UpdateWindowSurface(getCurrentWindow());
	
		}
		else {
			printf("Cannot update NULL render OR NULL surface...");
			system("pause");	
			destroyCurrentWindow();
		}
	}

	//Init the main window if not already initiated
	void GraphicsEngine::initMainWindow() {

		//temp main window
		SDL_Window* _window = NULL;
		SDL_Renderer* _rend = NULL;
		SDL_Surface* _surface = NULL;

		if (getCurrentWindow() == NULL) {
			
			_window = SDL_CreateWindow("Super Malario 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
		
			if (_window == NULL) {
				cout << "Failed to create main window: " << SDL_GetError() << endl;
				system("pause");
				destroyCurrentWindow();
			}
			else {
				setCurrentWindow(_window);
				printf("Main window is set\n");

				if (getMainSurface() == NULL) {

					_surface = SDL_GetWindowSurface(getCurrentWindow());
						
					if (_surface == NULL) {
						printf("Error init suirface");
						system("pause");
						destroyCurrentWindow();
					}
					else {
						setMainSurface(_surface);
						printf("Main surface is set");
					}
				
				}
				else {
					printf("Surface already created");
					system("pause");
				}

				//now, create a new render
				if (getMainRenderer() == NULL) {
					//Create a new one
					_rend = SDL_CreateRenderer(getCurrentWindow(), -1, 0);
					
					if (_rend == NULL) {
						//failed to create a new renderer
						printf("Failed to create a new renderer\n");
						system("pause");
						destroyCurrentWindow();
					}
					else {
						//New render created, update the main one
						setMainRender(_rend);
						SDL_RenderClear(_rend);
						printf("Main renderer created!\n");
					}
				}
				else {
					//Render already created
					printf("Renderer already created\n");
					system("pause");
				}
			}
		}
		else {
			printf("WARNING: Main window is already set\n");
			system("pause");
		}
		
		
		
	}


	//Constructor
	GraphicsEngine::GraphicsEngine() {

		//Init class
		// Initialize SDL. SDL_Init will return -1 if it fails.
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			cout << "Error initializing SDL: " << SDL_GetError() << endl;
			system("pause");
			// End the program
			//return;
		}

		initMainWindow();
	}

	GraphicsEngine::~GraphicsEngine() {

	}



