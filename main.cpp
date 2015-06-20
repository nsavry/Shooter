#include "Ship.hpp"
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

#include "Ship.hpp"
#include "bullet.hpp"

void	displayEdge(void)
{
	int		i;
	
	i = 0;
	while (i < 99)
	{
		mvprintw(3, 3 + i, "+");
		i++;
	}
	i = 0;
	while (i < 29)
	{
		mvprintw(3 + i, 3, "+");
		i++;
	}
	i = 0;
	while (i < 29)
	{
		mvprintw(3 + i, 101, "+");
		i++;
	}
	i = 0;
	while (i < 99)
	{
		mvprintw(31, 3 + i, "+");
		i++;
	}
}

void	displayText(int score, int life)
{
	int		i;

	i = 0;
	mvprintw(2, 3, "Score: %d", score);
	mvprintw(2, 80, "Life:");
	while (i < life)
	{
		mvprintw(2, 86 + (i * 2), "@");
		i++;
	}
}

void	displayBullet(Bullet *bul)
{
	int		i;
	i = 0;
	while (i < 200)
	{
		if (bul[i].getY() < 100)
		{
			mvprintw(bul[i].getX(), bul[i].getY(), "-");
			bul[i].setY(bul[i].getY() + 1);
		}
		i++;
	}
}

void	spawnEnemy(Ship *ship, int aff)
{
	int		test;
	int		i;

	if (aff == 0)
	{
		i = 0;
		while (ship[i].getStatus())
			i++;
		if (i < 50)
		{
			test = rand() % 2;
			if (test == 0)
			{
				ship[i].setStatus(true);	
				ship[i].setY((rand() % 27) + 4);
				ship[i].setX(101);
			}
		}
		i = 0;
		while (i < 50)
		{
			if (ship[i].getStatus())
			{
				ship[i].setX(ship[i].getX() - 1);
				if (ship[i].getX() == 3)
					ship[i].setStatus(false);
			}
			i++;
		}
	}
	i = 0;
	while (i < 50)
	{
		if (ship[i].getStatus())
			mvprintw(ship[i].getY(), ship[i].getX(), ")");
		i++;
	}
}

void	bulletEnemy(Ship ship, Bullet bul)
{
	if (bul[i].getX() == ship[i].getY())
	{
		ship[i].setStatus(false);
	}
}

int		main(void)
{
	int		key;
	int		x;
	int		y;
	int		i;
	int		k;

	k = 0;
	srand(time(NULL));
	Bullet	*bul = new Bullet[200];
	Ship	*ship = new Ship[50];
	x = 17;
	y = 10;
	key = 0;
	initscr();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
	while (key != 'q')
	{
		i = 0;
		while (i++ < 9000000);
		clear();
		displayEdge();
		displayText(100, 4);
		mvprintw(x, y, ">");
		key = getch();
		displayBullet(bul);
		spawnEnemy(ship, k);
		refresh();
		if (key == 258 && x < 30)
			x++;
		else if (key == 259 && x > 4)
			x--;
		else if (key == 260 && y > 4)
			y--;
		else if (key == 261 && y < 52)
			y++;
		else if (key == 32)
		{
			i = 0;
			while (bul[i].getY() < 100 && i < 200)
				i++;
			bul[i].setX(x);
			bul[i].setY(y + 1);
		}
		k++;
		if (k == 20)
			k = 0;
	}
	clear();
	refresh();
	endwin();
}
