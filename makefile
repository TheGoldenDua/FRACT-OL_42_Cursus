CC = cc 
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
RM = rm -rf

Name = fractol

SRCS = fractol.c events.c init.c render.c math_utils.c utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lmlx -lX11 -lXext -lm -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(rm) $(NAME)

re: fclean all

.PHONY: all clean fclean re 