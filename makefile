CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -Lminilibx -lmlx -lX11 -lXext
RM = rm -f

NAME = fractol

SRCS = fractol.c events.c init.c render.c math_utils.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
