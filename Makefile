##
## EPITECH PROJECT, 2023
## my-radar
## File description:
## Project root Makefile
##

CC 			= 	gcc

MAIN		=	$(addprefix $(SRC_D), $(MAIN_F))
OBJ_M		=	$(MAIN:.c=.o)
MAIN_F		=	main.c

SRC			= 	$(addprefix $(SRC_D), $(SRC_F))
OBJ 		= 	$(SRC:.c=.o)
SRC_D 		= 	src/
SRC_F 		=	usage.c \
				simulation.c \
				start_menu.c \
				draw/draw_sim.c \
				draw/draw_plane.c \
				draw/draw_towers.c \
				draw/draw_background.c \
				draw/draw_timer.c \
				draw/draw_pause_menu.c \
				draw/draw_info.c \
				draw/draw_quadtree.c \
				events/poll_events.c \
				events/start_menu_poll_events.c \
				events/pause_sim.c \
				utilities/geometry.c \
				utilities/positions_checking.c \
				utilities/get_box_corners.c \
				utilities/get_percentage.c \
				utilities/sprite_opacity.c \
				collisions/box_collisions.c \
				collisions/plane_collisions.c \
				structures/tower.c \
				structures/window.c \
				structures/path.c \
				structures/plane/plane_create.c \
				structures/plane/plane_init.c \
				structures/plane/plane_move.c \
				structures/quadtree/quadtree.c \
				structures/quadtree/quadtree_query.c \
				structures/sim/sim.c \
				structures/sim/sim_states.c \
				structures/sim/sim_info.c \
				structures/sim/graphical/graphical.c \
				structures/sim/graphical/timeframe.c \
				structures/sim/graphical/timelapse.c \
				structures/sim/graphical/sim_fonts.c \
				structures/sim/graphical/sim_textures.c \
				structures/sim/graphical/sim_texts.c \
				file_manipulation/get_file_buffer.c \
				file_manipulation/get_entities_from_file.c \

SRC_UT   	=	$(addprefix $(SRC_UT_D), $(SRC_UT_F))
OBJ_UT 	 	=	$(SRC_UT:.c=.o)
SRC_UT_D 	= 	tests/
SRC_UT_F 	=	test_boundary_overlaps.c \
				test_pos_match.c \
				test_pos_are_near.c \
				test_boundary_contains_pos.c \

INC			= 	-I./include/ -I./include/structures/ -I./include/structures/sim/

CFLAGS		= 	-W -Wall -Wextra -Werror $(INC) $(LDFLAGS) $(DBFLAGS)

DBFLAGS		=	-g -g3 -ggdb

LDFLAGS 	=	-L./lib -lmy -lcsfml-graphics -lcsfml-system -lm

LDFLAGS_UT	= 	-lcriterion -lgcov --coverage

NAME 		= 	my-radar

NAME_UT 	= 	unit_tests

all: $(NAME)

$(NAME):	makelib $(OBJ) $(OBJ_M)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_M) $(CFLAGS)

makelib:
	make -C ./lib/my/ all

tests_run: clean $(OBJ) $(OBJ_UT)
	echo -e "\e[1;32mCompiling $(NAME_UT) binary... \e[0m"
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT)
	@rm -f $(SRC_UT_F:.c=.gcda)
	@rm -f $(SRC_UT_F:.c=.gcno)

clean:
	rm -f $(OBJ)
	rm -f *.gc*
	make -C ./lib/my clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)
	make -C ./lib/my clean

re: fclean all