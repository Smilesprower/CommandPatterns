// SoftwareEngineeringProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define SDL_MAIN_HANDLED
#pragma comment(lib,"SDL2.lib") 

#include <SDL.h>
#include "Application.h"

int main(int argc, char** argv) {

	Application* app = new Application();

	app->initialize("CommandPattern", 300, 100, 800, 600, SDL_WINDOW_INPUT_FOCUS);
	app->loop();
	app->cleanUp();

	return 0;
}