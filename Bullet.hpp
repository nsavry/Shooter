#ifndef Bullet_hpp
# define Bullet_hpp

# include "Ship.hpp"
# include "Ast.hpp"
# include "Player.hpp"

class Bullet
{
	public:
	Bullet(void);
	Bullet(int x, int y);
	Bullet(Bullet const &rhs);
	~Bullet(void);

	Bullet	&operator=(Bullet const &rhs);

	int		getX(void) const;
	void	setX(int x);
	int		getY(void) const;
	void	setY(int y);

	void	hitBox(Ship &ship, Player &player);
	void	hitBox(Ast &ast, Player &player);

	private:
	int		_x;
	int		_y;
};

#endif
