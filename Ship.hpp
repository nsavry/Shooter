#ifndef Ship_hpp
# define Ship_hpp

# include "Player.hpp"

class Ship
{
	public:
	Ship(void);
	Ship(Ship const &rhs);
	~Ship(void);

	Ship			&operator=(Ship const &rhs);

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
