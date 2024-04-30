NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

RM = rm -f

SRC = ft_atoi.c ft_split.c operations.c push_swap_outils.c push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
		 $(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJ) 

fclean: clean
		$(RM) $(NAME)

re: fclean all