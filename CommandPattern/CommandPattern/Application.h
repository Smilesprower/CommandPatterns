#pragma once
#include "SDL.h"
#include "LTimer.h"
#include "InputHandler.h"
#include <vector>
class Application
{
public:
	Application();
	~Application();
	bool initialize(const char*, int, int, int, int, int);
	void cleanUp();
	void loop();

private:
	bool m_quit;
	float m_lastTime;

	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	InputHandler * m_inputHandler;
	Character * m_character;
	std::vector<Command*> command_queue;

	void loadContent();
	void unloadContent();
	void render();
	void update();
	void handleEvents();
};

