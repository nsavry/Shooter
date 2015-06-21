#include <iostream>
#include "Player.hpp"

Player::Player(void): _x(17), _y(10), _score(0), _life(4)
{
}

Player::Player(Player const &src)
{
	*this = src;
	return;
}

Player::~Player(void)
{
}

Player	&Player::operator=(Player const &rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
		this->_score = rhs.getScore();
		this->_life = rhs.getLife();
	}
	return *this;
}

int		Player::getX(void) const
{
	return (this->_x);
}

void	Player::setX(int x)
{
	this->_x = x;
}

int		Player::getY(void) const
{
	return (this->_y);
}

void	Player::setY(int y)
{
	this->_y = y;
}

int		Player::getScore(void) const
{
	return (this->_score);
}

void	Player::setScore(int score)
{
	this->_score = score;
}

int		Player::getLife(void) const
{
	return (this->_life);
}

void	Player::setLife(int life)
{
	this->_life = life;
}
