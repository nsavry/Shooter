#include <iostream>
#include "Bullet.hpp"

Bullet::Bullet(void): _x(160), _y(160)
{
}

Bullet::Bullet(int x, int y): _x(x), _y(y)
{
}

Bullet::Bullet(Bullet const &src)
{
	*this = src;
}

Bullet::~Bullet(void)
{
}

Bullet	&Bullet::operator=(Bullet const &rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return *this;
}

int		Bullet::getX(void) const
{
	return (this->_x);
}

int		Bullet::getY(void) const
{
	return (this->_y);
}

void		Bullet::setX(int x)
{
	this->_x = x;
}

void		Bullet::setY(int y)
{
	this->_y = y;
}

void		Bullet::hitBox(Ship &ship, Player &player)
{
	if (ship.getX() == this->_y && ship.getY() == this->_x)
	{
		this->_y = 200;
		ship.setStatus(false);
		ship.setX(300);
		ship.setY(300);
		player.setScore(player.getScore() + 100);
	}
}	

void		Bullet::hitBox(Ast &ast, Player &player)
{
	if (ast.getX() == this->_y && ast.getY() == this->_x)
	{
		this->_y = 200;
		ast.setStatus(false);
		ast.setX(300);
		ast.setY(300);
		player.setScore(player.getScore() + 500);
	}
}
