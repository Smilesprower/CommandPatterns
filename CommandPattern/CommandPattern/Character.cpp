#include "stdafx.h"
#include "Character.h"


Character::Character(std::string name)
	: m_name(name)
{
}


Character::~Character()
{
}

void Character::move_left()
{
	std::cout << m_name.c_str() << ": Moved Left" << std::endl;
}

void Character::move_right()
{
	std::cout << m_name.c_str() << ": Moved Right" << std::endl;
}

void Character::jump()
{
	std::cout << m_name.c_str() << ": Jumped" << std::endl;
}

void Character::crouch()
{
	std::cout << m_name.c_str() << ": Crouched" << std::endl;
}

