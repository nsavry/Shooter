#ifndef Ast_hpp
# define Ast_hpp

# include "Player.hpp"

class Ast
{
	public:
	Ast(void);
	Ast(Ast const &rhs);
	~Ast(void);

	Ast			&operator=(Ast const &rhs);

	bool			getStatus(void) const;
	void			setStatus(bool isAlive);
	int				getX(void) const;
	int				getY(void) const;
	void			setX(int x);
	void			setY(int y);

	void	hitBox(Player &player);

	protected:
	bool			_status;
	int				_posX;
	int				_posY;
};

#endif
