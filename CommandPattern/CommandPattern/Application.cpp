#include "stdafx.h"
#include "Application.h"

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

Application::Application()
	: m_quit(false)
	, m_lastTime(LTimer::gameTime())
{
	m_inputHandler = new InputHandler();
	m_character = new Character("Phil the Wizard");
}


Application::~Application()
{
}

bool Application::initialize(const char * title, int xPos, int yPos, int width, int height, int flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	}
	return true;
}

void Application::cleanUp()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
}

void Application::loop()
{
	LTimer capTimer;
	int frameNum = 0;

	while (!m_quit)
	{
		capTimer.start();

		handleEvents();
		update();
		render();

		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

void Application::loadContent()
{
}

void Application::unloadContent()
{
}

void Application::render()
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void Application::update()
{
	unsigned int currentTime = LTimer::gameTime();
	float deltaTime = (currentTime - m_lastTime) / 1000.f;
	m_lastTime = currentTime;
}

void Application::handleEvents()
{
	if (m_inputHandler->handleInput(&command_queue))
	{
		m_quit = true;
	}

	while (!command_queue.empty()) 
	{
		command_queue.back()->execute(m_character);
		command_queue.pop_back();
	}
}
