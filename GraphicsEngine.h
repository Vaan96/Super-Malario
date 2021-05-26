#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "resource.h"
#include <stdlib.h>
#include <iostream>
#include <thread>  


using namespace std;

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	SDL_Window* getCurrentWindow();
	void setCurrentWindow(SDL_Window* Mwindow);
	void destroyCurrentWindow();
	void setMainRender(SDL_Renderer* rnd);
	SDL_Renderer* getMainRenderer();
	SDL_Surface* getMainSurface();
	void setMainSurface(SDL_Surface* surf);
	bool renderTexture(SDL_Surface* img, SDL_Rect src, SDL_Rect dst);
	void updateCurrentWindow();
	void initMainWindow();

private:
	SDL_Window* window;
	SDL_Renderer* mainRender;
	SDL_Surface* surface;

};


	