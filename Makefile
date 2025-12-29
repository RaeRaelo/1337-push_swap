# Name of the executable
NAME = push_swap

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = ./Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source Files (Based on your image)
SRCS = main.c \
       helpers.c \
       operations.c \
       ps_parsing.c \
       radix.c \
       sort_small.c \
       sort_utils.c \
       sort_utils2.c

# Object Files (Converted from .c to .o)
OBJS = $(SRCS:.c=.o)

# Header Includes
INCLUDES = -I. -I$(LIBFT_DIR)

# Rules

all: $(NAME)

# Compile Libft first, then compile push_swap
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to force make inside Libft directory
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean object files
clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

# Clean everything including the executable
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Re-compile everything
re: fclean all

.PHONY: all clean fclean re