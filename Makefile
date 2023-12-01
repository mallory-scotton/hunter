##
## EPITECH PROJECT, 2023
## myhunter
## File description:
## Makefile
##

SRC :=	init.c \
		hud.c \
		loop.c \
		main.c \
		window.c \
		events/handler.c \
		events/joystick_movements.c \
		events/joystick.c \
		events/keyboard.c \
		events/mouse.c \
		events/window.c \
		functions/fire.c \
		functions/move.c \
		gamemode/gm_1plyr.c \
		gamemode/gm_2plyr.c \
		gamemode/gm_menu.c \
		gamemode/shared/ducks.c \
		gamemode/shared/text.c \
		gamemode/menu/menu.c \
		util/factor.c \
		util/maths.c \
		util/itob.c \
		util/strings.c

_SRC := $(SRC:%=src/%)

OBJ := $(_SRC:.c=.o)

NAME := my_hunter

INCLUDE := -I include/

CFLAGS := 	-g $(INCLUDE) \
			-lcsfml-graphics \
			-lcsfml-system \
			-lcsfml-window \
			-lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	gcc -lm -g3 -o $(NAME) $(OBJ) $(CFLAGS)
	make clean

clean:
	find -type f -iname "*.o" -delete

fclean: clean
	rm -f $(NAME)

re: fclean all
