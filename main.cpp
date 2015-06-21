#include "Ship.hpp"
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

#include "Ship.hpp"
#include "Ast.hpp"
#include "Star.hpp"
#include "Bullet.hpp"
#include "Player.hpp"

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

void	displayText(Player *player)
{
	int		i;

	i = 0;
	mvprintw(2, 3, "Score: %d", player->getScore());
	mvprintw(2, 80, "Life:");
	while (i < player->getLife())
	{
		mvprintw(2, 86 + (i * 2), "@");
		i++;
	}
}

void	displayBullet(Bullet *bul, Ship *ship, Ast *ast, Player *player)
{
	int		i;
	int		j;

	i = 0;
	while (i < 200)
	{
		if (bul[i].getY() < 100)
		{
			mvprintw(bul[i].getX(), bul[i].getY(), "-");
			bul[i].setY(bul[i].getY() + 1);
			j = 0;
			while (j < 50)
			{
				bul[i].hitBox(ast[j], *player);
				bul[i].hitBox(ship[j], *player);
				j++;
			}
		}
		i++;
	}
}

void	spawnEnemy(Ship *ship, int aff)
{
	int		test;
	int		i;

	if (aff < 2)
	{
		i = 0;
		while (ship[i].getStatus())
			i++;
		if (i < 50)
		{
			test = rand() % 4;
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
}

void	displayEnemy(Ship *ship, Player *player)
{
	int		i;

	i = 0;
	while (i < 50)
	{
		ship[i].hitBox(*player);	
		if (ship[i].getStatus())
			mvprintw(ship[i].getY(), ship[i].getX(), ")");
		i++;
	}
}

void	spawnStars(Star *star, int aff)
{
	int		test;
	int		i;

	if (aff % 3)
	{
		i = 0;
		while (star[i].getStatus())
			i++;
		if (i < 100)
		{
			test = rand() % 3;
			if (test == 0)
			{
				star[i].setStatus(true);	
				star[i].setY((rand() % 27) + 4);
				star[i].setX(101);
			}
		}
		i = 0;
		while (i < 100)
		{
			if (star[i].getStatus())
			{
				star[i].setX(star[i].getX() - 1);
				if (star[i].getX() == 3)
					star[i].setStatus(false);
			}
			i++;
		}
	}
}

void	displayStars(Star *star)
{
	int		i;

	i = 0;
	while (i < 100)
	{
		if (star[i].getStatus())
			mvprintw(star[i].getY(), star[i].getX(), "*");
		i++;
	}
}

void	spawnAst(Ast *ast, int aff)
{
	int		test;
	int		i;

	if (aff % 2)
	{
		i = 0;
		while (ast[i].getStatus())
			i++;
		if (i < 100)
		{
			test = rand() % 10;
			if (test == 0)
			{
				ast[i].setStatus(true);	
				ast[i].setY((rand() % 27) + 4);
				ast[i].setX(101);
			}
		}
		i = 0;
		while (i < 100)
		{
			if (ast[i].getStatus())
			{
				ast[i].setX(ast[i].getX() - 1);
				if (ast[i].getX() == 3)
					ast[i].setStatus(false);
			}
			i++;
		}
	}
}

void	displayAst(Ast *ast, Player *player)
{
	int		i;

	i = 0;
	while (i < 50)
	{
		ast[i].hitBox(*player);	
		if (ast[i].getStatus())
			mvprintw(ast[i].getY(), ast[i].getX(), "#");
		i++;
	}
}

int		main(void)
{
	int		key;
	int		i;
	int		iframe;
	Bullet	*bul = new Bullet[200];
	Ship	*ship = new Ship[50];
	Ast		*ast = new Ast[50];
	Star	*stars = new Star[100];
	Player	*player = new Player;

	key = 0;
	iframe = 0;
	
	srand(time(NULL));
	
	//start_color();
	//init_pair(0, COLOR_YELLOW, COLOR_BLACK);
	
	initscr();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
	
	while (key != 'q' && player->getLife() > 0)
	{
		i = 0;
		while (i++ < 9000000);
		
		clear();
		
		displayEdge();
		displayText(player);
		
		spawnStars(stars, iframe);
		spawnEnemy(ship, iframe);
		spawnAst(ast, iframe);

		displayBullet(bul, ship, ast, player);
		displayStars(stars);
		displayEnemy(ship, player);
		displayAst(ast, player);
		mvprintw(player->getX(), player->getY(), ">");
		
		key = getch();
		
		refresh();
		
		if (key == 258 && player->getX() < 30)
			player->setX(player->getX() + 1);
		else if (key == 259 && player->getX() > 4)
			player->setX(player->getX() - 1);
		else if (key == 260 && player->getY() > 4)
			player->setY(player->getY() - 1);
		else if (key == 261 && player->getY() < 52)
			player->setY(player->getY() + 1);
		else if (key == 32)
		{
			i = 0;
			while (bul[i].getY() < 100 && i < 200)
				i++;
			bul[i].setX(player->getX());
			bul[i].setY(player->getY() + 1);
		}

		iframe++;
		if (iframe == 20)
			iframe = 0;
	}

	clear();
	refresh();
	endwin();
}
