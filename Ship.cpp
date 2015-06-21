#include <iostream>
#include "Ship.hpp"

Ship::Ship(void): _status(false)
{
}

Ship::Ship(Ship const &src)
{
	*this = src;
}

Ship::~Ship(void)
{
}

Ship		&Ship::operator=(Ship const &rhs)
{
	if (this != &rhs) {
		this->_status = rhs.getStatus();
	}
	return *this;
}

int				Ship::getY() const
{
	return (this->_posY);
}

int				Ship::getX() const
{
	return (this->_posX);
}

void			Ship::setY(int y)
{
	this->_posY = y;
}

void			Ship::setX(int x)
{
	this->_posX = x;
}

bool			Ship::getStatus(void) const
{
	return (this->_status);
}

void			Ship::setStatus(bool isAlive)
{
	this->_status = isAlive;
}

void			Ship::hitBox(Player &player)
{
	if (this->_posY == player.getX() && this->_posX == player.getY())
	{
		this->_status = false;
		this->_posX = 300;
		this->_posY = 300;
		player.setLife(player.getLife() - 1);
		player.setX(17);
		player.setY(10);
	}
}
