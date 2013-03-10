##
## Makefile for make in /home/dell-a_f//projets/bmail
## 
## Made by florian dell-aiera
## Login   <dell-a_f@epitech.net>
## 
## Started on  Sun Mar 10 13:21:40 2013 florian dell-aiera
## Last update Sun Mar 10 13:27:28 2013 florian dell-aiera
##

NAME=	bmail

SRC=	src/main.cpp \
	src/Core.cpp \
	src/Connection.cpp \
	src/Parse.cpp \
	src/Process.cpp

OBJ=	$(SRC:.cpp=.o)

CFLAGS=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)