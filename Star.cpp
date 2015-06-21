#include <iostream>
#include "Star.hpp"

Star::Star(void): _status(false)
{
}

Star::Star(Star const &src)
{
	*this = src;
}

Star::~Star(void)
{
}

Star		&Star::operator=(Star const &rhs)
{
	if (this != &rhs) {
		this->_status = rhs.getStatus();
	}
	return *this;
}

int				Star::getY() const
{
	return (this->_posY);
}

int				Star::getX() const
{
	return (this->_posX);
}

void			Star::setY(int y)
{
	this->_posY = y;
}

void			Star::setX(int x)
{
	this->_posX = x;
}

bool			Star::getStatus(void) const
{
	return (this->_status);
}

void			Star::setStatus(bool isAlive)
{
	this->_status = isAlive;
}
