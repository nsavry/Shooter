#ifndef Star_hpp
# define Star_hpp

# include "Player.hpp"

class Star
{
	public:
	Star(void);
	Star(Star const &rhs);
	~Star(void);

	Star			&operator=(Star const &rhs);

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
