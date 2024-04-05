NAME = libftprintf.a
LIBFT = libft
SRCS = ft_printf.c ft_printf_functions.c
CFLAGS = -Wall -Wextra -Werror -I. -I./libft
OBJS = $(SRCS:.c=.o)
CC = cc
AR = ar
RM = rm

# Execute when run make
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) -rcs $(NAME) $(OBJS)

# Build object files from .c files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	@$(RM) -rf $(OBJS)
	@make clean --no-print-directory -C $(LIBFT)

# Remove object files and rush-02
fclean: clean
	@$(RM) -rf $(OBJS)
	@make clean --no-print-directory -C $(LIBFT)
	@$(RM) -rf $(NAME)
	@$(RM) -rf $(LIBFT)/libft.a

# Rebuild program
re: fclean all

# These targets are always executed
.PHONY: all clean fclean re
