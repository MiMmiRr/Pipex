CC = gcc
CFLAGS = -Werror -Wextra -Wall

NAME = pipex

SRCS = Src/transformer.c Src/pathifier.c Src/main.c \
	Src/ft_strjoin.c Src/ft_split.c Src/ft_strncmp.c \
	Src/redirect.c

OBJ = $(SRCS:Src/%.c=Obj/%.o)

HEADER = Src/pipex.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -ggdb -o $(NAME)

Obj/%.o: Src/%.c $(HEADER)
	@mkdir -p Obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf Obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
