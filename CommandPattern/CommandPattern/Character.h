#pragma once
#include <iostream>
class Character
{
public:
	Character(std::string name);
	~Character();

	void move_left();
	void move_right();
	void jump();
	void crouch();

private :
	std::string m_name;
};

