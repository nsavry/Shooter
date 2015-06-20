#ifndef Bullet_hpp
# define Bullet_hpp

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

	private:
	int		_x;
	int		_y;
};

#endif
