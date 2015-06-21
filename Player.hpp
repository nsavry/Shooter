#ifndef Player_hpp
# define Player_hpp

class Player
{
	public:
	Player(void);
	Player(Player const &rhs);
	~Player(void);

	Player	&operator=(Player const &rhs);

	int		getX(void) const;
	void	setX(int x);
	int		getY(void) const;
	void	setY(int y);
	int		getScore(void) const;
	void	setScore(int score);
	int		getLife(void) const;
	void	setLife(int life);

	private:
	int		_x;
	int		_y;
	int		_score;
	int		_life;
};

#endif
