NAME = ft_retro

SRC = Bullet.cpp\
	  Ship.cpp\
	  Ast.cpp\
	  Star.cpp\
	  Player.cpp\
	  main.cpp

OBJ = $(SRC:.cpp=.o)
CC = clang++

CFLAGS = -Wall -Wextra -Werror

FlAGCUR = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	@($(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lncurses)
	@echo "\033[32m$(NAME) created !\033[0m"

%.o : %.cpp
	@($(CC) -c $(SRC) $(CFLAGS))

clean :
	@(rm -f $(OBJ))
	@echo "\033[33mObject files deleted!\033[0m"

fclean : clean
	@(rm -f $(NAME))
	@echo "\033[31m$(NAME) deleted!\033[0m"

re : fclean all
