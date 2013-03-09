##
## Makefile for rush in /home/dell-a_f//projets/bmail
## 
## Made by florian dell-aiera
## Login   <dell-a_f@epitech.net>
## 
## Started on  Sat Mar  9 15:05:49 2013 florian dell-aiera
## Last update Sat Mar  9 15:08:55 2013 florian dell-aiera
##


NAME=		bmail

SRC=		src/main.cpp

OBJ=		$(SRC:.cpp=.o)

CFLAGS =	 -g -Wall -Werror -Wextra
LDFLAGS=

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(OBJ)
re:		fclean all