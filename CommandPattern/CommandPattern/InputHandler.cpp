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
	commands[SDLK_s] = crouch;
	commands[SDLK_DOWN] = crouch;
}


InputHandler::~InputHandler()
{
}

bool InputHandler::handleInput(std::vector<Command*>* command_queue)
{
	
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) 
			return true;
		if (event.type == SDL_KEYDOWN)
		{
			/*
			Get current pressed key.
			Iterate through map of commands
			If theres a match push back command from map into command queue
			*/
			int keyPressed = event.key.keysym.sym;
			std::map<int, Command*>::iterator iter;
			for (iter = commands.begin(); iter != commands.end(); iter++)
			{
				if (keyPressed == iter->first)
				{
					command_queue->push_back(iter->second);
				}
			}
		}
	}
	return false;
}
