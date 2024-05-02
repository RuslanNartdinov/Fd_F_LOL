SRC_FILES = src/draw.c \
		    src/main.c \
			src/mathematics.c \
			src/mutate.c \
			src/read_file.c \

HELPERS_FILES = helpers/ft_split.c \
				helpers/ft_atoi.c \
				helpers/get_next_line_bonus.c \
				helpers/get_next_line_utils_bonus.c \

SRC = $(SRC_FILES) $(HELPERS_FILES)
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = fdf
all : $(NAME)

$(NAME) : $(OBJ)
	${CC} ${CFLAGS} ${OBJ} -o $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re