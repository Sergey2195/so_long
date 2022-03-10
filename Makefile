
   
SRCS =		srcs/main.c srcs/check_args.c srcs/error_exit.c srcs/map_init.c gnl/get_next_line.c srcs/check_map.c srcs/tile_array.c srcs/finish.c srcs/button.c srcs/images.c srcs/update.c srcs/render.c

HEADERS = 	include/so_long.h

OBJS =		$(SRCS:.c=.o)

LIBFT =		libft/libft.a

NAME =		so_long

CC			= gcc 
RM			= rm -f
FLAGS		= -I. -Wextra -Werror -Wall
LINKS 		= -lmlx -framework OpenGL -framework AppKit

$(NAME):		$(OBJS)
			$(MAKE) -C libft/
			cp $(LIBFT) $(NAME)
			$(CC) $(OBJS) $(LINKS) $(LIBFT) -o $(NAME)

all:			$(NAME)

%.o:			%.c $(HEADERS)
			$(CC) $(FLAGS) -c $< -o $@

clean:
			$(MAKE) clean -C libft/
			$(RM) $(OBJS)

fclean:			clean
			$(MAKE) fclean -C libft/
			$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re