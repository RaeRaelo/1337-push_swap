
NAME = push_swap


CC = cc
CFLAGS = -Wall -Wextra -Werror


LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a


SRCS = main.c \
       helpers.c \
       operations.c \
       ps_parsing.c \
       radix.c \
       sort_small.c \
       sort_utils.c \
       sort_utils2.c


OBJS = $(SRCS:.c=.o)


INCLUDES = -I. -I$(LIBFT_DIR)



all: $(NAME)


$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)


clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean


fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean


re: fclean all

.PHONY: all clean fclean re