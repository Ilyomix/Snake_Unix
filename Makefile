##
## Makefile for  in /home/abd-li_i/nibbler
## 
## Made by ilyes abd-lillah
## Login   <abd-li_i@epitech.net>
## 
## Started on  Fri Nov 16 17:19:09 2012 ilyes abd-lillah
## Last update Sun Apr  6 22:21:31 2014 ilyes abd-lillah
##

SRC	=	core/main.cpp \
		core/Dlloader.cpp \
		core/GameManager.cpp \
		core/Snake.cpp \

CC	=	g++

NAME	=	nibbler

CFLAGS	=	-W -Wall -Werror 

OBJ	=	$(SRC:.cpp=.o)

$(NAME):	$(OBJ)
		$(CC) -fpic -shared Lib/SdlLib.cpp -o lib_nibbler_SDL.so 
		$(CC) -fpic -shared Lib/NcursesLib.cpp -o lib_nibbler_NCurses.so	
		$(CC) -fpic -shared Lib/OpenglLib.cpp -o lib_nibbler_OpenGl.so	
		$(CC) $(SRC) -o $(NAME) -ldl -lSDL -lSDL_image -lncurses -lSDL_mixer
		export LD_LIBRARY_PATH="./lib_nibbler_SDL.so"
		export LD_LIBRARY_PATH="./lib_nibbler_NCurses.so"
		export LD_LIBRARY_PATH="./lib_nibbler_OpenGl.so"

all:		$(NAME)

clean:
	rm -f core/$(OBJ)
	rm -f *~

fclean:		clean
	rm -f lib_nibbler_SDL.so
	rm -f lib_nibbler_NCurses.so
	rm -f lib_nibbler_OpenGl.so
	rm -f $(NAME)

re:	fclean all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

.phony: all clean fclean re
