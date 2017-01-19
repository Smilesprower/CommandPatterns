#pragma once
#include <iostream>
#include <map>
#include <stack>
#include <SDL.h>
#include "Character.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
protected:
	Command() {};
};

class MacroCommand : public Command
{
public:
	MacroCommand() {};
	~MacroCommand() {};
	virtual void add(Command* command)
	{
		m_command_stack.push(command);
	}
	virtual void remove()
	{
		if (!m_command_stack.empty()) {
			m_command_stack.pop();
		}
	}
	virtual void execute()
	{
		if (!m_command_stack.empty()) {
			m_command_stack.top()->execute();
		}
	}
	virtual void undo()
	{
		if (!m_command_stack.empty()) {
			m_command_stack.pop();
		}
	}
private:
	std::stack<Command*> m_command_stack;
};


class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	bool handleInput();

private:
	SDL_Event event;

	Command *move_left;
	Command *move_right;
	Command *jump;
	Command *crouch;
	MacroCommand m_commandMacro;
	std::map <int, Command*> commands;
};

class MoveLeft : public Command
{
public:
	void execute() { std::cout << "Move Left" << std::endl; }
};
class MoveRight : public Command
{
public:
	void execute() { std::cout << "Move Right" << std::endl; }
};
class Jump : public Command
{
public:
	void execute() { std::cout << "Jump" << std::endl; }
};
class Crouch : public Command
{
public:
	void execute() { std::cout << "Crouch" << std::endl; }
};


