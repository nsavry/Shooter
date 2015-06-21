#include <iostream>
#include "Ast.hpp"

Ast::Ast(void): _status(false)
{
}

Ast::Ast(Ast const &src)
{
	*this = src;
}

Ast::~Ast(void)
{
}

Ast		&Ast::operator=(Ast const &rhs)
{
	if (this != &rhs) {
		this->_status = rhs.getStatus();
	}
	return *this;
}

int				Ast::getY() const
{
	return (this->_posY);
}

int				Ast::getX() const
{
	return (this->_posX);
}

void			Ast::setY(int y)
{
	this->_posY = y;
}

void			Ast::setX(int x)
{
	this->_posX = x;
}

bool			Ast::getStatus(void) const
{
	return (this->_status);
}

void			Ast::setStatus(bool isAlive)
{
	this->_status = isAlive;
}

void			Ast::hitBox(Player &player)
{
	if (this->_posY == player.getX() && this->_posX == player.getY())
	{
		this->_status = false;
		player.setLife(player.getLife() - 1);
		player.setX(17);
		player.setY(10);
	}
}
