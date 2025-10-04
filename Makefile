NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = philo.c\
	exception.c\
	infinite_repetition.c\
	finite_repetition.c\
	route.c\
	acting.c\
	stop.c\
	time.c\
	utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
