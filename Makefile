##
## Makefile for  in /home/AmOrAA/Delivery/Matchstick/CPE_2016_matchstick
## 
## Made by Florian Testu
## Login   <AmOrAA@epitech.net>
## 
## Started on  Mon Feb 20 12:21:02 2017 Florian Testu
## Last update Fri Feb 24 22:30:36 2017 Florian Testu
##

CC      =       gcc

RM      =       rm -f

NAME    =       matchstick

SRC     =       src/matchstick.c		\
		src/fonc.c			\
		src/my_str_to_wordtab.c		\
		src/my_remp_map.c		\
		src/check_lose.c		\
		src/get_next_line.c		\
		src/check_error.c		\
		src/cond.c			\
		src/cond2.c			\
		src/cond3.c			\
		src/main.c

CFLAGS +=       -W -Wall -Wextra -pedantic -Iinclude

LIB     =       -L ./lib/

OBJ     =       $(SRC:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
		$(RM) $(OBJ)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
