#include "stdafx.h"
#include "InputHandler.h"


InputHandler::InputHandler()
{
	move_left = new MoveLeft();
	move_right = new MoveRight();
	jump = new Jump();
	crouch = new Crouch();

	commands[SDLK_a] = move_left;
	commands[SDLK_LEFT] = move_left;
	commands[SDLK_d] = move_right;
	commands[SDLK_RIGHT] = move_right;
	commands[SDLK_w] = jump;
	commands[SDLK_UP] = jump;
	commands[SDLK_SPACE] = jump;
	commands[SDLK_s] = crouch;
	commands[SDLK_DOWN] = crouch;
}


InputHandler::~InputHandler()
{
}

bool InputHandler::handleInput()
{
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) 
			return true;
		if (event.type == SDL_KEYDOWN)
		{
			int keyPressed = event.key.keysym.sym;
			std::map<int, Command*>::iterator iter;
			for (iter = commands.begin(); iter != commands.end(); iter++)
			{
				if (keyPressed == iter->first)
				{
					m_commandMacro.add(iter->second);
					m_commandMacro.execute();
				}
			}
			if (keyPressed == SDLK_BACKSPACE)
			{
				m_commandMacro.undo();
				m_commandMacro.execute();
			}
		}

	}
	return false;
}
