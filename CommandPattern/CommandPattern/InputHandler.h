#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <SDL.h>
#include "Character.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Character *character) = 0;
protected:
	Command() {};
};



class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	bool handleInput(std::vector<Command*> *command_queue);

private:
	SDL_Event event;

	Command *move_left;
	Command *move_right;
	Command *jump;
	Command *crouch;
	std::map <int, Command*> commands;
};


class MoveLeft : public Command
{
public:
	void execute(Character * character) { character->move_left(); }
};
class MoveRight : public Command
{
public:
	void execute(Character * character) { character->move_right(); }
};
class Jump : public Command
{
public:
	void execute(Character * character) { character->jump(); }
};
class Crouch : public Command
{
public:
	void execute(Character * character) { character->crouch(); }
};


