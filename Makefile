SRC_FILES = src/draw.c \
		    src/main.c \
			src/mathematics.c \
			src/mutate.c \
			src/read_file.c \
			src/get.c \

HELPERS_FILES = helpers/ft_split.c \
				helpers/ft_atoi.c \
				helpers/get_next_line_bonus.c \
				helpers/get_next_line_utils_bonus.c \

SRC = $(SRC_FILES) $(HELPERS_FILES)
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = fdf
MAKE_MLX = cd mlx && make
all : $(NAME)

$(NAME) : $(OBJ)
	$(MAKE_MLX) 
	${CC} ${CFLAGS} ${OBJ} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	rm -f $(OBJ)
	$(MAKE) clean -C mlx
fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re